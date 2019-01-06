#include <iostream> //  1256    K번째 접미어
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int K;
        cin >> K;
        
        string s;
        cin >> s;
        
        cout << "#" << testCase << " ";
        if(K <= s.length()) {
            string temp[1000];
            for(int i=0; i<s.length(); i++)
                temp[i] = s.substr(i, s.length());
            
            sort(temp, temp+s.length());
            
            cout << temp[K-1] << endl;
        }
        else
            cout << "none" << endl;
    }
    return 0;
}
