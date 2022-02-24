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
		throw exception("���� �� ����� ���� ������!\n");

	//BM
	f.write("BM", 2);

	//���������� �������
	Page = n / Length;
	if (n % Length != 0) Page += 1;
	//���������� ��������� �� ��������� ��������
	int difference = Page * Length - n;

	//������
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

	//������ ��������� ��������
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
	if (!f.is_open()) // ���� ���� �� ������
		throw exception("���� �� ����� ���� ������!\n");

	int buff;
	bool buf[300];
	int j;

	//����� �����
	f.seekg(0, std::ios::end);
	int d = f.tellg();
	Page = (d - 2) / (512 - Ostatok);
	if ((d - 2) % (512 - Ostatok)) Page++;
	//��� ����� ��

	f.seekg(2, ios::beg);
	for (int i = p; i < Page; i++)
	{
		j = 0;
		cout << "\n�������� �" << i + 1 << endl;
		cout << "\n����������� �������� (1 - ������� ����, 0 - �������� ���):" << endl;
		for (int i = 0; i < Length; i++)
		{
			f.read(reinterpret_cast<char*>(&buf[i]), 1);
			if (buf[i]) j++;
			cout << buf[i] << " ";


		}
		cout << "\n�������� ���������:" << endl;
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

	cout << "��� �����: " << endl;
	string FName; 
	cin >> FName;

	int k;
	cout << "�������� ����?" << endl;
	cin >> k;

	if (k == true)
	{
		cout << "���-�� ��������� =  " << endl;
		unsigned int n; //���-�� �������

		while (true)
		{
			cin >> n;
			if (n >= 10000) cout << "������������ �����" << endl;
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
		cout << "��� ������� � ������? :" << endl;
		cout << "1 �������" << endl;
		cout << "2 �����" << endl;
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
				cout << "������������ ����" << endl;
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

