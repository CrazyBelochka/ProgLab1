#include "PlayField.h"

void PressStart(string var2, Game play, string name1, string name2);

string FirstMenu();



int main()
{
	nlohmann::json j{};
	Game play;
	Gamers g1, g2;
	setlocale(LC_ALL, "Russian");
	g1.name = "Roma ";
	g2.name = "Nikita ";
	j["name1"] = g1.name;
	j["name2"] = g2.name;
	j["var2"] = FirstMenu();
	PressStart(j["var2"].get<string>(), play, j["name1"].get<string>() , j["name2"].get<string>());
}
