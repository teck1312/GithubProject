// 4Gewinnt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

// IF 1 oder 0
// Eingabe
// CHECKER
// 


#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;


void Feldanzeigen(void);
void FeldInit(void);
void yourTurn(void);
void Runde(void);
void check(void);
void rundenanzahl(void);
void a1(void);
void winner(void);
void abstand(void);
void singleplayer(void);
void checkerror(void);

int turnCounter = 1;
int turnreturn = 0;
int PositionArray0 = 5;
int PositionArray1 = 5;
int PositionArray2 = 5;
int PositionArray3 = 5;
int PositionArray4 = 5;
int PositionArray5 = 5;
int PositionArray6 = 5;
int case1;
int counterRunde = 0;
int Rundenanzahl = 0; 
int punkt1 = 0;
int punkt2 = 0;
int errorcode = 0;

string spieler1;
string spieler2;
string error;

boolean s1winner = false;
boolean s2winner = false;
boolean checker = false;

char Position[6][7];

#define RED     "\033[31m"      
#define GREEN   "\033[32m"
#define WHITE   "\033[37m" 
#define YELLOW  "\033[33m" 
#define BOLDYELLOW  "\033[1m\033[33m" 


int main()
{
	singleplayer();
}


void singleplayer()  
{
	rundenanzahl();
	FeldInit();


	for (int i = 0; i < Rundenanzahl; i++)
	{
		system("cls");
		Feldanzeigen();
		while (counterRunde < 42)
		{
			counterRunde++;

			yourTurn();
			Runde();
			Feldanzeigen();
			check();

			if (checker == true)
			{
				break;
			}
		}
		Sleep(1500);
		FeldInit();
		a1();
	}
	system("cls");
	winner();


}

void a1()
{
	 PositionArray0 = 5;
	 PositionArray1 = 5;
	 PositionArray2 = 5;
	 PositionArray3 = 5;
	 PositionArray4 = 5;
	 PositionArray5 = 5;
	 PositionArray6 = 5;
	 counterRunde = 0;
	 checker = false;

}

void Feldanzeigen()
{

	std::cout << " Pos.1 Pos.2 Pos.3 Pos.4 Pos.5 Pos.6 Pos.7" << "\n";
	std::cout << "-------------------------------------------" << "\n";
	for (int g = 0; g < 6; g++)			//FELDNEUSETZUNG
	{
		std::cout << "|  ";
		for (int y = 0; y <= 6; y++)
		{
			if (Position[g][y] == 'X')
			{
				cout << GREEN << Position[g][y];
				cout << WHITE << "";
			}
			if (Position[g][y] == 'O')
			{
				cout << RED << Position[g][y];
				cout << WHITE << "";
			}
			if (Position[g][y] == '-')
			{
				cout << Position[g][y];
			}
			if (y <= 5)
			{
				std::cout << "  |  ";
			}
		}

	

		switch (g)
		{

		case 3: 
			std::cout << "  |              " << "Punktestand: " << "\n";
			std::cout << "-------------------------------------------              " << spieler1 << ": " << punkt1 << "\n";
			break;
		

		case 4: 
			std::cout << "  |              " << spieler2 << ": " << punkt2 << "\n";
			std::cout << "-------------------------------------------" << "\n";
			break;

		default:
			std::cout << "  |" << "\n";
			std::cout << "-------------------------------------------" << "\n";
			break;

	}
	}



	
	//std::cout << " Pos.1 Pos.2 Pos.3 Pos.4 Pos.5 Pos.6 Pos.7" << "\n";
	//std::cout << "-------------------------------------------" << "\n";
	//std::cout << "|  " << Position[0][0] << "  |  " << Position[0][1] << "  |  " << Position[0][2] << "  |  " << Position[0][3] << "  |  " << Position[0][4] << "  |  " << Position[0][5] << "  |  " << Position[0][6] << "  |" << "\n";
	//std::cout << "-------------------------------------------" << "\n";
	//std::cout << "|  " << Position[1][0] << "  |  " << Position[1][1] << "  |  " << Position[1][2] << "  |  " << Position[1][3] << "  |  " << Position[1][4] << "  |  " << Position[1][5] << "  |  " << Position[1][6] << "  |" << "\n";
	//std::cout << "-------------------------------------------" << "\n";
	//std::cout << "|  " << Position[2][0] << "  |  " << Position[2][1] << "  |  " << Position[2][2] << "  |  " << Position[2][3] << "  |  " << Position[2][4] << "  |  " << Position[2][5] << "  |  " << Position[2][6] << "  |              "<<"Punktestand: "<< "\n";
	//std::cout << "-------------------------------------------              "<< spieler1 << ": " << punkt1 <<"\n";
	//std::cout << "|  " << Position[3][0] << "  |  " << Position[3][1] << "  |  " << Position[3][2] << "  |  " << Position[3][3] << "  |  " << Position[3][4] << "  |  " << Position[3][5] << "  |  " << Position[3][6] << "  |              "<< spieler2 << ": " << punkt2 << "\n";
	//std::cout << "-------------------------------------------" << "\n";
	//std::cout << "|  " << Position[4][0] << "  |  " << Position[4][1] << "  |  " << Position[4][2] << "  |  " << Position[4][3] << "  |  " << Position[4][4] << "  |  " << Position[4][5] << "  |  " << Position[4][6] << "  |" << "\n";
	//std::cout << "-------------------------------------------" << "\n";
	//std::cout << "|  " << Position[5][0] << "  |  " << Position[5][1] << "  |  " << Position[5][2] << "  |  " << Position[5][3] << "  |  " << Position[5][4] << "  |  " << Position[5][5] << "  |  " << Position[5][6] << "  |" << "\n";
	//std::cout << "-------------------------------------------" << "\n";
	
	

}

