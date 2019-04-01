#include <iostream>
enum Program {
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
bool mainSelection(int choice,int& value, Program& program); //Sprawdzenie wyboru dla Menu Glownego yes
bool sizeSelection(int size,int length,int& value,Program& program); //Sprawdzenie wprowadzonych danych (rozmiar, dlugosc) yes
bool victorySelection(int choice,int& value, Program& program); //Sprawdzenie wyboru dla Menu Zwyciestwa yes
bool defeatSelection(int choice,int& value, Program& program); //Sprawdzenie wyboru dla Menu Przegranej yes
bool charSelection(int choice, bool& wheel, Program& program); //Sprawdzenie wyboru dla Menu Wyboru znaku yes
void constructor(char** board, int size); //Funkcja budujaca plansze yes
void destroyer(char** board, int size); //Funkcja niszczaca plansze yes
void switchProgram(int& value, Program& program); //funkcja przelaczajaca pomiedzy case w grze yes 
void settingDefoult(int& size, int& lenght); //Ladowanie podstawowych danych yes
void horizontalChecking(char** board,int size, int length, int& result); //Sprawdzanie poziome planszy no
void verticalChecking(char** board,int size, int length, int& result); //Sprawdzanie pionowe planszy no
void obliquecheck(char** board,int size, int length, int& result); //Spwardzanie skosne planszy no
void viewBoard(char** board, int size); //wyswietlenie planszy no
bool trafficChoice(char**board, int size, int& choiceX, int& choiceY); //Pobranie danych odnosnie wybranej pozycji yes
int main() {
	int choice;
	int value = 0;
	int length;
	int size;
	bool wheel;
	bool reply;
	bool play = true;
	char** board = nullptr;
	Program program = Program::MainMenu;
	do {
		switch (program) {
		case MainMenu:
			reply = false;
			do {
				system("cls");
				if (reply)
					std::cout << "Podano niewlasciwe dane!\n";
				std::cout <<"|---Menu Glowne---|\n"
					<< "1.\tGra w kolko i krzyzyk\n"
					<< "2.\tWlasne ustawienia gry\n"
					<< "3.\tWyjscie\n"
					<<"Wybierz jedna z opcji powyzej, podajac odpowiednia liczbe\n";
				std::cin >> choice;
				reply = true;
			} while (mainSelection(choice,value, program));break;
		case MenuSize: 
			reply = false;
			do {
				system("cls");
				if (reply)
					std::cout << "Podano niewlasciwe dane!\n";
				std::cout << "|---Wybor opcji gry---|\n"
					<< "Podaj rozmiar planszy: ";
				std::cin >> size;
					std::cout<< "Podaj jak dluga linie trzeba ulozyc: ";
				std::cin >> length;
				reply = true;
			} while (sizeSelection(size,length,value,program)); break;
		case MenuChoice: 	
			reply = false;
			do {
				system("cls");
				if (reply)
					std::cout << "Podano niewlasciwe dane!\n";
				std::cout<<"|--Menu wyboru znaku--|\n"
					<<"1.\tO\n"
					<<"2.\tX\n"
					<< "Wybierz jedna z opcji powyzej, podajac odpowiednia liczbe\n";
				std::cin >> choice;
				reply = true;
		} while (charSelection(choice, wheel,program)); break;
		case SettingDefault:
			settingDefoult(size, length);
			switchProgram(value, program); break;
		case Config: 
			constructor(board, size); 
			switchProgram(value, program); break;
		case Play: break;
		case Victory:
			reply = false;
			do {
				system("cls");
				if (reply)
				std::cout << "Podano niewlasciwe dane!\n";
				std::cout<<"Zwyciestwo!!\n"
					<<"1.\tGraj jeszcze raz\n"
					<<"2.\tWroc do Menu Glownego\n"
					<< "Wybierz jedna z opcji powyzej, podajac odpowiednia liczbe\n";
				reply = true;
				std::cin >> choice;
		} while (victorySelection(choice, value ,program)); break;
		case Defeat:
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
			} while (defeatSelection(choice, value ,program));		break;
		case Destroyer: 
			destroyer(board,size); 
			switchProgram(value, program); break;
		case Exit:
			std::cout << "Wyjscie\n"; 
			play = false; break;
		}
	} while (play);
	system("pause");
	return 0;
}
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
void constructor(char** board, int size) {
	int i;
	int j;
	board = new char*[size];
	for (i = 0; i < size; i++) {
		board[i] = new char[size];
		for (j = 0; j < size; j++)
			board[i][j] = ' ';
	}
}
void destroyer(char** board, int size) {
	int i;
	for (i = 0; i < size; i++)
		delete[] board[i];
	delete[] board;
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
void horizontalChecking(char** board, int size, int length, int& result) {

}
void verticalChecking(char** board, int size, int length, int& result) {

}
void obliquecheck(char** board, int size, int length, int& result) {


}
void viewBoard(char** board, int size) {
	int i;
	int j;
	for (i = 0; i < size; i++) {
		if(i==0)
		std::cout << (char)179;
		for (j = 0; j < size-2; j++) {
			std::cout << (char)148;
		}
		if (i == 0)
			std::cout << (char)136;
	}
}
bool trafficChoice(char**board, int size, int& choiceX, int& choiceY) {
	if ((choiceX >= 0 && choiceX < size) && (choiceY >= 0 && choiceY < size)) {
		if (board[choiceX][choiceY]) return true;
	}
	return false;
}