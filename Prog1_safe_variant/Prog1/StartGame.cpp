#include "PlayField.h"

using json = nlohmann::json;

void PressStart(string var2, Game play, string name1, string name2)
{
	PlayField GameStart;
	CleverGamer cleverplayer1;
	RealGamer realplayer1;
	RandomGamer randomplayer1;
	Gamers Draw;
	nlohmann::json j1{};
	if (var2[0] == '1')
	{
		size_t checker = 0;
		int check = 0;
		GameStart.StartGame(name1, name2);
		GameStart.DrawPlayField(GameStart.place);
		for (play.amount_moves = 0; play.amount_moves < NUMBER_OF_FIELDS; play.amount_moves++)
		{
			check = realplayer1.FindAndMakePossibleMoves(play.amount_moves, GameStart.NumberVariations, play, GameStart.place);

			GameStart.DrawPlayField(GameStart.place);
			checker = play.WinCheck(GameStart.NumberVariations);
			if (checker == CROSS)
			{
				cout << "First player won" << endl;
				j1["name_winner"] = name1;
				j1["playing_field"] = GameStart.NumberVariations;
				j1["amount_moves"] = play.amount_moves;
				cout << "Congratulations: " << j1["name_winner"].get<string>();


				break;
			}
			if (checker == CIRCLE)
			{
				cout << "Second player won" << endl;
				j1["name_winner"] = name2;
				j1["playing_field"] = GameStart.NumberVariations;
				j1["amount_moves"] = play.amount_moves;
				cout << "Congratulations: " << j1["name_winner"].get<string>();
				break;
			}
		}
		if (play.amount_moves == 9)
		{
			cout << "Draw" << endl;
		}
	}
	if (var2[0] == '2')
	{
		cout << endl << "Choose, who is going to draw cross first: " << endl;
		cout << "1 - his purpose not to lose" << endl;
		cout << "2 - his moves are random" << endl;
		int choose = 0;
		int checker = 0;
		int checker2 = 0;
		int move = 0;
		cin >> choose;
		if (choose == 1)
		{
			GameStart.StartGame(name1, name2);
			while (play.amount_moves != 9)
			{
				checker2 = cleverplayer1.MakeMoveCleverGamer(play.amount_moves, GameStart.NumberVariations, GameStart.place);
				GameStart.DrawPlayField(GameStart.place);
				checker = play.WinCheck(GameStart.NumberVariations);
				if (checker == CROSS)
				{
					cout << "First player won" << endl;
					j1["name_winner"] = name1;
					j1["playing_field"] = GameStart.NumberVariations;
					j1["amount_moves"] = play.amount_moves;
					cout << "Congratulations: " << j1["name_winner"].get<string>();
					break;
				}
				if (checker == CIRCLE)
				{
					cout << "Second player won" << endl;
					j1["name_winner"] = name2;
					j1["playing_field"] = GameStart.NumberVariations;
					j1["amount_moves"] = play.amount_moves;
					cout << "Congratulations: " << j1["name_winner"].get<string>();
					break;
				}
				Sleep(500);
				play.amount_moves++;
				if (play.amount_moves == 9)
				{
					break;
				}

				move = randomplayer1.FindPossibleRandMoves(GameStart.NumberVariations);
				randomplayer1.MakePossibleRandMoves(play.amount_moves, GameStart.NumberVariations, move, GameStart.place);
				GameStart.DrawPlayField(GameStart.place);
				checker = play.WinCheck(GameStart.NumberVariations);
				if (checker == CROSS)
				{
					cout << "First player won" << endl;
					j1["name_winner"] = name1;
					j1["playing_field"] = GameStart.NumberVariations;
					j1["amount_moves"] = play.amount_moves;
					cout << "Congratulations: " << j1["name_winner"].get<string>();
					break;
				}
				if (checker == CIRCLE)
				{
					cout << "Second player won" << endl;
					j1["name_winner"] = name2;
					j1["playing_field"] = GameStart.NumberVariations;
					j1["amount_moves"] = play.amount_moves;
					cout << "Congratulations: " << j1["name_winner"].get<string>();
					break;
				}
				Sleep(500);
				play.amount_moves++;
			}
			if (play.amount_moves == 9)
			{
				cout << "Draw";
			}
		}
		if (choose == 2)
		{
			GameStart.StartGame(name1, name2);
			while (play.amount_moves != 9)
			{
				move = randomplayer1.FindPossibleRandMoves(GameStart.NumberVariations);
				randomplayer1.MakePossibleRandMoves(play.amount_moves, GameStart.NumberVariations, move, GameStart.place);
				GameStart.DrawPlayField(GameStart.place);
				checker = play.WinCheck(GameStart.NumberVariations);
				if (checker == CROSS)
				{
					cout << "First player won" << endl;
					j1["name_winner"] = name1;
					j1["playing_field"] = GameStart.NumberVariations;
					j1["amount_moves"] = play.amount_moves;
					cout << "Congratulations: " << j1["name_winner"].get<string>();
					break;
				}
				if (checker == CIRCLE)
				{
					cout << "Second player won" << endl;
					j1["name_winner"] = name2;
					j1["playing_field"] = GameStart.NumberVariations;
					j1["amount_moves"] = play.amount_moves;
					cout << "Congratulations: " << j1["name_winner"].get<string>();
					break;
				}
				Sleep(500);
				play.amount_moves++;
				if (play.amount_moves == 9)
				{
					break;
				}
				checker2 = cleverplayer1.MakeMoveCleverGamer(play.amount_moves, GameStart.NumberVariations, GameStart.place);
				GameStart.DrawPlayField(GameStart.place);
				checker = play.WinCheck(GameStart.NumberVariations);
				if (checker == CROSS)
				{
					cout << "First player won" << endl;
					j1["name_winner"] = name1;
					j1["playing_field"] = GameStart.NumberVariations;
					j1["amount_moves"] = play.amount_moves;
					cout << "Congratulations: " << j1["name_winner"].get<string>();
					break;
				}
				if (checker == CIRCLE)
				{
					cout << "Second player won" << endl;
					j1["name_winner"] = name2;
					j1["playing_field"] = GameStart.NumberVariations;
					j1["amount_moves"] = play.amount_moves;
					cout << "Congratulations: " << j1["name_winner"].get<string>();
					break;
				}
				Sleep(500);
				play.amount_moves++;
			}
			if (
				play.amount_moves == 9)
			{
				cout << "Draw";
			}
		}
	}


	string serializedString = j1.dump();
	nlohmann::json j2 = nlohmann::json::parse(serializedString);

	cout << setw(4) << j2 << endl;


}

string FirstMenu()
{
	string var2;
	cout << "Choose variations of the game: " << endl;
	cout << "1 - Play alone" << endl;
	cout << "2 - Automatic game" << endl;
	cin >> var2;
	return(var2);
}

