#include "Rotor.h"
#include <utility>
#include <string>
#include <iostream>
using namespace std;

Node::Node(char L):  let(L)
{
	prev=NULL;
	next=NULL;
	crypt=NULL;
}

Node::Node()
{
	let='0';
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
	for (int i =0; i < pln.size(); i++)
	{
		Node* tempN = new Node;
		tempN->let = pln[i];
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
		tempN->let = temp[i];
		output.add(tempN);

	}

	input.link(output);

	
}

char Rotor::operator[]( char alph) 
{
	
	Node* finder = input.head;
	while (finder->let != alph)
	{
		finder= finder->next;
	}
	return finder->crypt->let;
}