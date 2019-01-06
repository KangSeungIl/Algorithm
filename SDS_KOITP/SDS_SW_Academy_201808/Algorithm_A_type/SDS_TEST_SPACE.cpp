#include <iostream> // SDS_TEST_SPACE 순환공간

using namespace std;

int abs(int a) {
    if(a < 0)
        return -a;
    else
        return a;
}

int main() {
    int T;
    cin >> T;

    for(int testCase=1; testCase<=T; testCase++) {
        int N, M;
        cin >> N >> M;
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int min = abs(r1-r2) + abs(c1-c2);
        int direction[8][2] = { {-N, 0}, {N, 0}, {0, -M}, {0, M}, {N, M}, {-N, M}, {N, -M}, {-N, -M} };
        for(int i=0; i<8; i++) {
            int newr = r1 + direction[i][0];
            int newc = c1 + direction[i][1];
            if(min > (abs(newr-r2) + abs(newc-c2)))
                min = abs(newr-r2) + abs(newc-c2);
        }

        cout << "#" << testCase << " " << min << endl;
    }
    return 0;
}
