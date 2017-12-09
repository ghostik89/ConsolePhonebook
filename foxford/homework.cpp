//using #include<map>
#include <cstdio>
#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include"Personh.h"
using namespace std;

//cin>>people
Person getPerson() {
	string first,second;
	cout << "Enter name: ";
	getline(cin, first);
	cout << "Eneter surename: ";
	getline(cin, second);
	return Person(first,second);
}

//add new member
void addEntry(map<Person, string>& book) {
	string number;
	Person human = getPerson();

	cout << "Enter new member"
		<< human.getName() << ": ";
	getline(cin, number);
	
	auto entry = make_pair(human, number);
	auto pr = book.insert(entry);
	if (pr.second) cout << "Succues!\n";
	else {
		cout << "Not found " << human.getName()
			<< ". Number: " << pr.first->second << endl;
	}
}

//look all phonebook
void listEntries(map<Person, string>& book) {
	if (book.empty()) {
		cout << "Phonebook is empty.\n";
		return;
	}
	cout << setiosflags(ios::left);
	for (auto iter = book.begin(); iter != book.end(); iter++)
		cout << setw(30) << iter->first.getName()
		<< setw(12) << iter->second << endl;
	cout << resetiosflags(ios::right);//вывод с выравниванием вправо
}

//find member in the book
void getEntry(map<Person, string>& book) {
	Person person = getPerson();
	auto iter = book.find(person);
	if (iter == book.end())
		cout << "Not found " << person.getName();
	else
		cout << "Number " << person.getName()
		<< " - " << iter->second << endl;
}

//delete characters from phonebook
void deleteEntry(map<Person, string>& book) {
	Person person = getPerson();
	auto iter = book.find(person);
	
	if (iter == book.end())
		cout << "There haven't" << person.getName() << endl;
	else {
		book.erase(iter);
		cout << "Character " << person.getName() << "deleted\n";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	map<Person, string> phonebook;
	char answer(0);

	while (true) {
		cout << "Do you want create new charater?(Y или N):\n";
		cin >> answer;
		cin.ignore();

		if (toupper(answer) == 'N') break;
		if (toupper(answer) != 'Y') {
			cout << "Incorrect answer. Try again.";
			continue;
		}
		addEntry(phonebook);
	}

	//to phonebook
	while (true){
		cout << "Select mode:\n A - add member, D - delete member"<<
			" G - find member, L - look all book, Q - quit\n";
		cin >> answer;
		cin.ignore();
		switch (toupper(answer)) {
		case 'A': 
			addEntry(phonebook); break;
		case 'G':
			getEntry(phonebook);
			break;
		case 'D':
			deleteEntry(phonebook);
			break;
		case 'L':
			listEntries(phonebook);
			break;
		case 'Q':
			return 0;
		default:
			cout << "Error! Try again!\n";
			break;
		}
	}
	return 0;
}