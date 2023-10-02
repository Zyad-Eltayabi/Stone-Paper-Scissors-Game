#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

enum enGameTools { Paper = 1, Stone = 2, Scissor = 3 };

enum enGameResult { Player = 1, Computer = 2, NoWinner = 3 };

int fn_ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int fn_RandomNumber(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

enGameTools fn_ComSelection()
{
	return (enGameTools)fn_RandomNumber(1, 3);
}

enGameTools fn_UserSelection()
{
	int UserSelection = 0;

	cout << "Your Choice:: [1]:Paper , [2]:Stone, [3]:Scissor ? \n";
	cin >> UserSelection;

	return (enGameTools)UserSelection;
}

string fn_PrintComAndUserSelection(enGameTools SelectionNumber)
{
	switch (SelectionNumber)
	{
	case Paper:
		return "Paper";
	case Stone:
		return "Stone";
	case Scissor:
		return "Scissor";
	default:
		return "Invaild Selection";
	}
}

enGameResult fn_GameResult(enGameTools Player, enGameTools Com)
{
	if (Player == Com)
	{
		return enGameResult::NoWinner;
	}
	else if (Player == Paper && Com == Stone)
	{
		return enGameResult::Player;
	}
	else if (Player == Paper && Com == Scissor)
	{
		return enGameResult::Computer;
	}
	else if (Player == Stone && Com == Paper)
	{
		return enGameResult::Computer;
	}
	else if (Player == Stone && Com == Scissor)
	{
		return enGameResult::Player;
	}
	else if (Player == Scissor && Com == Paper)
	{
		return enGameResult::Player;
	}
	else
	{
		return enGameResult::Computer;
	}
}

string fn_WhoISTheWinner(enGameResult Winner)
{
	switch (Winner)
	{
	case enGameResult::Player:
		return "Player";
	case enGameResult::Computer:
		return "Computer";
	case enGameResult::NoWinner:
		return "No Winner";
	}
}

void fn_ResultColor(string Winner)
{
	if (Winner == "Player")
		system("color 2D");

	else if (Winner == "Computer")
		system("color 4E");

	else
		system("color 6D");
}

void fn_RoundDetails(int& RoundsNumber, int& PlayerWins, int& ComWins)
{
	RoundsNumber = fn_ReadPositiveNumber("How Many Rounds 1 to 10 ?");

	enGameTools UserSelection;
	enGameTools ComSelection;

	for (int i = 1; i <= RoundsNumber; i++)
	{
		cout << "\nRound [" << i << "]  begins:" << endl;

		UserSelection = fn_UserSelection();
		ComSelection = fn_ComSelection();

		cout << "________________________Round [" << i << "] ________________" << endl;

		cout << "\nPlayer Choice :" << fn_PrintComAndUserSelection(UserSelection) << endl;
		cout << "Computer Choice :" << fn_PrintComAndUserSelection(ComSelection) << endl;
		cout << "Round Winner    :" << "[ " << fn_WhoISTheWinner(fn_GameResult(UserSelection, ComSelection)) << " ]" << endl;

		cout << "___________________________________________________" << endl;

		fn_ResultColor(fn_WhoISTheWinner(fn_GameResult(UserSelection, ComSelection)));

		if (fn_WhoISTheWinner(fn_GameResult(UserSelection, ComSelection)) == "Player")
		{
			++PlayerWins;
		}
		else if (fn_WhoISTheWinner(fn_GameResult(UserSelection, ComSelection)) == "Computer")
		{
			++ComWins;
		}
	}
}

string fn_EndGameResultTitle(int PlayerWins, int ComWins)
{
	if (PlayerWins > ComWins)
		return "The Player Won :-)";
	else if (PlayerWins == ComWins)
		return "Draw";
	else
		return " G a m e   O v e r :-( ";
}
string fn_FinalWinner(int PlayerWins, int ComWins)
{

	if (PlayerWins > ComWins)
		return "Player";
	else if (PlayerWins == ComWins)
		return "Draw";
	else
		return "Computer";
}

void fn_EndGameResult()
{
	int RoundsNumber = 0, PlayerWins = 0, ComWins = 0;

	fn_RoundDetails(RoundsNumber, PlayerWins, ComWins);

	cout << "\n";

	cout << "\n\t\t\t\t______________________________________________\n";
	cout << "\n\t\t\t\t\t+++" << fn_EndGameResultTitle(PlayerWins, ComWins) << "+++" << endl;
	cout << "\t\t\t\t______________________________________________\n";
	cout << "\n\t\t\t\t_______________" << "[ Game Result ]" << "_______________" << endl;

	cout << "\n\t\t\t\t Game Rounds        : " << RoundsNumber << endl;
	cout << "\t\t\t\t Player won times   : " << PlayerWins << endl;
	cout << "\t\t\t\t Computer won times : " << ComWins << endl;
	cout << "\t\t\t\t Draw times         : " << RoundsNumber - (PlayerWins + ComWins) << endl;
	cout << "\t\t\t\t Final Winner       : " << fn_FinalWinner(PlayerWins, ComWins) << endl;

	cout << "\t\t\t\t______________________________________________\n";

}

void fn_StartGame()
{
	char NewGame = 'Y';

	do
	{
		system("color 07");
		system("cls");

		fn_EndGameResult();

		cout << "\n\t\t\t\t Do you want to play again? Y/N ?  ";
		cin >> NewGame;


	} while (NewGame == 'Y' || NewGame == 'y');
}


int main()
{
	//Generate a random number
	srand((unsigned)time(NULL));

	fn_StartGame();

}