#include "car.h"

//Конструкторы
car::car() {
	std::cout << "\t\t\tcar()\n";
	init();
}
car::car(
	int y,
	const char* b,
	const char* m,
	const char* c,
	const double* h,
	double w
) {
	std::cout << "\t\t\tcar(параметры)\n";
	init();
	setYear(y);
	setBrand(b);
	setModel(m);
	setCities(c);
	setHours(h);
	setWeight(w);
}
car::car(const car &p) {
	std::cout << "\t\t\tcar(const car &p)\n";
	init();
	setYear(p.year);
	setBrand(p.brand);
	setModel(p.model);
	setCities(p.city);
	setHours(p.hours);
	setWeight(p.weight);
}
void car::init() {
	year = 0;
	brand = NULL;
	model = NULL;
	city = NULL;
	hours = NULL;
	weight = 0;
	countCity = 0;
}

//Сеттеры
void car::setYear(int y) {
	year = y;
}
void car::setBrand(const char* b) {
	int n = _strlen(b);
	removeBrand();
	if (n) {
		brand = new char[n + 1];
		_strcpy(brand, b, n + 1);
	}
}
void car::setModel(const char* m) {
	int n = _strlen(m);
	removeModel();
	if (n) {
		model = new char[n + 1];
		_strcpy(model, m, n + 1);
	}
}
void car::setCities(const char* c) {
	int n = _strlen(c);
	removeCities();
	if (n) {
		city = new char[n + 1];
		_strcpy(city, c, n + 1);
		cityRedact();
		countCity = _strcnt(city, separ);
		hours = new double[countCity]();
	}
}
void car::setHours(const double* h) {
	delete[] hours;
	if (h) {
		hours = new double[countCity];
		for (int i = 0; i < countCity; ++i)
			hours[i] = h[i];
	}
	else
		hours = NULL;
}
void car::setWeight(double w) {
	weight = w;
}

//Геттеры
int car::getYear() {
	return year;
}
const char* car::getBrand() {
	return brand;
}
const char* car::getModel() {
	return model;
}
const char* car::getCities() {
	return city;
}
const double* car::getHours() {
	return hours;
}
double car::getWeight() {
	return weight;
}

//Add
void car::addCity(const char* c, double h) {
	if (_strlen(c)) {
		char* tmp1;
		if (city)
			tmp1 = _stradd(city, separ, c);
		else
			tmp1 = _stradd(city, "", c);
		double *tmp2 = new double[countCity + 1];
		for (int i = 0; i < countCity; ++i)
			tmp2[i] = hours[i];
		tmp2[countCity++] = h;
		removeCities();
		city = tmp1;
		hours = tmp2;
	}
}

//Перезапись
bool car::rewriteCity(const char* c1, const char* c2) {
	if (!city)
		return false;
	if (!_strlen(c2))
		return removeCity(c1);
	if (!_strrw(&city, c1, c2))
		return false;
	return true;
}
bool car::rewriteHours(const char *c, double h) {
	int n = _strnmb(city, c, separ);
	if (n < countCity) {
		hours[n] = h;
	}
	else return false;
	return true;
}

//Удаление
void car::removeYear() {
	year = 0;
}
void car::removeBrand() {
	delete[] brand;
	brand = 0;
}
void car::removeModel() {
	delete[] model;
	model = 0;
}
bool car::removeCity(const char *c) {
	char *tmp = _stradd(c, "", separ);
	if (!city)
		return false;
	if (!_strrw(&city, tmp, "")) {
		if (!_strrw(&city, c, "")) {
			delete[] tmp;
			return false;
		}
	}
	int i = _strnmb(city, c, separ);
	for (++i; i < countCity; ++i) {
		hours[i - 1] = hours[i];
	}
	--countCity;
	if (!countCity) {
		removeCities();
	}
	else {
		cityRedact();
	}
	return true;
}
void car::removeCities() {
	delete[] city;
	city = NULL;
	removeHours();
}
void car::removeHours() {
	delete[] hours;
	hours = NULL;
}
void car::removeWeight() {
	weight = 0;
}

