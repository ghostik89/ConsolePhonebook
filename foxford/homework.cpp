//������������� ���������� �����
#include <cstdio>
#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include"Personh.h"
using namespace std;

//������ ���� �� cin
Person getPerson() {
	string first,second;
	cout << "������� ���: ";
	getline(cin, first);
	cout << "������� �������: ";
	getline(cin, second);
	return Person(first,second);
}

//�������� ����� ��������� � ���������� �����
void addEntry(map<Person, string>& book) {
	string number;
	Person human = getPerson();

	cout << "������� ���������� ����� ���"
		<< human.getName() << ": ";
	getline(cin, number);
	
	auto entry = make_pair(human, number);
	auto pr = book.insert(entry);
	if (pr.second) cout << "������� �������.\n";
	else {
		cout << "��������� ���������� ��� " << human.getName()
			<< ". �����: " << pr.first->second << endl;
	}
}

//����� ����������� ���������� �����
void listEntries(map<Person, string>& book) {
	if (book.empty()) {
		cout << "���������� ����� �����.\n";
		return;
	}
	cout << setiosflags(ios::left);
	for (auto iter = book.begin(); iter != book.end(); iter++)
		cout << setw(30) << iter->first.getName()
		<< setw(12) << iter->second << endl;
	cout << resetiosflags(ios::right);//����� � ������������� ������
}

//��������� ��������� �� ����������� �����
void getEntry(map<Person, string>& book) {
	Person person = getPerson();
	auto iter = book.find(person);
	if (iter == book.end())
		cout << "�� ������� ��������� ��� " << person.getName();
	else
		cout << "����� " << person.getName()
		<< " - " << iter->second << endl;
}

//�������� ������ �� ���������� �����
void deleteEntry(map<Person, string>& book) {
	Person person = getPerson();
	auto iter = book.find(person);
	
	if (iter == book.end())
		cout << "��� ��������� ���" << person.getName() << endl;
	else {
		book.erase(iter);
		cout << "��������� ��� " << person.getName() << "�������\n";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	map<Person, string> phonebook;
	char answer(0);

	while (true) {
		cout << "������ �� �� ������ ����� ��� �����(Y ��� N):\n";
		cin >> answer;
		cin.ignore;
	}

	if (toupper(answer) == 'N') break;
	cin.get();
	return 0;
}