/*
 * matrix.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: ram
 */
#include <iostream>

#include <cstdlib>
using namespace std;


int main() {
	int m[5][5];
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
		cin >> m[i][j];
		}
	}
	int ipos = 0, jpos = 0;
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			if(1 == m[i][j]){
				ipos = i;
				jpos = j;
			}
		}
	}
	cout << (abs(ipos-2) + abs(jpos-2)) << endl;

}



