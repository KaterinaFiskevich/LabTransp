#ifndef TRANSPOTER_H_
#define TRANSPOTER_H_
#include <iostream>
#include "funString.h"

class transpoter {
public:
	virtual void print() = 0;                   //�����
	virtual const char* getId() = 0;            //��������� id �������(������ ��� ���)
	void cityRedact();                          //������� ������ ������� �� ������� ���������� ������� � �������� �� separ
protected:
	char *city;                                 //������� �� �������
	double weight;                              //���
	const char separ[3] = ", ";                 //������� ����������� ������
	const char emp[17] = "_��� ����������_";    
};

#endif //!TRANSPOTER_H_
