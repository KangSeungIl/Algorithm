#include <iostream> // FIND_MAX    최댓값 찾기

using namespace std;

int main() {
    int T = 1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        std::ios::sync_with_stdio(false);
        int N;
        cin >> N;
        
        int max = -1000001;
        for(int i=0; i<N; i++) {
            int temp;
            cin >> temp;
            if(temp > max)
                max = temp;
            cout << max << " ";
        }
        cout << endl;
    }
    return 0;
}


