#include <iostream> //  1218    괄호 짝짓기
#include <vector>

#define bracketsize 4
using namespace std;

int main() {
    int T = 10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector <int> count(bracketsize, 0);
        for(int i=0; i<n; i++) {
            char temp;
            cin >> temp;
            if(temp == '(')
                count[0]++;
            else if(temp == ')')
                count[0]--;
            else if(temp == '[')
                count[1]++;
            else if(temp == ']')
                count[1]--;
            else if(temp == '{')
                count[2]++;
            else if(temp == '}')
                count[2]--;
            else if(temp == '<')
                count[3]++;
            else
                count[3]--;
        }
        
        bool op = false;
        for(int i=0; i<bracketsize; i++) {
            if(count[i] != 0) {
                op = true;
                break;
            }
        }
        
        cout << "#" << testCase << " ";
        if(op)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    return 0;
}
