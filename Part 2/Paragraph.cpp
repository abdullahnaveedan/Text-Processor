#include "Paragraph.h"
#include <fstream>
#include <iostream>
using namespace std;

ofstream& operator<<(ofstream& Fout, Paragraph& obj)
{
    /*Fout << "Number Of Paragraphs: " << obj.Get_S1() << endl;*/
    //Fout << "Total Sentences: " << obj.Count_Sentences() << endl;
    /*Fout << "Total Words: " << obj.Count_Total_Words() << endl;*/
    int word = 0;
    int extra = 0;
    int num = 1;
    int count = 0;
    for (int i = 0; i < obj.s1; i++) {
        for (int j = 0; j < obj.s2; j++) {
            for (int k = 0; k < obj.s3; k++) {
                for (int l = 0; l < obj.s4; l++) {
                    if (obj.arr[i][j][k][l] != '.' && obj.arr[i][j][k][l] != ' ') {
                        count++;
                    }
                    if (obj.arr[i][j][k][l] == '.') {
                        num++;
                        word = 0;
                    }
                    if (obj.arr[i][j][k][l] == ' ') {
                        word++;
                        Fout << "Total Characters in Word " << word << " in Sentence " << num << ": " << count - extra << endl;
                        extra = count;
                    }
                }
            }
        }
    }

    return Fout;
}
ostream& operator<<(ostream& Cout, const Paragraph& para)
{
    for (int i = 0; i < para.s1; i++) {
        for (int j = 0; j < para.s2; j++) {
            for (int k = 0; k < para.s3; k++) {
                for (int l = 0; l < para.s4; l++) {
                    Cout << para.arr[i][j][k][l];
                }
            }
        }
    }
    return Cout;
}
ifstream& operator>>(ifstream& fin, Paragraph& para)
{

    para.arr = nullptr;
    para.arr = new char*** [para.s1];
    for (int i = 0; i < para.s1; i++)
    {
        para.arr[i] = new char** [para.s2];
        for (int j = 0; j < para.s2; j++)
        {
            para.arr[i][j] = new char* [para.s3];
            for (int k = 0; k < para.s3; k++) {
                para.arr[i][j][k] = new char[para.s4];
            }
        }
    }
    for (int i = 0; i < para.s1; i++) {
        for (int j = 0; j < para.s2; j++) {
            for (int k = 0; k < para.s3; k++) {
                for (int l = 0; l < para.s4; l++) {
                    para.arr[i][j][k][l] = { '\0' };
                }
            }
        }
    }

    for (int i = 0; i < para.s1; i++) {
        for (int j = 0; j < para.s2; j++) {
            for (int k = 0; k < para.s3; k++) {
                for (int l = 0; l < para.s4; l++) {
                    fin.get( para.arr[i][j][k][l]);
                }
            }
        }
    }

	return fin;
}
Paragraph::Paragraph()
{
    arr = nullptr;
    s1 = 1;
    s2 = 100;
    s3 = 100; 
    s4 = 100;
}
Paragraph::Paragraph(char**** ptr, int s, int ss, int sss, int ssss)
{
    this->arr = new char*** [s1];
    for (int i = 0; i < s1; i++)
    {
        this->arr[i] = new char** [s2];
        for (int j = 0; j < s2; j++)
        {
            this->arr[i][j] = new char* [s3];
            for (int k = 0; k < s3; k++)
                this->arr[i][j][k] = new char[s4];
        }
    }
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            for (int k = 0; k < s3; k++) {
                for (int l = 0; l < s4; l++) {
                    this->arr[i][j][k][l] = ptr[i][j][k][l];
                }
            }
        }
    }
    s1 = s;
    s2 = ss;
    s3 = sss;
    s4 = ssss;
}
Paragraph::Paragraph(Paragraph& para)
{
    s1 = para.s1;
    s2 = para.s2;
    s3 = para.s3;
    s4 = para.s4;

    this->arr = new char*** [s1];
    for (int i = 0; i < s1; i++)
    {
        this->arr[i] = new char** [s2];
        for (int j = 0; j < s2; j++)
        {
            this->arr[i][j] = new char* [s3];
            for (int k = 0; k < s3; k++)
                this->arr[i][j][k] = new char[s4];
        }
    }
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            for (int k = 0; k < s3; k++) {
                for (int l = 0; l < s4; l++) {
                    this->arr[i][j][k][l] = para.arr[i][j][k][l];
                }
            }
        }
    }
}
bool Paragraph::operator==(Paragraph& ref)
{
    if (s1 == ref.s1 || s2 == ref.s2 || s3 == ref.s3 || s4 == ref.s4) {
        return true;
    }
    else {
        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                for (int k = 0; k < s3; k++) {
                    for (int l = 0; l < s4; l++) {
                        if (arr[i][j][k][l] != ref.arr[i][j][k][l]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
}
bool Paragraph::operator!=(Paragraph& ref)
{
    if (s1 != ref.s1 || s2 != ref.s2 || s3 != ref.s3 || s4 != ref.s4) {
        return true;
    }
    else {
        for (int i = 0; i < s1; i++) {
            for (int j = 0; j < s2; j++) {
                for (int k = 0; k < s3; k++) {
                    for (int l = 0; l < s4; l++) {
                        if (arr[i][j][k][l] != ref.arr[i][j][k][l]) {
                            return true;
                        }
                    }
                }
            }
        }
        return true;
    }
}
Paragraph& Paragraph::operator=(Paragraph& para)
{
    if (this != &para)
    {
        if (arr)
        {
            delete[]arr;
            arr = nullptr;
        }

        this->arr = new char*** [para.s1];
        for (int i = 0; i < para.s1; i++)
        {
            this->arr[i] = new char** [para.s2];
            for (int j = 0; j < para.s2; j++)
            {
                this->arr[i][j] = new char* [para.s3];
                for (int k = 0; k < para.s3; k++)
                    this->arr[i][j][k] = new char[para.s4];
            }
        }
        for (int i = 0; i < para.s1; i++) {
            for (int j = 0; j < para.s2; j++) {
                for (int k = 0; k < para.s3; k++) {
                    for (int l = 0; l < para.s4; l++) {
                        this->arr[i][j][k][l] = para.arr[i][j][k][l];
                    }
               }
            }
        }
    }
    return *this;
}
bool Paragraph::Case_Check()
{
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            for (int k = 0; k < s3; k++) {
                for (int l = 0; l < s4; l++) {
                    if (arr[i][j][k][l]>='A' && arr[i][j][k][l]<='Z') {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }
}
void Paragraph::operator+()
{
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (this->arr[i][j][k][l]>=97 && this->arr[i][j][k][l]<=122) {
                        this->arr[i][j][k][l] -= 32;
                    }
                }
            }
        }
    }
}
void Paragraph::operator-()
{
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (this->arr[i][j][k][l] >= 65 && this->arr[i][j][k][l] <= 90) {
                        this->arr[i][j][k][l] += 32;
                    }
                }
            }
        }
    }
}
int Paragraph::Count_English_Char()
{
    int count = 0;
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (this->arr[i][j][k][l] >= 65 && this->arr[i][j][k][l] <= 90 || arr[i][j][k][l] >= 97 && this->arr[i][j][k][l] <= 122) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
int Paragraph::Count_Punctuation_Char()
{
    int count = 0;
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (this->arr[i][j][k][l] >= 33 && this->arr[i][j][k][l] <= 47 || this->arr[i][j][k][l] >= 58 && this->arr[i][j][k][l] <= 64) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
bool Paragraph::Check_Encrypt_Dycrypt()
{
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (arr[i][j][k][l] >= 'a' && arr[i][j][k][l] <= 'z' || arr[i][j][k][l] >= 'A' && arr[i][j][k][l] <= 'Z' && arr[i][j][k][l] == 46) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }
}
void Paragraph::operator%(int key)
{
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    this->arr[i][j][k][l] += key;
                }
            }
        }
    }
}
void Paragraph::operator*(int key)
{
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    this->arr[i][j][k][l] -= key;
                }
            }
        }
    }
}
void Paragraph::Set_S1(int s)
{
    s1 = s;
}
void Paragraph::Set_S2(int s)
{
    s2 = s;
}
void Paragraph::Set_S3(int s)
{
    s3 = s;
}
void Paragraph::Set_S4(int s)
{
    s4 = s;
}
int Paragraph::Get_S1()
{
    return s1;
}
int Paragraph::Get_S2()
{
    return s2;
}
int Paragraph::Get_S3()
{
    return s3;
}
int Paragraph::Get_S4()
{
    return s4;
}
void Paragraph::Display()
{
    cout << "Total English characters Are: " << Count_English_Char() << endl;
    cout << "Total Punctuation characters Are: " << Count_Punctuation_Char() << endl;
    cout << "Number Of Paragraphs: " << s1 << endl;
}