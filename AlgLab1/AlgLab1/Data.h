#pragma once
#include <ctime>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <string>
//#include "stdafx.h"

using namespace std;

const unsigned int Length = 512 / (sizeof(int));

const unsigned int Ostatok = 512 - Length * (sizeof(int)+ 1);


struct List
{
	bool status;//���������������
	int num;//����� ��������
	int time;//����� ������ � �������������
	bool* bitMap;// ������ ������� ����
	int* list;// ������ ��������
public:
	List()
	{
		status = 0;
		num = 0;
		time = 0;
		bitMap = new bool[Length];
		for (int i = 0; i < Length; i++)
		{
			bitMap[i] = false;
		}
		list = new int[Length];
	}
	~List()
	{
		delete[]bitMap;
		delete[]list;
	}

};

class Data
{
private:
	List* list;//����� �������
	string file;//��� �����
public:
	unsigned int Page;
	Data(string file);

	~Data();
protected:
	void Load(int num, int i);//�������� � ����
};
