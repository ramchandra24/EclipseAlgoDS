/*
 * LargestUniqueSubstring_LC.cpp
 *
 *  Created on: Jun 30, 2018
 *      Author: RAM
 */

#include <iostream>

using namespace std;

void calcMaxAndClearLength(int *alpha, int &maxLen, int makeOne){
	int len = 0;
	for(int i=0; i<26; ++i){
		len += alpha[i];
		alpha[i] = 0;
	}
	if(len > maxLen){
		maxLen = len;
	}
	alpha[makeOne] = 1;
}

int lengthOfLongestSubstring(string s) {
	int alpha[26] = {0};
	int maxLen = 0;
	for(int i=0; i<s.length(); ++i){
		if (alpha[s[i]-'a'] > 0) {
			calcMaxAndClearLength(alpha, maxLen, (s[i]-'a'));
		}
		else {
		   alpha[s[i]-'a'] = 1;
		}
	}
	return maxLen;
}

int main(){

	cout << "Length = " << lengthOfLongestSubstring("aadfsssafaaagadwetggs") << endl;
	return 0;
}
