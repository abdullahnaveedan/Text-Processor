#include <iostream>
#include "Paragraph.h"
#include <fstream>
using namespace std;
int main()
{
	ifstream fin;
	ofstream fout;
	Paragraph obj,obj1;
	Paragraph(); //default.

	int spaces=0;
	int dots=0;
	char ch;
	fin.open("para.txt");
	while (fin.get(ch)) {
		if (ch == ' ') {
			spaces++;
		}
		if (ch == '.') {
			dots++;
		}
		}

	obj.Set_S1(1);
	obj.Set_S2(spaces + 1);
	obj.Set_S3(dots);
	obj.Set_S4(15);
	fin.close();

	/*fout.open("dummy.txt");
	fout << obj;
	fout.close();*/

	fin.open("para.txt");
	fin >> obj;
	fin.close();

	cout << "Paragraph: " << endl;
	cout << obj;
	cout << endl;

	cout << endl;
	cout << "Copy Constructor Called. " << endl;
	Paragraph obj3(obj);
	cout << obj3;
	cout << endl;

	cout << endl;
	if (obj == obj1) {
		cout << "Both Objects Are Equal." << endl;
	}
	else {
		cout << "Both Objects Are Not Equal." << endl;
	}
	cout << endl;

	if (obj.Case_Check()) {
		cout << "The Paragraph Is in Upper Case: " << endl;
		cout << obj;
		cout << endl;
	}
	else {
		cout << "Paragraph Is in Lower Case: " << endl;
		cout << obj;
		cout << endl;
	}

	+obj;
	cout << endl;
	if (obj.Case_Check()) {
		cout << "The Paragraph Is in Upper Case: " << endl;
		cout << obj;
		cout << endl;
	}
	else {
		cout << "Paragraph Is in Lower Case: " << endl;
		cout << obj;
		cout << endl;
	}

	-obj;
	cout << endl;
	if (obj.Case_Check()) {
		cout << "The Paragraph Is in Upper Case: " << endl;
		cout << obj;
		cout << endl;

	}
	else {
		cout << "Paragraph Is in Lower Case: " << endl;
		cout << obj;
		cout << endl;
	}

	cout << endl;
	cout << "Total English characters Are: " << obj.Count_English_Char() << endl;
	cout << "Total Punctuation characters Are: " << obj.Count_Punctuation_Char() << endl;
	cout << endl;

	cout << "Total Number Of Sentences In Paragraph: " <<obj.Count_Sentences()<< endl;
	cout << endl;
	
	cout << "Assignment Operator Called: " << endl;
	Paragraph obj2;
	obj2.Set_S1(1);
	obj2.Set_S2(spaces + 1);
	obj2.Set_S3(dots);
	obj2.Set_S4(15);
	obj2 = obj;
	cout << obj2;
	cout << endl;

	cout << endl;
	cout << "Total Words: " <<obj.Count_Total_Words()<< endl;
	cout << endl;

	obj.Count_Words_Sen();
	cout << endl;

	obj.Count_Word_Char();
	cout << endl;

	
	fout.open("frequency.txt");
	fout << obj;
	fout.close();
		return 0;
}