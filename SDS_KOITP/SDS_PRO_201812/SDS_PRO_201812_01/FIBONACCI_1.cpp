#include <iostream> // FIBONACCI_1    피보나치 수 1

using namespace std;

long long fibo[91];

long long fibonacci(int N) {
    if(N <= 1)
        return N;
    else if(fibo[N] != 0)
        return fibo[N];
    else
        return fibo[N] = fibonacci(N-2) + fibonacci(N-1);
}

int main() {
    int T = 1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        cout << fibonacci(N) << endl;
    }
    return 0;
}
