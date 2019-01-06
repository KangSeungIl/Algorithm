#include <iostream> // POWER    거듭제곱 구하기

using namespace std;

#define LIMIT 1000000007

unsigned long long my_pow(unsigned long long base, unsigned long long exp) {
    unsigned long long res = 1;
    while (exp) {
        if (exp & 1) {
            res *= base;
            res %= LIMIT;
        }
        exp >>= 1;
        base *= base;
        base %= LIMIT;
    }
    return res;
}

int main() {
    int T = 1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        unsigned long long a, b;
        cin >> a >> b;
        
        cout << my_pow(a, b) << endl;
    }
    return 0;
}
