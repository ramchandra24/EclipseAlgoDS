#include<bits/stdc++.h>

using namespace std;

void perm(char *str, int index = 0)
{
    std::set<char> used;

    char *p = str + index;
    char *q = p;

    if (*p == '\0') {
        cout << str << endl;
        return;
    }

    while (*q) {
        if (used.find(*q) == used.end()) {
            std::swap(*p, *q);
            perm(str, index + 1);
            std::swap(*p, *q);

            used.insert(*q);
        }
        q++;
    }
}

int main(){
	int n;
	cin >> n;

	vector<int> a = {1,2,3,4};
	if(n > 64 || n < -16){
		cout << "no solution";
		return 0;
	}
	char ab[] = "abcd";
	perm(ab);
}
