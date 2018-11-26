#include "function.h"


plane* work(plane *p, int &s) {
	using std::cout;
	using std::cin;
	int i;
	int ch;
	bool flag = true;
	plane *ptr;
	while (flag) {
		ptr = NULL;
		cout
			<< "   1) �������� �������\n"
			<< "   2) ������� �������\n"
			<< "   3) ������� ������� ��� ������\n"
			<< "   4) ������� ������ ��������� �� ������\n"
			<< "   5) ������� ������ ���������� �� ���������\n"
			<< "   6) ���������\n";
		cout << "�������� ����� ������: ";
		cin >> ch;
		getchar();
		switch (ch) {
		case 1:
			cout << "   ���� ������ �������� �������� ������ ������� enter\n";
			cout << "   �������-�����������: " << separator << "\n";
			ptr = new plane[s + 1];
			for (i = 0; i < s; ++i) {
				ptr[i] = *(p + i);
			}
			delete[] p;
			p = ptr;
			p[s].readType();
			p[s].readName();
			p[s].readWeight();
			p[s].readDim();
			p[s].readCity();
			++s;
			break;
		case 2:
			if (s) {
				try {
					ch = select(p, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				for (i = 0; i < ch; ++i) {
					ptr[i] = p[i];
				}
				for (++i; i < s; ++i) {
					ptr[i - 1] = p[i];
				}
				delete[] p;
				p = ptr;
				--s;
				std::cout << "�������� ���������\n";
			}
			else {
				printName(p, s);
			}
			break;
		case 3:
			if (s) {
				int n;
				char *str;
				try {
					ch = select(p, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				cout
					<< "\n\n"
					<< "    1| ������ ����� ���\n"
					<< "    2| ������ ����� ���\n"
					<< "    3| ������ ����� ����������� ���\n"
					<< "    4| ������ ����� ��������\n"
					<< "    5| ������ ����� ���������� ������\n"
					<< "    6| �������� ����� �����\n"
					<< "    7| ��������� ���� �� �������\n"
					<< "    8| �������� �����, ������ ��� ������\n"
					<< "    9| ������� �� ����� ���\n"
					<< "   10| ������� �� ����� ���\n"
					<< "   11| ������� �� ����� ����������� ���\n"
					<< "   12| ������� �� ����� ��������\n"
					<< "   13| ������� �� ����� ���������� ������\n"
					<< "   14| ��������� ���� ����\n"
					<< "   15| ��������� ���� �����\n"
					<< "   16| ��������� ���� ������������ ����\n"
					<< "   17| ��������� ���� ���������\n"
					<< "   18| ������� �����\n"
					<< "   19| ��������� ���� ���������� �������\n"
					<< "   20| ���������\n";
				while (flag) {
					str = NULL;
					cout << "�������� ����� ������: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						p[ch].readType();
						std::cout << "\t\t�������\n";
						break;
					case 2:
						p[ch].readName();
						std::cout << "\t\t�������\n";
						break;
					case 3:
						p[ch].readWeight();
						std::cout << "\t�������\n";
						break;
					case 4:
						p[ch].readDim();
						std::cout << "\t�������\n";
						break;
					case 5:
						p[ch].readCity();
						std::cout << "\t�������\n";
						break;
					case 6:
						str = _strrd("\t������� �������� ������: ");
						p[ch].addCity(str);
						std::cout << "\t�������\n";
						break;
					case 7: 
						if(p[ch].getCities()) {
							char *str2;
							cout << "\t";
							p[ch].writeCity();
							str = _strrd("������� �������� ����������� ������: ");
							str2 = _strrd("������� �������� ����������� ������: ");
							if (p[ch].rewriteCity(str, str2))
								std::cout << "\t�������\n";
							else
								std::cout << "\t����� �� ������������ � ������\n";
							delete[] str2;
						}
						else 
							std::cout << "\t������ ���������� ������� ����";
						break;
					case 8:
						cout
							<< "\t0 - �������� �����"
							<< "\t1 - �������� ������"
							<< "\t2 - �������� ������"
							<< "\n������� ����� ������: ";
						cin >> n;
						getchar();
						str = _strrd("������� ��������: ");
						p[ch].rewriteDim(n, _strdbl(str));
						std::cout << "�������\n";
						break;
					case 9:
						cout << "\t";
						p[ch].writeType();
						break;
					case 10:
						cout << "\t";
						p[ch].writeName();
						break;
					case 11:
						cout << "\t";
						p[ch].writeWeight();
						break;
					case 12:
						cout << "\t";
						p[ch].writeDim();
						break;
					case 13:
						cout << "\t";
						p[ch].writeCity();
						break;
					case 14:
						p[ch].removeType();
						std::cout << "\t�������\n";
						break;
					case 15:
						p[ch].removeName();
						std::cout << "\t�������\n";
						break;
					case 16:
						p[ch].removeWeight();
						std::cout << "\t�������\n";
						break;
					case 17:
						p[ch].removeDim();
						std::cout << "\t�������\n";
						break;
					case 18:
						if (p[ch].getCities()) {
							cout << "\t";
							p[ch].writeCity();
							str = _strrd("������� �������� ������: ");
							if (p[ch].removeCity(str))
								std::cout << "\t�������\n";
							else
								std::cout << "\t����� �� ������������ � ������\n";
						}
						else
							std::cout << "\t������ ���������� ������� ����";
						break;
					case 19:
						p[ch].removeCities();
						std::cout << "\t�������\n";
						break;
					case 20:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
				print(p, s);
			}
			break;
		case 4:
			printName(p, s);
			break;
		case 5:
			print(p, s);
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
	return p;
}
train* work(train *t, int &s) {
	using std::cout;
	using std::cin;
	int i;
	int ch;
	bool flag = true;
	train *ptr;
	while (flag) {
		ptr = NULL;
		cout
			<< "   1) �������� �����\n"
			<< "   2) ������� �����\n"
			<< "   3) ������� ����� ��� ������\n"
			<< "   4) ������� ������ ������� �� ������\n"
			<< "   5) ������� ������ ���������� �� �������\n"
			<< "   6) ���������\n";
		cout << "�������� ����� ������: ";
		cin >> ch;
		getchar();
		switch (ch) {
		case 1:
			cout << "   ���� ������ �������� �������� ������ ������� enter\n";
			cout << "   �������-�����������: " << separator << '\n';
			ptr = new train[s + 1];
			for (i = 0; i < s; ++i) {
				ptr[i] = *(t + i);
			}
			delete[] t;
			t = ptr;
			t[s].readName();
			t[s].readYear();
			t[s].readCity();
			t[s].readCount();
			t[s].readWeight();
			++s;
			break;
		case 2:
			if (s) {
				try {
					ch = select(t, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				ptr = new train[s - 1];
				for (i = 0; i < ch; ++i) {
					ptr[i] = t[i];
				}
				for (++i; i < s; ++i) {
					ptr[i - 1] = t[i];
				}
				delete[] t;
				t = ptr;
				--s;
				std::cout << "\t�������� ���������\n";
			}
			else {
				print(t, s);
			}
			break;
		case 3:
			if (s) {
				int n;
				char *str;
				try {
					ch = select(t, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				cout
					<< "\n\n"
					<< "    1| ������ ����� ���\n"
					<< "    2| ������ ����� ��� �������\n"
					<< "    3| ������ ����� ���������� ������\n"
					<< "    4| ������ ����� ���-�� �������\n"
					<< "    5| ������ ����� ����������� ���\n"
					<< "    6| �������� ����� �����\n"
					<< "    7| �������� ���-�� �������\n"
					<< "    8| ��������� ���� �� �������\n"
					<< "    9| ������� �� ����� ���\n"
					<< "   10| ������� �� ����� ��� �������\n"
					<< "   11| ������� �� ����� ���������� ������\n"
					<< "   12| ������� �� ����� ���-�� �������\n"
					<< "   13| ������� �� ����� ����������� ���\n"
					<< "   14| �������� ���� �����\n"
					<< "   15| �������� ���� ���� �������\n"
					<< "   16| �������� ���� ���������� �������\n"
					<< "   17| ������� �����\n"
					<< "   18| �������� ���� ���-�� �������\n"
					<< "   19| �������� ���� ������������ ����\n"
					<< "   20| ���������\n";
				while (flag) {
					str = NULL;
					cout << "�������� ����� ������: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						t[ch].readName();
						std::cout << "\t�������\n";
						break;
					case 2:
						t[ch].readYear();
						std::cout << "\t�������\n";
						break;
					case 3:
						t[ch].readCity();
						std::cout << "\t�������\n";
						break;
					case 4:
						t[ch].readCount();
						std::cout << "\t�������\n";
						break;
					case 5:
						t[ch].readWeight();
						std::cout << "\t�������\n";
						break;
					case 6:
						str = _strrd("\t������� �������� ������: ");
						t[ch].addCity(str);
						std::cout << "\t�������\n";
						break;
					case 7:
						cout << "\t";
						str = _strrd("������� ���-�� ����������� �������: ");
						t[ch].addCount(int(_strdbl(str)));
						std::cout << "\t�������\n";
						break;
					case 8:
						if (t[ch].getCities()) {
							char *str2;
							cout << "\t";
							t[ch].writeCity();
							str = _strrd("������� �������� ����������� ������: ");
							str2 = _strrd("������� �������� ����������� ������: ");
							if (t[ch].rewriteCity(str, str2))
								std::cout << "\t�������\n";
							else
								std::cout << "\t����� �� ������������ � ������\n";
							delete[] str2;
						}
						else
							std::cout << "\t������ ���������� ������� ����";
						break;
					case 9:
						cout << "\t";
						t[ch].writeName();
						break;
					case 10:
						cout << "\t";
						t[ch].writeYear();
						break;
					case 11:
						cout << "\t";
						t[ch].writeCity();
						break;
					case 12:
						cout << "\t";
						t[ch].writeCount();
						break;
					case 13:
						cout << "\t";
						t[ch].writeWeight();
						break;
					case 14:
						t[ch].removeName();
						std::cout << "\t�������\n";
						break;
					case 15:
						t[ch].removeYear();
						std::cout << "\t�������\n";
						break;
					case 16:
						t[ch].removeCities();
						std::cout << "\t�������\n";
						break;
					case 17:
						if (t[ch].getCities()) {
							cout << "\t";
							t[ch].writeCity();
							str = _strrd("������� �������� ������: ");
							if (t[ch].removeCity(str))
								std::cout << "\t�������\n";
							else
								std::cout << "\t����� �� ������������ � ������\n";
						}
						else
							std::cout << "\t������ ���������� ������� ����";
						break;
					case 18:
						t[ch].removeCount();
						std::cout << "\t�������\n";
						break;
					case 19:
						t[ch].removeWeight();
						std::cout << "\t�������\n";
						break;
					case 20:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
				print(t, s);
			}
			break;
		case 4:
			printName(t, s);
			break;
		case 5:
			print(t, s);
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
	return t;
}
car* work(car *cr, int &s) {
	using std::cout;
	using std::cin;
	int i;
	int ch;
	bool flag = true;
	car *ptr;
	while (flag) {
		ptr = NULL;
		cout
			<< "   1) �������� ������\n"
			<< "   2) ������� ������\n"
			<< "   3) ������� ������ ��� ������\n"
			<< "   4) ������� ������ ����� �� ������\n"
			<< "   5) ������� ������ ���������� �� �������\n"
			<< "   6) ���������\n";
		cout << "�������� ����� ������: ";
		cin >> ch;
		getchar();
		switch (ch) {
		case 1:
			cout << "   ���� ������ �������� �������� ������ ������� enter\n";
			cout << "   �������-�����������: " << separator << '\n';
			ptr = new car[s + 1];
			for (i = 0; i < s; ++i) {
				ptr[i] = *(cr + i);
			}
			delete[] cr;
			cr = ptr;
			cr[s].readYear();
			cr[s].readBrand();
			cr[s].readModel();
			cr[s].readCity();
			cr[s].readWeight();
			++s;
			break;
		case 2:
			if (s) {
				try {
					ch = select(cr, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				ptr = new car[s - 1];
				for (i = 0; i < ch; ++i) {
					ptr[i] = cr[i];
				}
				for (++i; i < s; ++i) {
					ptr[i - 1] = cr[i];
				}
				delete[] cr;
				cr = ptr;
				--s;
				std::cout << "\t�������� ���������\n";
			}
			else {
				print(cr, s);
			}
			break;
		case 3:
			if (s) {
				int n;
				char *str;
				try {
					ch = select(cr, s);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				cout
					<< "\n\n"
					<< "    1| ������ ����� ��� �������\n"
					<< "    2| ������ ����� �����\n"
					<< "    3| ������ ����� ������\n"
					<< "    4| ������ ����� ���������� ������\n"
					<< "    5| ������ ����� ����������� ���\n"
					<< "    6| �������� ����� �����\n"
					<< "    7| �������� ���� �� �������\n"
					<< "    8| �������� ���� �������� � ������ �� �������\n"
					<< "    9| ������� �� ����� ��� �������\n"
					<< "   10| ������� �� ����� �����\n"
					<< "   11| ������� �� ����� ������\n"
					<< "   12| ������� �� ����� ���������� ������\n"
					<< "   13| ������� �� ����� ����������� ���\n"
					<< "   14| �������� ���� ���� �������\n"
					<< "   15| �������� ���� �����\n"
					<< "   16| �������� ���� ������\n"
					<< "   17| ������� �����\n"
					<< "   18| �������� ���� ���������� ������\n"
					<< "   19| �������� ���� ������������ ����\n"
					<< "   20| ���������\n";
				while (flag) {
					str = NULL;
					cout << "�������� ����� ������: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						cr[ch].readYear();
						std::cout << "\t�������\n";
						break;
					case 2:
						cr[ch].readBrand();
						std::cout << "\t�������\n";
						break;
					case 3:
						cr[ch].readModel();
						std::cout << "\t�������\n";
						break;
					case 4:
						cr[ch].readCity();
						std::cout << "\t�������\n";
						break;
					case 5:
						cr[ch].readWeight();
						std::cout << "\t�������\n";
						break;
					case 6: 
						double d;
						str = _strrd("\t������� �������� ������: ");
						d = _strdbl(_strrd("\t������� ���-�� ����� ��������: "));
						cr[ch].addCity(str, d);
						std::cout << "\t�������\n";
						break;
					case 7:
						if (cr[ch].getCities()) {
							char *str2;
							cout << "\t";
							cr[ch].writeCity();
							str = _strrd("������� �������� ����������� ������: ");
							str2 = _strrd("������� �������� ����������� ������: ");
							if (cr[ch].rewriteCity(str, str2))
								std::cout << "\t�������\n";
							else
								std::cout << "\t����� �� ������������ � ������\n";
							delete[] str2;
						}
						else
							std::cout << "\t������ ���������� ������� ����\n";
						break;
					case 8:
						if (cr[ch].getCities()) {
							double d;
							cout << "\t";
							cr[ch].writeCity();
							str = _strrd("������� �������� ������: ");
							d = _strdbl(_strrd("������� ����� ���� ��������: "));
							if (cr[ch].rewriteHours(str, d))
								std::cout << "\t�������\n";
							else
								std::cout << "\t����� �� ������������ � ������\n";
						}
						else
							std::cout << "\t������ ���������� ������� ����";
						break;
					case 9:
						cout << "\t";
						cr[ch].writeYear();
						break;
					case 10:
						cout << "\t";
						cr[ch].writeBrand();
						break;
					case 11:
						cout << "\t";
						cr[ch].writeModel();
						break;
					case 12:
						cr[ch].writeCity();
						break;
					case 13:
						cout << "\t";
						cr[ch].writeWeight();
						break;
					case 14:
						cr[ch].removeYear();
						std::cout << "\t�������\n";
						break;
					case 15:
						cr[ch].removeBrand();
						std::cout << "\t�������\n";
						break;
					case 16:
						cr[ch].removeModel();
						std::cout << "\t�������\n";
						break;
					case 17:
						if (cr[ch].getCities()) {
							cout << "\t";
							cr[ch].writeCity();
							str = _strrd("������� �������� ������: ");
							if (cr[ch].removeCity(str))
								std::cout << "\t�������\n";
							else
								std::cout << "\t����� �� ������������ � ������\n";
						}
						else
							std::cout << "\t������ ���������� ������� ����";
						break;
					case 18:
						cr[ch].removeCities();
						std::cout << "\t�������\n";
						break;
					case 19:
						cr[ch].removeWeight();
						std::cout << "\t�������\n";
						break;
					case 20:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
				print(cr, s);
			}
			break;
		case 4:
			printName(cr, s);
			break;
		case 5:
			print(cr, s);
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
	return cr;
}

template <typename T>
void printName(T *tr, int s) {
	std::cout << "\n\t������ �� ������: ";
	const char *c;
	for (int i = 0; i < s; ++i) {
		c = tr[i].getId();
		if (c) std::cout << c << " ";
		else std::cout << '#' << i << " ";
	}
	if (!s) std::cout << "����";
	std::cout << "\n";
}
template <typename T>
void print(T *tr, int s) {
	std::cout << "\n\t������ ������ ����������� ������� ����: ";
	if (!s) std::cout << "����";
	else std::cout << '\n';
	for (int i = 0; i < s; ++i) {
		std::cout << '|' << i << '|';
		tr[i].print();
	}
	std::cout << '\n';
}
template <typename T>
int select(T *tr, int s) {
	int ch;
	printName(tr, s);
	exceptions e("����� �������� ������ �������\n");
	std::cout << "�������� �����(0..N): ";
	std::cin >> ch;
	getchar();
	if (ch >= s)
		throw e;
	return ch;
}
