#include "Enigma.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ltoi(char let) ;
int atoi(char t);
int atoi(string str );

Counter::Counter(int i)
{
	for (int n =0; n < i; n++) counts.push_back(0);
}

vector<int> Counter::move()
{
	vector<int> result;
	int carry = 1;
	for (int i =0; i < counts.size(); i++)
	{
		counts[i]+=carry;
		result.push_back(1);
		if(counts[i] <= 25)
		{
			break;
		}
		
	}
	return result;
}


Enigma::Enigma()
{
	RF = new Reflector();
	size=0;
	c=NULL;
	front =back=NULL;

	int input=0;
	while (input ==0)
	{
		cout << "Please Select type of Enigma\n\n";
		cout << "-1) Quit\n";
		cout << " 1) Bank Enigma (3 Rotors, Pick 3)\n";
		cout << " 2) Army Enigma (5 Rotors, Pick 3)\n";
		cout << " 3) Naval Enigma (8 Rotors, Pick 3)\n";
		cout << " 4) Advanced Naval Enigma (8 Rotors, Pick 4)\n";
		cin >> input;
		if 	    (input ==-1) cout << "Quiting...\n";
		else if (input == 1) makeBankE();
		else if (input == 2) makeArmyE();
		else if (input == 3) makeNavalE();
		else if (input == 4) makeANavalE();
		else 
		{
			cout << "Invalid input\n";
			input=0;
		}
	}
	input == -1? made = false: made = true;
}
Enigma::~Enigma()
{
	delete RF;
	RF = NULL;
	delete c;
	if (front != NULL)
	{
		Deconhelper(front);
	}
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
	c = new Counter(3);
	basic(1);
}

void Enigma::makeArmyE()
{
	c = new Counter(3);
	basic(2);
}

void Enigma::makeNavalE()
{
	c = new Counter(3);
	basic(3);
}

void Enigma::makeANavalE()
{
	c = new Counter(4);
	basic(4);
}


void Enigma::basic(int n)
{
	int i;
	string choice;
	int movem;
	n != 4? i = 3 : i = 4;
	if (n==1)
	{
		cout << "\nLoading Bank Enigma"<<endl;
		cout << "Choose 3 different Rotors in desired order of usage? (Options: 1-3)"<<endl;
	}
	else if (n==2)
	{
		cout << "\nLoading Army Enigma"<<endl;
		cout << "Choose 3 different Rotors in desired order of usage? (Options: 1-5)"<<endl;		
	}
	else if (n==3)
	{
		cout << "\nLoading Naval Enigma"<<endl;
		cout << "Choose 3 different Rotors in desired order of usage? (Options: 1-8)"<<endl;			
	}
	else if (n==4)
	{
		cout << "\nLoading Advanced Naval Enigma"<<endl;
		cout << "Choose 4 different Rotors in desired order of usage? (Options: 1-8)"<<endl;			
	}
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
	cout << endl << "Starting positions? (Enter 0-25 ";
	n!=4? cout << "three": cout << "four";
	cout << " times)" <<endl;
	
	for (Rotor * itr = front; itr!= NULL; itr=itr->next)
	{
		cin >> movem;
		itr->shift(movem);
		itr->print();
	}
}
string Enigma::decrypt(string text)
{


	string trans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int X;
	string output;
	vector<int> movement;
	for (int i =0; i < text.size(); i++)
	{
		if (text[i] == ' ')output+=text[i];
		else
		{
			Rotor* start = front;
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
				X = (*start)(X);
				start=start->prev;
			}
			output+=trans[X];

			movement = c->move();
			start = front;
			for (int j =0; j < movement.size(); j++)
			{
				start->shift(); 
				start=start->next;
			}
		}

	}
	cout<<"DECRYPTED: "<<output<<endl;
	return output;
	
}

string Enigma::encrypt()
{
	int length =0;
	string input;
	string temp;
	cout << "How many words are in your phrase?\n";
	cin >> length;
	cout << "Enter a phrase to be encrypted: \n";
	int i=0;
	while (i < length)
	{
		cin >> temp;
		input+= (temp + ' ');
		i++;
	}
	cout << "You entered: "<<input << endl;



	string trans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int X;
	string output;
	vector<int> movement;
	for (int i =0; i < input.size(); i++)
	{
		if (input[i] == ' ')output+=input[i];
		else
		{
			Rotor* start = front;
			X = ltoi(input[i]);
			while (start != NULL)
			{
				X = (*start)[X];
				start=start->next;
			}
			X=(*RF)[X];
			start = back;
			while (start != NULL)
			{
				X = (*start)(X);
				start=start->prev;
			}
			output+=trans[X];

			movement = c->move();
			start = front;
			for (int j =0; j < movement.size(); j++)
			{
				start->shift(); 
				start=start->next;
			}
		}

	}
	cout<<"ENCRYPTED: "<<output<<endl;
	return output;
	
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