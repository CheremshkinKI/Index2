#include "ChekingeWriting.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#define MAX 30
//ExpressionValidate
ChekingeWriting::ChekingeWriting(TStack* a)
{
	int Sizze = a->GiveCount();
	string* masss = new string[Sizze];//для получения стрингов
	string* Mmass = new string[Sizze];//Для вывода чисел
	for (int i = 0; i <Sizze; i++)
	{
		masss[i] = a->Get();
		//a->Print();
	}
	int score = Sizze;
	score--;
	mass = new string[Sizze];
	for (int i = 0; i < Sizze; i++)
	{
		mass[i] = masss[score];
		score--;
	}
	score = 0;
	chek = new TStack(MAX);
	for (int i = 0; i < Sizze; i++)
	{
		Mmass[i] = mass[i];
		chek->Put(mass[i]);
	}
	int* prznaki = new int[Sizze];
	string* scobki = new string[Sizze];
	string* znaki = new string[Sizze];
	string* chisla = new string[Sizze];
	string* perem = new string[Sizze];
	int* IndexSc = new int[Sizze];
	int* Indprobel = new int[Sizze];
	int* Indznaki = new int[Sizze];
	int* Inchisla = new int[Sizze];
	int* flagperem = new int[Sizze];
	
	
	for (int i = 0; i < Sizze; i++)
	{
		if (Mmass[i] == " ")
		{
			Indprobel[i] = 1;
			kolPr++;
		}
		if (Mmass[i] == "(" || Mmass[i] == ")")
		{
			scobki[i] = Mmass[i];
			IndexSc[i] = 1;
			Mmass[i] = " ";
			kolSc++;
		}
		if (Mmass[i] == "+" || Mmass[i] == "-" || Mmass[i] == "*" || Mmass[i] == "/" || Mmass[i] == "=")
		{
			znaki[i] = Mmass[i];
			Indznaki[i] = 1;
			Mmass[i] = " ";
			kolZnak++;
			if (Mmass[i] == "+" || Mmass[i] == "-")
			{
				prznaki[i] = 1;
			}
			if (Mmass[i] == "*" || Mmass[i] == "/")
			{
				prznaki[i] = 2;
			}
		}

	}
	for (int i = 0; i < Sizze; i++)
	{
		if (Mmass[i] == " ")
		{
			continue;
		}
		if (Mmass[i] == " ")
		{
			continue;
		}
		chisla[i] = Mmass[i];
		char* ch = new char[Mmass[i].size() + 1];
		strcpy(ch, Mmass[i].c_str());
		int b = ch[0]-'0';
		if (b != 1 && b != 2 && b != 3 && b != 4 && b != 5 && b != 6 && b != 7 && b != 8 && b != 9&&b!=0)
		{
			cout << "Введите значение для переменной : " << Mmass[i] << endl;
			cin >> perem[i];
			flagperem[i] = 1;
		}
		else
		{
			perem[i] = Mmass[i];
		}
		
		
		Inchisla[i] = 1;
		kolCh++;
	}
	Scobki = new string[Sizze];
	Znaki = new string[Sizze];
	Chisla = new string[Sizze];
	GIndexSc = new int[Sizze];
	GIndprobel = new int[Sizze];
	GIndznaki = new int[Sizze];
	PRznaki = new int[Sizze];
	GIchisla= new int[Sizze];
	Perem = new string[Sizze];
	FlagPerem = new int[Sizze];
	for (int i = 0; i < Sizze; i++)
	{
		 Scobki[i]=scobki[i];
		 Znaki[i]=znaki[i];
		 Chisla[i]=chisla[i];
		 GIndexSc[i]=IndexSc[i];
		 GIndprobel[i]=Indprobel[i];
		 GIndznaki[i]=Indznaki[i];
		 PRznaki[i] = Indznaki[i];
		 GIchisla[i] = Inchisla[i];
		 Perem[i] = perem[i];
		 FlagPerem[i] = flagperem[i];
	}
	SIZE = Sizze;
	delete[]masss;
	delete[] Mmass;
	delete[] scobki;
	delete[] znaki;
	delete[] chisla;
	delete[] IndexSc;
	delete[] Indprobel;
	delete[] Indznaki;
	delete[] Inchisla;
	delete[] prznaki;
	delete[]flagperem;
	delete[]perem;
}

