#include "function.h"

using std::cout;
using std::cin;

void work_plane(Keeper *kpr) {
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

			ptr = new plane();
			ptr->readType();
			ptr->readName();
			ptr->readWeight();
			ptr->readDim();
			ptr->readCity();
			kpr->add_transpoter(ptr, 0);

			delete ptr;
			break;
		case 2:
			if (kpr->get_size(0)) {
				try {
					ch = select(kpr->get_plane(), kpr->get_size(0));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				kpr->delete_transpoter(0, ch);
				cout << "�������� ���������\n";
			}
			else {
				print(kpr->get_plane(), kpr->get_size(0));
			}
			break;
		case 3:
			if (kpr->get_size(0)) {
				int n;
				char *str;
				try {
					ch = select(kpr->get_plane(), kpr->get_size(0));
				}
				catch (exceptions e) {
					cout << e.what();
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
						(kpr->get_plane() + ch)->readType();
						cout << "\t\t�������\n";
						break;
					case 2:
						(kpr->get_plane() + ch)->readName();
						cout << "\t\t�������\n";
						break;
					case 3:
						(kpr->get_plane() + ch)->readWeight();
						cout << "\t�������\n";
						break;
					case 4:
						(kpr->get_plane() + ch)->readDim();
						cout << "\t�������\n";
						break;
					case 5:
						(kpr->get_plane() + ch)->readCity();
						cout << "\t�������\n";
						break;
					case 6:
						str = _strrd("\t������� �������� ������: ");
						(kpr->get_plane() + ch)->addCity(str);
						cout << "\t�������\n";
						break;
					case 7: 
						if((kpr->get_plane() + ch)->getCities()) {
							char *str2;
							cout << "\t";
							(kpr->get_plane() + ch)->writeCity();
							str = _strrd("������� �������� ����������� ������: ");
							str2 = _strrd("������� �������� ����������� ������: ");
							if ((kpr->get_plane() + ch)->rewriteCity(str, str2))
								cout << "\t�������\n";
							else
								cout << "\t����� �� ������������ � ������\n";
							delete[] str2;
						}
						else 
							cout << "\t������ ���������� ������� ����";
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
						(kpr->get_plane() + ch)->rewriteDim(n, _strdbl(str));
						cout << "�������\n";
						break;
					case 9:
						cout << "\t";
						(kpr->get_plane() + ch)->writeType();
						break;
					case 10:
						cout << "\t";
						(kpr->get_plane() + ch)->writeName();
						break;
					case 11:
						cout << "\t";
						(kpr->get_plane() + ch)->writeWeight();
						break;
					case 12:
						cout << "\t";
						(kpr->get_plane() + ch)->writeDim();
						break;
					case 13:
						cout << "\t";
						(kpr->get_plane() + ch)->writeCity();
						break;
					case 14:
						(kpr->get_plane() + ch)->removeType();
						cout << "\t�������\n";
						break;
					case 15:
						(kpr->get_plane() + ch)->removeName();
						cout << "\t�������\n";
						break;
					case 16:
						(kpr->get_plane() + ch)->removeWeight();
						cout << "\t�������\n";
						break;
					case 17:
						(kpr->get_plane() + ch)->removeDim();
						cout << "\t�������\n";
						break;
					case 18:
						if ((kpr->get_plane() + ch)->getCities()) {
							cout << "\t";
							(kpr->get_plane() + ch)->writeCity();
							str = _strrd("������� �������� ������: ");
							if ((kpr->get_plane() + ch)->removeCity(str))
								cout << "\t�������\n";
							else
								cout << "\t����� �� ������������ � ������\n";
						}
						else
							cout << "\t������ ���������� ������� ����";
						break;
					case 19:
						(kpr->get_plane() + ch)->removeCities();
						cout << "\t�������\n";
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
				print(kpr->get_plane(), kpr->get_size(0));
			}
			break;
		case 4:
			printName(kpr->get_plane(), kpr->get_size(0));
			break;
		case 5:
			print(kpr->get_plane(), kpr->get_size(0));
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
}
void work_train(Keeper *kpr) {
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

			ptr = new train();
			ptr->readName();
			ptr->readYear();
			ptr->readCity();
			ptr->readCount();
			ptr->readWeight();
			kpr->add_transpoter(ptr, 1);

			delete ptr;
			break;
		case 2:
			if (kpr->get_size(1)) {
				try {
					ch = select(kpr->get_train(), kpr->get_size(1));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				kpr->delete_transpoter(1, ch);
				cout << "\t�������� ���������\n";
			}
			else {
				print(kpr->get_train(), kpr->get_size(1));
			}
			break;
		case 3:
			if (kpr->get_size(1)) {
				int n;
				char *str;
				try {
					ch = select(kpr->get_train(), kpr->get_size(1));
				}
				catch (exceptions e) {
					cout << e.what();
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
					<< "   14| ��������� ���� �����\n"
					<< "   15| ��������� ���� ���� �������\n"
					<< "   16| ��������� ���� ���������� �������\n"
					<< "   17| ������� �����\n"
					<< "   18| ��������� ���� ���-�� �������\n"
					<< "   19| ��������� ���� ������������ ����\n"
					<< "   20| ���������\n";
				while (flag) {
					str = NULL;
					cout << "�������� ����� ������: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						(kpr->get_train() + ch)->readName();
						cout << "\t�������\n";
						break;
					case 2:
						(kpr->get_train() + ch)->readYear();
						cout << "\t�������\n";
						break;
					case 3:
						(kpr->get_train() + ch)->readCity();
						cout << "\t�������\n";
						break;
					case 4:
						(kpr->get_train() + ch)->readCount();
						cout << "\t�������\n";
						break;
					case 5:
						(kpr->get_train() + ch)->readWeight();
						cout << "\t�������\n";
						break;
					case 6:
						str = _strrd("\t������� �������� ������: ");
						(kpr->get_train() + ch)->addCity(str);
						cout << "\t�������\n";
						break;
					case 7:
						cout << "\t";
						str = _strrd("������� ���-�� ����������� �������: ");
						(kpr->get_train() + ch)->addCount(int(_strdbl(str)));
						cout << "\t�������\n";
						break;
					case 8:
						if ((kpr->get_train() + ch)->getCities()) {
							char *str2;
							cout << "\t";
							(kpr->get_train() + ch)->writeCity();
							str = _strrd("������� �������� ����������� ������: ");
							str2 = _strrd("������� �������� ����������� ������: ");
							if ((kpr->get_train() + ch)->rewriteCity(str, str2))
								cout << "\t�������\n";
							else
								cout << "\t����� �� ������������ � ������\n";
							delete[] str2;
						}
						else
							cout << "\t������ ���������� ������� ����";
						break;
					case 9:
						cout << "\t";
						(kpr->get_train() + ch)->writeName();
						break;
					case 10:
						cout << "\t";
						(kpr->get_train() + ch)->writeYear();
						break;
					case 11:
						cout << "\t";
						(kpr->get_train() + ch)->writeCity();
						break;
					case 12:
						cout << "\t";
						(kpr->get_train() + ch)->writeCount();
						break;
					case 13:
						cout << "\t";
						(kpr->get_train() + ch)->writeWeight();
						break;
					case 14:
						(kpr->get_train() + ch)->removeName();
						cout << "\t�������\n";
						break;
					case 15:
						(kpr->get_train() + ch)->removeYear();
						cout << "\t�������\n";
						break;
					case 16:
						(kpr->get_train() + ch)->removeCities();
						cout << "\t�������\n";
						break;
					case 17:
						if ((kpr->get_train() + ch)->getCities()) {
							cout << "\t";
							(kpr->get_train() + ch)->writeCity();
							str = _strrd("������� �������� ������: ");
							if ((kpr->get_train() + ch)->removeCity(str))
								cout << "\t�������\n";
							else
								cout << "\t����� �� ������������ � ������\n";
						}
						else
							cout << "\t������ ���������� ������� ����";
						break;
					case 18:
						(kpr->get_train() + ch)->removeCount();
						cout << "\t�������\n";
						break;
					case 19:
						(kpr->get_train() + ch)->removeWeight();
						cout << "\t�������\n";
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
			print(kpr->get_train(), kpr->get_size(1));
			}
			break;
		case 4:
			printName(kpr->get_train(), kpr->get_size(1));
			break;
		case 5:
			print(kpr->get_train(), kpr->get_size(1));
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
}
void work_car(Keeper *kpr) {
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
			ptr = new car();
			ptr->readYear();
			ptr->readBrand();
			ptr->readModel();
			ptr->readCity();
			ptr->readWeight();
			kpr->add_transpoter(ptr, 2);

			delete ptr;
			break;
		case 2:
			if (kpr->get_size(2)) {
				try {
					ch = select(kpr->get_car(), kpr->get_size(2));
				}
				catch (exceptions e) {
					cout << e.what();
					break;
				}
				kpr->delete_transpoter(2, ch);
				cout << "\t�������� ���������\n";
			}
			else {
				print(kpr->get_car(), kpr->get_size(2));
			}
			break;
		case 3:
			if (kpr->get_size(2)) {
				int n;
				char *str;
				try {
					ch = select(kpr->get_car(), kpr->get_size(2));
				}
				catch (exceptions e) {
					cout << e.what();
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
					<< "   14| ��������� ���� ���� �������\n"
					<< "   15| ��������� ���� �����\n"
					<< "   16| ��������� ���� ������\n"
					<< "   17| ������� �����\n"
					<< "   18| ��������� ���� ���������� ������\n"
					<< "   19| ��������� ���� ������������ ����\n"
					<< "   20| ���������\n";
				while (flag) {
					str = NULL;
					cout << "�������� ����� ������: ";
					cin >> n;
					getchar();
					switch (n--) {
					case 1:
						(kpr->get_car() + ch)->readYear();
						cout << "\t�������\n";
						break;
					case 2:
						(kpr->get_car() + ch)->readBrand();
						cout << "\t�������\n";
						break;
					case 3:
						(kpr->get_car() + ch)->readModel();
						cout << "\t�������\n";
						break;
					case 4:
						(kpr->get_car() + ch)->readCity();
						cout << "\t�������\n";
						break;
					case 5:
						(kpr->get_car() + ch)->readWeight();
						cout << "\t�������\n";
						break;
					case 6: 
						double d;
						str = _strrd("\t������� �������� ������: ");
						d = _strdbl(_strrd("\t������� ���-�� ����� ��������: "));
						(kpr->get_car() + ch)->addCity(str, d);
						cout << "\t�������\n";
						break;
					case 7:
						if ((kpr->get_car() + ch)->getCities()) {
							char *str2;
							cout << "\t";
							(kpr->get_car() + ch)->writeCity();
							str = _strrd("������� �������� ����������� ������: ");
							str2 = _strrd("������� �������� ����������� ������: ");
							if ((kpr->get_car() + ch)->rewriteCity(str, str2))
								cout << "\t�������\n";
							else
								cout << "\t����� �� ������������ � ������\n";
							delete[] str2;
						}
						else
							cout << "\t������ ���������� ������� ����\n";
						break;
					case 8:
						if ((kpr->get_car() + ch)->getCities()) {
							double d;
							cout << "\t";
							(kpr->get_car() + ch)->writeCity();
							str = _strrd("������� �������� ������: ");
							d = _strdbl(_strrd("������� ����� ���� ��������: "));
							if ((kpr->get_car() + ch)->rewriteHours(str, d))
								cout << "\t�������\n";
							else
								cout << "\t����� �� ������������ � ������\n";
						}
						else
							cout << "\t������ ���������� ������� ����";
						break;
					case 9:
						cout << "\t";
						(kpr->get_car() + ch)->writeYear();
						break;
					case 10:
						cout << "\t";
						(kpr->get_car() + ch)->writeBrand();
						break;
					case 11:
						cout << "\t";
						(kpr->get_car() + ch)->writeModel();
						break;
					case 12:
						(kpr->get_car() + ch)->writeCity();
						break;
					case 13:
						cout << "\t";
						(kpr->get_car() + ch)->writeWeight();
						break;
					case 14:
						(kpr->get_car() + ch)->removeYear();
						cout << "\t�������\n";
						break;
					case 15:
						(kpr->get_car() + ch)->removeBrand();
						cout << "\t�������\n";
						break;
					case 16:
						(kpr->get_car() + ch)->removeModel();
						cout << "\t�������\n";
						break;
					case 17:
						if ((kpr->get_car() + ch)->getCities()) {
							cout << "\t";
							(kpr->get_car() + ch)->writeCity();
							str = _strrd("������� �������� ������: ");
							if ((kpr->get_car() + ch)->removeCity(str))
								cout << "\t�������\n";
							else
								cout << "\t����� �� ������������ � ������\n";
						}
						else
							cout << "\t������ ���������� ������� ����";
						break;
					case 18:
						(kpr->get_car() + ch)->removeCities();
						cout << "\t�������\n";
						break;
					case 19:
						(kpr->get_car() + ch)->removeWeight();
						cout << "\t�������\n";
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
			print(kpr->get_car(), kpr->get_size(2));
			}
			break;
		case 4:
			printName(kpr->get_car(), kpr->get_size(2));
			break;
		case 5:
			print(kpr->get_car(), kpr->get_size(2));
			break;
		case 6:
			flag = false;
			break;
		}
		cout << '\n';
	}
}

template <typename T>
void printName(T *tr, int s) {
	cout << "\n\t������ �� ������: ";
	const char *c;
	for (int i = 0; i < s; ++i) {
		c = tr[i].getId();
		if (c) cout << c << " ";
		else cout << '#' << i << " ";
	}
	if (!s) cout << "����";
	cout << "\n";
}
template <typename T>
void print(T *tr, int s) {
	cout << "\n\t������ ������ ����������� ������� ����: ";
	if (!s) cout << "����";
	else cout << '\n';
	for (int i = 0; i < s; ++i) {
		cout << '|' << i << '|';
		tr[i].print();
	}
	cout << '\n';
}
template <typename T>
int select(T *tr, int s) {
	int ch;
	printName(tr, s);
	exceptions e("����� �������� ������ �������\n");
	cout << "�������� �����(0..N): ";
	cin >> ch;
	getchar();
	if (ch >= s)
		throw e;
	return ch;
}
