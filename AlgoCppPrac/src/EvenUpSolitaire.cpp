#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	stack<int> s;
	for(int i=0; i<n; ++i){
		if(s.size() == 0){
			int num;
			cin >> num;
			s.push(num);
		}
		else{
			int tp = s.top();
			int num;
			cin >> num;
			if ((num + tp) % 2 == 0){
				s.pop();
			}
			else{
				s.push(num);
			}
		}
	}
	cout << s.size() << endl;

	return 0;
}


