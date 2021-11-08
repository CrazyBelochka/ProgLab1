#include "game.h"


class Gamers
{
public:
	string name;

protected:
	void PutCrossInPlace(char place[ARRAY_LENGTH][ARRAY_HEIGHT], int x, int y)
	{
		place[x - 3][y - 3] = '0';
		place[x + 3][y - 3] = '0';
		place[x - 2][y - 2] = '0';
		place[x + 2][y - 2] = '0';
		place[x - 1][y - 1] = '0';
		place[x + 1][y - 1] = '0';
		place[x][y] = '0';
		place[x - 1][y + 1] = '0';
		place[x + 1][y + 1] = '0';
		place[x - 2][y + 2] = '0';
		place[x + 2][y + 2] = '0';
		place[x - 3][y + 3] = '0';
		place[x + 3][y + 3] = '0';
	}

	void PutCircleInPlace(char place[ARRAY_LENGTH][ARRAY_HEIGHT], int x, int y)
	{
		place[x - 1][y - 3] = '0';
		place[x][y - 3] = '0';
		place[x + 1][y - 3] = '0';
		place[x - 2][y - 2] = '0';
		place[x + 2][y - 2] = '0';
		place[x - 3][y - 2] = '0';
		place[x + 3][y - 2] = '0';
		place[x - 4][y - 1] = '0';
		place[x + 4][y - 1] = '0';
		place[x - 4][y] = '0';
		place[x + 4][y] = '0';
		place[x - 4][y + 1] = '0';
		place[x + 4][y + 1] = '0';
		place[x - 2][y + 2] = '0';
		place[x + 2][y + 2] = '0';
		place[x - 3][y + 2] = '0';
		place[x + 3][y + 2] = '0';
		place[x - 1][y + 3] = '0';
		place[x][y + 3] = '0';
		place[x + 1][y + 3] = '0';
	}
};

