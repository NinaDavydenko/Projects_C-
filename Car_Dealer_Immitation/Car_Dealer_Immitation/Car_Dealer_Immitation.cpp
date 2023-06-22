#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
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
using namespace std;

struct Car
{
	int year;
	float V;
	int price;
};

class CarDealler
{
private:
	multimap <string, Car> cars;
public:
	CarDealler()
	{

	}
	void operator()(pair<string, Car>carr)
	{
		cout << carr.first << '\t' << carr.second.year << '\t' << carr.second.V << "l\t" << carr.second.price << endl;
	}
	void Add()
	{
		string name;
		Car car;
		cout << "Enter name of car: " << endl;
		cin >> name;
		cout << "Enter production year: " << endl;
		cin >> car.year;
		cout << "Enter engine volume: " << endl;
		cin >> car.V;
		cout << "Enter price of car: " << endl;
		cin >> car.price;
		pair<string, Car>carr(name, car);
		cars.insert(carr);
	}
	void SearchNamePrint()
	{
		int k = 0;
		string name;
		cout << "Enter name of car: " << endl;
		cin >> name;

		for (auto it = cars.begin(); it != cars.end(); ++it)
		{
			if (it->first == name)
			{
				cout << it->first << '\t' << it->second.year << '\t' << it->second.V << "l\t" << it->second.price << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!!\nCar is not found!" << endl;
		}
	}
	void SearchYearPrint()
	{
		int k = 0;
		int y;
		cout << "Enter production year: " << endl;
		cin >> y;
		for (auto it = cars.begin(); it != cars.end(); ++it)
		{
			if (it->second.year == y)
			{
				cout << it->first << '\t' << it->second.year << '\t' << it->second.V << "l\t" << it->second.price << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!!\nCar is not found!" << endl;
		}
	}
	void SearchVPrint()
	{
		int k = 0;
		float v;
		cout << "Enter engine volume: " << endl;
		cin >> v;
		for (auto it = cars.begin(); it != cars.end(); ++it)
		{
			if (it->second.V == v)
			{
				cout << it->first << '\t' << it->second.year << '\t' << it->second.V << "l\t" << it->second.price << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!!\nCar is not found!" << endl;
		}
	}
	void SearchPPrint()
	{
		int k = 0;
		int b;
		int e;
		cout << "Enter price range (begin >> end): " << endl;
		cin >> b >> e;
		for (auto it = cars.begin(); it != cars.end(); ++it)
		{
			if (it->second.price >= b && it->second.price <= e)
			{
				cout << it->first << '\t' << it->second.year << '\t' << it->second.V << "l\t" << it->second.price << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!!\nCar is not found!" << endl;
		}
	}
	void Print()
	{
		for_each(cars.begin(), cars.end(), CarDealler());
	}
	void SaleCar()
	{
		int k = 0;
		string name;
		Car carr;
		cout << "Enter name of car: " << endl;
		cin >> name;
		cout << "Enter production year: " << endl;
		cin >> carr.year;
		cout << "Enter engine volume: " << endl;
		cin >> carr.V;
		cout << "Enter price of car: " << endl;
		cin >> carr.price;
		for (auto it = cars.begin(); it != cars.end(); ++it)
		{
			if (it->first == name && it->second.year == carr.year && it->second.V == carr.V && it->second.price == carr.price)
			{
				cout << it->first << '\t' << it->second.year << '\t' << it->second.V << "l\t" << it->second.price << endl;
				cars.erase(it);
				cout << "Car sold!" << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!!\nCar is not found!" << endl;
		}
	}
	void DeleteCar()
	{
		int k = 0;
		string name;
		Car carr;
		cout << "Enter name of car: " << endl;
		cin >> name;
		cout << "Enter production year: " << endl;
		cin >> carr.year;
		cout << "Enter engine volume: " << endl;
		cin >> carr.V;
		cout << "Enter price of car: " << endl;
		cin >> carr.price;
		for (auto it = cars.begin(); it != cars.end(); ++it)
		{
			if (it->first == name && it->second.year == carr.year && it->second.V == carr.V && it->second.price == carr.price)
			{
				cout << it->first << '\t' << it->second.year << '\t' << it->second.V << "l\t" << it->second.price << endl;
				cars.erase(it);
				cout << "Car deleted!" << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!!\nCar is not found!" << endl;
		}
	}
	void SearchnRedPrice()
	{
		int k = 0;
		string name;
		Car carr;
		cout << "Enter name of car: " << endl;
		cin >> name;
		cout << "Enter production year: " << endl;
		cin >> carr.year;
		cout << "Enter engine volume: " << endl;
		cin >> carr.V;
		cout << "Enter price of car: " << endl;
		cin >> carr.price;
		for (auto it = cars.begin(); it != cars.end(); ++it)
		{
			if (it->first == name && it->second.year == carr.year && it->second.V == carr.V && it->second.price == carr.price)
			{
				cout << it->first << '\t' << it->second.year << '\t' << it->second.V << "l\t" << it->second.price << endl;
				cout << "Enter new price of car: " << endl;
				cin >> it->second.price;
				cout << it->first << '\t' << it->second.year << '\t' << it->second.V << "l\t" << it->second.price << endl;
				k++;
			}
		}
		if (k == 0)
		{
			cout << "ERROR!!!\nCar is not found!" << endl;
		}
	}

};

void main()
{
	CarDealler v;
	int z = 1, x;
	cout << "[Add]" << endl;
	cout << " Show all" << endl;
	cout << " Search(name)" << endl;
	cout << " Search(year)" << endl;
	cout << " Search(engine volume)" << endl;
	cout << " Search(price)" << endl;
	cout << " Search and Redact Price" << endl;
	cout << " Search and Delete" << endl;
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
			cout << "Search(name)_______________________" << endl;
			v.SearchNamePrint();
			system("pause");
		}
		if (x == 13 && z == 4)
		{
			system("CLS");
			cout << "Search(year)_______________________" << endl;
			v.SearchNamePrint();
			system("pause");
		}
		if (x == 13 && z == 5)
		{
			system("CLS");
			cout << "Search(engine volume)_______________________" << endl;
			v.SearchPPrint();
			system("pause");
		}
		if (x == 13 && z == 6)
		{
			system("CLS");
			cout << "Search(price)_______________________" << endl;
			v.SearchPPrint();
			system("pause");
		}
		if (x == 13 && z == 7)
		{
			system("CLS");
			cout << "Search and Edit Price____________" << endl;
			v.SearchnRedPrice();
			system("pause");
		}
		if (x == 13 && z == 8)
		{
			system("CLS");
			cout << "Search and Delete____________" << endl;
			v.DeleteCar();
			system("pause");
		}

		if (x == 13 && z == 9)
			exit(0);
		switch (x)
		{
		case 72: z--;
			break;
		case 80: z++;
			break;
		}
		if (z < 1)
			z = 9;
		if (z > 9)
			z = 1;
		switch (z)
		{
		case 1:system("CLS");
			cout << "[Add]" << endl;
			cout << " Show all" << endl;
			cout << " Search(name)" << endl;
			cout << " Search(year)" << endl;
			cout << " Search(engine volume)" << endl;
			cout << " Search(price)" << endl;
			cout << " Search and Edit Price" << endl;
			cout << " Search and Delete" << endl;
			cout << " Exit" << endl;
			break;
		case 2:system("CLS");
			cout << " Add" << endl;
			cout << "[Show all]" << endl;
			cout << " Search(name)" << endl;
			cout << " Search(year)" << endl;
			cout << " Search(engine volume)" << endl;
			cout << " Search(price)" << endl;
			cout << " Search and Edit Price" << endl;
			cout << " Search and Delete" << endl;
			cout << " Exit" << endl;
			break;
		case 3:system("CLS");
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << "[Search(name)]" << endl;
			cout << " Search(year)" << endl;
			cout << " Search(engine volume)" << endl;
			cout << " Search(price)" << endl;
			cout << " Search and Edit Price" << endl;
			cout << " Search and Delete" << endl;
			cout << " Exit" << endl;
			break;
		case 4:system("CLS");
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search(name)" << endl;
			cout << "[Search(year)]" << endl;
			cout << " Search(engine volume)" << endl;
			cout << " Search(price)" << endl;
			cout << " Search and Edit Price" << endl;
			cout << " Search and Delete" << endl;
			cout << " Exit" << endl;
			break;
		case 5:system("CLS");
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search(name)" << endl;
			cout << " Search(year)" << endl;
			cout << "[Search(engine volume)]" << endl;
			cout << " Search(price)" << endl;
			cout << " Search and Edit Price" << endl;
			cout << " Search and Delete" << endl;
			cout << " Exit" << endl;
			break;
		case 6:system("CLS");
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search(name)" << endl;
			cout << " Search(year)" << endl;
			cout << " Search(engine volume)" << endl;
			cout << "[Search(price)]" << endl;
			cout << " Search and Edit Price" << endl;
			cout << " Search and Delete" << endl;
			cout << " Exit" << endl;
			break;
		case 7:system("CLS");
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search(name)" << endl;
			cout << " Search(year)" << endl;
			cout << " Search(engine volume)" << endl;
			cout << " Search(price)" << endl;
			cout << "[Search and Edit Price]" << endl;
			cout << " Search and Delete" << endl;
			cout << " Exit" << endl;
			break;
		case 8:system("CLS");
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search(name)" << endl;
			cout << " Search(year)" << endl;
			cout << " Search(engine volume)" << endl;
			cout << " Search(price)" << endl;
			cout << " Search and Edit Price" << endl;
			cout << "[Search and Delete]" << endl;
			cout << " Exit" << endl;
			break;
		case 9:system("CLS");
			cout << " Add" << endl;
			cout << " Show all" << endl;
			cout << " Search(name)" << endl;
			cout << " Search(year)" << endl;
			cout << " Search(engine volume)" << endl;
			cout << " Search(price)" << endl;
			cout << " Search and Edit Price" << endl;
			cout << " Search and Delete" << endl;
			cout << "[Exit]" << endl;
			break;
		}
	}
	system("pause");
}