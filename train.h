#ifndef TRAIN_H_
#define TRAIN_H_
#include "transpoter.h"

class train : public transpoter {
public:
	train();								//Конструктор
	train(
		const char *n,
		int y,
		const char *c,
		int ct,
		double w
	);										//Конструктор с параметром
	train(const train &t);					//Конструктор копирования


	void setName(const char* n);			//Установить имя
	void setYear(int y);					//Установить год выпуска
	void setCities(const char* c);			//Установить список посещаемых городов
	void setCount(int y);					//Установить кол-во вагонов
	void setWeight(double w);				//Установить перевозимый вес

	const char* getName();					//Получить имя
	int getYear();							//Получить год выпуска
	const char* getCities();				//получить посещаемые города
	int getCount();							//Получить кол-во вагонов
	double getWeight();						//Получить массу перевозимого груза

	void addCity(const char* c);			//Добавление города в маршрут
	void addCount(int ct);					//Добавление кол-ва вагонов к составу

	bool rewriteCity(const char* c1, const char* c2);	//Перезапись города

	void removeName();						//Отчистить поле имени
	void removeYear();						//Отчистить поле года выпуска
	bool removeCity(const char *c);			//Удалить город
	void removeCities();					//Отчистить список посещаемых городов
	void removeCount();						//Отчситить кол-во вагонов
	void removeWeight();					//Отчистить поле хранения веса

	void readName();						//Чтение с консоли имени
	void readCity();						//		посещаемых городов
	void readYear();						//		года выпуска
	void readCount();						//		кол-ва вагонов
	void readWeight();						//		перевозимой массы

	void writeName() const;					//Вывод в консоль имени
	void writeCity() const;					//		посещаемых городов
	void writeYear() const;					//		года выпуска
	void writeCount() const;				//		кол-ва вагонов
	void writeWeight() const;				//		перевозимой массы

	void print();							//Функция вывода информации
	friend std::ostream& operator<<(std::ostream& os, const train &p);		//Функция вывода информации

	const char* getId();					//Функция получение id

	train& operator=(const train &t);		//Оператор присваивания

	~train();								//Деструктор
private:
	char *name;                 //Имя
	int year;                   //Год 
	int count;                  //Кол-во вагонов
	void init();                //Функция инициализатор
};

#endif // !TRAIN_H_