ChekingeWriting::~ChekingeWriting()
{
	delete[] postf;
	delete[]chek;
	SIZE=0;
	delete[]mass;
	delete[]Scobki;
	delete[]Znaki;
	delete[]Chisla;
	Vvod = false;
	delete[]GIndexSc;
	delete[]GIndprobel;
	delete[]GIndznaki;
	delete[]PRznaki;
	delete[]GIchisla;
	kolSc=0;
	kolPr=0;
	kolZnak=0;
	kolCh=0;
	Top = 0;
	delete[]data;
	delete[]postfixx;
}

void ChekingeWriting::Check()
{
	ofstream file2; 
	file2.open("C:\\Users\\kirill\\source\\repos\\Lab4.1(sem 3)\\test2.txt",std::ios::app);
	if (!file2)
	{
		cout << "Файл для записи не открылся" << endl;
		return;
	}
	int Size = SIZE;
	cout << "Происходит проверка" << endl;
	if (kolSc % 2 != 0)
	{
		string kal;
		for (int i = 0; i < Size; i++)
		{
			kal += mass[i];
		}
		file2 << "Выражение: " << kal << endl;
		file2 << "Ошибка: " << "Не хватает скобок"<<endl;
		file2 << "Постфиксная форма: нет" << endl;
		file2 << "Результат: невозможно посчитать" << endl;
		cout << "Не хватает скобок" << endl << "Не правильный ввод-> Выход";
		Vvod = false;
		return;
	}
	int leftsc=0, rigthsc=0;
	for (int i = 0; i < Size; i++)
	{
		if (mass[i] == "(")
		{
			leftsc++;
		}
		if (mass[i] == "(")
		{
			rigthsc++;
		}
	}
	if (rigthsc != leftsc)
	{
		string kal;
		for (int i = 0; i < Size; i++)
		{
			kal += mass[i];
		}
		file2 << "Выражение: " << kal << endl;
		file2 << "Ошибка: " << "Количество закрывающихся скобок не равно закрывающимся" << endl;
		file2 << "Постфиксная форма: нет" << endl;
		file2 << "Результат: невозможно посчитать" << endl;
		cout << "Количество закрывающихся скобок не равно закрывающимся" << endl;
		Vvod = false;
		return;
	}
/*	for (int i = 0; i < Size; i++)
	{
		cout << mass[i];
	}*/
	for (int i = 0; i < Size; i++)
	{
		
		if (mass[i] == "+"|| mass[i] == "-"|| mass[i] == "*"|| mass[i] == "/"|| mass[i] == "=")
		{
			if (i == Size - 1)
			{
				string kal;
				for (int j = 0; j < Size;j++)//
				{
					kal += mass[i];
				}
				file2 << "Выражение: " << kal << endl;
				file2 << "Ошибка: " << "Неправильная постановка знака" << endl;
				file2 << "Постфиксная форма: нет" << endl;
				file2 << "Результат: невозможно посчитать" << endl;
				cout << "Пошел нахуй пидор грязный. Неправильная постановка знака" << endl;
				cout << "Ошибка в элементе: " << mass[i];
				Vvod = false;
				return;
			}
			if (mass[i + 1] == ")")
			{
				string kal;
				for (int i = 0; i < Size; i++)
				{
					kal += mass[i];
				}
				file2 << "Выражение: " << kal << endl;
				file2 << "Ошибка: " << " Неправильная постановка скобок,после знака должна идти или <(> или число" << endl;
				file2 << "Постфиксная форма: нет" << endl;
				file2 << "Результат: невозможно посчитать" << endl;
				cout << "Пошел нахуй пидор грязный. Неправильная постановка скобок,после знака должна идти или <(> или число" << endl;
				cout << "Ошибка в элементе: " << mass[i + 1];
				Vvod = false;
				return;
			}
			if (mass[i + 1] == "+"|| mass[i + 1] == "-"|| mass[i + 1] == "*"||mass[i + 1] == "/"|| mass[i + 1] == "=")
			{
				string kal;
				for (int i = 0; i < Size; i++)
				{
					kal += mass[i];
				}
				file2 << "Выражение: " << kal << endl;
				file2 << "Ошибка: " << " Неправильная постановка скобок,после знака должна идти или <(> или число" << endl;
				file2 << "Постфиксная форма: нет" << endl;
				file2 << "Результат: невозможно посчитать" << endl;
				cout << "Пошел нахуй пидор грязный. Неправильная постановка знаков,после знака должна идти или <(> или число" << endl;
				cout << "Ошибка в элементе: " << mass[i + 1];
				Vvod = false;
				return;
			}
		}
		if (mass[i] == ")")
		{
			if (i == Size - 1)
			{
				break;
				
			}
			if (mass[i + 1] == "(")
			{
				string kal;
				for (int i = 0; i < Size; i++)
				{
					kal += mass[i];
				}
				file2 << "Выражение: " << kal << endl;
				file2 << "Ошибка: " << " Неправильная постановка скобок, после скобки должен идти знак" << endl;
				file2 << "Постфиксная форма: нет" << endl;
				file2 << "Результат: невозможно посчитать" << endl;
				cout << "Пошел нахуй пидор грязный. Неправильная постановка скобок, после скобки должен идти знак" << endl;
				cout << "Ошибка в элементе: " << mass[i + 1];
				Vvod = false;
				return;
			}
		}
	}
	string nokal;
	for (int i = 0; i < Size; i++)
	{
		nokal += mass[i];
	}
	file2 << "Выражение: " << nokal << endl;
	file2 << "Ошибка: " << "нет" << endl;
	file2.close();
	Vvod = true;
}