void rundenanzahl()
{
	std::cout << error << endl;
	std::cout << "Geben Sie die Rundenanzahl an (max: 100): " ;
	std::cin >> Rundenanzahl; 

	if (!cin.fail()) { 
		if (Rundenanzahl > 100) { errorcode = 3; checkerror(); } 
		if (Rundenanzahl < 0) { errorcode = 4; checkerror(); }
	}
	else { errorcode = 2; checkerror(); }

	std::cout << "\n" << "Bitte geben Sie den Namen des ersten Spielers an: ";
	std::cin >> spieler1;
	std::cout << "\n" << "Bitte geben sie den Namen des zweiten Spielers an: ";
	std::cin >> spieler2;
}

void FeldInit()
{
	for (int g = 0; g < 7; g++)			//FELDNEUSETZUNG
	{
		for (int y = 0; y < 6; y++)
		{
			Position[y][g] = '-';
		}
	}
}

void yourTurn()
{
	turnreturn = turnCounter % 2;
	turnCounter++;
}

void Runde()
{
	if (turnreturn == 0)
	{
		std::cout << "Spieler 2 ist dran" << "\n";
		std::cout << "In welche Position soll dein Chip hin?:	";
		std::cin >> case1;
			if (cin.fail())
			{
				errorcode = 1;
				checkerror();
				
			}
	}
	
	else
	{
		std::cout << "Spieler 1 ist dran" << "\n";
		std::cout << "In welche Position soll dein Chip hin?:	";
		std::cin >> case1;
		if (cin.fail())
		{
			errorcode = 1;
			checkerror();

		}
	
	}


	if (case1 < 0 || case1 > 0 || case1 == 0)
	{
		if (turnreturn == 0)
		{
		
			switch (case1) {
			case 1:	Position[PositionArray0][0] = 'O'; 				//PositionArray0-6 sind 5, sobald man in Case das nötige eingibt, zählt es eins runter bzw. in der Tabelle eins hoch
				PositionArray0 = PositionArray0 - 1;
				system("cls");
				break;
			case 2: Position[PositionArray1][1] = 'O';
				PositionArray1 = PositionArray1 - 1;
				system("cls");
				break;
			case 3:	Position[PositionArray2][2] = 'O';
				PositionArray2 = PositionArray2 - 1;
				system("cls");
				break;
			case 4:	Position[PositionArray3][3] = 'O';
				PositionArray3 = PositionArray3 - 1;
				system("cls");
				break;
			case 5:	Position[PositionArray4][4] = 'O';
				PositionArray4 = PositionArray4 - 1;
				system("cls");
				break;
			case 6:	Position[PositionArray5][5] = 'O';
				PositionArray5 = PositionArray5 - 1;
				system("cls");
				break;
			case 7:	Position[PositionArray6][6] = 'O';
				PositionArray6 = PositionArray6 - 1;
				system("cls");
				break;
			default:
				system("cls");
				Feldanzeigen();
				Runde();
				break;
			}

		}
		if (turnreturn == 1)
		{

			switch (case1) {
			case 1:	Position[PositionArray0][0] = 'X'; 				//PositionArray0-6 sind 5, sobald man in Case das nötige eingibt, zählt es eins runter bzw. in der Tabelle eins hoch
				PositionArray0 = PositionArray0 - 1;
				system("cls");
				break;
			case 2: Position[PositionArray1][1] = 'X';
				PositionArray1 = PositionArray1 - 1;
				system("cls");
				break;
			case 3:	Position[PositionArray2][2] = 'X';
				PositionArray2 = PositionArray2 - 1;
				system("cls");
				break;
			case 4:	Position[PositionArray3][3] = 'X';
				PositionArray3 = PositionArray3 - 1;
				system("cls");
				break;
			case 5:	Position[PositionArray4][4] = 'X';
				PositionArray4 = PositionArray4 - 1;
				system("cls");
				break;
			case 6:	Position[PositionArray5][5] = 'X';
				PositionArray5 = PositionArray5 - 1;
				system("cls");
				break;
			case 7:	Position[PositionArray6][6] = 'X';
				PositionArray6 = PositionArray6 - 1;
				system("cls");
				break;
			default:
				system("cls");
				Feldanzeigen();
				Runde();
				break;
			}
		}
	}

	else
	{
		system("cls");
		Feldanzeigen();
		Runde();
	}
}

