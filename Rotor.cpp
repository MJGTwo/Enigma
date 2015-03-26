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

Row::Row()
{
	size=0;
	head=NULL;
	tail=NULL;
	partner=NULL;
}


void Row::add(Node* n)
{
	if (size==0)
	{
		head = n;
		tail = n;
		size++;
	}
	else
	{
		tail->next=n;
		head->prev=n;
		tail=n;
		size++;
	}
}

void Row::shift()
{
	partner->tail=partner->head;
	partner->head=partner->head->next;
	link(*partner);
}

void Row::link(Row &othr)
{
	partner=&othr;
	othr.partner=this;
	Node * thisitr=this->head;
	Node * othritr=othr.head;
	if (this->size != othr.size) return;
	thisitr->crypt = othritr;
	othritr->crypt = thisitr;
	thisitr=thisitr->next;
	othritr=othritr->next;
	while (thisitr != this->tail->next)
	{
		thisitr->crypt = othritr;
		othritr->crypt = thisitr;
		thisitr=thisitr->next;
		othritr=othritr->next;
	}
}

Rotor::Rotor(int num)
{
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

int lettoval(char let)
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