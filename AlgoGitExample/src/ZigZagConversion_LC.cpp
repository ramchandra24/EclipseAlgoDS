/*
 * ZigZagConversion_LC.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: RAM
 */

#include <iostream>
#include <vector>

using namespace std;


void printMatrix(vector< vector <char> > m) {
	cout << "Matrix : " << endl;
	for(int i=0; i<m.size(); ++i) {
		for(int j=0; j<m[i].size(); ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}


string ZigZagMatrix(string s, int numRows) {

	vector< vector< char > > mat(numRows);

	//mat = new vector< char >(numRows);
	int cols = 0;
	int slen = 0;
	for(int i=0; slen < s.length(); ++i) {
		cols++;
		slen += numRows;
		for(int j=0; j<(numRows-2) && slen < s.length(); ++j) {
			cols++;
			slen++;
		}
		//cout << "slen : " << slen << " :: cols : " << cols << endl;
	}
	//cout << "Columns : " << cols << endl;
	for(int i=0; i<numRows; ++i) {
		mat[i] = vector< char >(cols);
	}

	for(int i=0; i<mat.size(); ++i) {
		for(int j=0; j<mat[i].size(); ++j) {
			mat[i][j] = '0';
		}
	}
	//printMatrix(mat);

	slen = 0;
	for(int i=0; i<cols && slen < s.length(); ) {
		// go down
		int j=0;
		for(; j<numRows && slen < s.length(); ++j) {
			mat[j][i] = s[slen++];
		}
		int sum = i+j;
		 ++i;
		// go back up
		for(int k=numRows-1; k>=0 && slen < s.length(); --k) {
			if((i+k+1 == sum) && (k > 0)) {
				mat[k][i] = s[slen++];
				++i;
			}
		}

	}
	string res;
	for(int i=0; i<mat.size(); ++i) {
		for(int j=0; j<mat[i].size(); ++j) {
			if(mat[i][j] != '0') {
				res += mat[i][j];
			}
		}
	}

	//printMatrix(mat);
	return res;
}

int main() {

	string s = "ZIGZAGCONVERSIONMATRIX";
	cout << "Converted string : " << ZigZagMatrix(s, 3) << endl;

	return 0;
}
