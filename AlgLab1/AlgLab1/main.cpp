#include <ctime>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <string>
#include "Data.h";
//#include "stdafx.h"

using namespace std;

unsigned int Page;

void Input(string file, int n)
{
	srand(time(NULL));
	int random;

	ofstream f(file, ios::binary | ios_base::trunc);
	if (!f.is_open())
		throw exception("Файл не может быть открыт!\n");

	//BM
	f.write("BM", 2);

	//количество страниц
	Page = n / Length;
	if (n % Length != 0) Page += 1;
	//количество элементов на последней странице
	int difference = Page * Length - n;

	//запись
	for (int i = 0; i < Page - 1; i++)
	{
		bool buf = 1;
		for (int j = 0; j < Length; j++)
		{
			f.write(reinterpret_cast<char*>(&buf), 1);
		}
		for (int j = 0; j < Length; j++)
		{
			random = rand() % 10;
			f.write(reinterpret_cast<char*>(&random), 4);
		}
	}

	//запись последней страницы
	for (int j = 0; j < Length - difference; j++)
	{
		bool buf = 1;
		f.write(reinterpret_cast<char*>(&buf), 1);
	}
	for (int j = 0; j < difference; j++)
	{
		bool buf = 0;
		f.write(reinterpret_cast<char*>(&buf), 1);
	}
	for (int j = 0; j < Length - difference; j++)
	{
		random = rand() % 10;
		f.write(reinterpret_cast<char*>(&random), 4);
	}

	f.close();
}

void Output(string file, int p)
{
	ifstream f(file, ios::binary);
	if (!f.is_open()) // если файл не открыт
		throw exception("Файл не может быть открыт!\n");

	int buff;
	bool buf[300];
	int j;

	//длина файла
	f.seekg(0, std::ios::end);
	int d = f.tellg();
	Page = (d - 2) / (512 - Ostatok);
	if ((d - 2) % (512 - Ostatok)) Page++;
	//без учета БМ

	f.seekg(2, ios::beg);
	for (int i = p; i < Page; i++)
	{
		j = 0;
		cout << "\nСтраница №" << i + 1 << endl;
		cout << "\nЗаполненные элементы (1 - элемент есть, 0 - элемента нет):" << endl;
		for (int i = 0; i < Length; i++)
		{
			f.read(reinterpret_cast<char*>(&buf[i]), 1);
			if (buf[i]) j++;
			cout << buf[i] << " ";


		}
		cout << "\nЗначение элементов:" << endl;
		for (int i = 0; i < Length; i++)
		{
			f.read(reinterpret_cast<char*>(&buff), 4);
			if (buf[i])
				cout << "[" << buff << "]";
			if ((i + 1) % 20 == 1) cout << endl;
		}
	}
	cout << endl;
	f.close();
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int random;

	cout << "Имя файла: " << endl;
	string FName; 
	cin >> FName;

	int k;
	cout << "Записать файл?" << endl;
	cin >> k;

	if (k == true)
	{
		cout << "Кол-во элементов =  " << endl;
		unsigned int n; //кол-во записей

		while (true)
		{
			cin >> n;
			if (n >= 10000) cout << "Недостаточно места" << endl;
			else break;
		}
		try
		{
			Input(FName, n);
		}
		catch (exception error)
		{
			cout << error.what() << endl;
		}
	}

	int i = 0;


	Data d(FName);


	while (1)
	{
		cout << endl;
		cout << "Что сделать с файлом? :" << endl;
		cout << "1 вывести" << endl;
		cout << "2 выход" << endl;
		cout << endl;
		int i = 0;
		try
		{
			cin >> i;
			switch (i)
			{
			case 1:
			{
				Output(FName, 0);
			}break;
			case 2:
			{
				exit(0);
				break;
			}break;


			
			default:
			{
				cout << "Неккоректный ввод" << endl;
				cin >> i;
			}break;
			}
		}
		catch (exception error)
		{
			cout << error.what() << endl;
		}
	}
}

