#include <iostream> //  1234    비밀번호
#include <vector>
#include <string>

using namespace std;

int main() {
    int T=10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector <int> password(n, 0);
        string num;
        cin >> num;
        for(int i=0; i<n; i++)
            password[i] = num[i]-'0';
        
        while(1) {
            bool op = false;
            for(int i=0; i<n-1; i++) {
                for(int j=i+1; j<n; j++) {
                    if(password[j] == -1)
                        continue;
                    else {
                        if(password[i]==password[j]) {
                            password[i] = -1;
                            password[j] = -1;
                            i = -1;
                            op = true;
                        }
                        break;
                    }
                }
            }
            if(!op)
                break;
        }
        cout << "#" << testCase << " ";
        for(int i=0; i<n; i++)
            if(password[i] != -1)
                cout << password[i];
        cout << endl;
    }
    return 0;
}
