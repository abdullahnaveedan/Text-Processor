#include <iostream>
using namespace std;
#pragma once
class Paragraph
{
public:
	char**** arr;
	int s1;
	int s2;
	int s3;
	int s4;
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
	bool Check_Encrypt_Dycrypt();
	void operator%(int);
	void operator*(int);
	void Set_S1(int s);
	void Set_S2(int s);
	void Set_S3(int s);
	void Set_S4(int s);
	int Get_S1();
	int Get_S2();
	int Get_S3();
	int Get_S4();
	void Display();
};