void abstand()
{
	int x = 0;
	while(x < 8)
	{
		cout <<endl;
		x++;
	}

}

void winner()
{
	if (punkt1 > punkt2)
	{
		std::cout << BOLDYELLOW;
		std::cout << endl << "Glueckwunsch, " << spieler1 << " hat das Spiel gewonnen!" << endl;
std::cout << "              __________    " << endl;
std::cout << "             |          |   " << endl;
std::cout << "             |  WINNER  |   " << endl;
std::cout << "             |  WINNER  |   " << endl;
std::cout << "             | CHICKEN- |   " << endl;
std::cout << "             |  DINNER  |   " << endl;
std::cout << "             |          |   " << endl;
std::cout << "              \\	       /    " << endl;
std::cout << "               \\      /     " << endl;
std::cout << "             ___|    |___   " << endl;
std::cout << "            |            |  " << endl;
std::cout << "            |            |  " << endl;
std::cout << WHITE;


	}






	if (punkt1 < punkt2)
	{
		std::cout << BOLDYELLOW;
		std::cout << endl << "Glueckwunsch, " << spieler1 << " hat das Spiel gewonnen!" << endl;
		std::cout << "              __________    " << endl;
		std::cout << "             |          |   " << endl;
		std::cout << "             |  WINNER  |   " << endl;
		std::cout << "             |  WINNER  |   " << endl;
		std::cout << "             | CHICKEN- |   " << endl;
		std::cout << "             |  DINNER  |   " << endl;
		std::cout << "             |          |   " << endl;
		std::cout << "              \\	       /    " << endl;
		std::cout << "               \\      /     " << endl;
		std::cout << "             ___|    |___   " << endl;
		std::cout << "            |            |  " << endl;
		std::cout << "            |            |  " << endl;
		std::cout << WHITE;
	}


	if (punkt1 == punkt2)
	{
		std::cout << BOLDYELLOW;
		std::cout << endl << "Glueckwunsch, " << spieler1 <<" und " << spieler2 << ". Ihr habt einen Unentschieden." << endl;
		std::cout << "           __________    " << "              __________    " << endl;
		std::cout << "          |          |   " << "             |          |   " << endl;
		std::cout << "          |  WINNER  |   " << "             |  WINNER  |   " << endl;
		std::cout << "          |  WINNER  |   " << "             |  WINNER  |   " << endl;
		std::cout << "          | CHICKEN- |   " << "             | CHICKEN- |   " << endl;
		std::cout << "          |  DINNER  |   " << "             |  DINNER  |   " << endl;
		std::cout << "          |          |   " << "             |          |   " << endl;
		std::cout << "           \\	    /     " << "             \\	/  " << endl;
		std::cout << "            \\      /    " << "                \\      /    " << endl;
		std::cout << "          ___|    |___   " << "             ___|    |___   " << endl;
		std::cout << "         |            |  " << "            |            |  " << endl;
		std::cout << "         |            |  " << "            |            |  " << endl;
		std::cout << WHITE;
	}
	abstand();
}

