#ifndef FUCTION_H_
#define FUCTION_H_
#include "Keeper.h"

void work_plane(Keeper *kpr);		 // ��� ������ ���������
void work_train(Keeper *kpr);		 // ��� ������ � �������
void work_car(Keeper *kpr);			 // ��� ������ � ����

template <typename T>
void printName(T *tr, int s);  //������ ������� �������� �� id ����������� ����������� ����

template <typename T>
void print(T *tr, int s);      //������ ������ ���������� �����������

template <typename T>
int select(T *tr, int s);      //����� ����������� �� ������� ��������


#endif //!FUCTION_H_