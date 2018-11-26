#ifndef MY_EXCEPTIONS_H_
#define MY_EXCEPTIONS_H_
#include <iostream>
//Класс для отлова всех исключений
class exceptions {
public:
	exceptions();				//Конструктор
	exceptions(const char*);    //Конструктор с параметром
	exceptions(exceptions&);    //Конструтор копирования
	~exceptions();              //Деструктор
	const char* what();         //Функция получения текстового описания ошибки
private:
	char *mesg;                 //Текс ошибка
	int size;                   //Размер текста
};

#endif // !MY_EXCEPTIONS_H_