void check()
{
	for (int Check = 0; Check < 6; Check++)
	{
		for (int Check2 = 0; Check2 < 7; Check2++)
		{


			if (((Position[Check][Check2]) == 'O') && ((Position[Check][Check2 + 1]) == 'O') && ((Position[Check][Check2 + 2]) == 'O') && ((Position[Check][Check2 + 3]) == 'O'))
			{
				
				checker = true;
				punkt2++;
				break;
			}

			if (((Position[Check][Check2]) == 'O') && ((Position[Check + 1][Check2]) == 'O') && ((Position[Check + 2][Check2]) == 'O') && ((Position[Check + 3][Check2]) == 'O'))
			{
				checker = true;
				punkt2++;
				break;
			}

			if (((Position[Check][Check2]) == 'O') && ((Position[Check + 1][Check2 + 1]) == 'O') && ((Position[Check + 2][Check2 + 2]) == 'O') && ((Position[Check + 3][Check2 + 3]) == 'O'))
			{
				checker = true;
				punkt2++;
				break;
			}

			if (((Position[Check][Check2]) == 'O') && ((Position[Check + 1][Check2 - 1]) == 'O') && ((Position[Check + 2][Check2 - 2]) == 'O') && ((Position[Check + 3][Check2 - 3]) == 'O'))
			{
				checker = true;
				punkt2++;
				break;
			}

			if (((Position[Check][Check2]) == 'X') && ((Position[Check][Check2 + 1]) == 'X') && ((Position[Check][Check2 + 2]) == 'X') && ((Position[Check][Check2 + 3]) == 'X'))
			{
				checker = true;
				punkt1++;
				break;
			}

			if (((Position[Check][Check2]) == 'X') && ((Position[Check + 1][Check2]) == 'X') && ((Position[Check + 2][Check2]) == 'X') && ((Position[Check + 3][Check2]) == 'X'))
			{
				checker = true;
				punkt1++;
				break;
			}

			if (((Position[Check][Check2]) == 'X') && ((Position[Check + 1][Check2 + 1]) == 'X') && ((Position[Check + 2][Check2 + 2]) == 'X') && ((Position[Check + 3][Check2 + 3]) == 'X'))
			{
				checker = true;
				punkt1++;
				break;
			}

			if (((Position[Check][Check2]) == 'X') && ((Position[Check + 1][Check2 - 1]) == 'X') && ((Position[Check + 2][Check2 - 2]) == 'X') && ((Position[Check + 3][Check2 - 3]) == 'X'))
			{
				checker = true;
				punkt1++;
				break;
			}
		}
	}
}

void checkerror()
{


	switch (errorcode)
	{
	case 1:
		std::cin.clear();
		std::cin.ignore();
		system("cls");
		Feldanzeigen();
		Runde();
		break;

	case 2:
		std::cin.clear();
		std::cin.ignore();
		system("cls");
		error = "Diese Rundenanzahl ist nicht keine legitime Eingabe!";
		rundenanzahl();
		break;


	case 3:
		std::cin.clear();
		std::cin.ignore();
		system("cls");
		error = "Diese Rundenanzahl ist zu hoch!";
		rundenanzahl();

	case 4:
		std::cin.clear();
		std::cin.ignore();
		system("cls");
		error = "Diese Rundenanzahl ist zu klein!";
		rundenanzahl();

	}
}
