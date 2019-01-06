#include <iostream> // MAX_SUBARRAY    최대구간합

using namespace std;

int iarray[1000001];

long long my_max(long long a, long long b) {
    long long max;
    a > b ? max = a : max = b;
    return max;
}
int main() {
    int T=1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        for(int i=0; i<N; i++)
            cin >> iarray[i];
        
        long long sum = 0;
        long long result = -2000001;
        for(int i=0; i<N; i++) {
            sum = my_max(sum, 0) + iarray[i];
            result = my_max(sum, result);
        }
        
        cout << result << endl;
    }
    return 0;
}
