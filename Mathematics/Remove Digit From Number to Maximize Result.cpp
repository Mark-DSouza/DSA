#include <bits/stdc++.h>
using namespace std;


// Idea:
// Scan the number string from left to right. If the digit is encountered, check its next digit to see if it is greater than the given digit. If the next number is greater than given digit, eliminate the digit at current position.
// If no such digit is found, eliminate the last occurence of the digit.
// TC: O(n)
// SC: O(1)

string removeDigit(string number, char digit) {
	int replacementIndex, n = number.size();
	for (int i = 0; i < n; i++) {
		if (number[i] == digit) {
			replacementIndex = i;
			if (i != n-1 && number[i+1] > number[i]) {
				break;
			}
		}
	}

	return number.substr(0, replacementIndex) + number.substr(replacementIndex+1);
}