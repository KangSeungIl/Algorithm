#include <iostream> //  1244    최대상금
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int max_s = 0;

int cal(string s) {
    int result = 0;
    for(int i=0; i<s.length(); i++)
        result += (s[i]-'0')*pow(10, s.length()-1-i);
    return result;
}
void recur(string s, int n, vector <bool> &visited) {
    if(n <= 0) {
        if(max_s < cal(s))
            max_s = cal(s);
        return;
    }
    
    if(visited[cal(s)])
        return;
    visited[cal(s)] = true;
    
    for(int i=0; i<s.length()-1; i++) {
        for(int j=i+1; j<s.length(); j++) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            recur(s, n-1, visited);
            s[j] = s[i];
            s[i] = temp;
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        string s;
        int n;
        cin >> s >> n;
        
        max_s = 0;
        vector <bool> visited(1000000, false);
        recur(s, n, visited);
        
        cout << "#" << testCase << " " << max_s << endl;
    }
}
