/*
 * LargestUniqueSubstring_LC.cpp
 *
 *  Created on: Jun 30, 2018
 *      Author: RAM
 */

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
     vector<char> charVec;
     int maxLen = 0;
     for(int i=0; i<s.length(); ++i) {
         if(find(charVec.begin(), charVec.end(), s[i]) != charVec.end()) {
             if(maxLen < charVec.size()){
                 maxLen = charVec.size();
             }
             while(s[i] != charVec[0])
                 charVec.erase(charVec.begin());
             charVec.erase(charVec.begin());
             charVec.push_back(s[i]);
         }
         else {
             charVec.push_back(s[i]);
         }
     }
     if(maxLen < charVec.size()) {
         maxLen = charVec.size();
     }
     return maxLen;
 }

int main(){

	cout << "Length = " << lengthOfLongestSubstring("aadfsssafaaagadwetggs") << endl;
	return 0;
}
