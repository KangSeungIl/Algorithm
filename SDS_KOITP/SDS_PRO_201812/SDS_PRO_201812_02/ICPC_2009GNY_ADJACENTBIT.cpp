#include <iostream> // ICPC_2009GNY_ADJACENTBIT    인접한 비트의 개수

using namespace std;

unsigned int dp[101][100][2];

int main() {
    int T;
    cin >> T;
    
    dp[1][0][1] = 1;
    dp[1][0][0] = 1;
    
    for (int k = 0; k < 100; k++) {
        for (int n = 2; n <= 100; n++) {
            if (k == 0) {
                dp[n][k][1] += dp[n - 1][k][0];
            } else {
                dp[n][k][1] += dp[n - 1][k][0] + dp[n - 1][k - 1][1];
            }
            dp[n][k][0] += dp[n - 1][k][0] + dp[n - 1][k][1];
        }
    }
    
    for(int testCase=1; testCase<=T; testCase++) {
        int t, N, K;
        cin >> t >> N >> K;
        
        cout << t << " " << dp[N][K][0] + dp[N][K][1] << endl;
    }
    return 0;
}
