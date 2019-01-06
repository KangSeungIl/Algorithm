#include <iostream> // SDS_TEST_CONSULTING    전화상담

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N, K, L;
        cin >> N >> K >> L;
        
        int customer[10000][2];
        for(int i=0; i<N; i++)
            cin >> customer[i][0] >> customer[i][1];
        
        int max = 0;
        int size = L/K;
        if(L/K > N)
            size = N;
        for(int i=1; i<=size; i++) {
            int left = L;
            int score = 10*i;
            int indicat[4] = {0, };
            for(int j=0; j<i; j++) {
                indicat[customer[j][1]] += customer[j][0] - K;
                left -= K;
            }
            for(int j=3; j>0; j--) {
                if(left == 0)
                    break;
                if(indicat[j] <= left) {
                    left -= indicat[j];
                    indicat[j] = 0;
                }
                else {
                    indicat[j] -= left;
                    left = 0;
                }
            }
            for(int j=1; j<=3; j++)
                score -= j*indicat[j];
            
            if(left < K && score > max)
                max = score;
        }
        
        cout << "#" << testCase << " " << max << endl;
    }
    return 0;
}
