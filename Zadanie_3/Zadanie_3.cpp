//--------------------------------------------------------------------------------------------------------------//
//	date: 03-04-2019 															Author: Grupa Podstawowa Cpp	//
//	name: "Gra w Kolko i krzyzyk"																				//
//	title: "Gra z mozliwoscia ustalenia wielkosci planszy wraz z regula, ile znakow kolo siebie trzeba umiescic //
//	by wygrac"																									//
//--------------------------------------------------------------------------------------------------------------//
#include <iostream>
enum Program { //typ enumeryczny 
	MainMenu,
	MenuSize,
	MenuChoice,
	SettingDefault,
	Config,
	Destroyer,
	Play,
	Victory,
	Defeat,
	Exit
};
//--------------------Procedury-------------------------------------------------------------------//
void prMainMenu(Program& program, int& choice, int& value, bool reply); //procedura menu glownego
void prSizeMenu(Program& program, int& size, int& length, int& value, bool reply); //procedura menu rozmiaru
void prChoice(Program& program, int& choice, bool& wheel, int& value, bool reply); //procedura menu wyboru
void prVictoryMenu(Program& program, int& choice, int& value, bool reply); //procedura menu zwyciestwa
void prDefeatMenu(Program& program, int& choice, int& value, bool reply); //procedura menu porazki
void prExit(bool& play); //procedura wyjscia z programu


