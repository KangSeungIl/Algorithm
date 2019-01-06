#include <iostream> //  1204     최빈수 구하기
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++) {
        int testCase;
        cin >> testCase;
        
        vector <int> table(101, 0);
        int max = 0;
        int max_num = 0;
        for(int j=0; j<1000; j++) {
            int temp;
            cin >> temp;
            table[temp]++;
            if(max <= table[temp]) {
                max = table[temp];
                max_num = temp;
            }
        }
        cout << "#" << testCase << " " << max_num << endl;
    }
    return 0;
}
