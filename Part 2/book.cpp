
# include <iostream>
# include <fstream>
using namespace std;









						/***** PARENT PARAGRAPH CLASS  *****/











class Paragraph
{

private:
	char**** arr;
	int s1;
	int s2;
	int s3;
	int s4;
public:
	Paragraph()
	{
		arr = nullptr;
		s1 = 0;
		s2 = 0;
		s3 = 0;
		s4 = 0;
	}
	Paragraph(char****ptr, int p1, int p2, int p3, int p4)
	{
		arr = ptr;
		s1 = p1;
		s2 = p2;
		s3 = p3;
		s4 = p4;
	}
	Paragraph(Paragraph&obj)
	{
		arr = obj.arr;
		s1 = obj.s1;
		s2 = obj.s2;
		s3 = obj.s3;
		s4 = obj.s4;
	}
	bool operator==(Paragraph&obj)
	{
		for (int i = 0; i < obj.s1; i++)
		{
			for (int j = 0; j <obj.s2; j++)
			{
				for (int k = 0; i < obj.s3; k++)
				{
					for (int l = 0; i <obj.s4; l++)
					{
						if (arr[i][j][k][l] != obj.arr[i][j][k][l])
						{
							return false;
						}
					}

				}
			}
		}

		if (s1 == obj.s1)
		{
			if (s2 == obj.s1)
			{
				if (s3 == obj.s3)
				{
					if (s4 != obj.s4)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	bool operator!=(Paragraph&obj)
	{
		for (int i = 0; i < obj.s1; i++)
		{
			for (int j = 0; j <obj.s2; j++)
			{
				for (int k = 0; i < obj.s3; k++)
				{
					for (int l = 0; i <obj.s4; l++)
					{
						if (arr[i][j][k][l] == obj.arr[i][j][k][l])
						{
							return false;
						}
					}

				}
			}
		}

		if (s1 != obj.s1)
		{
			if (s2 != obj.s1)
			{
				if (s3 != obj.s3)
				{
					if (s4 == obj.s4)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	Paragraph& operator=(Paragraph&obj)
	{
		for (int i = 0; i < obj.s1; i++)
		{
			for (int j = 0; j <obj.s2; j++)
			{
				for (int k = 0; i < obj.s3; k++)
				{
					for (int l = 0; i <obj.s4; l++)
					{
						this->arr[i][j][k][l] = obj.arr[i][j][k][l];
					}

				}
			}
		}
		return *this;
	}
	void operator+()
	{
		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j <s2; j++)
			{
				for (int k = 0; i < s3; k++)
				{
					for (int l = 0; i <s4; l++)
					{
						if (arr[i][j][k][l] >= 'a'&&arr[i][j][k][l] <= 'z')
						{
							arr[i][j][k][l] = arr[i][j][k][l] - 32;
						}
					}

				}
			}
		}

	}
	void operator-()
	{
		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j < s2; j++)
			{
				for (int k = 0; i < s3; k++)
				{
					for (int l = 0; i < s4; l++)
					{
						if (arr[i][j][k][l] >= 'A'&&arr[i][j][k][l] <= 'Z')
						{
							arr[i][j][k][l] = arr[i][j][k][l] + 32;
						}
					}

				}
			}
		}
	}
	int countAlphabets()
	{
		int count = 0;
		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j < s2; j++)
			{
				for (int k = 0; i < s3; k++)
				{
					for (int l = 0; i < s4; l++)
					{
						if (this->arr[i][j][k][l] == '$') 
						{

							count++;
						}
					}

				}
			}
		}
		return count;
	}
	
	void Set_S1(int s)
	{
		s1 = s;
	}
	void Set_S2(int s)
	{
		s2 = s;
	}
	void Set_S3(int s)
	{
		s3 = s;
	}
	void Set_S4(int s)
	{
		s4 = s;
	}
	int Get_S1()
	{
		return s1;
	}
	int Get_S2()
	{
		return s2;
	}
	int Get_S3()
	{
		return s3;
	}
	int Get_S4()
	{
		return s4;
	}
	void Display()
	{
		
		cout << "ParaGraph : " << countAlphabets() << endl;
	}
	friend ifstream& operator>>(ifstream&fin, Paragraph&p)
	{
		for (int i = 0; i < p.s1; i++)
		{
			for (int j = 0; j < p.s2; j++)
			{
				for (int k = 0; i < p.s3; k++)
				{
					for (int l = 0; i < p.s4; l++)
					{
						fin.get(p.arr[i][j][k][l]);
					}
				}
			}
		}
		return fin;
	}
	friend ofstream& operator<<(ofstream&Fout, Paragraph&p)
	{
		for (int i = 0; i < p.s1; i++)
		{
			for (int j = 0; j < p.s2; j++)
			{
				for (int k = 0; i < p.s3; k++)
				{
					for (int l = 0; i < p.s4; l++)
					{
						Fout <<  p.arr[i][j][k][l];
					}

				}
			}
		}
		return Fout;
	}
	friend ostream & operator << (ostream& Cout, const Paragraph& para)
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
};












						/***** CHILD CLASSES******/








class Sentences :public Paragraph
{
private:
	char****arr;
	int s1;
	int s2;
	int s3; 
	int s4;
public:
	Sentences() :Paragraph()
	{
		s1 = Get_S1();
		s2 = Get_S2();
		s3 = Get_S3();
		s4 = Get_S4();
	}
	Sentences(char**** arr, int s1, int s2, int s3, int s4) :Paragraph(arr, s1, s2, s3, s4) 
	{
		//code
	}
	
	int countSen()
	{
		int count = 0;
		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j < s2; j++)
			{
				for (int k = 0; k < s3; k++)
				{
					for (int l = 0; l < s4; l++)
					{
						if (this->arr[i][j][k][l] == '.') 
						{
							count++;
						}
					}
				}
			}
		}
		return count;
	}
	void Display()
	{
		cout << "Sentence is : " << countSen() << ".\n";
	}
	friend ostream& operator<<(ostream& output, const Sentences& sen)
	{
		for (int i = 0; i < sen.s1; i++) 
		{
			for (int j = 0; j < sen.s2; j++) 
			{
				for (int k = 0; k < sen.s3; k++) 
				{
					for (int l = 0; l < sen.s4; l++) 
					{
						output << sen.arr[i][j][k][l];
					}
				}
			}
		}
		return output;
	}
	friend ifstream& operator>>(ifstream& input, Sentences& sen)
	{
		for (int i = 0; i < sen.s1; i++)
		{
			for (int j = 0; j < sen.s2; j++)
			{
				for (int k = 0; k < sen.s3; k++)
				{
					for (int l = 0; l < sen.s4; l++)
					{
						input.get(sen.arr[i][j][k][l]);
					}
				}
			}
		}

		return input;
	}
};









				/******NEXT CHAILD ******/










