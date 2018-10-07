#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
#define For(i, a, b) for(int i=a; i<b; ++i)
#define pb push_back

void print(vector<int> a){
    For(i, 0, a.size()){
        cout << a[i] << " ";
    }
    cout << endl;
}


vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    int max = scores[0];
    for(int i=1; i<scores.size(); ++i){
        if (scores[i] > max){
            max = scores[i];
        }
    }
    vector<int> a(max+1, 0);
    for(int i=0; i<scores.size(); ++i){
        a[scores[i]]++;
    }
    //print(a);
    vector<int> res;
    for(int i=0; i<alice.size(); ++i){
        int it = alice[i];
        int rank = 1;
        if(it < max){
         for(int j=it+1; j<a.size(); ++j){
                if(a[j] > 0)
                     rank++;
            }
        }
        res.pb(rank);
    }
    return res;
}


int main(){
	const int ar[] = {100, 100, 50, 40, 40, 20, 10};
	vector<int> scores(ar, ar+sizeof(ar)/sizeof(ar[0]) );
	const int alscore[] = {5, 25, 50, 120};
	vector<int> alice(alscore, alscore + sizeof(alscore)/sizeof(alscore[0]));

	vector<int> res = climbingLeaderboard(scores, alice);
	print(res);

	return 0;
}

