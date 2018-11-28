#ifndef TRANSPOTER_H_
#define TRANSPOTER_H_
#include <iostream>
#include "funString.h"

class transpoter {
public:
	virtual void print() = 0;                   //экран
	virtual const char* getId() = 0;            //Получение id объекта(обычно это имя)
	void cityRedact();                          //Удаляет лишние символы из массива посещаемых городов и заменяет их separ
protected:
	char *city;                                 //Маршрут из городов
	double weight;                              //вес
	const char separ[3] = ", ";                 //Символы разделяющие города
	const char emp[17] = "_Нет информации_";    
};

#endif //!TRANSPOTER_H_