//----------------------------Pozostale funkcje---------------------------------------------------//
bool mainSelection(int choice,int& value, Program& program); //Sprawdzenie wyboru dla Menu Glownego yes
bool sizeSelection(int size,int length,int& value,Program& program); //Sprawdzenie wprowadzonych danych (rozmiar, dlugosc) yes
bool victorySelection(int choice,int& value, Program& program); //Sprawdzenie wyboru dla Menu Zwyciestwa yes
bool defeatSelection(int choice,int& value, Program& program); //Sprawdzenie wyboru dla Menu Przegranej yes
bool charSelection(int choice, bool& wheel, Program& program); //Sprawdzenie wyboru dla Menu Wyboru znaku yes
char** constructor(char** board, int size); //Funkcja budujaca plansze yes
char** destroyer(char** board, int size); //Funkcja niszczaca plansze yes
void switchProgram(int& value, Program& program); //funkcja przelaczajaca pomiedzy case w grze yes 
void settingDefoult(int& size, int& lenght); //Ladowanie podstawowych danych yes
void horizontalChecking(char** board,int size, int length, bool& result, bool wheel); //Sprawdzanie poziome planszy no
void verticalChecking(char** board,int size, int length, bool& result, bool wheel); //Sprawdzanie pionowe planszy no
void obliquecheck(char** board,int size, int length, bool& result,bool wheel); //Spwardzanie skosne planszy no
void viewBoard(char** board, int size); //wyswietlenie planszy no
bool trafficChoice(char**board, int size, int& choiceX, int& choiceY); //Pobranie danych odnosnie wybranej pozycji yes
int main() {
	int choice; //zmienna wyboru dla menu
	int value; //zmienna pomocnicza w sterowaniu 
	int length; //zmienna okreslajaca wartosc reguly
	int size = 6;	//zmienna okreslajaca wielkosc wielkosc planszy
	bool wheel; //zmienna znaku
	bool reply = false; //zmienna sterujaca odpowiedzialna za niepoprawne wprowadzenie wartosci
	bool play = true; //zmienna okresljaca czy gra sie toczy, podstawowo utawiono na "true"
	char** board = nullptr; //zmienna dotyczaca planszy
	Program program = Program::MainMenu; //zmienna tytpu enumerowanego
	board = constructor(board, size);
	viewBoard(board, size);
	board = destroyer(board, size);
	system("pause");
	return 0;

	do {
		switch (program) {
		case MainMenu:	prMainMenu(program, choice, value, reply); break;
		case MenuSize: prSizeMenu(program, size, length, value, reply); break;
		case MenuChoice: prChoice(program, choice, wheel, value, reply); break;
		case SettingDefault: 	
			settingDefoult(size, length);
			switchProgram(value, program); break;
		case Config: 
			board = constructor(board, size); 
			switchProgram(value, program); break;
		case Play: //do dokonczenia!!!
			
			
			
			
			break;
		case Victory:prVictoryMenu(program, choice, value, reply); break;
		case Defeat: prDefeatMenu(program, choice, value, reply); break;
		case Destroyer: 
			board = destroyer(board,size); 
			switchProgram(value, program); break;
		case Exit:prExit(play);	break;
		}
	} while (play);
	system("pause");
	return 0;
}
void horizontalChecking(char** board, int size, int length, bool& result, bool wheel) {

}//Sprawdzanie poziome planszy no
void verticalChecking(char** board, int size, int length, bool& result, bool wheel) {

}//Sprawdzanie pionowe planszy no
void obliquecheck(char** board, int size, int length, bool& result, bool wheel) {

}//Spwardzanie skosne planszy no
bool mainSelection(int choice,int& value, Program& program) {
	switch (choice) {
	case 1:
		value = 1;
		program = Program::SettingDefault; break;
	case 2:
		program = Program::MenuSize; break;
	case 3:
		program = Program::Exit; break;
	default:
		return true;
	}
	return false;
}
bool sizeSelection(int size, int length,int& value, Program& program) {
	if ((size > 2 && size < 10) && (length > 3 && length < 10)) {
		value = 2;
		program = Program::Config;
		return false;
	}
	return true;
}
bool victorySelection(int choice,int& value, Program& program) {
	switch (choice) {
	case 1:
		program = Program::Play; break;
	case 2:
		program = Program::Destroyer; break;
		value = 3;
	default: return true;
	}
	return false;
}
bool defeatSelection(int choice,int& value ,Program& program) {
	switch (choice) {
	case 1:
		program = Program::Play; break;
	case 2:
		program = Program::Destroyer; break;
		value = 3;
	default: return true;
	}
	return false;
}
bool charSelection(int choice, bool& wheel, Program& program) {
	
	switch (choice) {
	case 1: wheel = true; break;
	case 2: wheel = false; break;
	default: return true;
	}
	program = Program::Play;
	return false;
}
char** constructor(char** board, int size) {
	int i;
	int j;
	board = new char*[size];
	for (i = 0; i < size; i++) {
		board[i] = new char[size];
		for (j = 0; j < size; j++)
			board[i][j] = ' ';
	}
	board[0][0] = 'O';
	board[1][1] = 'X';
	return board;
}
char** destroyer(char** board, int size) {
	int i;
	for (i = 0; i < size; i++)
		delete[] board[i];
	delete[] board;
	return board;
}
void switchProgram(int& value, Program& program) {
	switch (value) {
	case 1:
		program = Program::Config; 
		value = 2; break;
	case 2:
		program = Program::MenuChoice; break;
	case 3:
		program = Program::MainMenu; break;
	}
}
void settingDefoult(int& size, int& lenght) {
	size = 3;
	lenght = 3;
}
void viewBoard(char** board, int size) {
	int i;
	int t;
	std::cout << (char)218 << (char)196;
	for (i = 1; i < size; i++) std::cout << (char)194 << (char)196;
	std::cout << (char)191 << "\n";
	for (t = 0; t < size; t++) {
			std::cout << (char)179;
			for (i = 1; i <= size; i++) std::cout << board[t][i-1] << (char)179;
			std::cout << "\n";
			if (t == size - 1) break;
			std::cout << (char)195<<(char)196;
			for (i = 1; i < size; i++) std::cout << (char)197 << (char)196;
			std::cout << (char)180 << "\n";
		}
	std::cout << (char)192 << (char)196;
	for (i = 1; i < size; i++) std::cout << (char)193 << (char)196;
	std::cout << (char)217 << "\n";
}
bool trafficChoice(char**board, int size, int& choiceX, int& choiceY) {
	if ((choiceX >= 0 && choiceX < size) && (choiceY >= 0 && choiceY < size)) {
		if (board[choiceX][choiceY]) return true;
	}
	return false;
}
void prMainMenu(Program& program, int& choice,int& value,bool reply) {
	reply = false;
	do {
		system("cls");
		if (reply)
			std::cout << "Podano niewlasciwe dane!\n";
		std::cout << "|---Menu Glowne---|\n"
			<< "1.\tGra w kolko i krzyzyk\n"
			<< "2.\tWlasne ustawienia gry\n"
			<< "3.\tWyjscie\n"
			<< "Wybierz jedna z opcji powyzej, podajac odpowiednia liczbe\n";
		std::cin >> choice;
		reply = true;
	} while (mainSelection(choice, value, program));
}
void prSizeMenu(Program& program, int& size,int& length, int& value, bool reply) {
	reply = false;
	do {
		system("cls");
		if (reply)
			std::cout << "Podano niewlasciwe dane!\n";
		std::cout << "|---Wybor opcji gry---|\n"
			<< "Podaj rozmiar planszy: ";
		std::cin >> size;
		std::cout << "Podaj jak dluga linie trzeba ulozyc: ";
		std::cin >> length;
		reply = true;
	} while (sizeSelection(size, length, value, program));
}
void prChoice(Program& program, int& choice, bool& wheel,int& value,bool reply) {
	reply = false;
	do {
		system("cls");
		if (reply)
			std::cout << "Podano niewlasciwe dane!\n";
		std::cout << "|--Menu wyboru znaku--|\n"
			<< "1.\tO\n"
			<< "2.\tX\n"
			<< "Wybierz jedna z opcji powyzej, podajac odpowiednia liczbe\n";
		std::cin >> choice;
		reply = true;
	} while (charSelection(choice, wheel, program));
}
void prVictoryMenu(Program& program,int& choice, int& value, bool reply ) {
	reply = false;
	do {
		system("cls");
		if (reply)
			std::cout << "Podano niewlasciwe dane!\n";
		std::cout << "Zwyciestwo!!\n"
			<< "1.\tGraj jeszcze raz\n"
			<< "2.\tWroc do Menu Glownego\n"
			<< "Wybierz jedna z opcji powyzej, podajac odpowiednia liczbe\n";
		reply = true;
		std::cin >> choice;
	} while (victorySelection(choice, value, program));
}
void prDefeatMenu(Program& program, int& choice, int& value, bool reply) {
	reply = false;
	do {
		system("cls");
		if (reply)
			std::cout << "Podano niewlasciwe dane!\n";
		std::cout << "Przegrales!!\n"
			<< "1.\tGraj jeszcze raz\n"
			<< "2.\tWroc do Menu Glownego\n"
			<< "Wybierz jedna z opcji powyzej, podajac odpowiednia liczbe\n";
		reply = true;
		std::cin >> choice;
	} while (defeatSelection(choice, value, program));
}
void prExit(bool& play) {
	std::cout << "Wyjscie\n";
	play = false;
}