#include <iostream> // SDS_TEST_SURVIVOR 마지막생존자

using namespace std;

int direction[9][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1} };
int main() {
    int T;
    cin >> T;

    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;

        int Map[10][10] = {0, };
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> Map[i][j];

      int result = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                bool water = false;
                bool mount = false;
                bool grass = false;
                bool op = true;
                for(int k=0; k<9; k++) {
                    int newi = i + direction[k][0];
                    int newj = j + direction[k][1];
                    if(newi < 0 || newi > N-1 || newj < 0 || newj > N-1)
                        continue;
                    if(Map[newi][newj] == 0) {
                        op = false;
                        break;
                    }
                    if(Map[newi][newj] == 1)
                        water = true;
                    else if(Map[newi][newj] == 2)
                        mount = true;
                    else if(Map[newi][newj] == 3)
                        grass = true;
                }
                if(op && water && mount && grass)
                    result++;
            }
        }
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}

