#ifndef __ROTOR_H__
#define __ROTOR_H__
#include <iostream>
using namespace std;
/*
The Rotor class is made of two subclasses: Node and Row. The Row class is made of a 
bidrectional list of Nodes. The Node class contains the value of the position of where it would
be located on a physical Rotor. It then has pointers to it's neighbors and to the Node that it is 
paired to, much like the wiring of two letters in a physical rotor. The Row has a head and tail 
Node pointer, a Row Pointer and a size variable. The Row pointer is used to aid in the linking
of two Row objects to make the Rotor class. The combination of head and tail ease the shifting
of the Rotor for setup. 

*/

class Node{	////The purpose of the node class is to contain the position value link to other nodes
	friend class Row;	
	friend class Rotor;
	friend class Reflector;
public:
	Node();
	~Node();

private:
	int num;

	Node* prev;
	Node* next;
	Node* crypt;	////Used to link nodes from two different rows in order to incrypt and decrypt data




};

class Row{
	friend class Rotor;
	friend class Reflector;
public:
	Row();
	~Row();
	Row(int i);
	

private:
	
	void add(Node *n);		////Adds a node to the row and creates a bidrectional list
	void link(Row &othr);	////links two rows together
	void deconHelper(Node*ptr); ///helper function to deconstruct

	Node* head;
	Node* tail;
	Row* partner;
	int size;

};



class Rotor{
	friend class Enigma;
public:
	Rotor(){}
	Rotor(int n);
	int  operator[] ( int numb);	

	void shift();
	void shift(int n);

	void move();
	void move(int n);

	void print() const;

private:
	Row input;
	Row output;
	Rotor* next;
	Rotor* prev;

};

class Reflector{

	friend class Enigma;
public:
	Reflector();
	int operator[](int n);

private:

	Row board;


};

#endif