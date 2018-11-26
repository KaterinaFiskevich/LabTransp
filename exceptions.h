#ifndef MY_EXCEPTIONS_H_
#define MY_EXCEPTIONS_H_
#include <iostream>
//����� ��� ������ ���� ����������
class exceptions {
public:
	exceptions();				//�����������
	exceptions(const char*);    //����������� � ����������
	exceptions(exceptions&);    //���������� �����������
	~exceptions();              //����������
	const char* what();         //������� ��������� ���������� �������� ������
private:
	char *mesg;                 //���� ������
	int size;                   //������ ������
};

#endif // !MY_EXCEPTIONS_H_