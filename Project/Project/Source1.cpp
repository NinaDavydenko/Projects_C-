#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <conio.h>
#include <map>
#include <list>

using namespace std;

struct Words
{
	string word;
	int count = 0;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	char start[] { "Вот дом, Который построил Джек. А это пшеница, Которая в темном чулане хранится В доме, Который построил Джек. А это веселая птица-синица, Которая часто ворует пшеницу, Которая в темном чулане хранится В доме, Который построил Джек." };	char str[50][20];
	char* p = strtok(start, " ,.");
	int i = 0;
	while (p != NULL)
	{
		strcpy(str[i], p);
		i++;
		p = strtok(NULL, " ,.");
	}

	string s[50];
	Words w;
	map<int, Words> m;
	int k = 1;
	for (int j = 0; j < i; j++)
	{
		s[j] = str[j];
	}

	int sum = 0;
	for (int j = 0; j < i; j++)
	{
		w.word = s[j];
		w.count = k;
		if(m.empty())
			m[j] = w;
		else
		{
			int y = -1;
			for (auto it = m.begin(); it != m.end(); it++)
			{
				if (it->second.word == w.word)
				{
					it->second.count++;
					y = 1;
				}
			}
			if(y < 0)
				m[j] = w;
		}
		sum++;
	}
    
	int q = 0;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		q++;
		cout << q << ".\t" << it->second.word << "\t" << it->second.count << endl;
	}

	cout << "Total amount of words: " << sum << endl;
	cout << "Amount of unique words: " << q << endl;

    system("pause");
    return 0;
}