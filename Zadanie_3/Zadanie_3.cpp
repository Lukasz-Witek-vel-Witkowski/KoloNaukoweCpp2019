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
bool mainSelection(int choice, Program& program); //Sprawdzenie wyboru dla Menu Glownego
bool sizeSelection(int size,int length ,Program& program); //Sprawdzenie wprowadzonych danych (rozmiar, dlugosc)
bool victorySelection(int choice, Program& program); //Sprawdzenie wyboru dla Menu Zwyciestwa
bool defeatSelection(int choice, Program& program); //Sprawdzenie wyboru dla Menu Przegranej
bool charSelection(int choice, bool& wheel, Program& program); //Sprawdzenie wyboru dla Menu Wyboru znaku
void constructor(char** board, int size); //Funkcja budujaca plansze
void destroyer(char** board); //Funkcja niszczaca plansze
void switchProgram(int value, Program& program); //funkcja przelaczajaca pomiedzy case w grze 
void settingDefoult(int& size, int& lenght); //Ladowanie podstawowych danych
void horizontalChecking(char** board,int size, int length, int& result); //Sprawdzanie poziome planszy
void verticalChecking(char** board,int size, int length, int& result); //Sprawdzanie pionowe planszy
void obliquecheck(char** board,int size, int length, int& result); //Spwardzanie skosne planszy
void viewBoard(char** board, int size); //wyswietlenie planszy
void trafficChoice(char**board, int size, int& choiceX, int& choiceY); //Pobranie danych odnosnie wybranej pozycji
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
			} while (mainSelection(choice, program));break;
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
			} while (sizeSelection(size,length,program)); break;
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
		} while (victorySelection(choice, program)); break;
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
			} while (defeatSelection(choice, program));		break;
		case Destroyer: 
			destroyer(board); 
			switchProgram(value, program); break;
		case Exit:
			std::cout << "Wyjscie\n"; 
			system("pause");
			return 0;
		}
	} while (play);
	system("pause");
	return 0;
}