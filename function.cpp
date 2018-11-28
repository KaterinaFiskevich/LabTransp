#include "function.h"

using std::cout;
using std::cin;

void work_plane(Keeper *kpr) {
	int ch;
	bool flag = true;
	plane *ptr;
	while (flag) {
		ptr = NULL;
		cout
			<< "   1) Добавить самолет\n"
			<< "   2) Удалить самолет\n"
			<< "   3) Выбрать самолет для работы\n"
			<< "   4) Вывести список самолетов по именам\n"
			<< "   5) Вывести полную информацию по самолетам\n"
			<< "   6) Вернуться\n";
		cout << "Выберите номер пункта: ";
		cin >> ch;
		getchar();
		switch (ch) {
		case 1:
			cout << "   Если хотите оставить параметр пустым нажмите enter\n";
			cout << "   Символы-разделители: " << separator << "\n";

			ptr = new plane();
			ptr->readType();
			ptr->readName();
			ptr->readWeight();
			ptr->readDim();
			ptr->readCity();
			kpr->add_transpoter(ptr, 0);

			delete ptr;
			break;
		case 2:
			if (kpr->get_size(0)) {
				try {
					ch = select(kpr->get_plane(), kpr->get_size(0));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				kpr->delete_transpoter(0, ch);
				cout << "Удаление завершено\n";
			}
			else {
				print(kpr->get_plane(), kpr->get_size(0));
			}
			break;
		case 3:
			if (kpr->get_size(0)) {
				int n;
				char *str;
				try {
					ch = select(kpr->get_plane(), kpr->get_size(0));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				cout
					<< "\n\n"
					<< "    1| Задать новый тип\n"
					<< "    2| Задать новое имя\n"
					<< "    3| Задать новый перевозимый вес\n"
					<< "    4| Задать новые габариты\n"
					<< "    5| Задать новые посещаемые города\n"
					<< "    6| Добавить новый город\n"
					<< "    7| Измениить один из городов\n"
					<< "    8| Изменить длину, ширину или высоту\n"
					<< "    9| Вывести на экран тип\n"
					<< "   10| Вывести на экран имя\n"
					<< "   11| Вывести на экран перевозимый вес\n"
					<< "   12| Вывести на экран габариты\n"
					<< "   13| Вывести на экран посещаемые города\n"
					<< "   14| Отчситить поле типа\n"
					<< "   15| Отчситить поле имени\n"
					<< "   16| Отчситить поле перевозимого веса\n"
					<< "   17| Отчситить поле габаритов\n"
					<< "   18| Удалить город\n"
					<< "   19| Отчситить поле посещаемых городов\n"
					<< "   20| Вернуться\n";
				while (flag) {
					str = NULL;
					cout << "Выберите номер пункта: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						(kpr->get_plane() + ch)->readType();
						cout << "\t\tУспешно\n";
						break;
					case 2:
						(kpr->get_plane() + ch)->readName();
						cout << "\t\tУспешно\n";
						break;
					case 3:
						(kpr->get_plane() + ch)->readWeight();
						cout << "\tУспешно\n";
						break;
					case 4:
						(kpr->get_plane() + ch)->readDim();
						cout << "\tУспешно\n";
						break;
					case 5:
						(kpr->get_plane() + ch)->readCity();
						cout << "\tУспешно\n";
						break;
					case 6:
						str = _strrd("\tВведите название города: ");
						(kpr->get_plane() + ch)->addCity(str);
						cout << "\tУспешно\n";
						break;
					case 7: 
						if((kpr->get_plane() + ch)->getCities()) {
							char *str2;
							cout << "\t";
							(kpr->get_plane() + ch)->writeCity();
							str = _strrd("Введите название заменяемого города: ");
							str2 = _strrd("Введите название заменяющего города: ");
							if ((kpr->get_plane() + ch)->rewriteCity(str, str2))
								cout << "\tУспешно\n";
							else
								cout << "\tГород не присутствует в списке\n";
							delete[] str2;
						}
						else 
							cout << "\tСписок посещаемых городов пуст";
						break;
					case 8:
						cout
							<< "\t0 - Изменить длину"
							<< "\t1 - Изменить ширину"
							<< "\t2 - Изменить высоту"
							<< "\nВведите номер пункта: ";
						cin >> n;
						getchar();
						str = _strrd("Введите значение: ");
						(kpr->get_plane() + ch)->rewriteDim(n, _strdbl(str));
						cout << "Успешно\n";
						break;
					case 9:
						cout << "\t";
						(kpr->get_plane() + ch)->writeType();
						break;
					case 10:
						cout << "\t";
						(kpr->get_plane() + ch)->writeName();
						break;
					case 11:
						cout << "\t";
						(kpr->get_plane() + ch)->writeWeight();
						break;
					case 12:
						cout << "\t";
						(kpr->get_plane() + ch)->writeDim();
						break;
					case 13:
						cout << "\t";
						(kpr->get_plane() + ch)->writeCity();
						break;
					case 14:
						(kpr->get_plane() + ch)->removeType();
						cout << "\tУспешно\n";
						break;
					case 15:
						(kpr->get_plane() + ch)->removeName();
						cout << "\tУспешно\n";
						break;
					case 16:
						(kpr->get_plane() + ch)->removeWeight();
						cout << "\tУспешно\n";
						break;
					case 17:
						(kpr->get_plane() + ch)->removeDim();
						cout << "\tУспешно\n";
						break;
					case 18:
						if ((kpr->get_plane() + ch)->getCities()) {
							cout << "\t";
							(kpr->get_plane() + ch)->writeCity();
							str = _strrd("Введите название города: ");
							if ((kpr->get_plane() + ch)->removeCity(str))
								cout << "\tУспешно\n";
							else
								cout << "\tГород не присутствует в списке\n";
						}
						else
							cout << "\tСписок посещаемых городов пуст";
						break;
					case 19:
						(kpr->get_plane() + ch)->removeCities();
						cout << "\tУспешно\n";
						break;
					case 20:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
				print(kpr->get_plane(), kpr->get_size(0));
			}
			break;
		case 4:
			printName(kpr->get_plane(), kpr->get_size(0));
			break;
		case 5:
			print(kpr->get_plane(), kpr->get_size(0));
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
}
void work_train(Keeper *kpr) {
	int ch;
	bool flag = true;
	train *ptr;
	while (flag) {
		ptr = NULL;
		cout
			<< "   1) Добавить поезд\n"
			<< "   2) Удалить поезд\n"
			<< "   3) Выбрать поезд для работы\n"
			<< "   4) Вывести список поездов по именам\n"
			<< "   5) Вывести полную информацию по поездам\n"
			<< "   6) Вернуться\n";
		cout << "Выберите номер пункта: ";
		cin >> ch;
		getchar();
		switch (ch) {
		case 1:
			cout << "   Если хотите оставить параметр пустым нажмите enter\n";
			cout << "   Символы-разделители: " << separator << '\n';

			ptr = new train();
			ptr->readName();
			ptr->readYear();
			ptr->readCity();
			ptr->readCount();
			ptr->readWeight();
			kpr->add_transpoter(ptr, 1);

			delete ptr;
			break;
		case 2:
			if (kpr->get_size(1)) {
				try {
					ch = select(kpr->get_train(), kpr->get_size(1));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				kpr->delete_transpoter(1, ch);
				cout << "\tУдаление завершено\n";
			}
			else {
				print(kpr->get_train(), kpr->get_size(1));
			}
			break;
		case 3:
			if (kpr->get_size(1)) {
				int n;
				char *str;
				try {
					ch = select(kpr->get_train(), kpr->get_size(1));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				cout
					<< "\n\n"
					<< "    1| Задать новый имя\n"
					<< "    2| Задать новый год выпуска\n"
					<< "    3| Задать новые посещаемые города\n"
					<< "    4| Задать новое кол-во вагонов\n"
					<< "    5| Задать новый перевозимый вес\n"
					<< "    6| Добавить новый город\n"
					<< "    7| Добавить кол-во вагонов\n"
					<< "    8| Измениить один из городов\n"
					<< "    9| Вывести на экран имя\n"
					<< "   10| Вывести на экран год выпуска\n"
					<< "   11| Вывести на экран посещаемые города\n"
					<< "   12| Вывести на экран кол-во вагонов\n"
					<< "   13| Вывести на экран перевозимый вес\n"
					<< "   14| Отчситить поле имени\n"
					<< "   15| Отчситить поле года выпуска\n"
					<< "   16| Отчситить поле посещаемых городов\n"
					<< "   17| Удалить город\n"
					<< "   18| Отчситить поле кол-ва вагонов\n"
					<< "   19| Отчситить поле перевозимого веса\n"
					<< "   20| Вернуться\n";
				while (flag) {
					str = NULL;
					cout << "Выберите номер пункта: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						(kpr->get_train() + ch)->readName();
						cout << "\tУспешно\n";
						break;
					case 2:
						(kpr->get_train() + ch)->readYear();
						cout << "\tУспешно\n";
						break;
					case 3:
						(kpr->get_train() + ch)->readCity();
						cout << "\tУспешно\n";
						break;
					case 4:
						(kpr->get_train() + ch)->readCount();
						cout << "\tУспешно\n";
						break;
					case 5:
						(kpr->get_train() + ch)->readWeight();
						cout << "\tУспешно\n";
						break;
					case 6:
						str = _strrd("\tВведите название города: ");
						(kpr->get_train() + ch)->addCity(str);
						cout << "\tУспешно\n";
						break;
					case 7:
						cout << "\t";
						str = _strrd("Введите кол-во добавляемых вагонов: ");
						(kpr->get_train() + ch)->addCount(int(_strdbl(str)));
						cout << "\tУспешно\n";
						break;
					case 8:
						if ((kpr->get_train() + ch)->getCities()) {
							char *str2;
							cout << "\t";
							(kpr->get_train() + ch)->writeCity();
							str = _strrd("Введите название заменяемого города: ");
							str2 = _strrd("Введите название заменяющего города: ");
							if ((kpr->get_train() + ch)->rewriteCity(str, str2))
								cout << "\tУспешно\n";
							else
								cout << "\tГород не присутствует в списке\n";
							delete[] str2;
						}
						else
							cout << "\tСписок посещаемых городов пуст";
						break;
					case 9:
						cout << "\t";
						(kpr->get_train() + ch)->writeName();
						break;
					case 10:
						cout << "\t";
						(kpr->get_train() + ch)->writeYear();
						break;
					case 11:
						cout << "\t";
						(kpr->get_train() + ch)->writeCity();
						break;
					case 12:
						cout << "\t";
						(kpr->get_train() + ch)->writeCount();
						break;
					case 13:
						cout << "\t";
						(kpr->get_train() + ch)->writeWeight();
						break;
					case 14:
						(kpr->get_train() + ch)->removeName();
						cout << "\tУспешно\n";
						break;
					case 15:
						(kpr->get_train() + ch)->removeYear();
						cout << "\tУспешно\n";
						break;
					case 16:
						(kpr->get_train() + ch)->removeCities();
						cout << "\tУспешно\n";
						break;
					case 17:
						if ((kpr->get_train() + ch)->getCities()) {
							cout << "\t";
							(kpr->get_train() + ch)->writeCity();
							str = _strrd("Введите название города: ");
							if ((kpr->get_train() + ch)->removeCity(str))
								cout << "\tУспешно\n";
							else
								cout << "\tГород не присутствует в списке\n";
						}
						else
							cout << "\tСписок посещаемых городов пуст";
						break;
					case 18:
						(kpr->get_train() + ch)->removeCount();
						cout << "\tУспешно\n";
						break;
					case 19:
						(kpr->get_train() + ch)->removeWeight();
						cout << "\tУспешно\n";
						break;
					case 20:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
			print(kpr->get_train(), kpr->get_size(1));
			}
			break;
		case 4:
			printName(kpr->get_train(), kpr->get_size(1));
			break;
		case 5:
			print(kpr->get_train(), kpr->get_size(1));
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
}
void work_car(Keeper *kpr) {
	int ch;
	bool flag = true;
	car *ptr;
	while (flag) {
		ptr = NULL;
		cout
			<< "   1) Добавить машину\n"
			<< "   2) Удалить машину\n"
			<< "   3) Выбрать машину для работы\n"
			<< "   4) Вывести список машин по именам\n"
			<< "   5) Вывести полную информацию по машинам\n"
			<< "   6) Вернуться\n";
		cout << "Выберите номер пункта: ";
		cin >> ch;
		getchar();
		switch (ch) {
		case 1:
			cout << "   Если хотите оставить параметр пустым нажмите enter\n";
			cout << "   Символы-разделители: " << separator << '\n';
			ptr = new car();
			ptr->readYear();
			ptr->readBrand();
			ptr->readModel();
			ptr->readCity();
			ptr->readWeight();
			kpr->add_transpoter(ptr, 2);

			delete ptr;
			break;
		case 2:
			if (kpr->get_size(2)) {
				try {
					ch = select(kpr->get_car(), kpr->get_size(2));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				kpr->delete_transpoter(2, ch);
				cout << "\tУдаление завершено\n";
			}
			else {
				print(kpr->get_car(), kpr->get_size(2));
			}
			break;
		case 3:
			if (kpr->get_size(2)) {
				int n;
				char *str;
				try {
					ch = select(kpr->get_car(), kpr->get_size(2));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				cout
					<< "\n\n"
					<< "    1| Задать новый год выпуска\n"
					<< "    2| Задать новую марку\n"
					<< "    3| Задать новую модель\n"
					<< "    4| Задать новые посещаемые города\n"
					<< "    5| Задать новый перевозимый вес\n"
					<< "    6| Добавить новый город\n"
					<< "    7| Изменить один из городов\n"
					<< "    8| Изменить часы доставки у одного из городов\n"
					<< "    9| Вывести на экран год выпуска\n"
					<< "   10| Вывести на экран марку\n"
					<< "   11| Вывести на экран модель\n"
					<< "   12| Вывести на экран посещаемые города\n"
					<< "   13| Вывести на экран перевозимый вес\n"
					<< "   14| Отчистить поле года выпуска\n"
					<< "   15| Отчистить поле марки\n"
					<< "   16| Отчистить поле модели\n"
					<< "   17| Удалить город\n"
					<< "   18| Отчистить поле посещаемых городв\n"
					<< "   19| Отчистить поле перевозимого веса\n"
					<< "   20| Вернуться\n";
				while (flag) {
					str = NULL;
					cout << "Выберите номер пункта: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						(kpr->get_car() + ch)->readYear();
						cout << "\tУспешно\n";
						break;
					case 2:
						(kpr->get_car() + ch)->readBrand();
						cout << "\tУспешно\n";
						break;
					case 3:
						(kpr->get_car() + ch)->readModel();
						cout << "\tУспешно\n";
						break;
					case 4:
						(kpr->get_car() + ch)->readCity();
						cout << "\tУспешно\n";
						break;
					case 5:
						(kpr->get_car() + ch)->readWeight();
						cout << "\tУспешно\n";
						break;
					case 6: 
						double d;
						str = _strrd("\tВведите название города: ");
						d = _strdbl(_strrd("\tВведите кол-во часов доставки: "));
						(kpr->get_car() + ch)->addCity(str, d);
						cout << "\tУспешно\n";
						break;
					case 7:
						if ((kpr->get_car() + ch)->getCities()) {
							char *str2;
							cout << "\t";
							(kpr->get_car() + ch)->writeCity();
							str = _strrd("Введите название заменяемого города: ");
							str2 = _strrd("Введите название заменяющего города: ");
							if ((kpr->get_car() + ch)->rewriteCity(str, str2))
								cout << "\tУспешно\n";
							else
								cout << "\tГород не присутствует в списке\n";
							delete[] str2;
						}
						else
							cout << "\tСписок посещаемых городов пуст\n";
						break;
					case 8:
						if ((kpr->get_car() + ch)->getCities()) {
							double d;
							cout << "\t";
							(kpr->get_car() + ch)->writeCity();
							str = _strrd("Введите название города: ");
							d = _strdbl(_strrd("Введите новые часы доставки: "));
							if ((kpr->get_car() + ch)->rewriteHours(str, d))
								cout << "\tУспешно\n";
							else
								cout << "\tГород не присутствует в списке\n";
						}
						else
							cout << "\tСписок посещаемых городов пуст";
						break;
					case 9:
						cout << "\t";
						(kpr->get_car() + ch)->writeYear();
						break;
					case 10:
						cout << "\t";
						(kpr->get_car() + ch)->writeBrand();
						break;
					case 11:
						cout << "\t";
						(kpr->get_car() + ch)->writeModel();
						break;
					case 12:
						(kpr->get_car() + ch)->writeCity();
						break;
					case 13:
						cout << "\t";
						(kpr->get_car() + ch)->writeWeight();
						break;
					case 14:
						(kpr->get_car() + ch)->removeYear();
						cout << "\tУспешно\n";
						break;
					case 15:
						(kpr->get_car() + ch)->removeBrand();
						cout << "\tУспешно\n";
						break;
					case 16:
						(kpr->get_car() + ch)->removeModel();
						cout << "\tУспешно\n";
						break;
					case 17:
						if ((kpr->get_car() + ch)->getCities()) {
							cout << "\t";
							(kpr->get_car() + ch)->writeCity();
							str = _strrd("Введите название города: ");
							if ((kpr->get_car() + ch)->removeCity(str))
								cout << "\tУспешно\n";
							else
								cout << "\tГород не присутствует в списке\n";
						}
						else
							cout << "\tСписок посещаемых городов пуст";
						break;
					case 18:
						(kpr->get_car() + ch)->removeCities();
						cout << "\tУспешно\n";
						break;
					case 19:
						(kpr->get_car() + ch)->removeWeight();
						cout << "\tУспешно\n";
						break;
					case 20:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
			print(kpr->get_car(), kpr->get_size(2));
			}
			break;
		case 4:
			printName(kpr->get_car(), kpr->get_size(2));
			break;
		case 5:
			print(kpr->get_car(), kpr->get_size(2));
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
}

template <typename T>
void printName(T *tr, int s) {
	cout << "\n\tСписок по именам: ";
	const char *c;
	for (int i = 0; i < s; ++i) {
		c = tr[i].getId();
		if (c) cout << c << " ";
		else cout << '#' << i << " ";
	}
	if (!s) cout << "пуст";
	cout << "\n";
}
template <typename T>
void print(T *tr, int s) {
	cout << "\n\tПолный список перевозчика данного типа: ";
	if (!s) cout << "пуст";
	else cout << '\n';
	for (int i = 0; i < s; ++i) {
		cout << '|' << i << '|';
		tr[i].print();
	}
	cout << '\n';
}
template <typename T>
int select(T *tr, int s) {
	int ch;
	printName(tr, s);
	exceptions e("Номер самолета введен неверно\n");
	cout << "Выберите номер(0..N): ";
	cin >> ch;
	getchar();
	if (ch >= s)
		throw e;
	return ch;
}
