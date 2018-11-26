#include "exceptions.h"
#include "funString.h"


exceptions::exceptions(): mesg(NULL) {
	std::cout << "\t\t\texceptions()\n";
}
exceptions::exceptions(const char* s) {
	std::cout << "\t\t\texceptions(const char*)\n";
	int i, 
		n = _strlen(s);
	if (n) {
		mesg = new char[++n];
		for (i = 0; i < n; ++i) {
			mesg[i] = s[i];
		}
		size = n;
	}
	else {
		mesg = NULL;
	}
}
exceptions::exceptions(exceptions& e) {
	std::cout << "\t\t\texceptions(exceptions& e)\n";
	size = e.size;
	mesg = new char[size];
	for (int i = 0; i < size; ++i) {
		mesg[i] = e.mesg[i];
	}
}
exceptions::~exceptions() { 
	std::cout << "\t\t\t~exceptions()\n";
	delete[] mesg; 
}
const char* exceptions::what() { 
	return mesg;
}
