#include <bits/stdc++.h>

using namespace std;

string maxSubstring(string s) {
    string maxString = "";
    for (int i = 0; i < s.length(); ++i) {
        maxString = max(maxString, s.substr(i));
    }
    return maxString;
}

int main() {
    cout << maxSubstring("abbabzzbbabazzccc");
    return 0;
}