void ChekingeWriting::Print()
{
	Check();
	if (Vvod == false)
	{
		return;
	}
	cout << "Выводится таблица по нахождению всех элментов." << endl;
	int Size=SIZE;
	for (int i = 0; i < Size*4; i++)
	{
		cout << "_";
	}
	cout << endl;
	
	for (int i = 0; i < 10; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout<<"| " <<"Скобка"<< " | " <<"Индекс в выражении"<< " |" << endl;
	for (int i = 0; i < Size; i++)
	{
		if (GIndexSc[i] == 1)
		{
			cout << "| " << Scobki[i] << " | " << i << " |" << endl;
			for (int i = 0; i <10 ; i++)
			{
				cout << "_";
			}
			cout << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout << "| " << "Знак" << " | " << "Индекс в выражении" << " |" << endl;
	for (int i = 0; i < Size; i++)
	{
		if (GIndznaki[i] == 1)
		{
			cout << "| " << Znaki[i] << " | " << i << " |" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << "_";
			}
			cout << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout << "| " << "Элемент выражения" << " | "<< " Значение(если было введенно буквенное) " <<" | " << "Индекс в выражении" << " |" << endl;
	for (int i = 0; i < Size; i++)
	{
		if (GIchisla[i] == 1)
		{
			cout << "| " << Chisla[i] << " | "<<Perem[i]<<" | " << i << " |" << endl;
			if (FlagPerem[i])
			{
				Chisla[i] = Perem[i];
				mass[i] = Perem[i];
			}
			for (int i = 0; i < 10; i++)
			{
				cout << "_";
			}
			cout << endl;

		}
	}
	cout << endl;
	for (int i = 0; i < Size * 3; i++)
	{
		cout << "_";
	}
	cout << endl;
}

void ChekingeWriting::Kalk()
{
	Check();
	if (Vvod == false)
	{
		std::abort;
	}
	int Size = SIZE;
	int sumka1=0;
	int sumka2 = 0;
	int sumka3 = 0;
	int* sumka4 = new int[Size];
	string KALK;
	char* q;
	string* kalk = new string[Size];
	for (int i = 0; i < Size; i++)
	{
		KALK += mass[i];
		kalk[i] = mass[i];
	}
	cout << "Выражение" << KALK<<endl;
	for (int i = 0; i < Size; i++)
	{
		if (kalk[i] == "(")
		{
			/*q = new char[kalk[i+1].size() + 1];
			strcpy(q, kalk[i].c_str());
			if (q[0] == '0' || q[0] == '1' || q[0] == '2' || q[0] == '3' || q[0] == '4' || q[0] == '5' || q[0] == '6' || q[0] == '7' || q[0] == '8' || q[0] == '9')
			{
				if (kalk[i + 2] == "(")
				{
					cout << "Error <(int)>";
					std::abort();
				}
				if (kalk[i + 2] == "22")
				{
					;
				}
			*/
			continue;
		}
		if (kalk[i] == ")")
		{
			continue;
		}
		if (kalk[i] == "+" || kalk[i] == "-" || kalk[i] == "*" || kalk[i] == "/")
		{
			if (PRznaki[i] == 1)
			{
				if (PRznaki[i + 2] == 2)
				{
					sumka1=std::stoi(kalk[i + 3]);
					sumka2 = std::stoi(kalk[i + 1]);
					if (kalk[i + 2] == "/")
					{
						sumka3=sumka1 / sumka2;
						sumka1 = 0;
						sumka2 = 0;
						int k=0;
						kalk[i+1] = sumka3;
						for (int j = 0; j < Size - 2; j++)
						{
							if (j + 1 == 2)
							{

							}
							kalk[j] = kalk[k];
						}
						sumka4[i] = sumka3;
					}
					if (kalk[i + 2] == "*")
					{
						sumka3 = sumka1 * sumka2;
						sumka1 = 0;
						sumka2 = 0;
						sumka4[i] = sumka3;
					}
				}
				sumka1 = std::stoi(kalk[i + 1]);
				sumka2 = std::stoi(kalk[i - 1]);
				if (kalk[i] == "-")
				{
					sumka3 = sumka1 - sumka2;
					sumka1 = 0;
					sumka2 = 0;
					sumka4[i] = sumka3;
				}
				if (kalk[i] == "+")
				{
					sumka3 = sumka1 + sumka2;
					sumka1 = 0;
					sumka2 = 0;
					sumka4[i] = sumka3;
				}
			}
			if (PRznaki[i] == 2)
			{
				if (kalk[i - 1] == "/")
				{
					sumka3 = sumka1 / sumka2;
					sumka1 = 0;
					sumka2 = 0;
					sumka4[i] = sumka3;
				}
				if (kalk[i + 1] == "*")
				{
					sumka3 = sumka1 * sumka2;
					sumka1 = 0;
					sumka2 = 0;
					sumka4[i] = sumka3;
				}
			}
		}
	}
}

void ChekingeWriting::kalk2()
{
	Check();
	if (Vvod == false)
	{
		std::abort;
	}
	int Size = SIZE;
	int sumka1 = 0;
	int sumka2 = 0;
	int sumka3 = 0;
	int buf1 = 0;
	
	int* sumka4 = new int[Size];
	string KALK;
	//char* q;
	string* kalk = new string[Size];
	for (int i = 0; i < Size; i++)
	{
		KALK += mass[i];
		//kalk[i] = mass[i];
	}
	int c = 0;
	cout << "Выражение" << KALK << endl;
	//c = atoi(KALK.c_str());
	c = (11 - 4) * (32+14) / 30 + 5;
	std::cout << c;
	/*
	//	boost::lexical_cast<int> (KALK);
	cout << "Выражение" << KALK << endl;
	for (int i = 0; i < Size; i++)
	{
		if (kalk[i] == "(")
		{
			continue;
		}
		if (kalk[i] == ")")
		{
			continue;
		}
		if (kalk[i] == "+" || kalk[i] == "-" || kalk[i] == "*" || kalk[i] == "/")
		{
			if (PRznaki[i] == 1)
			{
				if (PRznaki[i + 2] == 2)
				{
					sumka1 = std::stoi(kalk[i + 3]);
					sumka2 = std::stoi(kalk[i + 1]);
					if (kalk[i + 2] == "/")
					{
						sumka3 = sumka1 / sumka2;
						sumka1 = 0;
						sumka2 = 0;
						int k = 0;
						kalk[i + 1] = sumka3;
						for (int j = 0; j < Size - 2; j++)
						{
							if (j + 1 == 2)
							{

							}
							kalk[j] = kalk[k];
						}
						sumka4[i] = sumka3;
					}
					if (kalk[i + 2] == "*")
					{
						sumka3 = sumka1 * sumka2;
						sumka1 = 0;
						sumka2 = 0;
						sumka4[i] = sumka3;
					}
				}
				sumka1 = std::stoi(kalk[i + 1]);
				sumka2 = std::stoi(kalk[i - 1]);
				if (kalk[i] == "-")
				{
					sumka3 = sumka1 - sumka2;
					sumka1 = 0;
					sumka2 = 0;
					sumka4[i] = sumka3;
				}
				if (kalk[i] == "+")
				{
					sumka3 = sumka1 + sumka2;
					sumka1 = 0;
					sumka2 = 0;
					sumka4[i] = sumka3;
				}
			}
			if (PRznaki[i] == 2)
			{
				if (kalk[i - 1] == "/")
				{
					sumka3 = sumka1 / sumka2;
					sumka1 = 0;
					sumka2 = 0;
					sumka4[i] = sumka3;
				}
				if (kalk[i + 1] == "*")
				{
					sumka3 = sumka1 * sumka2;
					sumka1 = 0;
					sumka2 = 0;
					sumka4[i] = sumka3;
				}
			}
		}
	}*/
}

void ChekingeWriting::kalk3()
{

	Check();
	if (Vvod == false)
	{
		std::abort;
	}
	int Size = SIZE;
	string KALK;
	for (int i = 0; i < Size; i++)
	{
		KALK += mass[i];
		//kalk[i] = mass[i];
	}
	float c;
	char f;
	cout << "Выражение" << KALK << endl;
	char* ch = new char[KALK.size() + 1];
	strcpy(ch, KALK.c_str());
	/*for (int i = 0; i < Size-1; i++)
	{
		cin.putback(ch[i]);
	}*/
	/*cin.get(f);
	cout << f;
	cin.putback('g');
	cin.get(f);
	cout << f;
	cin.putback('h');
	cin.get(f);
	cout << f;*/
	cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	c = expr();
	cout << c;
}
float ChekingeWriting::number()
{
	int res = 0;
	for (;;)
	{
		char c = cin.get();
		if (c >= '0' && c <= '9')
			res = res * 10 + c - '0';
		else
		{
			cin.putback(c);
			return res;
		}
	}
}
float ChekingeWriting::ckobki()
{
	char c = cin.get();
	if (c == '(')
	{
		float x = expr();
		cin.get();
		return x;
	}
	else
	{
		cin.putback(c);
		return number();
	}
}
float ChekingeWriting::factor()
{
	int x = ckobki();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '*':
			x *= ckobki();
			break;
		case '/':
			x /= ckobki();
			break;
		default:
			cin.putback(c);
			return x;
		}
	}
}
float ChekingeWriting::expr()
{
	int x = factor();
	for (;;)
	{
		char c = cin.get();
		switch (c)
		{
		case '+':
			x += factor();
			break;
		case '-':
			x -= factor();
			break;
		default:
			cin.putback(c);
			return x;
		}
	}
}
void ChekingeWriting::postfix()
{
	ofstream file2;
	file2.open("C:\\Users\\kirill\\source\\repos\\Lab4.1(sem 3)\\test2.txt", std::ios::app);
	if (!file2)
	{
		cout << "Файл для записи не открылся" << endl;
		return;
	}
	/*TStack*gr = new TStack(MAX);
	string* mas = new string[chek->GiveCount()];
	int sc = chek->GiveCount()-1;
	int Size = chek->GiveCount();
	for (int i = 0; i < chek->GiveCount(); i++)
	{
		mas[sc] = mass[i];
		sc--;
	}
	*/
//	int Size = SIZE;
//	string KALK;
	//char* q = new char[Size*Size*Size];
	/*for (int i = 0; i < Size; i++)
	{
		KALK += mass[i];
	}*/
//	char* buf1 = new char[SIZE * SIZE * SIZE];
//	char* buf2 = new char[SIZE * SIZE * SIZE];
	//string* buf1 = new string[SIZE];
	string* buf2 = new string[SIZE];
	//strcpy(buf1, KALK.c_str());
	infix_to_postfix(mass, buf2);
	cout << "Вывод постфиксной записи" << endl;
	for (int i = 0; i < SIZE; i++) 
	{
		cout << buf2[i];
	}
	cout << endl;
	//postfixx = buf2;
	//delete[]buf1;
	postfixx = buf2;
	buf2=NULL;
	delete buf2;
	file2 << "Постфиксная форма: ";
	for (int i = 0; i < SIZE; i++)
	{
		file2<< postfixx[i];
		//cout << postfixx[i];
	}
	file2 << endl;
	file2.close();
	cout << endl;

}
void ChekingeWriting::KALKpostfix()
{
	ofstream file2;
	file2.open("C:\\Users\\kirill\\source\\repos\\Lab4.1(sem 3)\\test2.txt", std::ios::app);
	if (!file2)
	{
		cout << "Файл для записи не открылся" << endl;
		return;
	}
	int sc=0;
	TStack* ch = new TStack(SIZE);
//	TStack* chall = new TStack(SIZE);
//	string* znall = new string[SIZE];
	loop1:
	string* zn = new string[SIZE];
	int size = SIZE;
	int position = 0;
	bool flag1=false;
	bool flag2 = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (postfixx[i] == "_")
		{
			continue;
		}
		if (postfixx[i] == "")
		{
			break;
		}
		if (flag1 == false) 
		{
			if (postfixx[i] != "+" && postfixx[i] != "-" && postfixx[i] != "/" && postfixx[i] != "*")
			{
				ch->Put(postfixx[i]);
				//chall->Put(postfixx[i]);
				zn[sc] = " ";
				sc++;
				size--;
				postfixx[i] = "_";
				continue;
			}
		}
		if (postfixx[i] != "+" && postfixx[i] != "-" && postfixx[i] != "/" && postfixx[i] != "*")
		{
			flag2 = true;
			position = i;
			break;
		}
		zn[sc] = postfixx[i];
		postfixx[i] = '_';
		sc++;
		flag1 = true;
	}
	flag1 = false;
	
	//ch->Print();
	for(int i = 0; i < SIZE; i++)
	{
		//cout << zn[i];
	}
	int j = 0;
	int k = 0;
	double buf1 = 0;
 	double buf2 = 0;
	double buf4 = 0;
	sc = 0;
	string* buf3 = new string[SIZE];
	while (ch->GiveCount() != 1)
	{
		if (zn[j] == " ")
		{
			j++;
			continue;
		}
		if (zn[j] == "+" || zn[j] == "-" || zn[j] == "/" || zn[j] == "*")
		{
			buf1 = atof(ch->Get().c_str());
			buf2 = atof(ch->Get().c_str());
			/*while (ch->GiveCount() != 2)
			{
				k++;
				buf3[k]=ch->Get();
				
			}*/
		//	ch->Print();
			if (zn[j] == "+")
			{
				buf4 = buf2 + buf1;
			}
			if (zn[j] == "-")
			{
				buf4 = buf2 - buf1;
			}
			if (zn[j] == "*")
			{
				buf4 = buf2 * buf1;
			}
			if (zn[j] == "/")
			{
				if (buf1 == 0)
				{
					file2 <<"Результат: подсчет невозможен,т.к. деление на 0 запрещенно"<<endl;
					return;
				}
				buf4 = buf2 / buf1;
			}
			//ch->Print();
			/*while (k != 0)
			{
				ch->Put(buf3[k]);
				k--;
			}*/
			ch->Put(to_string(buf4));
		}
		j++;
		//ch->Print();
		buf1 = 0;
		buf2 = 0;
		buf4 = 0;
	}
	//ch->Print();
	if (flag2 == true)
	{
		goto loop1;
	}
	cout << "Знаки: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << Znaki[i]<<" ";
	}
	cout << endl;
	cout << "Стэк: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << Chisla[i]<<" ";
	}
	cout << "Ответ: ";
	
	file2 << "Результат: ";
	ch->Print();
	string res;
	res=ch->Get();
	file2 << res << endl;
	file2.close();
}
void ChekingeWriting::infix_to_postfix(string infix[], string postfix[])
{
	postf = new TStack(SIZE);

	data = new string[SIZE];
	string token,x ;
	char *buf=new char[SIZE*SIZE*SIZE];
	int i, j;    //i-index of infix,j-index of postfix
	init();
	j = 0;
	int size = SIZE ;
	for (i = 0;i<size; i++)
	{
		//cout << i;
		strcpy(buf, infix[i].c_str());
		token = infix[i];
		if (isalnum(buf[0]))
			postfix[j++] = token;
		else
			if (token == "(")
				push("(");
			else
				if (token == ")")
					while ((x = pop()) != "(")
						postfix[j++] = x;
				else
				{
					while (precedence(token) <= precedence(top()) && !empty())
					{
						x = pop();
						postfix[j++] = x;
					}
					push(token);
				}
	}

	while (!empty())
	{
		x = pop();
		postfix[j++] = x;
	}

	//postfix[j] = '\0';
}

int  ChekingeWriting::precedence(string x)
{
	if (x == "(")
		return(0);
	if (x == "+" || x == "-")
		return(1);
	if (x == "*" || x == "/" || x == "%")
		return(2);

	return(3);
}

void  ChekingeWriting::init()
{
	Top = -1;
}

int ChekingeWriting::empty()
{
	if (Top == -1)
	{
		return(1);
	}
	string x = postf->Get();
	
	if (x == " ")
	{
		postf->Put(x);
		return(1);
	}
	postf->Put(x);
	return(0);
}

int ChekingeWriting::full()
{
	if (Top == MAX - 1)
		return(1);

	return(0);
}

void ChekingeWriting::push(string x)
{
	postf->Put(x);
	Top = Top + 1;
//	data[Top] = x;
}

string  ChekingeWriting::pop()
{
	string x;
	x = postf->Get();
//	x = data[Top];
	Top = Top - 1;
	return(x);
}

bool ChekingeWriting::Vvvod()
{
	return Vvod;
}

string ChekingeWriting::top()
{
	string x=postf->Get();
	
	if (Top == -1)
	{
		postf->Put(x += " ");
		return x += " ";
	}
//	x = data[Top];
	postf->Put(x);
	return x;
}