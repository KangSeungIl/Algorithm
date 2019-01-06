#include <iostream> //  1240    단순 2진 암호코드
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N, M;
        cin >> N >> M;
        
        vector <vector <int> > Scanner(N, vector <int> (M, 0));
        pair<int, int> startpoint;
        pair<int, int> endpoint;
        for(int i=0; i<N; i++) {
            bool op = false;
            string s;
            cin >> s;
            for(int j=0; j<M; j++) {
                Scanner[i][j] = s[j]-'0';
                if(!op && (s[j] == '1')) {
                    startpoint.first = i; startpoint.second=j;
                    op = true;
                }
                else if(op && (s[j] == '1')) {
                    endpoint.first = i; endpoint.second=j;
                }
            }
        }
        int add_front = 56-(endpoint.second-startpoint.second+1);
        vector <int> Code;
        bool zero = true;
        int zero_count = 0;
        bool one = false;
        int one_count = 0;
        for(int j=startpoint.second-add_front; j<=endpoint.second; j++) {
            if(zero) {
                if(Scanner[startpoint.first][j] == 0)
                    zero_count++;
                else {
                    zero = false;
                    Code.push_back(zero_count);
                    zero_count = 0;
                    one = true;
                    one_count++;
                }
            }
            else {
                if(Scanner[startpoint.first][j] == 1)
                    one_count++;
                else {
                    one = false;
                    Code.push_back(one_count);
                    one_count = 0;
                    zero = true;
                    zero_count++;
                }
            }
        }
        if(zero)
            Code.push_back(zero_count);
        else
            Code.push_back(one_count);
        
        vector <int> password;
        for(int i=0; i<Code.size()-3; i=i+4) {
            if(Code[i] == 1) {
                if(Code[i+1] == 1) {
                    if(Code[i+2] == 1) {
                        password.push_back(6);
                        continue;
                    }
                    else {
                        password.push_back(4);
                        continue;
                    }
                }
                else if(Code[i+1]==2) {
                    if(Code[i+2] == 1) {
                        password.push_back(8);
                        continue;
                    }
                    else {
                        password.push_back(5);
                        continue;
                    }
                }
                else if(Code[i+1]==3) {
                    password.push_back(7);
                    continue;
                }
                else {
                    password.push_back(3);
                    continue;
                }
            }
            else if(Code[i] == 2) {
                if(Code[i+1] == 1) {
                    password.push_back(2);
                    continue;
                }
                else {
                    password.push_back(1);
                    continue;
                }
            }
            else {
                if(Code[i+1] == 1) {
                    password.push_back(9);
                    continue;
                }
                else {
                    password.push_back(0);
                    continue;
                }
            }
        }
        
        int sum = 0;
        if(((password[0]+password[2]+password[4]+password[6])*3+password[1]+password[3]+password[5]+password[7])%10 == 0)
            for(int i=0; i<password.size(); i++)
                sum += password[i];
        
        cout << "#" << testCase << " " << sum << endl;
    }
    return 0;
}
