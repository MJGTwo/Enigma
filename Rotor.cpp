#include "Rotor.h"
#include <utility>
#include <string>
#include <iostream>
using namespace std;

int lettoval(char let) ;

Node::Node()
{
	prev=NULL;
	next=NULL;
	crypt=NULL;
}

Node::~Node()
{
	prev=NULL;
	next=NULL;
	crypt=NULL;
}

Row::Row()
{
	size=0;
	head=NULL;
	tail=NULL;
	partner=NULL;
}

Row::~Row()
{


	partner=NULL;
	tail=NULL;

	deconHelper(head);
}

void Row::deconHelper(Node*ptr)
{
	if (!(ptr->next ==head || ptr->next == NULL)) deconHelper(ptr->next);
	delete ptr;
	ptr=NULL;

	size--;

}

void Row::add(Node* n)
{
	if (size==0)
	{
		head = n;
		tail = head;

		size++;
	}
	else
	{
		tail->next=n;
		tail->next->prev=tail;

		head->prev=n;
		head->prev->next=head;

		tail=n;
		size++;
	}
}

void Rotor::shift()	///function shifts the crypt pairs by one and then relinks them.
{
	shift(1);
}

void Rotor::shift(int n) // function shifts the cryp pairs by n and then relinks them.
{
	int i =0;
	while (i < n)
	{
		output.tail=output.head;
		output.head=output.head->next;
		i++;
	}
	input.link(output);
}

void Rotor::move()
{
	move(1);
}

void Rotor::move(int n)
{
	if (n==0) return;
	int trans0,trans1;
	Node* helper0;
	Node *helper1;

	for (int i =0 ; i < n; i ++)
	{
		trans0=input.head->num;
		trans1=output.head->num;

		helper0=input.head;
		helper1=output.head;
		for (int j =0; j < 25; j++)
		{
			helper0->num=helper0->next->num;
			helper1->num=helper1->next->num;
			helper0=helper0->next;
			helper1=helper1->next;
		}

		helper0->num = trans0;
		helper1->num = trans1;


	}
}

void Row::link(Row &othr) //// Function pairs two rows together.
{
	if (partner!=NULL)	////If already linked, delink and then link
	{
		Node *temp =partner->head;
		do{
			temp->crypt=NULL;
			temp=temp->next;
		}while (temp != partner->head);

	}
	partner=&othr;
	othr.partner=this;
	Node * thisitr=this->head;
	Node * othritr=othr.head;
	if (this->size != othr.size) return;
	do{
		thisitr->crypt = othritr;
		othritr->crypt = thisitr;
		thisitr=thisitr->next;
		othritr=othritr->next;
	}while (thisitr != this->tail->next);
	

}

Row::Row(int i)
{
	int num = i;
	string temp;
	if (num ==1)
	{
		temp = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	}
	else if (num ==2)
	{
		temp = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	}
	else if (num ==3 )
	{
		temp = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
	}
	else if (num ==4 )
	{
		temp = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
	}
	else if (num == 5)
	{
		temp = "VZBRGITYUPSDNHLXAWMJQOFECK";
	}
	else if (num == 6)
	{
		temp = "JPGVOUMFYQBENHZRDKASXLICTW";
	}
	else if (num == 7)
	{
		temp = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
	}
	else if (num == 8)
	{
		temp = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
	}
	else
	{
		temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	}
	for (int i =0; i < temp.size(); i++)
	{
		Node* tempN = new Node;
		tempN->num = lettoval(temp[i]);
		add(tempN);

	}
}


