#include <iostream> //  1233    사칙연산 유효성 검사
#include <vector>
#include <string>

using namespace std;

int main() {
    int T=10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        bool oper = false;
        int num, left, right;
        string op;
        if (N % 2 == 1) {
            for (int i = 0; i < N / 2; i++) {
                cin >> num >> op >> left >> right;
                if(op[0] != '+' && op[0] != '-' && op[0] != '*' && op[0] != '/')
                    oper = true;
            }
            for (int i = N / 2; i < N; i++) {
                cin >> num >> op;
                if(op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/')
                    oper =true;
            }
        }
        else {
            for (int i = 0; i < (N / 2) - 1; i++) {
                cin >> num >> op >> left >> right;
                if(op[0] != '+' && op[0] != '-' && op[0] != '*' && op[0] != '/')
                    oper = true;
            }
            
            cin >> num >> op >> left;
            if(op[0] != '+' && op[0] != '-' && op[0] != '*' && op[0] != '/')
                oper = true;
            
            for (int i = N / 2; i < N; i++) {
                cin >> num >> op;
                if(op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/')
                    oper =true;
            }
        }
        
        cout << "#" << testCase << " ";
        if(oper)
            cout << "0" << endl;
        else
            cout << "1" << endl;
    }
    return 0;
}
