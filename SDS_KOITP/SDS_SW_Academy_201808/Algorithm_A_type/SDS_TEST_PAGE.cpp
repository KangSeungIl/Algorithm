#include <iostream> // SDS_TEST_PAGE 쉬어가는페이지

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int testCase=1; testCase<=T; testCase++) {
        int N, S, J, K;
        cin >> N >> S >> J >> K;

        int relaxpage[1000] = {0, };
        for(int i=0; i<K; i++)
            cin >> relaxpage[i];

        int current = S;
        int index = 0;
        int result = 0;
        while(current < N) {
            current += (J+1);
            for(int i=0; i<K; i++) {
                if(relaxpage[i] == current) {
                    result++;
                    break;
                }
            }
        }
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}

