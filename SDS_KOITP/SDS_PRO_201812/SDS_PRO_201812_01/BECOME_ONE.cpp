#include <iostream> // BECOME_ONE    1이 되고싶어

using namespace std;

int memo[1000001];

int search(int N) {
    if(N == 1)
        return 0;
    if(memo[N] > 0)
        return memo[N];
    
    memo[N] = search(N-1) + 1;
    
    if(N % 2 == 0){
        int temp = search(N>>1) + 1;
        if(memo[N] > temp) memo[N] =temp;
    }
    if(N % 3 == 0){
        int temp = search(N/3) + 1;
        if(memo[N] > temp) memo[N] = temp;
    }
    return memo[N];
}

int main() {
    int T=1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        cout << search(N) << endl;
    }
    return 0;
}
