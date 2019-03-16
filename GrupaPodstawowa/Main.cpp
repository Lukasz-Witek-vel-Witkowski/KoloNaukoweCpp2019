#include <iostream>

int main() {
	int tenRok = 2019;
	int podanyRok;
	std::cout << "Podaj rok urodzenia\n";
	std::cin >> podanyRok;
	if (18 <= tenRok - podanyRok) {
		std::cout << "Jestes pelnoletni\n";
	}
	else
		std::cout << "Przykro mi, jestes zamlody\n";
	system("pause");
	return 0;
}