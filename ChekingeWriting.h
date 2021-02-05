#pragma once
#include"SimpleStack.h"
#include <stdlib.h>
class ChekingeWriting
{
protected:
	TStack *chek;
	TStack* postf;
	int SIZE;
	string* mass;
	string* Scobki;
	string* Znaki;
	string* Chisla;
	bool Vvod=false;
	int* GIndexSc;
	int* GIndprobel;
	int* GIndznaki;
	int* GIchisla;
	int* PRznaki;
	string* Perem;
	int* FlagPerem;
	int kolSc;
	int kolPr;
	int kolZnak;
	int kolCh;
	int Top=0;
	//int* data = new int[1000];
	string* data;
	//char* postfixx;
	string*postfixx;
public:
	ChekingeWriting(TStack * a);
	~ChekingeWriting();
	void Check();
	void Print();
	void Kalk();//
	void kalk2();//
	void kalk3();
	float number();
	float ckobki();
	float factor();
	float expr();
	void postfix();
	void KALKpostfix();
	void infix_to_postfix(string infix[], string postfix[]);
	int precedence(string x);
	void init();
	int empty();
	int full();
	void push(string x);
	bool Vvvod();
	string pop();
	string top();
};

