#ifndef __ROTOR_H__
#define __ROTOR_H__


class Node{

public:
	Node();

	int num;

	Node* prev;
	Node* next;
	Node* crypt;




};

class Row{
public:
	Row();

	void shift();
	void add(Node *n);
	void link(Row &othr);


	Node* head;
	Node* tail;
	Row* partner;
	int size;
};



class Rotor{

public:

	Rotor(int n);
	char  operator[] ( char alph);

private:
	Row input;
	Row output;

};



#endif