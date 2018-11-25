#ifndef TRAIN_H_
#define TRAIN_H_
#include "transpoter.h"

class train : public transpoter {
public:
	train();								//�����������
	train(
		const char *n,
		int y,
		const char *c,
		int ct,
		double w
	);										//����������� � ����������
	train(const train &t);					//����������� �����������


	void setName(const char* n);			//���������� ���
	void setYear(int y);					//���������� ��� �������
	void setCities(const char* c);			//���������� ������ ���������� �������
	void setCount(int y);					//���������� ���-�� �������
	void setWeight(double w);				//���������� ����������� ���

	const char* getName();					//�������� ���
	int getYear();							//�������� ��� �������
	const char* getCities();				//�������� ���������� ������
	int getCount();							//�������� ���-�� �������
	double getWeight();						//�������� ����� ������������ �����

	void addCity(const char* c);			//���������� ������ � �������
	void addCount(int ct);					//���������� ���-�� ������� � �������

	bool rewriteCity(const char* c1, const char* c2);	//���������� ������

	void removeName();						//��������� ���� �����
	void removeYear();						//��������� ���� ���� �������
	bool removeCity(const char *c);			//������� �����
	void removeCities();					//��������� ������ ���������� �������
	void removeCount();						//��������� ���-�� �������
	void removeWeight();					//��������� ���� �������� ����

	void readName();						//������ � ������� �����
	void readCity();						//		���������� �������
	void readYear();						//		���� �������
	void readCount();						//		���-�� �������
	void readWeight();						//		����������� �����

	void writeName() const;					//����� � ������� �����
	void writeCity() const;					//		���������� �������
	void writeYear() const;					//		���� �������
	void writeCount() const;				//		���-�� �������
	void writeWeight() const;				//		����������� �����

	void print();							//������� ������ ����������
	friend std::ostream& operator<<(std::ostream& os, const train &p);		//������� ������ ����������

	const char* getId();					//������� ��������� id

	train& operator=(const train &t);		//�������� ������������

	~train();								//����������
private:
	char *name;                 //���
	int year;                   //��� 
	int count;                  //���-�� �������
	void init();                //������� �������������
};

#endif // !TRAIN_H_


