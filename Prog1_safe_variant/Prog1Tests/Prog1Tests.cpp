#include "pch.h"
#include "CppUnitTest.h"
#include "../Prog1/game.h"
#include "../Prog1/Gamers.h"
#include "../Prog1/Interface.h"
#include "../Prog1/PlayField.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Prog1Tests
{
	TEST_CLASS(GameClass)
	{
	public:
		int NumberVariations[NUMBER_OF_FIELDS] = { 0 };
		char place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
		Game play;
		PlayField GameStart;
		CleverGamer cleverplayer1;
		RealGamer realplayer1;
		RandomGamer randomplayer1;
		TEST_METHOD(Checker_of_win)
		{
			NumberVariations[0] = 1;
			NumberVariations[1] = 1;
			NumberVariations[2] = 1;
			Assert::AreEqual(1, play.WinCheck(NumberVariations));
			NumberVariations[0] = 2;
			NumberVariations[1] = 2;
			NumberVariations[2] = 2;
			Assert::AreEqual(2, play.WinCheck(NumberVariations));
			NumberVariations[0] = 1;
			NumberVariations[1] = 2;
			NumberVariations[2] = 2;
			Assert::AreEqual(0, play.WinCheck(NumberVariations));
		}
		
		TEST_METHOD(Find_possible_rand_moves)//оптимизация
		{		
			NumberVariations[0] = 1;
			NumberVariations[1] = 1;
			NumberVariations[2] = 2;
			NumberVariations[3] = 1;
			NumberVariations[4] = 2;
			NumberVariations[5] = 1;
			NumberVariations[6] = 2;
			NumberVariations[7] = 1;
			Assert::AreEqual(8, randomplayer1.FindPossibleRandMoves(NumberVariations));
			NumberVariations[0] = 1;
			NumberVariations[1] = 1;
			NumberVariations[2] = 2;
			NumberVariations[3] = 1;
			NumberVariations[4] = 2;
			NumberVariations[5] = 1;
			NumberVariations[6] = 2;
			NumberVariations[7] = 0;
			NumberVariations[8] = 1;
			Assert::AreEqual(7, randomplayer1.FindPossibleRandMoves(NumberVariations));


		}
		TEST_METHOD(Find_move_clever_gamer)
		{
			int amount_moves = 3;
			NumberVariations[4] = 1;
			NumberVariations[5] = 1;
			Assert::AreEqual(2, cleverplayer1.MakeMoveCleverGamer(amount_moves, NumberVariations, place));
			amount_moves = 4;
			NumberVariations[0] = 1;
			NumberVariations[1] = 1;
			Assert::AreEqual(1, cleverplayer1.MakeMoveCleverGamer(amount_moves, NumberVariations, place));
		}

	};
}
