#include <iostream>
bool okDate(int day, int month, int year);
int main() {
	int tenRok = 2019;
	int tenMiesiac = 3;
	int tenDzien = 12;
	int podanyRok;
	int podanyMiesiac;
	int podanyDzien;
	int i = 0;
	//const char positive = "Jestes pelnoletni\n";
	do{
		if (i > 0) {
			system("cls");
			std::cout << podanyDzien <<" - "<<podanyMiesiac<< " - " << podanyRok<<"  - Podana data nie istnieje!\n";
		}
	std::cout << "Podaj rok urodzenia\n";
	std::cin >> podanyRok;
	std::cout << "Podaj miesiac urodzenia\n";
	std::cin >> podanyMiesiac;
	std::cout << "Podaj dzien urodzenia\n";
	std::cin >> podanyDzien;
	i++;
	}while (!okDate(podanyDzien, podanyMiesiac, podanyRok));
	if (18 < tenRok - podanyRok) {
		std::cout << "Jestes pelnoletni\n";
	}
	else if (18 == tenRok - podanyRok) {
		if (podanyMiesiac < tenMiesiac) {
			std::cout << "Jestes pelnoletni\n";
		}
		else if (podanyMiesiac == tenMiesiac) {
			if (podanyDzien <= tenDzien) {
				std::cout << "Jestes pelnoletni\n";
			}
			else {
				std::cout << "Przykro mi, jestes zamlody\n";
			}
		}
		else {
			std::cout << "Przykro mi, jestes zamlody\n";
		}
	}
	else
		std::cout << "Przykro mi, jestes zamlody\n";
	system("pause");
	return 0;
}


bool okDate(int day, int month, int year){
	if(year>=0){
		switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day>=1&&day<=31) return true;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day>=1&&day<=30) return true;
			break;
		case 2:
			if(year%4==0){ //rok przestepny
				if(day>=1&&day<=29) return true;
				break;
			}
			else{ //rok zwykly
				if(day>=1&&day<=38) return true;
				break;
			}
		default: break;
		}
	}
	return false;
}