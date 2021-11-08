#include "Gamers.h"

class PlayField
{
	public:
	void DrawPlayField(char place[ARRAY_LENGTH][ARRAY_HEIGHT])
	{
		for (size_t y = 0; y < 1; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				place[x][y] = '_';
			}
		}


		for (size_t y = 1; y < ARRAY_HEIGHT - 16; y++)
		{
			place[1][y] = '|';
			place[23][y] = '|';
			place[47][y] = '|';
			place[72][y] = '|';
		}
		for (size_t y = 8; y < 9; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				place[x][y] = '_';
			}
		}


		for (size_t y = 9; y < ARRAY_HEIGHT - 8; y++)
		{
			place[1][y] = '|';
			place[23][y] = '|';
			place[47][y] = '|';
			place[72][y] = '|';
		}
		for (size_t y = 16; y < 17; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				place[x][y] = '_';
			}
		}


		for (size_t y = 16; y < ARRAY_HEIGHT; y++)
		{
			place[1][y] = '|';
			place[23][y] = '|';
			place[47][y] = '|';
			place[72][y] = '|';
		}
		for (size_t y = 24; y < 25; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				place[x][y] = '_';
			}
		}



		for (size_t y = 0; y < ARRAY_HEIGHT; y++)
		{
			for (size_t x = 0; x < ARRAY_LENGTH; x++)
			{
				if (place[x][y] == false)
				{
					cout << " ";
				}
				cout << place[x][y];
			}
			cout << endl;
		}
	}

	void StartGame(string name1, string name2)
	{
		cout << "			   Game Begins!" << endl;
		cout << name1 << "								" << name2 << endl;
	}

	char place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
	int NumberVariations[NUMBER_OF_FIELDS] = { 0 };
};
