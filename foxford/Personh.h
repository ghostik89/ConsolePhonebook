//Person.h
//людской класс
#pragma once
#include<iostream>
#include<string>
#include <functional>
using std::cout;
using std::endl;
using std::string;

class Person
{
public:
	Person(string first = "", string second = "") {
		firstname = first;
		secondname = second;
	}
	~Person();
	//оператор меньше
	bool operator<(const Person& p)const {
		if (secondname < p.secondname || ((secondname == p.secondname)
			&& (firstname < p.firstname)))
			return true;
		return false;
	}
	//получить имя
	string getName()const { return firstname + " " + secondname; }


private:
	string secondname;
	string firstname;
};


Person::~Person()
{
}
