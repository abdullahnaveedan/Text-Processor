#pragma once
#include "Sentences.h"
#include "Words.h"
class Words:public Sentences
{
public:
	Words();
	Words(char****, int, int, int, int);
	friend ifstream& operator>>(ifstream&, Words&);
	friend ostream& operator<<(ostream&, const Words&);
	int Count_Total_Words();
	void Count_Words_Sen();
	void Display();
};

