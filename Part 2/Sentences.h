#pragma once
#include "Paragraph.h"
class Sentences:public Paragraph
{
public:
	Sentences();
	Sentences(char****, int, int, int, int);
	friend ifstream& operator>>(ifstream&, Sentences&);
	friend ostream& operator<<(ostream&, const Sentences&);
	int Count_Sentences();
	void Display();
};

