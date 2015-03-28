#include "Enigma.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ltoi(char let) ;
int atoi(char t);
int atoi(string str );

Enigma::Enigma()
{
	makeBankE();
	
}
Enigma::~Enigma()
{
	delete RF;
	RF = NULL;

	Deconhelper(front);

}

void Enigma::Deconhelper(Rotor*R)
{
	if (R->next != NULL)
	{
		Deconhelper(R->next);
	}
	delete R;
	R=NULL;
	size--;
}

void Enigma::makeBankE()
{
	RF = new Reflector();
	size=0;
	string choice;
	int movem;
	cout << "\nLoading Bank Enigma"<<endl;



	cout << "What order do you want the rotors? (Enter 123 in any order) "<<endl;
	cin>>choice;

	for (int i =0; i < choice.size(); i++)
	{
		Rotor * temp = new Rotor(atoi(choice[i]));
		if (size==0) front=back=temp; 
		else
		{
			back->next=temp;
			back->next->prev=back;
			back=back->next;
		}
		temp->print();
		size++;
	}
	cout << endl << "Starting positions? (Enter 0-25 three times) "<<endl;
	int i =0;
	for (Rotor * itr = front; itr!= NULL; itr=itr->next)
	{

		cin >> movem;
		itr->move(movem);
		itr->print();
		i++;
	}

}

void Enigma::ShowRotorValues(int n)
{
	Rotor * itr = front+n-1;
	string trans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string line(4*26+1,'-');
 	cout << line<<endl;
 	cout <<"|";
 	for (int i =0; i < 26; i++)
 	{
 		cout << " " <<trans[i] << " |"<<flush;
 	}
 	cout<< endl<<"|";
 	for (int i =0; i < 26; i++)
 	{
 		cout << " " << trans[(*itr)[i]] << " |"<<flush;
 	}
 	cout<< endl<<line<<endl;
}


void Enigma::encrypt(string text)
{
	string trans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int X;
	string output;
	Rotor* start = front;
	for (int i =0; i < text.size(); i++)
	{
		X = ltoi(text[i]);
		while (start != NULL)
		{
			X = (*start)[X];
			start=start->next;
		}
		X=(*RF)[X];
		start = back;
		while (start != NULL)
		{
			X = (*start)[X];
			start=start->prev;
		}
		output+=trans[X];
	}
	cout<<output<<endl;
	
}

int ltoi(char let) ///This converts letters into their position in the alphabet starting with A=0
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

int atoi(char t)
{
	return t - '0';
}

int atoi(string str)
{
	int i = str.size()-1;
	int sum=0;
	
	int tens =1;
	for (;i>=0; i--)
	{
		sum = atoi(str[i])*tens;
		tens*=10;
	}
	return sum;
}