class Words :public Sentences
{
private:
	char****arr;
	int s1;
	int s2;
	int s3;
	int s4;
public:
	Words() :Sentences()
	{
		s1 = Get_S1();
		s2 = Get_S2();
		s3 = Get_S3();
		s4 = Get_S4();
	}
	Words::Words(char**** arr, int s1, int s2, int s3, int s4) :Sentences(arr, s1, s2, s3, s4)
	{
		//code
	}

	int countW()
	{
		int count = 0;
		for (int i = 0; i < this->s1; i++) 
		{
			for (int j = 0; j < this->s2; j++) 
			{
				for (int k = 0; k < this->s3; k++)
				{
					for (int l = 0; l < this->s4; l++)
					{
						if (this->arr[i][j][k][l] == ' ')
						{
							count++;
						}
					}
				}
			}
		}
		return count;
	}
	
	void Display()
	{
		Sentences::Display();
		cout << "Words are : " << countW() << ".\n";
	}


	friend ifstream& operator>>(ifstream&fin, Words&p)
	{
		for (int i = 0; i < p.s1; i++)
		{
			for (int j = 0; j < p.s2; j++)
			{
				for (int k = 0; i < p.s3; k++)
				{
					for (int l = 0; i < p.s4; l++)
					{
						fin.get(p.arr[i][j][k][l]);
					}

				}
			}
		}
		return fin;
	}
	friend ostream& operator<<(ostream&output, const Words&sen)
	{
		for (int i = 0; i < sen.s1; i++) 
		{
			for (int j = 0; j < sen.s2; j++) 
			{
				for (int k = 0; k < sen.s3; k++) 
				{
					for (int l = 0; l < sen.s4; l++) 
					{
						output << sen.arr[i][j][k][l];
					}
				}
			}
		}
		return output;
	}
	
};







				/***** CHILD CLASS ******/