void car::readYear() {
	year = (int)_strdbl(_strrd("\tВведите год выпуска: "));
}
void car::readBrand() {
	delete[] brand;
	brand = _strrd("\tВведите марку: ");
	if (!_strlen(brand)) {
		delete[] brand;
		brand = NULL;
	}
}
void car::readModel() {
	delete[] model;
	model = _strrd("\tВведите модель: ");
	if (!_strlen(model)) {
		delete[] model;
		model = NULL;
	}
}
void car::readCity() {
	delete[] city;
	city = _strrd("\tВведите посещаемые города: ");
	if (!_strlen(city)) {
		delete[] city;
		city = NULL;
		countCity = 0;
	}
	else {
		cityRedact();
		countCity = _strcnt(city, separ);
		hours = new double[countCity]();
		std::cout << "\tВведите кол-во часов доставки в каждый из городов\n";
		for (int i = 0; i < countCity; ++i) {
			std::cout << "\tГород " << i << ": ";
			hours[i] = _strdbl(_strrd(""));
		}
	}
}
void car::readWeight() {
	weight = _strdbl(_strrd("\tВведите перевозимый вес(кг): "));
}

void car::writeYear() const {
	std::cout << "Год выпуска: ";
	if (year) std::cout << year;
	else std::cout << emp;
	std::cout << '\n';
}
void car::writeBrand() const {
	std::cout << "Марка: " << ((brand) ? brand : emp) << '\n';
}
void car::writeModel() const {
	std::cout << "Модель: " << ((model) ? model : emp) << '\n';
}
void car::writeCity() const {
	int i, j, t;
	bool flag = false;
	if (city) {
		if (hours) {
			std::cout << "Посещаемые города:\n\t\t";
			t = 0;
			for (i = 0; city[i] != '\0'; ++i) {
				for (j = 0; separ[j] != '\0'; ++j) {
					if (city[i] == separ[j]) break;
				}
				if (separ[j] == '\0') {
					flag = true;
					std::cout << city[i];
				}
				else {
					if (flag) {
						std::cout << ": ";
						if (hours[t])
							std::cout << hours[t];
						else
							std::cout << emp;
						std::cout << "\n\t\t";
						flag = false;
						++t;
					}
				}
			}
			if (flag) {
				std::cout << ": ";
				if (hours[t])
					std::cout << hours[t];
				else
					std::cout << emp;
				std::cout << "\n";
			}
		}
		else {
			std::cout << "Посещаемые города: " << city;
			std::cout << "Время доставки: " << emp << '\n';
		}
	}
	else {
		std::cout << "Посещаемые города: " << emp << '\n';
		std::cout << "Время доставки: " << emp << '\n';
	}
}
void car::writeWeight() const {
	std::cout << "Перевозимый вес: ";
	if (weight) std::cout << weight;
	else std::cout << emp;
	std::cout << '\n';
}

//Вывод на экран
std::ostream& operator<<(std::ostream& os, const car &c) {
	os << "\tПараметры автомобиля:\n";
	os << "\t\t";
	c.writeYear();
	os << "\t\t";
	c.writeBrand();
	os << "\t\t";
	c.writeModel();
	os << "\t\t";
	c.writeCity();
	os << "\t\t";
	c.writeWeight();
	return os;
}
void car::print() {
	std::cout << *this;
}

//Id
const char* car::getId() {
	return brand;
}

//Присваивание
car& car::operator=(const car& c) {
	if (this == &c)
		return *this;
	setYear(c.year);
	setBrand(c.brand);
	setModel(c.model);
	setCities(c.city);
	setHours(c.hours);
	setWeight(c.weight);
	return *this;
}

//Деструктор
car::~car() {
	std::cout << "\t\t\t~car()\n";
	delete[] brand;
	delete[] model;
	delete[] city;
	delete[] hours;
}
