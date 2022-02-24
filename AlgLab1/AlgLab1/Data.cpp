#include "Data.h";


Data::Data(string file)
{
	this->file = file;
	list = new List[2];
}



void Data::Load(int num, int i)
{
	fstream f(file, ofstream::in | ofstream::out | ios::binary);
	if (!f.is_open()) // если файл не открыт
		throw exception("Файл не может быть открыт!\n");

	if (list[i].status == false) throw exception("Страница не загружена в оперативную память");

	f.seekg(2 + 5 * Length * (num - 1), std::ios::beg);

	for (int j = 0; j < Length; j++)
	{
		f.write(reinterpret_cast<char*>(&list[i].bitMap[j]), 1);
	}
	for (int j = 0; j < Length; j++)
	{
		if (list[i].bitMap[j])
			f.write(reinterpret_cast<char*>(&list[i].list[j]), 4);
	}
	f.close();
}

Data::~Data()
{
	delete[]list;
}

