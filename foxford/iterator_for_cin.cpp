#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <iterator>
using namespace std;

int main() {
	map<string, int> words; // map for words and this counters

	cout << "Enter text and for end press <Enter>, after Ctrl+z:\n";

	istream_iterator<string> begin(cin); //streaming iterator
	istream_iterator<string> end; //last streamming iterator

	while (begin != end) // perebor slov potoka
		words[*begin++]++; //increment and save words
	//look words
	cout << endl << "Statistics words of string:\n";
	for (auto iter = words.begin(); iter != words.end(); iter++)
		cout << setw(5) << iter->second << " " << iter->first
		<< endl;
	system("pause");
	return 0;
}