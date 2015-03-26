#include "Rotor.h"
#include <utility>
#include <string>
#include <iostream>
using namespace std;



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
	int temp[26];
	for (int i =0; i < 26; i++)
	{
		Node* tempN = new Node;
		tempN->num = i;
		input.add(tempN);

	}
	

	if (num ==1)
	{
		temp = "E K  M F  L G D Q  V  Z  N  T  O  W  Y  H  X  U  S  P  A I B R  CJ";
				[4,10,12,5,11,6,3,16,21,25,13,19,14,22,24,7,23,20,18,15,0,8,1,17,2,9];
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

int Rotor::operator[]( int numb) 
{
	
	Node* finder = input.head;
	while (finder->num != numb)
	{
		finder= finder->next;
	}
	string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i =0;
	while ( finder->crypt->let != alph[i]) i++;
	return i;
}
