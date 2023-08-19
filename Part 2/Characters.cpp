#include "Characters.h"
#include <fstream>

Characters::Characters():Words() {}
Characters::Characters(char**** arr, int s1, int s2, int s3, int s4) : Words(arr, s1, s2, s3, s4) {}
ostream& operator<<(ostream& Cout, const Characters& para)
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
ifstream& operator>>(ifstream& fin, Characters& para)
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
ofstream& operator<<(ofstream& Fout, Characters& obj)
{
    Fout << "Number Of Paragraphs: " << obj.Get_S1() << endl;
    int sen_count = 0;
    for (int i = 0; i < obj.s1; i++) {
        for (int j = 0; j < obj.s2; j++) {
            for (int k = 0; k < obj.s3; k++) {
                for (int l = 0; l < obj.s4; l++) {
                    if (obj.arr[i][j][k][l] == '.') {
                        sen_count++;
                    }
                }
            }
        }
    }

    Fout << "Total Sentences: " << sen_count << endl;
    int word_count = 0;
    for (int i = 0; i < obj.s1; i++) {
        for (int j = 0; j < obj.s2; j++) {
            for (int k = 0; k < obj.s3; k++) {
                for (int l = 0; l < obj.s4; l++) {
                    if (obj.arr[i][j][k][l] == ' ') {
                        word_count++;
                    }
                }
            }
        }
    }
    word_count = word_count + 1;
    Fout << "Total Words: " << word_count << endl;

    int number = 0;
    int ex = 0;
    int cnt = 1;
    for (int i = 0; i < obj.s1; i++) {
        for (int j = 0; j < obj.s2; j++) {
            for (int k = 0; k < obj.s3; k++) {
                for (int l = 0; l < obj.s4; l++) {
                    if (obj.arr[i][j][k][l] != '.' && obj.arr[i][j][k][l] == ' ') {
                        cnt++;
                    }
                    if (obj.arr[i][j][k][l] == '.') {
                        number++;
                        Fout << "Total Words in Sentence " << number << ": " << cnt - ex << endl;
                        ex = cnt;
                    }
                }
            }
        }
    }

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
void Characters::Count_Word_Char()
{
    int word = 0;
    int extra = 0;
    int num = 1;
    int count = 0;
    for (int i = 0; i < this->s1; i++) {
        for (int j = 0; j < this->s2; j++) {
            for (int k = 0; k < this->s3; k++) {
                for (int l = 0; l < this->s4; l++) {
                    if (this->arr[i][j][k][l] != '.' && this->arr[i][j][k][l] != ' ') {
                        count++;
                    }
                    if (this->arr[i][j][k][l] == '.') {
                        num++;
                        word = 0;
                    }
                    if (this->arr[i][j][k][l] == ' ') {
                        word++;
                        cout << "Total Characters in Word " << word << " in Sentence " << num << ": " << count - extra << endl;
                        extra = count;
                    }
                }
            }
        }
    }
}
void Characters::Display()
{
    Words::Display();
    Count_Word_Char();
}

