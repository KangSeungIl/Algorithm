#include <iostream> // MAX_SUBARRAY_RING    최대구간합(환)

using namespace std;

#define MAX_NUM 1000000

int number[MAX_NUM];

long long my_max(long long a, long long b) {
    if(a > b)
        return a;
    else
        return b;
}

long long kadane(int N) {
    long long sum = 0;
    long long result = 0;
    for(int i=0; i<N; i++) {
        sum = my_max(sum, 0) + number[i];
        result = my_max(sum, result);
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        long long sum = 0;
        for(int i=0; i<N; i++) {
            int temp;
            cin >> temp;
            sum += temp;
            number[i] = temp;
        }
        
        long long max_kadane = kadane(N);
        
        for(int i=0; i<N; i++)
            number[i] = -number[i];
        
        long long max_wrap = sum + kadane(N);
        
        long long result = my_max(max_kadane, max_wrap);
        
        if(result < 0)
            cout << 0 << endl;
        else
            cout << result << endl;
    }
    return 0;
}
