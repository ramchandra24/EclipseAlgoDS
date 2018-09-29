/*
 * HashTableRansomNote_HR.cpp
 *
 *  Created on: Jun 30, 2018
 *      Author: RAM
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void isRansomNoteInMagazine(vector<string> magazine, vector<string> note){

    map<string, int> magMap;
    for(int i=0; i<magazine.size(); ++i){
        map<string, int>::iterator iter;
        if((iter = magMap.find(magazine[i])) != magMap.end()) {
            magMap[iter->first] = iter->second + 1;
        }
        else {
            magMap.insert(make_pair(magazine[i], 1));
        }
    }

    for(int i=0; i<note.size(); ++i){
        map<string, int>::iterator iter;
        if((iter = magMap.find(note[i])) != magMap.end()){
            if(0 == iter->second){
                cout << "No" << endl;
                return;
            }
            else {
                magMap[iter->first] = iter->second - 1;
            }
        }
        else {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main(){

	vector<string> magazine {"me", "give", "the", "money", "to", "him", "today"};
	vector<string> note {"give", "money", "today", "hello"};

	isRansomNoteInMagazine(magazine, note);
	return 0;
}

