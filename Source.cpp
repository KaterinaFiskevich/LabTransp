#include "function.h"


int main() {
	int ch;
	int sizeP = 0,
		sizeT = 0,
		sizeC = 0;
	bool flag = true;
	Keeper *kpr = new Keeper;
	setlocale(LC_ALL, "Russian");
	
	std::cout << "Загрузить базу?(1 - y/0 - n) ";
	std::cin >> ch;
	getchar();
	try {
		if (ch) kpr->load();
	}
	catch (exceptions &e) {
		std::cout << e.what() << std::endl;
	}

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
			work_plane(kpr);
			break;
		case 2:
			work_train(kpr);
			break;
		case 3:
			work_car(kpr);
			break;
		case 4:
			flag = false;
			break;
		}
		std::cout << '\n';
	}
	std::cout << "Сохранить перед выходом?(1 - y/0 - n) ";
	std::cin >> ch;
	getchar();
	try {
		if (ch) kpr->save();
	}
	catch (exceptions &e) {
		std::cout << e.what() << std::endl;
	}

	delete kpr;
	return 0;
}

