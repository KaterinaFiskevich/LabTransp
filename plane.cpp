#include "plane.h"

//Конструкторы
plane::plane() {
	std::cout << "\t\t\tplane()\n";
	init();
}
plane::plane(
	const char *t,
	const char *n,
	double w,
	const double *d,
	const char *c
) {
	std::cout << "\t\t\tplane(параметры)\n";
	init();
	setType(t);
	setName(n);
	setWeight(w);
	setDim(d);
	setCities(c);
}
plane::plane(const plane &p) {
	std::cout << "\t\t\tplane(const plane&)\n";
	init();
	setType(p.type);
	setName(p.name);
	setWeight(p.weight);
	setDim(p.dimensions);
	setCities(p.city);
}
void plane::init() {
	type = NULL;
	name = NULL;
	weight = 0;
	city = NULL;
	for (int i = 0; i < dimSize; ++i)
		dimensions[i] = 0.0;
}

//Сеттеры
void plane::setType(const char* t) {
	int n = _strlen(t);
	removeType();
	if (n) {
		type = new char[n + 1];
		_strcpy(type, t, n + 1);
	}

}
void plane::setName(const char* n) {
	int m = _strlen(n);
	removeName();
	if (m) {
		name = new char[m + 1];
		_strcpy(name, n, m + 1);
	}
}
void plane::setWeight(double w) {
	weight = w;
}
void plane::setDim(const double *d) {
	for (int i = 0; i < dimSize; ++i)
		dimensions[i] = d[i];
}
void plane::setCities(const char* c) {
	int n = _strlen(c);
	removeCities();
	if (n) {
		city = new char[_strlen(c) + 1];
		_strcpy(city, c, n + 1);
		cityRedact();
	}
}

//Геттеры
const char* plane::getType() {
	return type;
}
const char* plane::getName() {
	return name;
}
double plane::getWeight() {
	return weight;
}
const double* plane::getDim() {
	double *d = new double[dimSize];
	for (int i = 0; i < dimSize; ++i)
		d[i] = dimensions[i];
	return d;
}
const char* plane::getCities() {
	return city;
}

//Add
void plane::addCity(const char* c) {
	if (_strlen(c)) {
		char *tmp;
		if (city)
			tmp = _stradd(city, separ, c);
		else
			tmp = _stradd(city, "", c);
		removeCities();
		city = tmp;
	}
}

//Перезапись
bool plane::rewriteCity(const char* c1, const char* c2) {
	if (!city)
		return false;
	if (!_strlen(c2))
		return removeCity(c1);
	if (!_strrw(&city, c1, c2))
		return false;
	return true;
}
void plane::rewriteDim(int i, double d) {
	dimensions[i] = d;
}

//Удаление
void plane::removeType() {
	delete[] type;
	type = NULL;
}
void plane::removeName() {
	delete[] name;
	name = NULL;

}
void plane::removeWeight() {
	weight = 0.0;
}
void plane::removeDim() {
	for (int i = 0; i < dimSize; ++i)
		dimensions[i] = 0;
}
bool plane::removeCity(const char *c) {
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
void plane::removeCities() {
	delete[] city;
	city = NULL;
}

//Считывание
void plane::readType() {
	delete[] type;
	type = _strrd("\tВведите тип: ");
	if (!_strlen(type)) {
		delete[] type;
		type = NULL;
	}
}
void plane::readName() {
	delete[] name;
	name = _strrd("\tВведите имя: ");
	if (!_strlen(name)) {
		delete[] name;
		name = NULL;
	}
}
void plane::readWeight() {
	weight = _strdbl(_strrd("\tВведите перевозимый вес(кг): "));
}
void plane::readDim() {
	std::cout << "\tВведите габариты самолета:\n";
	dimensions[0] = _strdbl(_strrd("\t\tДлина: "));
	dimensions[1] = _strdbl(_strrd("\t\tШирина: "));
	dimensions[2] = _strdbl(_strrd("\t\tВысота: "));
}
void plane::readCity() {
	delete[] city;
	city = _strrd("\tВведите посещаемые города: ");
	if (!_strlen(city)) {
		delete[] city;
		city = NULL;
	}
	else
		cityRedact();
}

//Вывод
void plane::writeType() const  {
	std::cout << "Тип: " << ((type) ? type : emp) << '\n';
}
void plane::writeName() const {
	std::cout << "Имя: " << ((name) ? name : emp) << '\n';
}
void plane::writeWeight() const {
	std::cout << "Перевозимый вес: ";
	if (weight) std::cout << weight;
	else std::cout << emp;
	std::cout << '\n';
}
void plane::writeDim() const {
	std::cout << "Габариты(Длина / Ширина / Высота): ";
	if (dimensions[0]) std::cout << dimensions[0];
	else std::cout << emp;
	std::cout << " x ";
	if (dimensions[1]) std::cout << dimensions[1];
	else std::cout << emp;
	std::cout << " x ";
	if (dimensions[2]) std::cout << dimensions[2];
	else std::cout << emp;
	std::cout << '\n';
}
void plane::writeCity() const {
	std::cout << "Посещаемые города: " << ((city) ? city : emp) << '\n';
}

//Вывод на экран
std::ostream& operator<<(std::ostream& os, const plane &p) {
	os << "\tПараметры самолета:\n";
	os << "\t\t";
	p.writeType();
	os << "\t\t";
	p.writeName();
	os << "\t\t";
	p.writeWeight();
	os << "\t\t";
	p.writeDim();
	os << "\t\t";
	p.writeCity();
	return os;
}
void plane::print() {
	std::cout << *this;
}

//Id
const char* plane::getId() {
	return name;
}

plane& plane::operator=(const plane& p) {
	if (this == &p)
		return *this;
	setType(p.type);
	setName(p.name);
	setCities(p.city);
	setDim(p.dimensions);
	setWeight(p.weight);
	return *this;
}

//Деструктор
plane::~plane() {
	std::cout << "\t\t\t~plane()\n";
	delete[] type;
	delete[] name;
	delete[] city;
}
