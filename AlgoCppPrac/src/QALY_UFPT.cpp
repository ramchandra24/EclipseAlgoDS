#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float Quality(float const (&qaly)[100], float const (&year)[100], int N) {
    float res = 0;
    for (auto i = 0; i < N; ++i) {
        res += qaly[i] * year[i];
    }
    return res;
}


int main() {

    int N;
    float qaly[100];
    float year[100];
    cin >> N;
    float y, q;
    for (int i = 0; i < N; ++i) {
        cin >> y >> q;
        qaly[i] = q;
        year[i] =y;
    }
    float res = Quality(qaly, year, N);
    cout << std::fixed << std::setprecision(3) << res << endl;
    return 0;
}
