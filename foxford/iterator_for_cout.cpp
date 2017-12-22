//Ex10_13.cpp
//Using iterators for paste
#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;
using std::accumulate;

int main() {
	vector<int> numbers;
	cout << "Enter numbers and press Enter, after press Ctrl+Z or char\n";
	istream_iterator<int> input(cin), input_end;
	ostream_iterator<int> out(cout, " ");//cout like number and " "

	copy(input, input_end, back_inserter<vector<int>>(numbers));//copy to numbers

	cout << "Entered numbers:\n";
	copy(numbers.begin(), numbers.end(), out);//cout vector

	cout << "\n" << "Amount entered numbers equals: " << accumulate(numbers.begin(), numbers.end(), 0) << "\n";
	
	getchar();
	return 0;
}