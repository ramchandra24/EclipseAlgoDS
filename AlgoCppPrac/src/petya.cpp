/*
 * petya.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: ram
 */


#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

void petya(string s1, string s2){
	for(unsigned int i=0; i<s1.length(); ++i){
		s1[i] = tolower(s1[i]);
	}
	for(unsigned int i=0; i<s2.length(); ++i){
		s2[i] = tolower(s2[i]);
	}
	int res = s1.compare(s2);
	if(res < 0) {
		cout << "-1" << endl;
	}
	else if (res == 0){
		cout << "0" << endl;
	}
	else {
		cout << "1" << endl;
	}
}

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	petya(s1, s2);
	return 0;
}



