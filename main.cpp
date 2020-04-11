#include "Functions.h"

using namespace std;

int main() {
	//Get string from user
	string str = getString();

	//initialize final variables
	int longest_str_length;
	string longest_substring;

	//Call main method
	longest_substring = getLongestSubstring(str);

	//Print results
	cout << "Longest found = " << longest_substring << endl;
	cout << "Length = " << longest_substring.length() << endl;
	
	return 0;
}