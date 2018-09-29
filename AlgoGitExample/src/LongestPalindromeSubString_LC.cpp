/*
 * LongestPalindromeSubString_LC.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: RAM
 */
#include <iostream>
#include <vector>

using namespace std;

void printTable(vector< vector<bool> > t) {
	int n = t.size();
	cout << "Table : " << endl;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

string longestPalindrome(string s) {

	int n = s.length();
	vector< vector<bool> > table(n);
	for(int i=0; i<n; ++i) {
		table[i] = vector<bool>(n);
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			table[i][j] = false;
		}
	}
	for(int i=0; i<n; ++i) {
		table[i][i] = true;
	}
	//printTable(table);
	int maxlength = 1, start = 0;
	for(int i=0; i<n-1; ++i) {
		if(s[i] == s[i+1]) {
			table[i][i+1] = true;
			maxlength = 2;
			start = i;
		}
	}


	for(int k=3; k<=n; ++k) {

		for(int i=0; i<n-k+1; ++i) {
			int j = i + k - 1;
			if (table[i+1][j-1] && s[i] == s[j]) {
				table[i][j] = true;

				if (k > maxlength) {
					start = i;
					maxlength = k;
				}
			}
		}
	}
	//printTable(table);
	return string(s, start, maxlength);
}

int main() {

	string s = "fdslihouhwkjhsfioasdfghgfdsaoiauhw";
	cout << "Longest palindromic substring of " << s << " is : "
			<< longestPalindrome(s) << endl;
	return 0;
}


