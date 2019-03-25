#include <iostream>

int main() {
	int min;
	int max;
	int size;
	int* tab;
	bool value = false;
	int iterator;
	do {
		if (value) {
			system("cls");
			std::cout << "Wprowadzone wartosci sa niepoprawne!\n";
		}
		value = true;
		std::cout << "Podaj minimalna wartosc przedzialu\n";
		std::cin >> min;
		std::cout << "Podaj maksymalna wartosc przedzialu\n";
		std::cin >> max;
		size = max - min+1; //w zaleznosci od interpretacji polecenia
	} while (size<=0||size>32000);
	tab = new int[size];
	for (iterator = 0; iterator < size; iterator++) {
		tab[iterator] = min++;
	}
	for (iterator = 0; iterator < size; iterator++) {
		std::cout << iterator+1 << " - [" << tab[iterator] << "]\n"; 
		//iterator+1 by numeracja nie byla od 0 
	}
	delete[] tab;
	system("pause");
	return 0;
}