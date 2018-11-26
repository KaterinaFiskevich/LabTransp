#include "function.h"


plane* work(plane *p, int &s) {
	using std::cout;
	using std::cin;
	int i;
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
			ptr = new plane[s + 1];
			for (i = 0; i < s; ++i) {
				ptr[i] = *(p + i);
			}
			delete[] p;
			p = ptr;
			p[s].readType();
			p[s].readName();
			p[s].readWeight();
			p[s].readDim();
			p[s].readCity();
			++s;
			break;
		case 2:
			if (s) {
				try {
					ch = select(p, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				for (i = 0; i < ch; ++i) {
					ptr[i] = p[i];
				}
				for (++i; i < s; ++i) {
					ptr[i - 1] = p[i];
				}
				delete[] p;
				p = ptr;
				--s;
				std::cout << "Удаление завершено\n";
			}
			else {
				printName(p, s);
			}
			break;
		case 3:
			if (s) {
				int n;
				char *str;
				try {
					ch = select(p, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
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
						p[ch].readType();
						std::cout << "\t\tУспешно\n";
						break;
					case 2:
						p[ch].readName();
						std::cout << "\t\tУспешно\n";
						break;
					case 3:
						p[ch].readWeight();
						std::cout << "\tУспешно\n";
						break;
					case 4:
						p[ch].readDim();
						std::cout << "\tУспешно\n";
						break;
					case 5:
						p[ch].readCity();
						std::cout << "\tУспешно\n";
						break;
					case 6:
						str = _strrd("\tВведите название города: ");
						p[ch].addCity(str);
						std::cout << "\tУспешно\n";
						break;
					case 7: 
						if(p[ch].getCities()) {
							char *str2;
							cout << "\t";
							p[ch].writeCity();
							str = _strrd("Введите название заменяемого города: ");
							str2 = _strrd("Введите название заменяющего города: ");
							if (p[ch].rewriteCity(str, str2))
								std::cout << "\tУспешно\n";
							else
								std::cout << "\tГород не присутствует в списке\n";
							delete[] str2;
						}
						else 
							std::cout << "\tСписок посещаемых городов пуст";
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
						p[ch].rewriteDim(n, _strdbl(str));
						std::cout << "Успешно\n";
						break;
					case 9:
						cout << "\t";
						p[ch].writeType();
						break;
					case 10:
						cout << "\t";
						p[ch].writeName();
						break;
					case 11:
						cout << "\t";
						p[ch].writeWeight();
						break;
					case 12:
						cout << "\t";
						p[ch].writeDim();
						break;
					case 13:
						cout << "\t";
						p[ch].writeCity();
						break;
					case 14:
						p[ch].removeType();
						std::cout << "\tУспешно\n";
						break;
					case 15:
						p[ch].removeName();
						std::cout << "\tУспешно\n";
						break;
					case 16:
						p[ch].removeWeight();
						std::cout << "\tУспешно\n";
						break;
					case 17:
						p[ch].removeDim();
						std::cout << "\tУспешно\n";
						break;
					case 18:
						if (p[ch].getCities()) {
							cout << "\t";
							p[ch].writeCity();
							str = _strrd("Введите название города: ");
							if (p[ch].removeCity(str))
								std::cout << "\tУспешно\n";
							else
								std::cout << "\tГород не присутствует в списке\n";
						}
						else
							std::cout << "\tСписок посещаемых городов пуст";
						break;
					case 19:
						p[ch].removeCities();
						std::cout << "\tУспешно\n";
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
				print(p, s);
			}
			break;
		case 4:
			printName(p, s);
			break;
		case 5:
			print(p, s);
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
	return p;
}
train* work(train *t, int &s) {
	using std::cout;
	using std::cin;
	int i;
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
			ptr = new train[s + 1];
			for (i = 0; i < s; ++i) {
				ptr[i] = *(t + i);
			}
			delete[] t;
			t = ptr;
			t[s].readName();
			t[s].readYear();
			t[s].readCity();
			t[s].readCount();
			t[s].readWeight();
			++s;
			break;
		case 2:
			if (s) {
				try {
					ch = select(t, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				ptr = new train[s - 1];
				for (i = 0; i < ch; ++i) {
					ptr[i] = t[i];
				}
				for (++i; i < s; ++i) {
					ptr[i - 1] = t[i];
				}
				delete[] t;
				t = ptr;
				--s;
				std::cout << "\tУдаление завершено\n";
			}
			else {
				print(t, s);
			}
			break;
		case 3:
			if (s) {
				int n;
				char *str;
				try {
					ch = select(t, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				cout
					<< "\n\n"
					<< "    1| Задать новое имя\n"
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
					<< "   14| Очистить поле имени\n"
					<< "   15| Очистить поле года выпуска\n"
					<< "   16| Очистить поле посещаемых городов\n"
					<< "   17| Удалить город\n"
					<< "   18| Очистить поле кол-ва вагонов\n"
					<< "   19| Очистить поле перевозимого веса\n"
					<< "   20| Вернуться\n";
				while (flag) {
					str = NULL;
					cout << "Выберите номер пункта: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						t[ch].readName();
						std::cout << "\tУспешно\n";
						break;
					case 2:
						t[ch].readYear();
						std::cout << "\tУспешно\n";
						break;
					case 3:
						t[ch].readCity();
						std::cout << "\tУспешно\n";
						break;
					case 4:
						t[ch].readCount();
						std::cout << "\tУспешно\n";
						break;
					case 5:
						t[ch].readWeight();
						std::cout << "\tУспешно\n";
						break;
					case 6:
						str = _strrd("\tВведите название города: ");
						t[ch].addCity(str);
						std::cout << "\tУспешно\n";
						break;
					case 7:
						cout << "\t";
						str = _strrd("Введите кол-во добавляемых вагонов: ");
						t[ch].addCount(int(_strdbl(str)));
						std::cout << "\tУспешно\n";
						break;
					case 8:
						if (t[ch].getCities()) {
							char *str2;
							cout << "\t";
							t[ch].writeCity();
							str = _strrd("Введите название заменяемого города: ");
							str2 = _strrd("Введите название заменяющего города: ");
							if (t[ch].rewriteCity(str, str2))
								std::cout << "\tУспешно\n";
							else
								std::cout << "\tГород не присутствует в списке\n";
							delete[] str2;
						}
						else
							std::cout << "\tСписок посещаемых городов пуст";
						break;
					case 9:
						cout << "\t";
						t[ch].writeName();
						break;
					case 10:
						cout << "\t";
						t[ch].writeYear();
						break;
					case 11:
						cout << "\t";
						t[ch].writeCity();
						break;
					case 12:
						cout << "\t";
						t[ch].writeCount();
						break;
					case 13:
						cout << "\t";
						t[ch].writeWeight();
						break;
					case 14:
						t[ch].removeName();
						std::cout << "\tУспешно\n";
						break;
					case 15:
						t[ch].removeYear();
						std::cout << "\tУспешно\n";
						break;
					case 16:
						t[ch].removeCities();
						std::cout << "\tУспешно\n";
						break;
					case 17:
						if (t[ch].getCities()) {
							cout << "\t";
							t[ch].writeCity();
							str = _strrd("Введите название города: ");
							if (t[ch].removeCity(str))
								std::cout << "\tУспешно\n";
							else
								std::cout << "\tГород не присутствует в списке\n";
						}
						else
							std::cout << "\tСписок посещаемых городов пуст";
						break;
					case 18:
						t[ch].removeCount();
						std::cout << "\tУспешно\n";
						break;
					case 19:
						t[ch].removeWeight();
						std::cout << "\tУспешно\n";
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
				print(t, s);
			}
			break;
		case 4:
			printName(t, s);
			break;
		case 5:
			print(t, s);
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
	return t;
}
car* work(car *cr, int &s) {
	using std::cout;
	using std::cin;
	int i;
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
			ptr = new car[s + 1];
			for (i = 0; i < s; ++i) {
				ptr[i] = *(cr + i);
			}
			delete[] cr;
			cr = ptr;
			cr[s].readYear();
			cr[s].readBrand();
			cr[s].readModel();
			cr[s].readCity();
			cr[s].readWeight();
			++s;
			break;
		case 2:
			if (s) {
				try {
					ch = select(cr, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				ptr = new car[s - 1];
				for (i = 0; i < ch; ++i) {
					ptr[i] = cr[i];
				}
				for (++i; i < s; ++i) {
					ptr[i - 1] = cr[i];
				}
				delete[] cr;
				cr = ptr;
				--s;
				std::cout << "\tУдаление завершено\n";
			}
			else {
				print(cr, s);
			}
			break;
		case 3:
			if (s) {
				int n;
				char *str;
				try {
					ch = select(cr, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
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
					<< "   14| Очистить поле года выпуска\n"
					<< "   15| Очистить поле марки\n"
					<< "   16| Очистить поле модели\n"
					<< "   17| Удалить город\n"
					<< "   18| Очистить поле посещаемых городв\n"
					<< "   19| Очистить поле перевозимого веса\n"
					<< "   20| Вернуться\n";
				while (flag) {
					str = NULL;
					cout << "Выберите номер пункта: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						cr[ch].readYear();
						std::cout << "\tУспешно\n";
						break;
					case 2:
						cr[ch].readBrand();
						std::cout << "\tУспешно\n";
						break;
					case 3:
						cr[ch].readModel();
						std::cout << "\tУспешно\n";
						break;
					case 4:
						cr[ch].readCity();
						std::cout << "\tУспешно\n";
						break;
					case 5:
						cr[ch].readWeight();
						std::cout << "\tУспешно\n";
						break;
					case 6: 
						double d;
						str = _strrd("\tВведите название города: ");
						d = _strdbl(_strrd("\tВведите кол-во часов доставки: "));
						cr[ch].addCity(str, d);
						std::cout << "\tУспешно\n";
						break;
					case 7:
						if (cr[ch].getCities()) {
							char *str2;
							cout << "\t";
							cr[ch].writeCity();
							str = _strrd("Введите название заменяемого города: ");
							str2 = _strrd("Введите название заменяющего города: ");
							if (cr[ch].rewriteCity(str, str2))
								std::cout << "\tУспешно\n";
							else
								std::cout << "\tГород не присутствует в списке\n";
							delete[] str2;
						}
						else
							std::cout << "\tСписок посещаемых городов пуст\n";
						break;
					case 8:
						if (cr[ch].getCities()) {
							double d;
							cout << "\t";
							cr[ch].writeCity();
							str = _strrd("Введите название города: ");
							d = _strdbl(_strrd("Введите новые часы доставки: "));
							if (cr[ch].rewriteHours(str, d))
								std::cout << "\tУспешно\n";
							else
								std::cout << "\tГород не присутствует в списке\n";
						}
						else
							std::cout << "\tСписок посещаемых городов пуст";
						break;
					case 9:
						cout << "\t";
						cr[ch].writeYear();
						break;
					case 10:
						cout << "\t";
						cr[ch].writeBrand();
						break;
					case 11:
						cout << "\t";
						cr[ch].writeModel();
						break;
					case 12:
						cr[ch].writeCity();
						break;
					case 13:
						cout << "\t";
						cr[ch].writeWeight();
						break;
					case 14:
						cr[ch].removeYear();
						std::cout << "\tУспешно\n";
						break;
					case 15:
						cr[ch].removeBrand();
						std::cout << "\tУспешно\n";
						break;
					case 16:
						cr[ch].removeModel();
						std::cout << "\tУспешно\n";
						break;
					case 17:
						if (cr[ch].getCities()) {
							cout << "\t";
							cr[ch].writeCity();
							str = _strrd("Введите название города: ");
							if (cr[ch].removeCity(str))
								std::cout << "\tУспешно\n";
							else
								std::cout << "\tГород не присутствует в списке\n";
						}
						else
							std::cout << "\tСписок посещаемых городов пуст";
						break;
					case 18:
						cr[ch].removeCities();
						std::cout << "\tУспешно\n";
						break;
					case 19:
						cr[ch].removeWeight();
						std::cout << "\tУспешно\n";
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
				print(cr, s);
			}
			break;
		case 4:
			printName(cr, s);
			break;
		case 5:
			print(cr, s);
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
	return cr;
}

template <typename T>
void printName(T *tr, int s) {
	std::cout << "\n\tСписок по именам: ";
	const char *c;
	for (int i = 0; i < s; ++i) {
		c = tr[i].getId();
		if (c) std::cout << c << " ";
		else std::cout << '#' << i << " ";
	}
	if (!s) std::cout << "пуст";
	std::cout << "\n";
}
template <typename T>
void print(T *tr, int s) {
	std::cout << "\n\tПолный список перевозчика данного типа: ";
	if (!s) std::cout << "пуст";
	else std::cout << '\n';
	for (int i = 0; i < s; ++i) {
		std::cout << '|' << i << '|';
		tr[i].print();
	}
	std::cout << '\n';
}
template <typename T>
int select(T *tr, int s) {
	int ch;
	printName(tr, s);
	exceptions e("Номер самолета введен неверно\n");
	std::cout << "Выберите номер(0..N): ";
	std::cin >> ch;
	getchar();
	if (ch >= s)
		throw e;
	return ch;
}
