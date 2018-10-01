#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define pb push_back
#define mp make_pair

void print(vector<int> a){
    For(i, 0, a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}

void printMP(vector<pair<int, int>> a){
    For(i, 0, a.size()){
        cout << a[i].first << " : " << a[i].second << endl;
    }
    cout << endl;
}


vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<pair<int, int>> a;
    int times;
    int ii;
	for(ii=1; ii<scores.size(); ++ii){
		times = 1;
        while((ii<scores.size()) && (scores[ii] == scores[ii-1])){
        	times++;
        	ii++;
        }
        a.pb(mp(scores[ii-1], times));
    }
	a.pb(mp(scores[ii-1], times));
    printMP(a);

    int max = a[0].first;
    cout << "max ; " << max << endl;
    vector<int> res;
    For(i, 0, alice.size()) {
        int it = alice[i];
        cout << "it : " << it << endl;
        int rank = 1;
        if(it < max){
        	int ind = 0;
        	while((ind < a.size()) && (a[ind].first > it)) {
        	 ++rank;
        	 ++ind;
        	}
        	cout << rank << endl;
        }
        res.pb(rank);
    }
    return res;
}


int main(){
	const int ar[] = {100, 90, 90, 80, 75, 60};
	vector<int> scores(ar, ar+sizeof(ar)/sizeof(ar[0]) );
	const int alscore[] = {50, 65, 77, 90, 102};
	vector<int> alice(alscore, alscore + sizeof(alscore)/sizeof(alscore[0]));

	vector<int> res = climbingLeaderboard(scores, alice);
	print(res);

	return 0;
}

