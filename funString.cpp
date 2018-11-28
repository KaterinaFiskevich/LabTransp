#include "funString.h"

int _strlen(const char* s) {
	int i = 0;
	if (s == NULL)
		return i;
	for (i = 0; s[i] != '\0'; ++i);
	return i;
}
void _strcpy(char* s1, const char* s2, int n) {
	for (int i = 0; i < n; ++i)
		s1[i] = s2[i];
}
void _strcpy(char* s1, const char* s2, int l, int r) {
	int j = 0;
	for (int i = l; i < r; ++i)
		s1[j++] = s2[i];
}
char* _stradd(const char *s1, const char *sep, const char* s2) {
	int i, j;
	int n1 = _strlen(s1);
	int n2 = _strlen(sep);
	int n3 = _strlen(s2);
	int n = n1 + n2 + n3 + 1;
	if (n == 1)
		return NULL;
	char *res = new char[n];
	for (i = 0; i < n1; ++i)
		res[i] = s1[i];
	for (j = 0; j < n2; ++j, ++i)
		res[i] = sep[j];
	for (j = 0; j < n3; ++j, ++i)
		res[i] = s2[j];
	res[i] = '\0';
	return res;
}
int _strfind(const char* s1, const char *s2) {
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0' && s1[i + j] != '\0'; ++j) {
			if (s1[i + j] != s2[j])
				break;
		}
		if (s2[j] == '\0')
			break;
	}
	return i;
}
bool _strrw(char** s1, const char *s2, const char *s3) {
	int i, j, k;
	int n = _strfind(*s1, s2);
	int n1 = _strlen(*s1);
	int n2 = _strlen(s2);
	int n3 = _strlen(s3);
	if (n < n1) {
		char *tmp = new char[n1 + n3 - n2 + 1];
		for (i = 0; i < n; ++i)
			tmp[i] = (*s1)[i];
		k = i + n2;
		for (j = 0; j < n3; ++j, ++i)
			tmp[i] = s3[j];
		for (j = k; j < n1; ++j, ++i)
			tmp[i] = (*s1)[j];
		tmp[i] = '\0';
		delete[] * s1;
		*s1 = tmp;
	}
	else
		return false;
	return true;
}
int _strcnt(const char *s1, const char* sep) {
	int i, j;
	int count = 0;
	bool flag = false;
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; sep[j] != '\0'; ++j)
			if (s1[i] == sep[j])
				break;
		if (sep[j] != '\0') {
			if (flag) {
				++count;
				flag = false;
			}
		}
		else
			flag = true;
	}
	return ((flag) ? ++count : count);
}
int _strnmb(const char *s1, const char *s2, const char* sep) {
	int n = _strfind(s1, s2);
	if (n == _strlen(s1))
		return n;
	char *tmp = new char[n + 1];
	tmp[n] = '\0';
	_strcpy(tmp, s1, n + 1);
	n = _strcnt(tmp, sep);
	delete[] tmp;
	return n;
}
char* _strrd(const char *s) {
	int i;
	char *ptr;
	char c[MAX_SIZE];
	std::cout << s;
	for (i = 0; (c[i] = getchar()) != '\n'; ++i);
	c[i] = '\0';
	ptr = new char[i + 1];
	do {
		ptr[i] = c[i];
	} while (i--);
	return ptr;
}
char* _strrd(std::ifstream &in) {
	int i;
	char *ptr = NULL;
	char c[MAX_SIZE];
	for (i = 0; (c[i] = in.get()) != '\n' && c[i] != EOF; ++i);
	if (c[i] == EOF) return ptr;
	c[++i] = '\0';
	ptr = new char[i + 1];
	do {
		ptr[i] = c[i];
	} while (i--);
	return ptr;
}
double _strdbl(const char *str) {
	int i;
	double num = 0.0;
	double k = 10.0;
	for (i = 0; str[i] != '\0'; ++i) {
		if (str[i] > 47 && str[i] < 58)
			num = num * k + ((int)str[i] - 48);
		if (str[i] == '.')
			break;
	}
	if (str[i] != '\0') {
		for (++i; str[i] != '\0'; ++i) {
			if (str[i] > 47 && str[i] < 58) {
				num += double((int)str[i] - 48) / k;
				k *= 10.0;
			}
		}
	}
	return num;
}

template <typename T>
T min(const T arg1, const T arg2) {
	return ((arg1 < arg2) ? arg1 : arg2);
}