class Characters :public Words
{
private:
	char****arr;
	int s1;
	int s2;
	int s3;
	int s4;
public:
	Characters() :Words()
	{
		s1 = Get_S1();
		s2 = Get_S2();
		s3 = Get_S3();
		s4 = Get_S4();
	}
	Characters(char****arr, int s1, int s2, int s3, int s4) : Words(arr, s1, s2, s3, s4)
	{
		//Codes
	}
	friend ifstream& operator>>(ifstream&fin, Characters&chr)
	{
		for (int i = 0; i < chr.s1; i++) 
		{
			for (int j = 0; j < chr.s2; j++) 
			{
				for (int k = 0; k < chr.s3; k++)
				{
					for (int l = 0; l < chr.s4; l++)
					{
						fin.get(chr.arr[i][j][k][l]);
					}
				}
			}
		}
		return fin;
	}
	friend ostream& operator<<(ostream&output, const Characters&chr)
	{
		for (int i = 0; i < chr.s1; i++) 
		{
			for (int j = 0; j < chr.s2; j++) 
			{
				for (int k = 0; k < chr.s3; k++)
				{
					for (int l = 0; l < chr.s4; l++)
					{
						output << chr.arr[i][j][k][l];
					}
				}
			}
		}
		return output;
	}
	void Count()
	{
		int word = 0;
		int extra = 0;
		int num = 1;
		int count = 0;
		for (int i = 0; i < this->s1; i++) 
		{
			for (int j = 0; j < this->s2; j++) 
			{
				for (int k = 0; k < this->s3; k++) 
				{
					for (int l = 0; l < this->s4; l++)
					{
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
	void Display()
	{
		Words::Display();
		Count();
	}
};







							/***** INT MAIN ****/
int main()
{
	cout << "Int main.\n";
	ifstream fin;
	ofstream file;

	fin.open("data.txt");
	file.open("output.txt");


	Paragraph p1;
	Sentences s1;
	Words w1;
	Characters c1;


	char n = {};
	int d = {}, s = {}, p = {};


	for (int i = 0; fin.get(n); i++)
	{
		if (n == '.')
		{
			d++;
		}
		else if (n = ' ')
		{
			s++;
		}
		else if (n == '$')
		{
			p++;
		}
	}
	fin.close();

	/*Paragraph*/
	fin.open("data.txt");
	p1.Set_S1(1);
	p1.Set_S2(s );
	p1.Set_S3(d);
	p1.Set_S4(15);
	fin >> p1;
	fin.close();
	p1.Display();

	/*Sentence*/
	s1.Set_S1(1);
	s1.Set_S2(s);
	s1.Set_S3(d);
	s1.Set_S4(15);	
	fin.open("data.txt");
	fin >> s1;
	fin.close();
	s1.Display();

	/*Words*/
	w1.Set_S1(1);
	w1.Set_S2(s);
	w1.Set_S3(d);
	w1.Set_S4(15);
	fin.open("data.txt");
	fin >> w1;
	fin.close();
	w1.Display();

	/*Charecter*/
	c1.Set_S1(1);
	c1.Set_S2(s);
	c1.Set_S3(d);
	c1.Set_S4(15);
	fin.open("data.txt");
	fin >> w1;
	fin.close();
	cout << s1;
	s1.Display();



	bool a = 0;
	a = p1 == s1;
	
	a = p1 != s1;
	
	+p1;
	
	-p1;
	

	file << p1;
	file << endl;


	return 0;
}