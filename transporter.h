#ifndef TRANSPOTER_H_
#define TRANSPOTER_H_
#include <iostream>
#include "funString.h"

class transpoter {
public:
	virtual void print() = 0;                   //Âûâîä èíôîðìàöèè íà ýêðàí
	virtual const char* getId() = 0;            //Ïîëó÷åíèå id îáúåêòà(îáû÷íî ýòî èìÿ)
	void cityRedact();                          //Óäàëÿåò ëèøíèå ñèìâîëû èç ìàññèâà ïîñåùàåìûõ ãîðîäîâ è çàìåíÿåò èõ separ
protected:
	char *city;                                 //Ìàðøðóò èç ãîðîäîâ
	double weight;                              //Ìàññà ïåðåâîçèìîãî âåñà
	const char separ[3] = ", ";                 //Ñèìâîëû ðàçäåëÿþùèå ãîðîäà
	const char emp[17] = "_Íåò èíôîðìàöèè_";    //×òî âûâîäèòü, åñëè ïàðàìåòð îòñóòñòâóåò
};

#endif //!TRANSPOTER_H_
