#include "ChekingeWriting.h"
#include <iostream>
#include "SimpleStack.h"
#include <locale.h>
#include <stdlib.h>
#include <limits>
#include <fstream>
#include <string>
#include <string.h>
#define MAX 30
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Rus");
    ofstream file2;
    file2.open("C:\\Users\\kirill\\source\\repos\\Lab4.1(sem 3)\\test2.txt");
    file2.close();
    ifstream file;
    file.open("C:\\Users\\kirill\\source\\repos\\Lab4.1(sem 3)\\test1.txt");
    if (!file)
    {
        cout << "Файл не открыт\n\n";
        return -1;
    }
    else
    {
        cout << "Все ОК! Файл открыт!\n\n";
        //return 1;
    }
    string* s =new string [MAX];//s[10];
    int i = 0;
    for (file >> s[i]; !file.eof(); file >> s[i])
    {
        cout << s[i] << endl;
        i++;
    }
    file.close();
    char* buf;
    string* buf2;
    TStack* buf3;
    ChekingeWriting* h;
    bool flag = false;
    for (int j = 0; j < i; j++)
    {
        buf2 = new string[MAX];
        buf = new char[255];
        buf3 = new TStack(MAX);
        strcpy(buf, s[j].c_str());
        int size = strlen(buf);
    //    int k = 0;
        int g = 0;
     //   buf += '\n';
        for(int k=0;k<size;k++)
        {
            if (buf[k] == '(')
            {
                if (flag == true)
                {
                    buf3->Put(buf2[g]);
                    g++;
                    flag = false;
                }
                buf3->Put("(");
            //  k++;
                continue;
            }
            if (buf[k] == ')')
            {
                if (flag == true)
                {
                    buf3->Put(buf2[g]);
                    g++;
                    flag = false;
                }
                buf3->Put(")");
               // k++;
                continue;
            }
            if (buf[k] == '+')
            {
                if (flag == true)
                {
                    buf3->Put(buf2[g]);
                    g++;
                    flag = false;
                }
                buf3->Put("+");
          //      k++;
                continue;
            }
            if (buf[k] == '-')
            {
                if (flag == true)
                {
                    buf3->Put(buf2[g]);
                    g++;
                    flag = false;
                }
                buf3->Put("-");
            //    k++;
                continue;
            }
            if (buf[k] == '*')
            {
                if (flag == true)
                {
                    buf3->Put(buf2[g]);
                    g++;
                    flag = false;
                }
                buf3->Put("*");
                continue;
            }
            if (buf[k] == '/')
            {
                if (flag == true)
                {
                    buf3->Put(buf2[g]);
                    g++;
                    flag = false;
                }
                buf3->Put("/");
             //  k++;
                continue;
            }
            buf2[g] += buf[k];
            flag = true;
     //       k++;
        }
        if (buf2[g] !="" )
        {
            buf3->Put(buf2[g]);
        }
        cout << endl;
        buf3->Print();
        cout << endl;
        h = new ChekingeWriting(buf3);
        h->Print();
        if (h->Vvvod() == false)
        {
            continue;
        }
        cout << "Перевод из инфиксной в постфиксную" << endl;
        
        h->postfix();
        h->KALKpostfix();
    }
   /* TStack* stack = new TStack(MAX);
    int g;
    cout << "Введите размер выражения"<<endl;
    cin >> g;
    string h;
    for (int i = 0; i < g; i++)
    {
        cout << "Введите эелемент " << i << endl;
        cin >> h;
        stack->Put(h);
    }
    cout << endl;/*
   /* stack->Put("(");
    stack->Put("1");
    stack->Put("+");
    stack->Put("3");
    stack->Put(")");
    stack->Put("+");
    stack->Put("5");
    stack->Put("*");
    stack->Put("9");
    stack->Print();*/
  /*  ChekingeWriting* f = new ChekingeWriting(stack);
    f->Print();
    cout << "Перевод из инфиксной в постфиксную" << endl;
    f->postfix();
    cout << endl;
    f->KALKpostfix();/*
  /*  getchar();
    getchar();*/
    /*
    g = stack->GetRedCode();
    cout << g << "  Error code" << endl;
    g = stack->IsEmpty();
    cout << g << "  Don't Have elements?" << endl;
    g = stack->IsFull();
    cout << g << "  It full?" << endl;
    g = stack->IsValid();
    cout << g << "  It normal?" << endl;
    h = stack->Get();
    stack->Print();
    cout << g << " Get" << endl;
    */
    /*
    int m;
    do
    {
        cout << "Выберите ошибку" << endl;
        cout << "1.Нормальная отработка" << endl << "2.Стек не имеет памяти" <<endl<<"3.Стек не имеет элементов"<< endl<<"4.Стэк переполнен"<<endl<<"5.Exit"<<endl;
        cin >> m;
        switch (m)
        {
        default:
            break;
        case 1:
        {
            TStack* stack = new TStack(10);
            int g;
            string h;
            stack->Put("(");
            stack->Put("1");
            stack->Put("+");
            stack->Put("3");
            stack->Put(")");
            stack->Put("-");
            stack->Put("5");
            stack->Put("*");
            stack->Put("9");
            stack->Print();
            
            g = stack->GetRedCode();
            cout << g << "  Error code" << endl;
            g = stack->IsEmpty();
            cout << g << "  Don't Have elements?" << endl;
            g = stack->IsFull();
            cout << g << "  It full?" << endl;
            g = stack->IsValid();
            cout << g << "  It normal?" << endl;
            h = stack->Get();
            stack->Print();
            cout << g << " Get" << endl;
            
        }break;
       /* case 2:
        {
            cout << "Error: -103 - no memory" << endl;
            TStack* stack = new TStack(0);
            int g;
            stack->Put(1);//т.к. памяти не выделенно, то поставит ошибку нет памяти 
            stack->Print();
            g = stack->GetRedCode();
            cout << g << "  -Error code" << endl;
            g = stack->IsEmpty();
            cout << g << "  -Don't Have elements?" << endl;
            g = stack->IsFull();
            cout << g << "  -It full?" << endl;
            g = stack->IsValid();
            cout << g << "  -It normal?" << endl;
            g = stack->Get();
            stack->Print();
            cout << g << " -Get" << endl;
        }break;
        case 3:
        {
            cout << "Error: -101 - no elements/empty" << endl;
            TStack* stack = new TStack(3);
            int g;
            stack->Get();//т.к. стэк путсой, то поставит ошибку нет элементов 
            g = stack->GetRedCode();
            cout << g << "  -Error code" << endl;
            g = stack->IsEmpty();
            cout << g << "  -Don't Have elements?" << endl;
            g = stack->IsFull();
            cout << g << "  -It full?" << endl;
            g = stack->IsValid();
            cout << g << "  -It normal?" << endl;
            g = stack->Get();
            stack->Print();
            cout << g << " -Get" << endl;
        }break;
        case 4:
        {
            cout << "Error: -102 - stack full" << endl;
            TStack* stack = new TStack(3);
            stack->Put(1);
            stack->Put(3);
            stack->Put(5);
            stack->Put(9);//т.к. памят переполнится , то поставит ошибку , что стэк переполнен
            int g;
            stack->Print();
           // stack->Get();
            g = stack->GetRedCode();
            cout << g << "  -Error code" << endl;
            g = stack->IsEmpty();
            cout << g << "  -Don't Have elements?" << endl;
            g = stack->IsFull();
            cout << g << "  -It full?" << endl;
            g = stack->IsValid();
            cout << g << "  -It normal?" << endl;
            g = stack->Get();
            cout << g << " -Get" << endl;
        }break;
        case 5: {; }break;//exit
        }
    } while (m != 5);
    */
    return 0;
}
