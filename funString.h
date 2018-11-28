#ifndef FUN_STRING_H_
#define FUN_STRING_H_

#include <iostream>
#include <fstream>
#define MAX_SIZE 2048		//Максимальная длина строки

//Определение разделителя
const char separator[] = ", .!?|/\\:;";

//Строки
int _strlen(const char* s);   //Длина строки
void _strcpy(char* s1, const char *s2, int n);  //Копирование строки
void _strcpy(char* s1, const char* s2, int l, int r);
char* _stradd(const char* s1, const char *sep, const char *s2); //Конкатенация строк 
int _strfind(const char* s1, const char *s2);  //Поиск подстроки
bool _strrw(char** s1, const char *s2, const char *s3);  //Замена подстроки
int _strcnt(const char *s1, const char* sep); //Кол-во слов
int _strnmb(const char *s1, const char *s2, const char* sep); //Поиск номера слова
char* _strrd(const char *s); //Считывание с приглашением
char* _strrd(std::ifstream &is); //Считывание из файла
double _strdbl(const char *str); //char -> double

template <typename T>
T min(const T arg1, const T arg2);  //Нахождение минимального

#endif // !FUN_STING_H_
