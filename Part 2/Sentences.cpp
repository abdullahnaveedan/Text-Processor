#include "Sentences.h"
#include <fstream>

Sentences::Sentences() :Paragraph(){}
Sentences::Sentences(char**** arr, int s1, int s2, int s3, int s4) :Paragraph(arr, s1, s2, s3, s4) {}
ostream& operator<<(ostream& Cout, const Sentences& para)
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
ifstream& operator>>(ifstream& fin, Sentences& para)
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
                    fin.get(para.arr[i][j][k][l]);
                }
            }
        }
    }

    return fin;
}
int Sentences::Count_Sentences()
{
    int count = 0;
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (this->arr[i][j][k][l] == '.') {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
void Sentences::Display()
{
	Paragraph::Display();
    cout << "Number of Sentences: " << Count_Sentences() << endl;
}
