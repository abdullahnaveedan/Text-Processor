#include <iostream>
using namespace std;
#pragma once
class Paragraph
{
private:
	char**** arr;
	int s1;
	int s2;
	int s3;
	int s4;
public:
	friend ostream& operator<<(ostream&, const Paragraph&);
	friend ifstream& operator>>(ifstream&, Paragraph&);
	friend ofstream& operator<<(ofstream&, Paragraph&);
	Paragraph();
	Paragraph(char****, int, int, int, int);
	Paragraph(Paragraph&);
	bool operator==(Paragraph&);
	bool operator!=(Paragraph&);
	Paragraph& operator=(Paragraph&);
	bool Case_Check();
	void operator+();
	void operator-();
	int Count_English_Char();
	int Count_Punctuation_Char();
	int Count_Sentences();
	int Count_Total_Words();
	void Count_Words_Sen();
	void Count_Word_Char();
	
	void Set_S1(int s);
	void Set_S2(int s);
	void Set_S3(int s);
	void Set_S4(int s);
	int Get_S1();
	int Get_S2();
	int Get_S3();
	int Get_S4();

};

