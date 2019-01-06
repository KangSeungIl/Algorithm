#include <iostream> //  1208    Flatten
#include <vector>

using namespace std;

int main() {
    for(int testCase=1; testCase<=10; testCase++) {
        int n;
        cin >> n;
        
        vector <int> table(100, 0);
        
        for(int i=0; i<100; i++)
            cin >> table[i];
        
        int max, min;
        for(int i=0; i<n+1; i++) {
            max = -1;
            int max_num;
            min = 987654321;
            int min_num;
            
            for(int j=0; j<100; j++) {
                if(max < table[j]) {
                    max = table[j];
                    max_num = j;
                }
                if(min > table[j]) {
                    min = table[j];
                    min_num = j;
                }
            }
            
            if(i == n)
                break;
            if((max - min) <= 1)
                break;
            
            table[max_num]--;
            table[min_num]++;
        }
        
        cout << "#" << testCase << " " << max-min << endl;
    }
    return 0;
}
