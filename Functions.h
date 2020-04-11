#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

string getString() {
	string x;
	cout << "Enter a string : ";
	cin >> x;

	return x;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int indexOfFirstChar(char x, string substr) {

	//Notice we are working through the substring backwards to find the nearest match
	for (int i = substr.length(); i > -1; i--) {
		if (x == substr[i]) {
			return i;
		}
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

string getLongestSubstring(string str) {
	//initialize counters
	int current_start = 0, current_stop = 0, longest_start = 0, longest_stop = 0, first_char;

	//declare flag
	bool found;

	//declare vector to hold known chars
	vector<char> knownChars;

	do
	{
		//1.

					//clear whatever is in the knownchars vector
					knownChars.clear();

					//reset found flag
					found = 0;

					//Loop through characters
					for (int i = current_start; i < str.length(); i++) {

						//Loop through the knownChars vector checking if current char at i is there
						for (int j = 0; j < knownChars.size(); j++) {
							//Check if there
							if (str[i] == knownChars[j]) {
								//set flag
								found = 1;
								//set substring in which we will look for first letter
								string sub = str.substr(0, i);
								//find first iteration of the letter we found
								first_char = indexOfFirstChar(str[i], sub);
								break;
							}
						}
			
						//Found match --> set stop index
						if (found == 1) {
							//set current_stop
							current_stop = i;
							//stop the for loop
							break;
						}

						//didnt find match --> push current char into knownchars vector
						knownChars.push_back(str[i]);
					}

					//if the char wasn't found --> set current_stop = str.length
					if (found == 0) {
						current_stop = str.length() - 1;
					}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		

		//2. check if new substring is longer than previous substring
					if ((current_stop - current_start) > (longest_stop - longest_start)) {
						//set new longest start and stop
						longest_start = current_start;
						longest_stop = current_stop;
					}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//3. If continuing, set new start index (characters left > longest string length)
					if ((str.length() - (first_char+1)) > (longest_stop - longest_start)) {
						//set New start
						current_start = first_char + 1;
					}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
	} while ((str.length() - (first_char+1)) > (longest_stop - longest_start));

	
	//substr method (start_index, length)
	return str.substr(longest_start, longest_stop - longest_start);
}
