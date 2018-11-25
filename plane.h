#ifndef PLANE_H_
#define PLANE_H_
#include "transpoter.h"

class plane : public transpoter {
public:
	enum { dimSize = 3 };						//������� ������������(�����/������/������)
	plane();									//�����������
	plane(
		const char *t,
		const char *n,
		double w,
		const double *d,
		const char *c
	);											//����������� � ����������
	plane(const plane &p);						//����������� �����������

	void setType(const char* t);				//��������� ����
	void setName(const char* n);				//			�����
	void setWeight(double w);					//			����
	void setDim(const double *d);				//			���������
	void setCities(const char* c);				//			���������� �������

	const char* getType();						//��������� ����
	const char* getName();						//			�����
	double getWeight();							//			����
	const double* getDim();						//			���������
	const char* getCities();					//			���������� �������

	void addCity(const char* c);				//���������� ������ � �������


	bool rewriteCity(const char* c1, const char* c2);	// ���������� ������
	void rewriteDim(int i, double d);					// ���������� ������ �� ��������� ���������

	void removeType();							//������� ���� ����
	void removeName();							//		�����
	void removeWeight();						//		������������ ����
	void removeDim();							//		���������
	bool removeCity(const char *c);				//������� �����
	void removeCities();						//������� ���� ���������� �������

	void readType();							//������ ����
	void readName();							//		�����
	void readWeight();							//		������������ ����
	void readDim();								//		���������
	void readCity();							//		���������� �������

	void writeType() const;						//����� � ������� ����
	void writeName() const;						//		�����
	void writeWeight() const;					//		������������ ����
	void writeDim() const;						//		���������
	void writeCity() const;						//		���������� �������

	void print();															//������� ������
	friend std::ostream& operator<<(std::ostream& os, const plane &p);		//����������

	const char* getId();						//������� ��������� id

	plane& operator=(const plane& p);			//�������� ������������
	~plane();									//����������
private:
	char *type;                 // ���
	char *name;                 // ���
	double dimensions[dimSize]; //��������
	void init();				//������� �������������
};
#endif // !MY_EXCEPTIONS_H_
