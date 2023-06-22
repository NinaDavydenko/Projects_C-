#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <map>
#include <fstream>
using namespace std;
struct Event
{
	vector<string> Time;
	vector<string> Eventt;
};
class Tasker
{
private:
	multimap <string, Event> tasks;
public:
	Tasker()
	{

	}
	void Add()
	{
		string date;
		string time;
		string eventt;
		Event event;
		cout << "Enter date: " << endl;
		getline(cin, date);
		cout << "Enter time: " << endl;
		getline(cin, time);
		cout << "Enter event/task: " << endl;
		getline(cin, eventt);
		int k = 0;
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
		{
			if (it->first == date)
			{
				auto it1 = it->second.Time.end();
				auto it2 = it->second.Eventt.end();
				it->second.Time.insert(it1, time);
				it->second.Eventt.insert(it2, eventt);
				k++;
			}
		}
		if (k == 0)
		{
			vector<string>::iterator it = event.Time.end();
			event.Time.insert(it, time);
			vector<string>::iterator ite = event.Eventt.end();
			event.Eventt.insert(ite, eventt);
			pair<string, Event>taskk(date, event);
			tasks.insert(taskk);
		}
	}
	void SearchnPrint()
	{
		int k = 0;
		string str;
		cout << "Enter date: " << endl;
		getline(cin, str);
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
		{
			if (it->first == str)
			{
				cout << it->first << ':' << endl;
				auto it2 = it->second.Eventt.begin();
				for (auto it1 = it->second.Time.begin(); it1 != it->second.Time.end() && it2 != it->second.Eventt.end(); it1++, it2++)
				{
					cout << '\t' << *it1 << '\t' << *it2 << endl;
				}
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!! Task/event is not found!" << endl;
		}
	}
	void SearchnRed()
	{
		int k = 0;
		string str;
		cout << "Enter date: " << endl;
		getline(cin, str);
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
		{
			if (it->first == str)
			{
				cout << it->first << ':' << endl;
				auto it2 = it->second.Eventt.begin();
				for (auto it1 = it->second.Time.begin(); it1 != it->second.Time.end() && it2 != it->second.Eventt.end(); it1++, it2++)
				{
					cout << '\t' << *it1 << '\t' << *it2 << endl;
				}
				while (1)
				{
					string time;
					int t = 0;
					cout << "Set time:" << endl;
					getline(cin, time);
					auto it3 = it->second.Eventt.begin();
					for (auto it1 = it->second.Time.begin(); it1 != it->second.Time.end() && it3 != it->second.Eventt.end(); it1++, it3++)
					{
						if (*it1 == time)
						{
							cout << '\t' << *it1 << '\t' << *it3 << endl;
							int tt;
							cout << "1-delete, 2-change time, 3-change task: " << endl;
							cin >> tt;
							if (tt == 1)
							{
								it->second.Time.erase(it1);
								it->second.Eventt.erase(it3);
								cout << "Deleted" << endl;
								t++;
							}
							else if (tt == 2)
							{
								string newt;
								cout << "Set new time: " << endl;
								cin >> newt;
								*it1 = newt;
								cout << "Time changed" << endl;
								t++;
							}
							else if (tt == 3)
							{
								string newt;
								cout << "Set new task: " << endl;
								cin >> newt;
								*it3 = newt;
								cout << "Task changed" << endl;
								t++;
							}
							else
							{
								cout << "ERROR!!!Incorrect value!" << endl;
								t = 0;
							}
							break;
							break;
							break;
						}
					}
					if (t != 0)
					{
						break;
						break;
					}
					else if (t == 0)
					{
						cout << "ERROR!!! Task/event is not found!" << endl;
						continue;
					}
				}
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!! Task/event is not found!" << endl;
		}
	}
	void SearchnDel()
	{
		int k = 0;
		string str;
		cout << "Enter date: " << endl;
		getline(cin, str);
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
		{
			if (it->first == str)
			{
				tasks.erase(it);
				k++;
				break;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!! Task/event is not found!" << endl;
		}
	}
	void Zapis()
	{
		ofstream f("D:\\DavydenkoExam.txt");
		f << "\tTime\tEvent/Task";
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
		{
			f << "\nDate: " << it->first;
			auto it2 = it->second.Eventt.begin();
			for (auto it1 = it->second.Time.begin(); it1 != it->second.Time.end() && it2 != it->second.Eventt.end(); it1++, it2++)
			{
				f << "\n\t" << *it1;
				f << "\t" << *it2;
			}
		}
		f.close();
	}
	void Print()
	{
		for (auto it = tasks.begin(); it != tasks.end(); ++it)
		{
			cout << it->first << ':' << endl;
			auto it2 = it->second.Eventt.begin();
			for (auto it1 = it->second.Time.begin(); it1 != it->second.Time.end() && it2 != it->second.Eventt.end(); it1++, it2++)
			{
				cout << '\t' << *it1 << '\t' << *it2 << endl;
			}
		}
	}
};

void main()
{
	Tasker v;
	int z = 1, x;
	cout << "Tasker_________________________" << endl;
	cout << "[Add]" << endl;
	cout << " Show all" << endl;
	cout << " Search" << endl;
	cout << " Search and Edit" << endl;
	cout << " Search and Delete" << endl;
	cout << " Save to file" << endl;
	cout << " Exit" << endl;

	while (1)
	{
		x = _getch();
		system("CLS");
		if (x == 13 && z == 1)
		{
			system("CLS");
			cout << "Add__________________________" << endl;
			v.Add();
			system("pause");
		}
		if (x == 13 && z == 2)
		{
			system("CLS");
			cout << "Show all_____________________" << endl;
			v.Print();
			system("pause");
		}
		if (x == 13 && z == 3)
		{
			system("CLS");
			cout << "Search_______________________" << endl;
			v.SearchnPrint();
			system("pause");
		}
		if (x == 13 && z == 4)
		{
			system("CLS");
			cout << "Search and Edit____________" << endl;
			v.SearchnRed();
			system("pause");
		}
		if (x == 13 && z == 5)
		{
			system("CLS");
			cout << "Search and Delete____________" << endl;
			v.SearchnDel();
			system("pause");
		}
		if (x == 13 && z == 6)
		{
			system("CLS");
			cout << "Save to file_________________" << endl;
			v.Zapis();
			system("pause");
		}
		if (x == 13 && z == 7)
			exit(0);
		switch (x)
		{
		case 72: z--;
			break;
		case 80: z++;
			break;
		}
		if (z < 1)
			z = 7;
		if (z > 7)
			z = 1;
		switch (z)
		{
		case 1:system("CLS");
			cout << "Tasker_________________________" << endl;
			cout << "[Add]" << endl;
			cout << " Show all" << endl;
			cout << " Search" << endl;
			cout << " Search and Edit" << endl;
			cout << " Search and Delete" << endl;
			cout << " Save to file" << endl;
			cout << " Exit" << endl;
			break;
		case 2:system("CLS");
			cout << "Tasker_________________________" << endl;
			cout << " Add" << endl;
			cout << "[Show all]" << endl;
			cout << " Search" << endl;
			cout << " Search and Edit" << endl;
			cout << " Search and Delete" << endl;
			cout << " Save to file" << endl;
			cout << " Exit" << endl;
			break;
		case 3:system("CLS");
			cout << "Tasker_________________________" << endl;
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << "[Search]" << endl;
			cout << " Search and Edit" << endl;
			cout << " Search and Delete" << endl;
			cout << " Save to file" << endl;
			cout << " Exit" << endl;
			break;
		case 4:system("CLS");
			cout << "Tasker_________________________" << endl;
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search" << endl;
			cout << "[Search and Edit]" << endl;
			cout << " Search and Delete" << endl;
			cout << " Save to file" << endl;
			cout << " Exit" << endl;
			break;
		case 5:system("CLS");
			cout << "Tasker_________________________" << endl;
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search" << endl;
			cout << " Search and Edit" << endl;
			cout << "[Search and Delete]" << endl;
			cout << " Save to file" << endl;
			cout << " Exit" << endl;
			break;
		case 6:system("CLS");
			cout << "Tasker_________________________" << endl;
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search" << endl;
			cout << " Search and Edit" << endl;
			cout << " Search and Delete" << endl;
			cout << "[Save to file]" << endl;
			cout << " Exit" << endl;
			break;
		case 7:system("CLS");
			cout << "Tasker_________________________" << endl;
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search" << endl;
			cout << " Search and Edit" << endl;
			cout << " Search and Delete" << endl;
			cout << " Save to file" << endl;
			cout << "[Exit]" << endl;
			break;
		}
	}
	system("pause");
}