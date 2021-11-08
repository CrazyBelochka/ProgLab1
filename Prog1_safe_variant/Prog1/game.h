#include <iostream>
#include <clocale>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <limits>
#include <nlohmann/json.hpp>
#include <vector>
#include <iomanip>
//#include "../Prog1/Graphics/MyForm.h"

enum PlayingOportunity
{
	EMPTY, CROSS, CIRCLE
};

const unsigned int HEIGHT_PLAYFIELD = 24;
const unsigned int ARRAY_LENGTH = 73;
const unsigned int ARRAY_HEIGHT = 25;
const unsigned int NUMBER_OF_FIELDS = 9;
using namespace std;


class Game
{
public:
	int WinCheck(int NumberVariations[NUMBER_OF_FIELDS])
	{
		if (((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 1))\
			|| (NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 1)\
			|| (NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 1)\
			|| (NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 1)\
			|| (NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 1))
		{
			return(CROSS);
		}
		if (((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 2))\
			|| (NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 2)\
			|| (NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 2)\
			|| (NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 2)\
			|| (NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 2))
		{
			return(CIRCLE);
		}
		else
		{
			return(EMPTY);
		}
	}

	int amount_moves = 0;
};

