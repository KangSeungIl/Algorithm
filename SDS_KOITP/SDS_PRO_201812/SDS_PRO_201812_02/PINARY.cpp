#include <iostream> // PINARY    이친수

using namespace std;

unsigned long long memo[91];

unsigned long long fibonacci(int N) {
    if(N <= 1)
        return N;
    else if(memo[N] != 0)
        return memo[N];
    else {
        return memo[N] = fibonacci(N-2) + fibonacci(N-1);
    }
}

int main() {
    int T=1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        memo[0] = 1;
        memo[1] = 1;
        cout << fibonacci(N) << endl;
    }
    return 0;
}
