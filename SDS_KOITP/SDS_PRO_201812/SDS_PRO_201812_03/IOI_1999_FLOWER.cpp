#include <iostream> // IOI_1999_FLOWER    꽃 진열

using namespace std;

int Beauty[101][101];

int my_max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int main() {
    int T = 1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int F, V;
        cin >> F >> V;
        
        for(int i=1; i<=F; i++)
            for(int j=1; j<=V; j++)
                cin >> Beauty[i][j];
        
        int size = V - F;
        int result = -5001;
        for(int i=2; i<=F; i++) {
            int current_max = -51;
            for(int j=i; j<=i+size; j++) {
                current_max = my_max(current_max, Beauty[i-1][j-1]);
                Beauty[i][j] += current_max;
                if(i == F)
                    result = my_max(result, Beauty[i][j]);
            }
        }
        cout << result << endl;
    }
    return 0;
}
