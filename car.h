#ifndef CAR_H_
#define CAR_H_
#include "transpoter.h"

class car : public transpoter {
public:
	car();				   //�����������
	car(
		int y,
		const char* b,
		const char* m,
		const char* c,
		const double* h,
		double w
	);                     //����������� � ����������
	car(const car &c);     //���������� �����������

	void setYear(int y);				//��������� ���� �������
	void setBrand(const char* b);       //��������� �����
	void setModel(const char* m);       //��������� ������
	void setCities(const char *c);      //��������� ���������� �������
	void setHours(const double *h);     //��������� ����� ��������
	void setWeight(double w);           //��������� ������������ ����

	int getYear();                      //��������� �������� ���� �������
	const char* getBrand();             //��������� �������� �����
	const char* getModel();             //��������� �������� ������
	const char* getCities();            //��������� �������� ���������� �������
	const double* getHours();           //��������� ����� ��������
	double getWeight();                 //��������� �������� ������������ ����

	void addCity(const char* c, double h);   //��������� ������ � ������ ����������

	bool rewriteCity(const char* c1, const char* c2);  //���������� ������
	bool rewriteHours(const char* c, double h);        //���������� ����� ��������

	void removeYear();                                 //������� ���� ���� �������
	void removeBrand();                                //������� ���� �����
	void removeModel();                                //�������� ���� ������
	bool removeCity(const char *c);                    //�������� �� �������� ������ �� �������
	void removeCities();                               //������� ���������� �������
	void removeHours();                                //������� ����� ��������
	void removeWeight();                               //������� ���� ������������ ����

	void readYear();                                   //������ � ������� ���� ������� ������
	void readBrand();                                  //������ � ������� �����
	void readModel();                                  //������ ������
	void readCity();                                   //������ ���������� �������
	void readWeight();                                 //������ ����������� �����

	void writeYear() const;                            //����� � ������� ���� �������
	void writeBrand() const;                           //����� � ������� �����
	void writeModel() const;                           //����� � ������� ������
	void writeCity() const;                            //����� ���������� �������
	void writeWeight() const;                          //����� ����������� �����

	void print();                                                     //����� ������
	friend std::ostream& operator<<(std::ostream& os, const car &p);  //���������� �� �������

	const char* getId();                                //��������� ��������� �� id

	car& operator=(const car& c);                       //�������� ������������

	~car();                                             //����������
private:
	int year;                   //���
	char *brand;                //�����
	char *model;                //������
	double *hours;              //����� �������� � ������ �����
	int countCity;              //���-�� �������
	void init();                //������� �������������
};

#endif //!CAR_H_

