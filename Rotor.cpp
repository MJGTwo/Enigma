#include "Rotor.h"
#include <utility>
#include <string>
#include <iostream>
using namespace std;

int lettoval(char let);

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

	Node * ptr = head;

	deconHelper(ptr);
}

void Row::deconHelper(Node*ptr)
{
	if (ptr->next !=head && ptr->next != NULL)
	{
		deconHelper(ptr->next);
		
	}
	delete ptr;
	size--;
	ptr=NULL;

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
	

	thisitr=NULL;
	othritr=NULL;
}

Rotor::Rotor(int num)	////the strings are the roginal values of the Enigma Rotors. Using a helper function 
{						////they are turned into numbers for incryption and decryption
	string pln = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string temp;
	for (int i =0; i < 26; i++)
	{
		Node* tempN = new Node;
		tempN->num = i;
		input.add(tempN);
		tempN=NULL;

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
		tempN=NULL;

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