Rotor::Rotor(int num)	////the strings are the roginal values of the Enigma Rotors. Using a helper function 
{						////they are turned into numbers for incryption and decryption
	next=prev=NULL;
	string pln = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string temp;
	for (int i =0; i < 26; i++)
	{
		Node* tempN = new Node;
		tempN->num = i;
		input.add(tempN);

	}
	

	if (num ==1)
	{
		temp = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	}
	else if (num ==2)
	{
		temp = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	}
	else if (num ==3 )
	{
		temp = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
	}
	else if (num ==4 )
	{
		temp = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
	}
	else if (num == 5)
	{
		temp = "VZBRGITYUPSDNHLXAWMJQOFECK";
	}
	else if (num == 6)
	{
		temp = "JPGVOUMFYQBENHZRDKASXLICTW";
	}
	else if (num == 7)
	{
		temp = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
	}
	else if (num == 8)
	{
		temp = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
	}
	else
	{
		temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	}
	for (int i =0; i < temp.size(); i++)
	{
		Node* tempN = new Node;
		tempN->num = lettoval(temp[i]);
		output.add(tempN);

	}

	input.link(output);

	
}

int Rotor::operator[]( int numb) 
{
	
	Node* finder = input.head;
	while (finder->num != numb)
	{
		finder= finder->next;
	}
	
	return finder->crypt->num;
}
 void Rotor::print() const
 {
 	string trans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 	string line(4*26+1,'-');
 	Node* iItr = input.head;
 	Node* oItr = output.head;
 	cout << line<<endl;
 	cout <<"|";
 	do{
 		cout << " "<< trans[iItr->num] << " |";

 		iItr=iItr->next;
 	}while(iItr!=input.head);
 	cout<< endl<<"|";
 	do{
 		cout << " "<< trans[oItr->num] << " |";
 		oItr=oItr->next;
 	}while(oItr!=output.head);
 	cout<< endl<<line<<endl;
 	

 }

Reflector::Reflector()
{
	int i =0;
	string plain = "ABCDEFGIJKMTV";
	string B = "YRUHQSLPXNOZW";
	for (; i < 13; i++)
	{
		Node* temp = new Node;
		temp->num=lettoval(plain[i]);
		board.add(temp);
	}
	int j =0;
	Node* ptr = board.head;
	for (; j < 13; j++)
	{
		Node* temp = new Node;
		temp->num= lettoval(B[j]);
		ptr->crypt=temp;
		temp->crypt=ptr;

		board.add(temp);
		ptr=ptr->next;
	}
}

int Reflector::operator[](int n)
{
	Node* finder = board.head;
	while (finder->num != n)
	{
		finder=finder->next;
	}
	return finder->crypt->num;
}

int lettoval(char let) ///This converts letters into their position in the alphabet starting with A=0
{
	if(let=='A')
	{
		return 0;
	}
	else if(let=='B')
	{
		return 1;	
	}
	else if(let=='C')
	{
		return 2;
	}
	else if(let=='D')
	{
		return 3;
	}
	else if(let=='E')
	{
		return 4;		
	}
	else if(let=='F')
	{
		return 5;
	}
	else if(let=='G')
	{
		return 6;		
	}
	else if(let=='H')
	{
		return 7;
	}
	else if(let=='I')
	{
		return 8;		
	}
	else if(let=='J')
	{
		return 9;
	}
	else if(let=='K')
	{
		return 10;		
	}
	else if(let=='L')
	{
		return 11;
	}
	else if(let=='M')
	{
		return 12;		
	}
	else if(let=='N')
	{
		return 13;
	}
	else if(let=='O')
	{
		return 14;		
	}
	else if(let=='P')
	{
		return 15;
	}
	else if(let=='Q')
	{
		return 16;		
	}
	else if(let=='R')
	{
		return 17;
	}
	else if(let=='S')
	{
		return 18;		
	}
	else if(let=='T')
	{
		return 19;
	}
	else if(let=='U')
	{
		return 20;		
	}
	else if(let=='V')
	{
		return 21;
	}
	else if(let=='W')
	{
		return 22;		
	}
	else if(let=='X')
	{
		return 23;
	}
	else if(let=='Y')
	{
		return 24;		
	}
	else if(let=='Z')
	{
		return 25;
	}
	else
	{
		return 0;
	}

}