#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
namespace Bankomat
{
	namespace Account
	{
		class Account
		{
		private:
			char FIO[255];
			int password;
			int balance;
			long int card;
		public:
			Account()
			{
				balance = 0;
			}
			void AddAcc(char* fio)
			{
				strcpy(FIO, fio);
				card = rand() % 9900000 + 100000;
				password = rand() % 9000 + 1000;
				cout << "Card: " << card << endl;
				cout << "Pass: " << password << endl;
			}
			int Enter()
			{
				for (int i = 0; i < 4; i++)
				{
					int k;
					cout << "Enter password: " << endl;
					cin >> k;
					if (k != password)
					{
						cout << "ERROR!!! Incorrect password, you have " << 3 - (i + 1) << " tryes" << endl;
						if (i + 1 == 3)
						{
							return 333;
						}
					}
					else if (k == password)
					{
						return 1;
					}
				}
			}
			void ShowBalance()
			{
				cout << "Your balance: " << balance << "grn" << endl;
			}
			void Popovn(int p)
			{
				balance += p;
				cout << p << " grn was withdrawn from the account" << endl;
			}
			void Znyaty(int z)
			{
				if (z > balance)
				{
					cout << "Incorrect sum" << endl;
				}
				else if (z <= balance)
				{
					balance -= z;
					cout << z << " grn was withdrawn from the account" << endl;
				}
			}
		};
	}
	namespace Client
	{
		class Client
		{
		private:
			Account::Account Acc;
		public:
			Client()
			{
				char fio[255];
				cout << "Input your Name and Surname: " << endl;
				cin.getline(fio, 255);
				cout << "Your card and password" << endl;
				Acc.AddAcc(fio);
			}
			int Login()
			{
				int k = Acc.Enter();
				if (k == 333)
				{
					return 0;
				}
				else if (k == 1)
				{
					return 1;
				}
			}
			void Show()
			{
				Acc.ShowBalance();
			}
			void Popovn()
			{
				cout << "Enter the amount to top up the account: " << endl;
				int p;
				cin >> p;
				Acc.Popovn(p);
			}
			void Znyaty()
			{
				cout << "Enter the amount you want to withdraw from the account: " << endl;
				int z;
				cin >> z;
				Acc.Znyaty(z);
			}
		};
	}

	namespace Bank
	{

		class Bank
		{
		public:
			Bank()
			{

			}
			void menu()
			{
				Client::Client Cli;
				system("pause");
				system("CLS");
				int o = Cli.Login();
				if (o == 0)
				{
					exit(0);
				}
				system("pause");
				system("CLS");
				int z = 1, x;
				cout << "[Show balance]" << endl;
				cout << "Top up" << endl;
				cout << "Withdraw" << endl;
				cout << "Exit" << endl;

				while (1)
				{
					x = _getch();
					system("CLS");
					if (x == 13 && z == 1)
					{
						system("CLS");
						Cli.Show();
						cout << "1-back to menu, 0-exit" << endl;
						int k;
						cin >> k;
						if (k == 0)
						{
							exit(0);
						}
						system("pause");
					}
					if (x == 13 && z == 2)
					{
						system("CLS");
						Cli.Popovn();
						cout << "1-back to menu, 0-exit" << endl;
						int k;
						cin >> k;
						if (k == 0)
						{
							exit(0);
						}
						system("pause");
					}
					if (x == 13 && z == 2)
					{
						system("CLS");
						Cli.Znyaty();
						cout << "1-back to menu, 0-exit" << endl;
						int k;
						cin >> k;
						if (k == 0)
						{
							exit(0);
						}
						system("pause");
					}
					if (x == 13 && z == 3)
						exit(0);
					switch (x)
					{
					case 72: z--;
						break;
					case 80: z++;
						break;
					}
					if (z < 1)
						z = 4;
					if (z > 4)
						z = 1;
					switch (z)
					{
					case 1:system("CLS");
						cout << "[Show balance]" << endl;
						cout << "Top up" << endl;
						cout << "Withdraw" << endl;
						cout << "Exit" << endl;
						break;
					case 2: system("CLS");
						cout << "Show balance" << endl;
						cout << "[Top up]" << endl;
						cout << "[Withdraw]" << endl;
						cout << "Exit" << endl;
						break;
					case 3:system("CLS");
						cout << "Show balance" << endl;
						cout << "Top up" << endl;
						cout << "[Withdraw]" << endl;
						cout << "Exit" << endl;
						break;
					case 4:system("CLS");
						cout << "Show balance" << endl;
						cout << "Top up" << endl;
						cout << "Withdraw" << endl;
						cout << "[Exit]" << endl;
						break;
					}
				}
			}
		};
	};
}
using namespace Bankomat;
void main()
{
	srand(time(0));

	Bank::Bank b;
	b.menu();
}

