#include <iostream>

int main() {
	int tenRok = 2019;
	int tenMiesiac = 3;
	int tenDzien = 12;
	int podanyRok;
	int podanyMiesiac;
	int podanyDzien;
	//const char positive = "Jestes pelnoletni\n";
	std::cout << "Podaj rok urodzenia\n";
	std::cin >> podanyRok;
	std::cout << "Podaj miesiac urodzenia\n";
	std::cin >> podanyMiesiac;
	std::cout << "Podaj dzien urodzenia\n";
	std::cin >> podanyDzien;
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