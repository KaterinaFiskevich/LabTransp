#ifndef FUCTION_H_
#define FUCTION_H_
#include "exceptions.h"
#include "plane.h"
#include "train.h"
#include "car.h"


plane* work(plane *p, int &s);  // ��� ������ ���������
train* work(train *t, int &s);  // ��� ������ � �������
car* work(car *c, int &s);      // ��� ������ � ����

template <typename T>
void printName(T *tr, int s);  //������ ������� �������� �� id ����������� ����������� ����

template <typename T>
void print(T *tr, int s);      //������ ������ ���������� �����������

template <typename T>
int select(T *tr, int s);      //����� ����������� �� ������� ��������


#endif //!FUCTION_H_