class CleverGamer : public Gamers
{
public:
	int MakeMoveCleverGamer(int amount_moves, int NumberVariations[NUMBER_OF_FIELDS], char place[ARRAY_LENGTH][ARRAY_HEIGHT])
	{
		if (amount_moves % 2 == 0)
		{
			if ((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CROSS;
				PutCrossInPlace(place, 58, 4);
				return(CROSS);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[2] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CROSS;
				PutCrossInPlace(place, 12, 4);
				return(CROSS);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[2] == 1) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = CROSS;
				PutCrossInPlace(place, 35, 4);
				return(CROSS);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = CROSS;
				PutCrossInPlace(place, 58, 12);
				return(CROSS);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[5] == 1) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = CROSS;
				PutCrossInPlace(place, 12, 12);
				return(CROSS);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[5] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CROSS;
				PutCrossInPlace(place, 35, 12);
				return(CROSS);
			}
			if ((NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CROSS;
				PutCrossInPlace(place, 58, 20);
				return(CROSS);
			}
			if ((NumberVariations[7] == 1) && (NumberVariations[8] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CROSS;
				PutCrossInPlace(place, 12, 20);
				return(CROSS);
			}
			if ((NumberVariations[6] == 1) && (NumberVariations[8] == 1) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = CROSS;
				PutCrossInPlace(place, 35, 20);
				return(CROSS);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CROSS;
				PutCrossInPlace(place, 12, 20);
				return(CROSS);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[6] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CROSS;
				PutCrossInPlace(place, 12, 4);
				return(CROSS);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[6] == 1) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = CROSS;
				PutCrossInPlace(place, 12, 12);
				return(CROSS);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = CROSS;
				PutCrossInPlace(place, 35, 20);
				return(CROSS);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[7] == 1) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = CROSS;
				PutCrossInPlace(place, 35, 4);
				return(CROSS);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[7] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CROSS;
				PutCrossInPlace(place, 35, 12);
				return(CROSS);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CROSS;
				PutCrossInPlace(place, 58, 20);
				return(CROSS);
			}
			if ((NumberVariations[5] == 1) && (NumberVariations[8] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CROSS;
				PutCrossInPlace(place, 58, 4);
				return(CROSS);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[8] == 1) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = CROSS;
				PutCrossInPlace(place, 58, 12);
				return(CROSS);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CROSS;
				PutCrossInPlace(place, 58, 20);
				return(CROSS);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[8] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CROSS;
				PutCrossInPlace(place, 12, 4);
				return(CROSS);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[8] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CROSS;
				PutCrossInPlace(place, 35, 12);
				return(CROSS);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CROSS;
				PutCrossInPlace(place, 12, 20);
				return(CROSS);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[6] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CROSS;
				PutCrossInPlace(place, 58, 4);
				return(CROSS);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[6] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CROSS;
				PutCrossInPlace(place, 35, 12);
				return(CROSS);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CROSS;
				PutCrossInPlace(place, 58, 4);
				return(CROSS);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[2] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CROSS;
				PutCrossInPlace(place, 12, 4);
				return(CROSS);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[2] == 2) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = CROSS;
				PutCrossInPlace(place, 35, 4);
				return(CROSS);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = CROSS;
				PutCrossInPlace(place, 58, 12);
				return(CROSS);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[5] == 2) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = CROSS;
				PutCrossInPlace(place, 12, 12);
				return(CROSS);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[5] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CROSS;
				PutCrossInPlace(place, 35, 12);
				return(CROSS);
			}
			if ((NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CROSS;
				PutCrossInPlace(place, 58, 20);
				return(CROSS);
			}
			if ((NumberVariations[7] == 2) && (NumberVariations[8] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CROSS;
				PutCrossInPlace(place, 12, 20);
				return(CROSS);
			}
			if ((NumberVariations[6] == 2) && (NumberVariations[8] == 2) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = CROSS;
				PutCrossInPlace(place, 35, 20);
				return(CROSS);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CROSS;
				PutCrossInPlace(place, 12, 20);
				return(CROSS);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[6] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CROSS;
				PutCrossInPlace(place, 12, 4);
				return(CROSS);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[6] == 2) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = CROSS;
				PutCrossInPlace(place, 12, 12);
				return(CROSS);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = CROSS;
				PutCrossInPlace(place, 35, 20);
				return(CROSS);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[7] == 2) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = CROSS;
				PutCrossInPlace(place, 35, 4);
				return(CROSS);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[7] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CROSS;
				PutCrossInPlace(place, 35, 12);
				return(CROSS);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CROSS;
				PutCrossInPlace(place, 58, 20);
				return(CROSS);
			}
			if ((NumberVariations[5] == 2) && (NumberVariations[8] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CROSS;
				PutCrossInPlace(place, 58, 4);
				return(CROSS);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[8] == 2) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = CROSS;
				PutCrossInPlace(place, 58, 12);
				return(CROSS);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CROSS;
				PutCrossInPlace(place, 58, 20);
				return(CROSS);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[8] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CROSS;
				PutCrossInPlace(place, 12, 4);
				return(CROSS);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[8] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CROSS;
				PutCrossInPlace(place, 35, 12);
				return(CROSS);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CROSS;
				PutCrossInPlace(place, 12, 20);
				return(CROSS);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[6] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CROSS;
				PutCrossInPlace(place, 58, 4);
				return(CROSS);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[6] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CROSS;
				PutCrossInPlace(place, 35, 12);
				return(CROSS);
			}
			int move = 0;
			size_t k = 0;
			for (size_t i = 0; i < 3; i++)
			{
				srand((unsigned int)time(0));
				move = rand() % 9;
				if (NumberVariations[move] == 0)
				{
					k = 1;
					break;
				}
			}
			if (k == 0)
			{
				for (size_t i = 0; i < NUMBER_OF_FIELDS; i++)
				{
					if (NumberVariations[i] == 0)
					{
						move = i;
						break;
					}
				}
			}
			if (NumberVariations[move] == 0)
			{
				NumberVariations[move] = CROSS;
				switch (move + 1)
				{
				case 1:
					PutCrossInPlace(place, 12, 4);
					break;
				case 2:
					PutCrossInPlace(place, 35, 4);
					break;
				case 3:
					PutCrossInPlace(place, 58, 4);
					break;
				case 4:
					PutCrossInPlace(place, 12, 12);
					break;
				case 5:
					PutCrossInPlace(place, 35, 12);
					break;
				case 6:
					PutCrossInPlace(place, 58, 12);
					break;
				case 7:
					PutCrossInPlace(place, 12, 20);
					break;
				case 8:
					PutCrossInPlace(place, 35, 20);
					break;
				case 9:
					PutCrossInPlace(place, 58, 20);
					break;

				default:
					break;
				}
			}
			return(amount_moves);
		}

		if (amount_moves % 2 == 1)
		{
			if ((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CIRCLE;
				PutCircleInPlace(place, 58, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[2] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CIRCLE;
				PutCircleInPlace(place, 12, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[2] == 2) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = CIRCLE;
				PutCircleInPlace(place, 35, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = CIRCLE;
				PutCircleInPlace(place, 58, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[5] == 2) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = CIRCLE;
				PutCircleInPlace(place, 12, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[5] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CIRCLE;
				PutCircleInPlace(place, 35, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CIRCLE;
				PutCircleInPlace(place, 58, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[7] == 2) && (NumberVariations[8] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CIRCLE;
				PutCircleInPlace(place, 12, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[6] == 2) && (NumberVariations[8] == 2) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = CIRCLE;
				PutCircleInPlace(place, 35, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CIRCLE;
				PutCircleInPlace(place, 12, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[6] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CIRCLE;
				PutCircleInPlace(place, 12, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[6] == 2) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = CIRCLE;
				PutCircleInPlace(place, 12, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = CIRCLE;
				PutCircleInPlace(place, 35, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[7] == 2) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = CIRCLE;
				PutCircleInPlace(place, 35, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[7] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CIRCLE;
				PutCircleInPlace(place, 35, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CIRCLE;
				PutCircleInPlace(place, 58, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[5] == 2) && (NumberVariations[8] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CIRCLE;
				PutCircleInPlace(place, 58, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[8] == 2) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = CIRCLE;
				PutCircleInPlace(place, 58, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CIRCLE;
				PutCircleInPlace(place, 58, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[8] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CIRCLE;
				PutCircleInPlace(place, 12, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[8] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CIRCLE;
				PutCircleInPlace(place, 35, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CIRCLE;
				PutCircleInPlace(place, 12, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[6] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CIRCLE;
				PutCircleInPlace(place, 58, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[6] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CIRCLE;
				PutCircleInPlace(place, 35, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CIRCLE;
				PutCircleInPlace(place, 58, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[2] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CIRCLE;
				PutCircleInPlace(place, 12, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[2] == 1) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = CIRCLE;
				PutCircleInPlace(place, 35, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = CIRCLE;
				PutCircleInPlace(place, 58, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[5] == 1) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = CIRCLE;
				PutCircleInPlace(place, 12, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[5] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CIRCLE;
				PutCircleInPlace(place, 35, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CIRCLE;
				PutCircleInPlace(place, 58, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[7] == 1) && (NumberVariations[8] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CIRCLE;
				PutCircleInPlace(place, 12, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[6] == 1) && (NumberVariations[8] == 1) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = CIRCLE;
				PutCircleInPlace(place, 35, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CIRCLE;
				PutCircleInPlace(place, 12, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[6] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CIRCLE;
				PutCircleInPlace(place, 12, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[6] == 1) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = CIRCLE;
				PutCircleInPlace(place, 12, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = CIRCLE;
				PutCircleInPlace(place, 35, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[7] == 1) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = CIRCLE;
				PutCircleInPlace(place, 35, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[7] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CIRCLE;
				PutCircleInPlace(place, 35, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CIRCLE;
				PutCircleInPlace(place, 58, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[5] == 1) && (NumberVariations[8] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CIRCLE;
				PutCircleInPlace(place, 58, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[8] == 1) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = CIRCLE;
				PutCircleInPlace(place, 58, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = CIRCLE;
				PutCircleInPlace(place, 58, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[8] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = CIRCLE;
				PutCircleInPlace(place, 12, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[8] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CIRCLE;
				PutCircleInPlace(place, 35, 12);
				return(CIRCLE);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = CIRCLE;
				PutCircleInPlace(place, 12, 20);
				return(CIRCLE);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[6] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = CIRCLE;
				PutCircleInPlace(place, 58, 4);
				return(CIRCLE);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[6] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = CIRCLE;
				PutCircleInPlace(place, 35, 12);
				return(CIRCLE);
			}
			int move = 0;
			size_t k = 0;
			for (size_t i = 0; i < 3; i++)
			{
				srand((unsigned int)time(0));
				move = rand() % 9;
				if (NumberVariations[move] == EMPTY)
				{
					k = 1;
					break;
				}
			}
			if (k == 0)
			{
				for (size_t i = 0; i < NUMBER_OF_FIELDS; i++)
				{
					if (NumberVariations[i] == EMPTY)
					{
						move = i;
						break;
					}
				}
			}
			if (NumberVariations[move] == EMPTY)
			{
				NumberVariations[move] = CIRCLE;
				switch (move + 1)
				{
				case 1:
					PutCircleInPlace(place, 12, 4);
					break;
				case 2:
					PutCircleInPlace(place, 35, 4);
					break;
				case 3:
					PutCircleInPlace(place, 58, 4);
					break;
				case 4:
					PutCircleInPlace(place, 12, 12);
					break;
				case 5:
					PutCircleInPlace(place, 35, 12);
					break;
				case 6:
					PutCircleInPlace(place, 58, 12);
					break;
				case 7:
					PutCircleInPlace(place, 12, 20);
					break;
				case 8:
					PutCircleInPlace(place, 35, 20);
					break;
				case 9:
					PutCircleInPlace(place, 58, 20);
					break;

				default:
					break;
				}
			}
		}

		return(0);
	}
};

class RandomGamer : public Gamers
{
public:
	int FindPossibleRandMoves(int NumberVariations[NUMBER_OF_FIELDS])
	{
		int move = 0;
		for (size_t i = 0; i < 3; i++)
		{
			srand((unsigned int)time(0));
			move = rand() % 9;
			if (NumberVariations[move] == EMPTY)
			{
				return(move);
			}
		}
		for (size_t i = 0; i < NUMBER_OF_FIELDS - 1; i++)
		{
			if (NumberVariations[i] == EMPTY)
			{
				return(i);
			}
		}
	}

	void MakePossibleRandMoves(int amount_moves, int NumberVariations[NUMBER_OF_FIELDS], int move, char place[ARRAY_LENGTH][ARRAY_HEIGHT])
	{
		if (amount_moves % 2 == 0)
		{
			if (NumberVariations[move] == EMPTY)
			{
				NumberVariations[move] = CROSS;
				switch (move + 1)
				{
				case 1:
					PutCrossInPlace(place, 12, 4);
					break;
				case 2:
					PutCrossInPlace(place, 35, 4);
					break;
				case 3:
					PutCrossInPlace(place, 58, 4);
					break;
				case 4:
					PutCrossInPlace(place, 12, 12);
					break;
				case 5:
					PutCrossInPlace(place, 35, 12);
					break;
				case 6:
					PutCrossInPlace(place, 58, 12);
					break;
				case 7:
					PutCrossInPlace(place, 12, 20);
					break;
				case 8:
					PutCrossInPlace(place, 35, 20);
					break;
				case 9:
					PutCrossInPlace(place, 58, 20);
					break;

				default:
					break;
				}
			}
		}
		else
		{
			if (NumberVariations[move] == EMPTY)
			{
				NumberVariations[move] = CIRCLE;
				switch (move + 1)
				{
				case 1:
					PutCircleInPlace(place, 12, 4);
					break;
				case 2:
					PutCircleInPlace(place, 35, 4);
					break;
				case 3:
					PutCircleInPlace(place, 58, 4);
					break;
				case 4:
					PutCircleInPlace(place, 12, 12);
					break;
				case 5:
					PutCircleInPlace(place, 35, 12);
					break;
				case 6:
					PutCircleInPlace(place, 58, 12);
					break;
				case 7:
					PutCircleInPlace(place, 12, 20);
					break;
				case 8:
					PutCircleInPlace(place, 35, 20);
					break;
				case 9:
					PutCircleInPlace(place, 58, 20);
					break;

				default:
					break;
				}
			}
		}
	}
};

class RealGamer : public CleverGamer
{
public:
	int FindAndMakePossibleMoves(int amount_moves, int NumberVariations[NUMBER_OF_FIELDS], Game play, char place[ARRAY_LENGTH][ARRAY_HEIGHT])
	{
		int reload = 0;
		int number = 0;
		int check = 0;

		if (amount_moves == 0)
		{
			cout << "Выберите куда нарисовать крестик:" << endl;
			cout << "0.Программа сама сделает ход" << endl;
			cout << "1.Левый верхний угол " << endl;
			cout << "2.Центральный верхний квадрат " << endl;
			cout << "3.Правый верхний угол " << endl;
			cout << "4.Левый центральный квадрат " << endl;
			cout << "5.Центральный квадрат " << endl;
			cout << "6.Правый центральный квадрат " << endl;
			cout << "7.Левый нижний угол " << endl;
			cout << "8.Центральный нижний квадрат " << endl;
			cout << "9.Правый нижний угол " << endl;
			cin >> number;
			if (number == 0)
			{
				check = MakeMoveCleverGamer(amount_moves, NumberVariations, place);
				return(CROSS);
			}
			else
			{
				NumberVariations[number - 1] = CROSS;
				switch (number)
				{
				case 1:
					PutCrossInPlace(place, 12, 4);
					return(CROSS);
				case 2:
					PutCrossInPlace(place, 35, 4);
					return(CROSS);
				case 3:
					PutCrossInPlace(place, 58, 4);
					return(CROSS);
				case 4:
					PutCrossInPlace(place, 12, 12);
					return(CROSS);
				case 5:
					PutCrossInPlace(place, 35, 12);
					return(CROSS);
				case 6:
					PutCrossInPlace(place, 58, 12);
					return(CROSS);
				case 7:
					PutCrossInPlace(place, 12, 20);
					return(CROSS);
				case 8:
					PutCrossInPlace(place, 35, 20);
					return(CROSS);
				case 9:
					PutCrossInPlace(place, 58, 20);
					return(CROSS);

				default:
					return(0);
				}
			}
		}
		if ((amount_moves != 0) && (amount_moves % 2 == 1))
		{
			cout << "Куда поставить нолик: " << endl;
			cout << "0.Программа сама сделает ход" << endl;
			if (NumberVariations[0] == 0)
			{
				cout << "1.Левый верхний угол " << endl;
			}
			if (NumberVariations[1] == 0)
			{
				cout << "2.Центральный верхний квадрат " << endl;
			}
			if (NumberVariations[2] == 0)
			{
				cout << "3.Правый верхний угол " << endl;
			}
			if (NumberVariations[3] == 0)
			{
				cout << "4.Левый центральный квадрат " << endl;
			}
			if (NumberVariations[4] == 0)
			{
				cout << "5.Центральный квадрат " << endl;
			}
			if (NumberVariations[5] == 0)
			{
				cout << "6.Правый центральный квадрат " << endl;
			}
			if (NumberVariations[6] == 0)
			{
				cout << "7.Левый нижний угол " << endl;
			}
			if (NumberVariations[7] == 0)
			{
				cout << "8.Центральный нижний квадрат " << endl;
			}
			if (NumberVariations[8] == 0)
			{
				cout << "9.Правый нижний угол " << endl;
			}
			cin >> number;

			if (number == 0)
			{
				check = MakeMoveCleverGamer(amount_moves, NumberVariations, place);
				return(CROSS);
			}
			else
			{

				if (NumberVariations[number - 1] != EMPTY)
				{
					reload = FindAndMakePossibleMoves(amount_moves, NumberVariations, play, place);
				}
				else
				{
					NumberVariations[number - 1] = CIRCLE;
					switch (number)
					{
					case 1:
						PutCircleInPlace(place, 12, 4);
						return(CIRCLE);
					case 2:
						PutCircleInPlace(place, 35, 4);
						return(CIRCLE);
					case 3:
						PutCircleInPlace(place, 58, 4);
						return(CIRCLE);
					case 4:
						PutCircleInPlace(place, 12, 12);
						return(CIRCLE);
					case 5:
						PutCircleInPlace(place, 35, 12);
						return(CIRCLE);
					case 6:
						PutCircleInPlace(place, 58, 12);
						return(CIRCLE);
					case 7:
						PutCircleInPlace(place, 12, 20);
						return(CIRCLE);
					case 8:
						PutCircleInPlace(place, 35, 20);
						return(CIRCLE);
					case 9:
						PutCircleInPlace(place, 58, 20);
						return(CIRCLE);

					default:
						return(0);
					}
				}
			}
		}
		if ((amount_moves != 0) && (amount_moves % 2 == 0))
		{
			cout << "Куда поставить крест: " << endl;
			cout << "0.Программа сама сделает ход" << endl;
			if (NumberVariations[0] == 0)
			{
				cout << "1.Левый верхний угол " << endl;
			}
			if (NumberVariations[1] == 0)
			{
				cout << "2.Центральный верхний квадрат " << endl;
			}
			if (NumberVariations[2] == 0)
			{
				cout << "3.Правый верхний угол " << endl;
			}
			if (NumberVariations[3] == 0)
			{
				cout << "4.Левый центральный квадрат " << endl;
			}
			if (NumberVariations[4] == 0)
			{
				cout << "5.Центральный квадрат " << endl;
			}
			if (NumberVariations[5] == 0)
			{
				cout << "6.Правый центральный квадрат " << endl;
			}
			if (NumberVariations[6] == 0)
			{
				cout << "7.Левый нижний угол " << endl;
			}
			if (NumberVariations[7] == 0)
			{
				cout << "8.Центральный нижний квадрат " << endl;
			}
			if (NumberVariations[8] == 0)
			{
				cout << "9.Правый нижний угол " << endl;
			}
			cin >> number;

			if (number == 0)
			{
				check = MakeMoveCleverGamer(amount_moves, NumberVariations, place);
				return(CROSS);
			}
			else
			{
				if (NumberVariations[number - 1] != EMPTY)
				{
					reload = FindAndMakePossibleMoves(amount_moves, NumberVariations, play, place);
				}
				else
				{
					NumberVariations[number - 1] = 1;
					switch (number)
					{
					case 1:
						PutCrossInPlace(place, 12, 4);
						return(CROSS);
					case 2:
						PutCrossInPlace(place, 35, 4);
						return(CROSS);
					case 3:
						PutCrossInPlace(place, 58, 4);
						return(CROSS);
					case 4:
						PutCrossInPlace(place, 12, 12);
						return(CROSS);
					case 5:
						PutCrossInPlace(place, 35, 12);
						return(CROSS);
					case 6:
						PutCrossInPlace(place, 58, 12);
						return(CROSS);
					case 7:
						PutCrossInPlace(place, 12, 20);
						return(CROSS);
					case 8:
						PutCrossInPlace(place, 35, 20);
						return(CROSS);
					case 9:
						PutCrossInPlace(place, 58, 20);
						return(CROSS);

					default:
						return(0);
					}
				}
			}
		}
	}
};


