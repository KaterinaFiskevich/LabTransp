#include "transpoter.h"

void transpoter::cityRedact() {
	int i, j;
	int k = 0;
	int nc = _strlen(city);
	int n = MAX_SIZE;
	bool flag = false;
	char *tmp = new char[n];
	for (i = 0; i < nc; ++i) {
		for (j = 0; separator[j] != '\0'; ++j)
			if (separator[j] == city[i])
				break;
		if (separator[j] == '\0') {
			flag = true;
			tmp[k++] = city[i];
		}
		else {
			if (flag) {
				for (j = 0; separ[j] != '\0'; ++j)
					tmp[k++] = separ[j];
				flag = false;
			}
		}
	}
	tmp[k] = '\0';
	delete[] city;

	n = _strlen(tmp);
	city = new char[n + 1];
	for (i = 0; i < n; ++i)
		city[i] = tmp[i];
	city[i] = '\0';
	delete[] tmp;
}

