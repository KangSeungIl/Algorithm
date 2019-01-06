#include <iostream> // IOI_1994_NUMTRIANGLE   숫자 삼각형

using namespace std;

int triangle[12502501];

int main() {
    int T = 1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        
        int count = 0;
        int result = 0;
        for(int i=1; i<=N; i++) {
            for(int j=0; j<i; j++) {
                int temp;
                cin >> temp;
                count++;
                if(i == 1)
                    triangle[count] = temp;
                else {
                    if(j == 0) {
                        triangle[count] = temp + triangle[(count-i)+1];
                    }
                    else if(j == i-1) {
                        triangle[count] = temp + triangle[(count-i)];
                    }
                    else {
                        int left = temp + triangle[(count-i)];
                        int right = temp + triangle[(count-i)+1];
                        left > right ? triangle[count] = left : triangle[count] = right;
                    }
                }
                if(i == N && result < triangle[count])
                    result = triangle[count];
            }
        }
        cout << result << endl;
    }
    return 0;
}
