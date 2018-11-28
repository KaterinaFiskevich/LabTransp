#include "Keeper.h"
#include "exceptions.h"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

#define PATH "C:/Katya/Base.txt"

Keeper::Keeper() : p(NULL), t(NULL), c(NULL) {
	for (int i = 0; i < COUNT; ++i)
		size[i] = 0;
}
Keeper::~Keeper() {
	delete[] p;
	delete[] t;
	delete[] c;
}

void Keeper::add_transpoter(transpoter* tr, int dec) {
	int i;
	plane *ptr1 = NULL;
	train *ptr2 = NULL;
	car *ptr3 = NULL;
	switch (dec) {
	case 0:
		ptr1 = new plane[size[0] + 1];
		for (i = 0; i < size[0]; ++i) {
			ptr1[i] = *(p + i);
		}
		delete[] p;
		p = ptr1;
		if(tr) p[size[0]] = (*(plane*)(tr));
		++size[0];
		break;
	case 1:
		ptr2 = new train[size[1] + 1];
		for (i = 0; i < size[1]; ++i) {
			ptr2[i] = *(t + i);
		}
		delete[] t;
		t = ptr2;
		if(tr) t[size[1]] = (*(train*)(tr));
		++size[1];
		break;
	case 2:
		ptr3 = new car[size[2] + 1];
		for (i = 0; i < size[2]; ++i) {
			ptr3[i] = *(c + i);
		}
		delete[] c;
		c = ptr3;
		if(tr) c[size[2]] = (*(car*)(tr));
		++size[2];
		break;
	}
}
void Keeper::delete_transpoter(int trNum, int dec) {
	int i;
	plane *ptr1 = NULL;
	train *ptr2 = NULL;
	car *ptr3 = NULL;
	switch (trNum) {
	case 0:
		ptr1 = new plane[size[0] - 1];
		for (i = 0; i < dec; ++i) {
			ptr1[i] = p[i];
		}
		for (++i; i < size[0]; ++i) {
			ptr1[i - 1] = p[i];
		}
		delete[] p;
		p = ptr1;
		--size[0];
		break;
	case 1:
		ptr2 = new train[size[1] - 1];
		for (i = 0; i < dec; ++i) {
			ptr2[i] = t[i];
		}
		for (++i; i < size[1]; ++i) {
			ptr2[i - 1] = t[i];
		}
		delete[] t;
		t = ptr2;
		--size[1];
		break;
	case 2:
		ptr3 = new car[size[2] - 1];
		for (i = 0; i < dec; ++i) {
			ptr3[i] = c[i];
		}
		for (++i; i < size[2]; ++i) {
			ptr3[i - 1] = c[i];
		}
		delete[] c;
		c = ptr3;
		--size[2];
		break;
	}
}

