#include <bits/stdc++.h>
using namespace std;

class Lambda {

public:
    static void printRandomNums(int min, int max, int nums) {
        srand(time(NULL));
        vector<int> times;
        int i = 0;
        while (i++ < nums) {
            int rnum = min + rand() % (max + 1 - min);
            times.push_back(rnum);
        }
        vector<int> evenNums;
        copy_if(times.begin(),
                times.end(),
                back_inserter(evenNums),
                [](int num) {return (num % 3 == 0);});
        for (auto n : evenNums) {
            cout << n << endl;
        }
    }


};

int main(int argc, char **argv) {
    Lambda::printRandomNums(1, 50, 10);
    return 0;
}
