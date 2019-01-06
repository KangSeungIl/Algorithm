#include <iostream> // RGB_DISTANCE    RGB거리

using namespace std;

long long Paint[300001][3];

int main() {
    int T=1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        for(int i=1; i<=N; i++) {
            cin >> Paint[i][0] >> Paint[i][1] >> Paint[i][2];
            if(i != 1) {
                for(int j=0; j<3; j++) {
                    long long min_pay;
                    int other1, other2;
                    j + 1 < 3 ? other1 = j+1 : other1 = j - 2;
                    j + 2 < 3 ? other2 = j+2 : other2 = j - 1;
                    Paint[i-1][other1] < Paint[i-1][other2] ? min_pay = Paint[i-1][other1] : min_pay = Paint[i-1][other2];
                    Paint[i][j] += min_pay;
                }
            }
        }
        
        long long result = Paint[N][0];
        for(int i=1; i<3; i++)
            if(result > Paint[N][i])
                result = Paint[N][i];
        
        cout << result << endl;
    }
    return 0;
}