void Keeper::save() {
	int i, j;
	ofstream out(PATH);
	exceptions e("Файл не был открыт");
	if (!out.is_open()) {
		throw e;
	}
	for (i = 0; i < size[0]; ++i) {
		if (p[i].getType())
			out << p[i].getType() << ';';
		else
			out << '\0' << ';';
		if(p[i].getName())
			out << p[i].getName() << ';';
		else
			out << '\0' << ';';
		if (p[i].getWeight())
			out << p[i].getWeight() << ';';
		else
			out << '\0' << ';';
		for (j = 0; j < plane::dimSize; ++j) {
			if (*(p[i].getDim() + j))
				out << *(p[i].getDim() + j) << ';';
			else
				out << '\0' << ';';
		}
		if (p[i].getCities())
			out << p[i].getCities() << ';';
		else
			out << '\0' << ';';
		out << endl;
	}
	out << endl;
	for (i = 0; i < size[1]; ++i) {
		if (t[i].getName())
			out << t[i].getName() << ';';
		else
			out << '\0' << ';';
		if (t[i].getYear())
			out << t[i].getYear() << ';';
		else
			out << '\0' << ';';
		if (t[i].getCities())
			out << t[i].getCities() << ';';
		else
			out << '\0' << ';';
		if (t[i].getCount())
			out << t[i].getCount() << ';';
		else
			out << '\0' << ';';
		if (t[i].getWeight())
			out << t[i].getWeight() << ';';
		else
			out << '\0' << ';';
		out << endl;
	}
	out << endl;
	for (i = 0; i < size[2]; ++i) {
		if (c[i].getYear())
			out << c[i].getYear() << ';';
		else
			out << '\0' << ';';
		if (c[i].getBrand())
			out << c[i].getBrand() << ';';
		else
			out << '\0' << ';';
		if (c[i].getModel())
			out << c[i].getModel() << ';';
		else
			out << '\0' << ';';
		if (c[i].getCities())
			out << c[i].getCities() << ';';
		else
			out << '\0' << ';';
		for (j = 0; i < c[j].getcountCity(); ++j) {
			if (*(c[i].getHours() + j))
				out << *(c[i].getHours() + j) << ';';
			else
				out << '\0' << ';';
		}
		if (c[i].getWeight())
			out << c[i].getWeight() << ';';
		else
			out << '\0' << ';';
		out << endl;
	}
	out.close();
}
void Keeper::load() {
	int i, j, k;
	int n;
	char* ptr;
	char* ptr2;
	ifstream in(PATH);
	exceptions e("Файл не был открыт");
	if (!in.is_open()) {
		throw e;
	}
	for (i = 0; 1; ++i) {
		ptr = _strrd(in);
		if (!ptr) {
			in.close();
			return;
		}
		if (ptr[0] != '\n') {
			add_transpoter(NULL, 0);

			for (k = 0; ptr[k] != ';'; ++k);
			n = k;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, 0, k);
			ptr2[n] = '\0';
			p[size[0] - 1].setType(ptr2);
			delete[] ptr2;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			p[size[0] - 1].setName(ptr2);
			delete[] ptr2;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			p[size[0] - 1].setWeight(_strdbl(ptr2));
			delete[] ptr2;

			double d[plane::dimSize];
			for (int t = 0; t < plane::dimSize; ++t) {
				j = ++k;
				for (; ptr[k] != ';'; ++k);
				n = k - j;
				ptr2 = new char[n + 1];
				_strcpy(ptr2, ptr, j, k);
				ptr2[n] = '\0';
				d[t] = _strdbl(ptr2);
				delete[] ptr2;
			}
			p[size[0] - 1].setDim(d);

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			p[size[0] - 1].setCities(ptr2);
			delete[] ptr2;

			delete[] ptr;
		}
		else {
			delete[] ptr;
			break;
		}
	}
	for (i = 0; 1; ++i) {
		ptr = _strrd(in);
		if (!ptr) {
			in.close();
			return;
		}
		if (ptr[0] != '\n') {
			add_transpoter(NULL, 1);

			for (k = 0; ptr[k] != ';'; ++k);
			n = k;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, 0, k);
			ptr2[n] = '\0';
			t[size[1] - 1].setName(ptr2);
			delete[] ptr2;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			t[size[1] - 1].setYear((int)_strdbl(ptr2));
			delete[] ptr2;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			t[size[1] - 1].setCities(ptr2);
			delete[] ptr2;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			t[size[1] - 1].setCount((int)_strdbl(ptr2));
			delete[] ptr2;
				
			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			t[size[1] - 1].setWeight(_strdbl(ptr2));
			delete[] ptr2;

			delete[] ptr;
		}
		else {
			delete[] ptr;
			break;
		}

	}
	for (i = 0; 1; ++i) {
		ptr = _strrd(in);
		if (!ptr) {
			in.close();
			return;
		}
		if (ptr[0] != '\n') {
			add_transpoter(NULL, 2);

			for (k = 0; ptr[k] != ';'; ++k);
			n = k;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, 0, k);
			ptr2[n] = '\0';
			c[size[2] - 1].setYear((int)_strdbl(ptr2));
			delete[] ptr2;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			c[size[2] - 1].setBrand(ptr2);
			delete[] ptr2;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			c[size[2] - 1].setModel(ptr2);
			delete[] ptr2;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			c[size[2] - 1].setCities(ptr2);
			delete[] ptr2;

			double *d = new double[c[i].getcountCity()];
			for (int t = 0; t < c[i].getcountCity(); ++t) {
				j = ++k;
				for (; ptr[k] != ';'; ++k);
				n = k - j;
				ptr2 = new char[n + 1];
				_strcpy(ptr2, ptr, j, k);
				ptr2[n] = '\0';
				d[t] = _strdbl(ptr2);
				delete[] ptr2;
			}
			c[size[2] - 1].setHours(d);
			delete[] d;

			j = ++k;
			for (; ptr[k] != ';'; ++k);
			n = k - j;
			ptr2 = new char[n + 1];
			_strcpy(ptr2, ptr, j, k);
			ptr2[n] = '\0';
			c[size[2] - 1].setWeight(_strdbl(ptr2));
			delete[] ptr2;

			delete[] ptr;
		}
		else {
			delete[] ptr;
			break;
		}
	}
	in.close();
}
