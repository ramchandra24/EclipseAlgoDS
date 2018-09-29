#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> charityAllocation(vector<float> profits){
	int l = profits.size();

	float pro[] = {0, 0, 0};
	vector<string> op;

	if (1 ==l ){
		op.push_back("A");
		return op;
	}
	else if (2 == l){
		op.push_back("A");
		op.push_back("B");
		return op;
	}

	op.push_back("A");
	op.push_back("B");
	op.push_back("C");
	for (int i=0; i<3; ++i){
		pro[i] = profits[i];
	}
	for (int i=3; i<l; ++i){
		int im = 0;
		if ((pro[0] <= pro[1]) && (pro[0] <= pro[2])){
			im = 0;
		}
		else if ((pro[1] <= pro[0]) && (pro[1] <= pro[2])) {
			im = 1;
		}
		else{
			im = 2;
		}
		pro[im] += profits[i];
		op.push_back(string(op[im]));

	}
	return op;
}

int main(){
	float pv[] = {25, 8, 2, 35, 15, 120, 55, 42};
	vector<float> p(8);
	for(int i=0; i<p.size(); ++i){
		p[i] = pv[i];
	}
	vector<string> o;
	o = charityAllocation(p);

	for(int i=0; i<o.size(); ++i)
		cout << o[i] << endl;
	return 0;
}

