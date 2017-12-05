//использование контейнера карты
#include <cstdio>
#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include"Personh.h"
using namespace std;

//читать людь их cin
Person getPerson() {
	string first,second;
	cout << "Введите имя: ";
	getline(cin, first);
	cout << "Введите фамилию: ";
	getline(cin, second);
	return Person(first,second);
}

//добавить новое вхождение в телефонную книгу
void addEntry(map<Person, string>& book) {
	string number;
	Person human = getPerson();

	cout << "Введите телефонный номер для"
		<< human.getName() << ": ";
	getline(cin, number);
	
	auto entry = make_pair(human, number);
	auto pr = book.insert(entry);
	if (pr.second) cout << "Введено успешно.\n";
	else {
		cout << "Вхождение существует для " << human.getName()
			<< ". Номер: " << pr.first->second << endl;
	}
}

//вывод содержимого телефонной книги
void listEntries(map<Person, string>& book) {
	if (book.empty()) {
		cout << "Телефонная книга пуста.\n";
		return;
	}
	cout << setiosflags(ios::left);
	for (auto iter = book.begin(); iter != book.end(); iter++)
		cout << setw(30) << iter->first.getName()
		<< setw(12) << iter->second << endl;
	cout << resetiosflags(ios::right);//вывод с выравниванием вправо
}

//извлчение вхождения из электронной книги
void getEntry(map<Person, string>& book) {
	Person person = getPerson();
	auto iter = book.find(person);
	if (iter == book.end())
		cout << "Не найдено вхождения для " << person.getName();
	else
		cout << "Номер " << person.getName()
		<< " - " << iter->second << endl;
}

//удаление записи из телефонной книги
void deleteEntry(map<Person, string>& book) {
	Person person = getPerson();
	auto iter = book.find(person);
	
	if (iter == book.end())
		cout << "Нут вхождения для" << person.getName() << endl;
	else {
		book.erase(iter);
		cout << "Вхождение для " << person.getName() << "удалено\n";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	map<Person, string> phonebook;
	char answer(0);

	while (true) {
		cout << "Хотите ли вы ввести номер для книги(Y или N):\n";
		cin >> answer;
		cin.ignore;
	}

	if (toupper(answer) == 'N') break;
	cin.get();
	return 0;
}