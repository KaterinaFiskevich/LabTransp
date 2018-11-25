#include "train.h"

//Конструкторы
train::train() {
	std::cout << "\t\t\ttrain()\n";
	init();
}
train::train(
	const char *n,
	int y,
	const char *c,
	int ct,
	double w
) {
	std::cout << "\t\t\ttrain(параметры)\n";
	init();
	setName(n);
	setYear(y);
	setCities(c);
	setCount(ct);
	setWeight(w);
}
train::train(const train &t) {
	std::cout << "\t\t\ttrain(const train &t)\n";
	init();
	setName(t.name);
	setYear(t.year);
	setCities(t.city);
	setCount(t.count);
	setWeight(t.weight);
}
void train::init() {
	name = NULL;
	year = 0;
	city = NULL;
	count = 0;
	weight = 0.0;
}


//Сеттеры
void train::setName(const char* n) {
	int m = _strlen(n);
	removeName();
	if (m) {
		name = new char[m + 1];
		_strcpy(name, n, m + 1);
	}
}
void train::setCities(const char* c) {
	int n = _strlen(c);
	removeCities();
	if (n) {
		city = new char[n + 1];
		_strcpy(city, c, n + 1);
		cityRedact();
	}
}
void train::setYear(int y) {
	year = y;
}
void train::setCount(int ct) {
	count = ct;
}
void train::setWeight(double w) {
	weight = w;
}

//Геттеры
const char* train::getName() {
	return name;
}
int train::getYear() {
	return year;
}
const char* train::getCities() {
	return city;
}
int train::getCount() {
	return count;
}
double train::getWeight() {
	return weight;
}

//Add
void train::addCity(const char* c) {
	if (_strlen(c)) {
		char* tmp;
		if (city)
			tmp = _stradd(city, separ, c);
		else
			tmp = _stradd(city, "", c);
		removeCities();
		city = tmp;
	}
}
void train::addCount(int ct) {
	count += ct;
}

//Перезапись
bool train::rewriteCity(const char* c1, const char* c2) {
	if (!city)
		return false;
	if (!_strlen(c2))
		return removeCity(c1);
	if (!_strrw(&city, c1, c2))
		return false;
	return true;
}

//Удаление
void train::removeName() {
	delete[] name;
	name = NULL;
}
bool train::removeCity(const char *c) {
	char *tmp = _stradd(c, "", separ);
	if (!city)
		return false;
	if (!_strrw(&city, tmp, "")) {
		if (!_strrw(&city, c, "")) {
			delete[] tmp;
			return false;
		}
	}
	if (!_strcnt(city, separ)) {
		removeCities();
	}
	delete[] tmp;
	return true;
}
void train::removeCities() {
	delete[] city;
	city = NULL;
}
void train::removeYear() {
	year = 0;
}
void train::removeCount() {
	count = 0;
}
void train::removeWeight() {
	weight = 0;
}

//Считывание
void train::readName() {
	delete[] name;
	name = _strrd("\tВведите имя: ");
	if (!_strlen(name)) {
		delete[] name;
		name = NULL;
	}
}
void train::readCity() {
	delete[] city;
	city = _strrd("\tВведите посещаемые города: ");
	if (!_strlen(city)) {
		delete[] city;
		city = NULL;
	}
	else
		cityRedact();
}
void train::readYear() {
	year = (int)_strdbl(_strrd("\tВведите год выпуска: "));
}
void train::readCount() {
	count = (int)_strdbl(_strrd("\tВведите кол-во вагонов: "));
}
void train::readWeight() {
	weight = _strdbl(_strrd("\tВведите перевозимый вес(кг): "));
}

//Вывод
void train::writeName() const {
	std::cout << "Имя: " << ((name) ? name : emp) << '\n';
}
void train::writeCity() const {
	std::cout << "Посещаемые города: " << ((city) ? city : emp) << '\n';
}
void train::writeYear() const {
	std::cout << "Год выпуска: ";
	if (year) std::cout << year;
	else std::cout << emp;
	std::cout << '\n';
}
void train::writeCount() const {
	std::cout << "Кол-во вагонов: ";
	if (count) std::cout << count;
	else std::cout << emp;
	std::cout << '\n';
}
void train::writeWeight() const {
	std::cout << "Перевозимый вес: ";
	if (weight) std::cout << weight;
	else std::cout << emp;
	std::cout << '\n';
}

//Вывод на экран
std::ostream& operator<<(std::ostream& os, const train &t) {
	char tmp[] = "отсутствует";
	os << "\t\t";
	t.writeName();
	os << "\t\t";
	t.writeCity();
	os << "\t\t";
	t.writeYear();
	os << "\t\t";
	t.writeCount();
	os << "\t\t";
	t.writeWeight();
	return os;
}
void train::print() {
	std::cout << *this;
}

//Id
const char* train::getId() {
	return name;
}

//Присваивание
train& train::operator=(const train& t) {
	if (this == &t)
		return *this;
	setName(t.name);
	setYear(t.year);
	setCities(t.city);
	setCount(t.count);
	setWeight(t.weight);
	return *this;
}

//Деструктор
train::~train() {
	std::cout << "\t\t\t~train()\n";
	delete[] name;
	delete[] city;
}
