#include "function.h"


int main() {
	int ch;
	int sizeP = 0,
		sizeT = 0,
		sizeC = 0;
	bool flag = true;
	plane *p = NULL;
	train *t = NULL;
	car *c = NULL;
	setlocale(LC_ALL, "Russian");
	while (flag) {
		std::cout
			<< "1. Самолет\n"
			<< "2. Поезд\n"
			<< "3. Машина\n"
			<< "4. Выход\n"
			<< "Введите номер пункта: ";
		std::cin >> ch;
		getchar();
		std::cout << '\n';
		switch (ch) {
		case 1:
			p = work(p, sizeP);
			break;
		case 2:
			t = work(t, sizeT);
			break;
		case 3:
			c = work(c, sizeC);
			break;
		case 4:
			flag = false;
			break;
		}
		std::cout << '\n';
	}
	delete[] p;
	delete[] t;
	delete[] c;
	return 0;
}

