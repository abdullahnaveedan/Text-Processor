#include "Words.h"
#include <fstream>

Words::Words():Sentences(){}
Words::Words(char**** arr, int s1, int s2, int s3, int s4):Sentences(arr,s1,s2,s3,s4){}
ostream& operator<<(ostream& Cout, const Words& para)
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
ifstream& operator>>(ifstream& fin, Words& para)
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
int Words::Count_Total_Words()
{
    int count = 0;
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (this->arr[i][j][k][l] == ' ') {
                        count++;
                    }
                }
            }
        }
    }
    count = count + 1;
    return count;
}
void Words::Count_Words_Sen()
{
    int num = 0;
    int extra = 0;
    int count = 1;
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (this->arr[i][j][k][l] != '.' && this->arr[i][j][k][l] == ' ') {
                        count++;
                    }
                    if (this->arr[i][j][k][l] == '.') {
                        num++;
                        cout << "Total Words in Sentence " << num << ": " << count - extra << endl;
                        extra = count;
                    }
                }
            }
        }
    }
}
void Words::Display()
{
    Sentences::Display();
    cout << "Total Words: " << Count_Total_Words() << endl;
    Count_Words_Sen();
}
