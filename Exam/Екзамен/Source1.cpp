#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

void Print_one(int t)
{
	cout << t << ' ';
}

void rev(int *pa, int size)
{
	int *arr = new int[size];
	for (int i = 0; i < size; i++, pa++)
	{
		Print_one(*pa);
		arr[i] = *pa;
	}
	cout << endl << "------------------------------------" << endl;

	pa = &arr[0];

	int *tarr = new int[size];
	for (int i = 0; i < size; i++)
	{
		tarr[i] = pa[i];
	}
	for (int i = 0; i < size / 2; i++)
	{
		pa[i] = tarr[size - 1 - i];
	}
	for (int i = 0; i < size / 2; i++)
	{
		pa[size - 1 - i] = tarr[i];
	}

	for (int i = 0; i < size; i++, pa++)
	{
		Print_one(*pa);
	}
	cout << endl;
	delete[] tarr;
}

void main()
{
	const int siz = 10;
	int arr[siz] = { 3,96,98,67,66,75,24,13,2,11 };
	int *p = &arr[0];
	rev(p, siz);
	system("pause");
}