#ifndef FUCTION_H_
#define FUCTION_H_
#include "exceptions.h"
#include "plane.h"
#include "train.h"
#include "car.h"


plane* work(plane *p, int &s);  // Для работы самолетом
train* work(train *t, int &s);  // Для работы с поездом
car* work(car *c, int &s);      // Для работы с авто

template <typename T>
void printName(T *tr, int s);  //Печать массива объектов по id перевозчика переданного типа

template <typename T>
void print(T *tr, int s);      //Печать полной информации перевозчика

template <typename T>
int select(T *tr, int s);      //Выбор перевозчика из массива объектов


#endif //!FUCTION_H_