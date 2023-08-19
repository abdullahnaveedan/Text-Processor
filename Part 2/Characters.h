#pragma once
#include "Words.h"
class Characters:public Words
{
public:
	Characters();
	Characters(char****, int, int, int, int);
	friend ifstream& operator>>(ifstream&, Characters&);
	friend ostream& operator<<(ostream&, const Characters&);
	friend ofstream& operator<<(ofstream&, Characters&);
	void Count_Word_Char();
	void Display();
};

