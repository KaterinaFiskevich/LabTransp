#ifndef FUCTION_H_
#define FUCTION_H_
#include "Keeper.h"

void work_plane(Keeper *kpr);		 // Для работы самолетом
void work_train(Keeper *kpr);		 // Для работы с поездом
void work_car(Keeper *kpr);			 // Для работы с авто

template <typename T>
void printName(T *tr, int s);  //Печать массива объектов по id перевозчика переданного типа

template <typename T>
void print(T *tr, int s);      //Печать полной информации перевозчика

template <typename T>
int select(T *tr, int s);      //Выбор перевозчика из массива объектов


#endif //!FUCTION_H_