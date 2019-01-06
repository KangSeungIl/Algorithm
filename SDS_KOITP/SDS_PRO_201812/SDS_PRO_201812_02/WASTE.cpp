#include <iostream> // WASTE    폐지 줍기

using namespace std;

int Map[200][200];

int main() {
    int T=1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> Map[i][j];
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(i == 0 && j == 0)
                    continue;
                if(i == 0)
                    Map[i][j] += Map[i][j-1];
                else if(j == 0)
                    Map[i][j] += Map[i-1][j];
                else {
                    int temp;
                    Map[i][j-1] > Map[i-1][j] ? temp = Map[i][j-1] : temp = Map[i-1][j];
                    Map[i][j] += temp;
                }
            }
        }
        
        cout << Map[N-1][N-1] << endl;
    }
    return 0;
}
