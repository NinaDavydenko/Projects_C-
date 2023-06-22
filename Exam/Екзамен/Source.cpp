#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <stdlib.h>
#include<time.h>
#include<Windows.h>

using namespace std;

struct Book
{
	char title[255];
	char author[255];
	char vyd[255];
	char ganr[255];
};

void Print_one(Book bib)
{
	cout << "Title\t: " << bib.title << endl;
	cout << "Author\t: " << bib.author << endl;
	cout << "Publisher\t: " << bib.vyd << endl;
	cout << "Genre\t: " << bib.ganr << endl;
	cout << endl;
}

void Print(Book *bib, int size)
{
	for (int i = 0; i < size; i++)
	{
		Print_one(bib[i]);
	}
	cout << endl;
}

void Edit_book(Book *bib, int l, char *search_edit)
{
	int t = 0, w;
	for (int i = 0; i < l; i++)
	{
		if (strstr(bib[i].title, search_edit))
		{
			Print_one(bib[i]);
			w = i;
			t++;
		}
	}
	if (t == 0)
	{
		cout << "ERROR!!!" << endl;
	}
	else
	{
		int q;
		cout << "What do you want to change?\n(1 - Title, 2 - Author, 3 - Publisher, 4 - Genre)";
		cin >> q;
		cin.ignore();
		switch (q)
		{
		case 1: 
			cout << "Enter a new title: ";
			gets_s(bib[w].title);
			break;
		case 2: 
			cout << "Enter a new author: ";
			gets_s(bib[w].author);
			break;
		case 3: 
			cout << "Enter a new publisher: ";
			gets_s(bib[w].vyd);
			break;
		case 4: 
			cout << "Enter a new genre: ";
			gets_s(bib[w].ganr);
			break;
		default:
			cout << "ERROR!!!" << endl;
			break;
		}
	}
}

void Search_author(Book *bib, int l, char *search_author)
{
	int t = 0;
	for (int i = 0; i < l; i++)
	{
		if (strstr(bib[i].author, search_author))
		{
			Print_one(bib[i]);
			t++;
		}
	}
	if (t == 0)
	{
		cout << "ERROR!!!" << endl;
	}
}

void Search_title(Book *bib, int l, char *search_title)
{
	int t = 0;
	for (int i = 0; i < l; i++)
	{
		if (strstr(bib[i].title, search_title))
		{
			Print_one(bib[i]);
			t++;
		}
	}
	if (t == 0)
	{
		cout << "ERROR!!!" << endl;
	}
}

void Sort_title(Book *bib, int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = size - 1; j > 0; j--)
		{
			if ((int)bib[j].title[0] < (int)bib[j - 1].title[0])
			{
				Book tmp = bib[j];
				bib[j] = bib[j - 1];
				bib[j - 1] = tmp;
			}
		}
	}
}

void Sort_author(Book *bib, int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = size - 1; j > 0; j--)
		{
			if ((int)bib[j].author[0] < (int)bib[j - 1].author[0])
			{
				Book tmp = bib[j];
				bib[j] = bib[j - 1];
				bib[j - 1] = tmp;
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int l = 10;
	Book bib[l]
	{
		{ "Mysterious Island", "Jules Verne", "Rainbow", "Adventures"},
		{ "Fahrenheit 451", "Ray Bradbury", "Amber", "Fiction"},
		{ "White Fang", "Jack London", "Kyiv", "Roman"},
		{ "The Great Gatsby", "Francis Scott", "Kyiv", "Roman"},
		{ "Rodney Stone", "Arthur Conan Doyle", "Truth", "Adventure"},
		{ "Treasure Island", "Robert Lewis Stevenson", "Kyiv", "Adventures"},
		{ "Andromeda Nebula", "Ivan Yefremov", "Kyiv", "Science fiction"},
		{ "Mansfield Park", "Jane Austen", "London", "Romance"},
		{ "N or M?", "Agatha Christie", "London", "Detective"},
		{ "Emma", "Jane Austen", "London", "Romance"}
	};

	while (1)
	{
		int z;
		bool Exit=false;
		system("CLS");
		cout << "LIBRARY_________________________" << endl;
		cout << "1 - Edit book information" << endl;
		cout << "2 - View all available books" << endl;
		cout << "3 - Search for a book by author" << endl;
		cout << "4 - Search for a book by title" << endl;
		cout << "5 - Exit" << endl;
		cin >> z;
		switch (z)
		{
		case 1:
			cin.ignore();
			system("CLS");
			char search_edit[255];
			cout << "Enter the title of the book to edit:" << endl;
			gets_s(search_edit);
			Edit_book(bib, l, search_edit);
			system("pause");
			break;
		case 2:
			cin.ignore();
			system("CLS");
			cout << "Select the type of library view (1 - sort by title, 2 - sort by author):";
			int y;
			cin >> y;
			switch (y)
			{
			case 1:
				Sort_title(bib, l);
				Print(bib, l);
				break;
			case 2:
				Sort_author(bib, l);
				Print(bib, l);
				break;
			default:
				cout << "ERROR!!!" << endl;
				break;
			}
			system("pause");
			break;
		case 3:
			cin.ignore();
			system("CLS");
			char search_author[255];
			cout << "Enter an author to search:" << endl;
			gets_s(search_author);
			Search_author(bib, l, search_author);
			system("pause");
			break;
		case 4:
			cin.ignore();
			system("CLS");
			char search_title[255];
			cout << "Enter the title of the book to search:" << endl;
			gets_s(search_title);
			Search_title(bib, l, search_title);
			system("pause");
			break;
		case 5:
			system("CLS");
			Exit = true;
			break;
		default:
			cout << "There is no such menu item" << endl;
		}
		if (Exit)
		{
			break;
		}
	}

	system("pause");
	return 0;
}