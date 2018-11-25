#ifndef CAR_H_
#define CAR_H_
#include "transpoter.h"

class car : public transpoter {
public:
	car();				   //Конструктор
	car(
		int y,
		const char* b,
		const char* m,
		const char* c,
		const double* h,
		double w
	);                     //Конструктор с параметром
	car(const car &c);     //Конструтор копирования

	void setYear(int y);				//Установка года выпуска
	void setBrand(const char* b);       //Установка марки
	void setModel(const char* m);       //Установка модели
	void setCities(const char *c);      //Установка посещаемых городов
	void setHours(const double *h);     //Установка часов доставки
	void setWeight(double w);           //Установка перевозимого веса

	int getYear();                      //Получение значения года выпуска
	const char* getBrand();             //Получение значения марки
	const char* getModel();             //Получение значения модели
	const char* getCities();            //Получение значения посещаемых городов
	const double* getHours();           //Получение часов доставки
	double getWeight();                 //Получение значения перевозимого веса

	void addCity(const char* c, double h);   //Добвление города в список посещаемых

	bool rewriteCity(const char* c1, const char* c2);  //Перезапись города
	bool rewriteHours(const char* c, double h);        //Перезапись часов доставки

	void removeYear();                                 //Отчиска поле года выпуска
	void removeBrand();                                //Отчиска поля марки
	void removeModel();                                //Отчистка поля модели
	bool removeCity(const char *c);                    //Удаление из маршрута одного из городов
	void removeCities();                               //Отчиска посещаемых городов
	void removeHours();                                //Отчиска часов доставки
	void removeWeight();                               //Отчиска поля перевозимого веса

	void readYear();                                   //Чтение с консоли года выпуска машины
	void readBrand();                                  //Чтение с консоли марки
	void readModel();                                  //Чтение модели
	void readCity();                                   //Чтение посещаемых городов
	void readWeight();                                 //Чтение перевозимой массы

	void writeYear() const;                            //Вывод в консоль года выпуска
	void writeBrand() const;                           //Вывод в консоль марки
	void writeModel() const;                           //Вывод в консоль модели
	void writeCity() const;                            //Вывод посещаемых городов
	void writeWeight() const;                          //Вывод перевохимой массы

	void print();                                                     //Вывод полной
	friend std::ostream& operator<<(std::ostream& os, const car &p);  //инфориации по объекту

	const char* getId();                                //Получение указателя на id

	car& operator=(const car& c);                       //Оператор присваивания

	~car();                                             //Деструктор
private:
	int year;                   //Год
	char *brand;                //Марка
	char *model;                //Модель
	double *hours;              //Время доставки в каждый город
	int countCity;              //Кол-во городов
	void init();                //Функция инициализации
};

#endif //!CAR_H_

