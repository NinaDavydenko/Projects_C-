#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <conio.h>
#include <list>
#include <fstream>

using namespace std;

class Exam
{
	string surname;
	string name;
	string father;
	string e1, e2, e3, e4, e5;
public:
	Exam(char* _s, char* _n, char* _f, char _e1, char _e2, char _e3, char _e4, char _e5)
	{
		surname = _s;
		name = _n;
		father = _f;
		e1 = _e1;
		e2 = _e2;
		e3 = _e3;
		e4 = _e4;
		e5 = _e5;
	}
	string get_e1()
	{
		return e1;
	}
	string get_e2()
	{
		return e2;
	}
	string get_e3()
	{
		return e3;
	}
	string get_e4()
	{
		return e4;
	}
	string get_e5()
	{
		return e5;
	}
	void Print()
	{
		cout << surname << " " << name << " " << father << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string file_name{ "D:\\Ніна\\Академія\\Project\\exam.txt" };
	fstream file;

	char s[50];
	char n[50];
	char f[50];
	char e1, e2, e3, e4, e5;

	list <Exam> l;

	char c = '~';
	file.open(file_name, ios::in);
	while (c != EOF && c == '~')
	{
		file.get(s, 50, '~');
		file.get(c);
		file.get(n, 50, '~');
		file.get(c);
		file.get(f, 50, '~');
		file.get(c);
		file.get(e1);
		file.get(c);
		file.get(e2);
		file.get(c);
		file.get(e3);
		file.get(c);
		file.get(e4);
		file.get(c);
		file.get(e5);
		file.get(c);
		if (strcmp(s, "") == NULL)
			c = '*';
		else
		{
			Exam exam(s, n, f, e1, e2, e3, e4, e5);
			l.push_back(exam);
		}
	}

	file.close();

	cout << "The entire list of students:" << endl;
	for (auto it = l.begin(); it != l.end(); it++)
	{
		it->Print();
	}
	cout << endl << endl;

	string mark;
	cout << "List of students who passed all exams on grade 5:" << endl;
	mark = { '5' };
	for (auto it = l.begin(); it != l.end(); it++)
	{
		if(it->get_e1()== mark && it->get_e2() == mark && it->get_e3() == mark 
			&& it->get_e4() == mark && it->get_e5() == mark)
			it->Print();
	}
	cout << endl << endl;

	cout << "List of students who have at least one grade 3:" << endl;
	mark = { '3' };
	for (auto it = l.begin(); it != l.end(); it++)
	{
		if (it->get_e1() == mark || it->get_e2() == mark || it->get_e3() == mark
			|| it->get_e4() == mark || it->get_e5() == mark)
			it->Print();
	}
	cout << endl << endl;

	cout << "List of students who have grade 2:" << endl;
	mark = { '2' };
	for (auto it = l.begin(); it != l.end(); it++)
	{
		int k = 0;
		if (it->get_e1() == mark)
			k++;
		if (it->get_e2() == mark)
			k++;
		if (it->get_e3() == mark)
			k++;
		if(it->get_e4() == mark)
			k++;
		if(it->get_e5() == mark)
			k++;
		if(k == 1)
			it->Print();
	}
	cout << endl << endl;

	system("pause");
	return 0;
}