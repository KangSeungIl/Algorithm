#include <iostream> //  1225    암호생성기
#include <queue>

using namespace std;

int main() {
    int T=10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        queue <int> crypto;
        for(int i=0; i<8; i++) {
            int temp;
            cin >> temp;
            crypto.push(temp);
        }
        
        bool op = false;
        while(1) {
            for(int i=1; i<=5; i++) {
                int temp = crypto.front();
                crypto.pop();
                temp -= i;
                if(temp <= 0) {
                    temp = 0;
                    crypto.push(temp);
                    op = true;
                    break;
                }
                crypto.push(temp);
            }
            if(op)
                break;
        }
        cout << "#" << testCase << " ";
        
        while(!crypto.empty()) {
            cout << crypto.front() << " ";
            crypto.pop();
        }
        cout << endl;
    }
    return 0;
}
