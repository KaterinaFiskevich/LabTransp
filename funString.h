#ifndef FUN_STRING_H_
#define FUN_STRING_H_

#include <iostream>
#include <fstream>
#define MAX_SIZE 2048		//������������ ����� ������

//����������� �����������
const char separator[] = ", .!?|/\\:;";

//������
int _strlen(const char* s);   //����� ������
void _strcpy(char* s1, const char *s2, int n);  //����������� ������
void _strcpy(char* s1, const char* s2, int l, int r);
char* _stradd(const char* s1, const char *sep, const char *s2); //������������ ����� 
int _strfind(const char* s1, const char *s2);  //����� ���������
bool _strrw(char** s1, const char *s2, const char *s3);  //������ ���������
int _strcnt(const char *s1, const char* sep); //���-�� ����
int _strnmb(const char *s1, const char *s2, const char* sep); //����� ������ �����
char* _strrd(const char *s); //���������� � ������������
char* _strrd(std::ifstream &is); //���������� �� �����
double _strdbl(const char *str); //char -> double

template <typename T>
T min(const T arg1, const T arg2);  //���������� ������������

#endif // !FUN_STING_H_
