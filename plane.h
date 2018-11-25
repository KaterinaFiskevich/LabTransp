#ifndef PLANE_H_
#define PLANE_H_
#include "transpoter.h"

class plane : public transpoter {
public:
	enum { dimSize = 3 };						//Порядок пространства(длина/ширина/высота)
	plane();									//Конструктор
	plane(
		const char *t,
		const char *n,
		double w,
		const double *d,
		const char *c
	);											//Конструктор с параметром
	plane(const plane &p);						//Конструктор копирования

	void setType(const char* t);				//Установка типа
	void setName(const char* n);				//			имени
	void setWeight(double w);					//			веса
	void setDim(const double *d);				//			габаритов
	void setCities(const char* c);				//			посещаемых городов

	const char* getType();						//Получение типа
	const char* getName();						//			имени
	double getWeight();							//			веса
	const double* getDim();						//			габаритов
	const char* getCities();					//			посещаемых городов

	void addCity(const char* c);				//Добавление города в маршрут


	bool rewriteCity(const char* c1, const char* c2);	// Перезапись города
	void rewriteDim(int i, double d);					// Перезапись одного из параметра габаритов

	void removeType();							//Отчиска поля типа
	void removeName();							//		имени
	void removeWeight();						//		перевозимого веса
	void removeDim();							//		габаритов
	bool removeCity(const char *c);				//Удалить город
	void removeCities();						//Отчиска поля посещаемых городов

	void readType();							//Чтение типа
	void readName();							//		имени
	void readWeight();							//		перевозимого веса
	void readDim();								//		габаритов
	void readCity();							//		посещаемых городов

	void writeType() const;						//Вывод в консоль типа
	void writeName() const;						//		имени
	void writeWeight() const;					//		перевозимого веса
	void writeDim() const;						//		габаритов
	void writeCity() const;						//		посещаемых городов

	void print();															//Функция вывода
	friend std::ostream& operator<<(std::ostream& os, const plane &p);		//информации

	const char* getId();						//Функция получение id

	plane& operator=(const plane& p);			//Оператор присваивания
	~plane();									//Деструктор
private:
	char *type;                 // Тип
	char *name;                 // Имя
	double dimensions[dimSize]; //Габариты
	void init();				//Функция инициализатор
};
#endif // !MY_EXCEPTIONS_H_
