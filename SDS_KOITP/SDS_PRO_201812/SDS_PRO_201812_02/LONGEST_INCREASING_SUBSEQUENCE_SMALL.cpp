#include <iostream> // LONGEST_INCREASING_SUBSEQUENCE_SMALL    최장 증가 부분 수열(LIS)_small

using namespace std;

int main() {
    int T=1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        int array[1000] = {0, };
        int max_index = -1;
        for(int i=0; i<N; i++) {
            int temp;
            cin >> temp;
            if(i == 0) {
                array[0] = temp;
                max_index++;
            }
            else {
                if(array[max_index] < temp) {
                    max_index++;
                    array[max_index] = temp;
                }
                else {
                    int index = max_index;
                    while(array[index] > temp)
                        index--;
                    array[++index] = temp;
                }
            }
        }
        cout << max_index+1 << endl;
    }
    return 0;
}
