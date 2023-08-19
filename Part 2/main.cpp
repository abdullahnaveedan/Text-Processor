#include <iostream>
#include "Paragraph.h"
#include "Sentences.h"
#include "Words.h"
#include "Characters.h"
#include <fstream>
using namespace std;
int main()
{
	ifstream fin;
	ofstream fout;
	Paragraph obj;
	Sentences obj1;
	Words obj2;
	Characters obj3;
	Paragraph(); 

	int spaces=0;
	int dots=0;
	char ch;
	fin.open("para.txt");
	while (fin.get(ch))
	{
		if (ch == ' ') 
		{
			spaces++;
		}
		if (ch == '.')
		{
			dots++;
		}
	}

	obj.Set_S1(1);
	obj.Set_S2(spaces + 1);
	obj.Set_S3(dots);
	obj.Set_S4(15);
	fin.close();

	obj1.Set_S1(1);
	obj1.Set_S2(spaces + 1);
	obj1.Set_S3(dots);
	obj1.Set_S4(15);

	obj2.Set_S1(1);
	obj2.Set_S2(spaces + 1);
	obj2.Set_S3(dots);
	obj2.Set_S4(15);

	obj3.Set_S1(1);
	obj3.Set_S2(spaces + 1);
	obj3.Set_S3(dots);
	obj3.Set_S4(15);
	/*fout.open("dummy.txt");
	fout << obj;
	fout.close();*/

	fin.open("para.txt");
	fin >> obj;
	fin.close();

	fin.open("para.txt");
	fin >> obj1;
	fin.close();

	fin.open("para.txt");
	fin >> obj2;
	fin.close();

	fin.open("para.txt");
	fin >> obj3;
	fin.close();

	cout << "Paragraph: " << endl;
	cout << obj1;
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

	+ obj;
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

	- obj;
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
	obj.Display();
	cout << endl;
	obj1.Display();
	cout << endl;
	obj2.Display();
	cout << endl;
	obj3.Display();
	cout << endl;

	cout << "Writing File: " << endl;
	fout.open("Freq.txt");
	fout << obj3;
	cout << ". . . . . " << endl;
	fout.close();
	cout << "File Writed Successfully!" << endl;
	cout << endl;

	if (obj.Check_Encrypt_Dycrypt()) {
		cout << "Data Is Decrypted." << endl;
	}
	else {
		cout << "Data Is Eccrypted." << endl;
	}

	cout << endl;
	obj % (4);
	cout << "Data After Encryption: " << endl;
	cout << obj;
	cout << endl;

	cout << endl;
	obj* (4);
	cout << "Data After Decryption: " << endl;
	cout << obj;
	cout << endl;

	system("pause");
	return 0;
}