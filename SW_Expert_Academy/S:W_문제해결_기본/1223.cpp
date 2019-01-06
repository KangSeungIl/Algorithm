#include <iostream> //  1223    계산기2
#include <vector>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;

int main() {
    for(int testCase=1; testCase<=10; testCase++) {
        int length;
        cin >> length;
        
        string temp;
        cin >> temp;
        
        int sum = 0;
        
        stack <char> oper;
        stack <int> num;
        
        for(int i=0; i<length; i++) {
            if(i%2 == 0) {
                num.push(temp[i]-48);
            } else {
                if(!oper.empty() && oper.top() == '*' && temp[i] == '+') {
                    while(oper.top() != '+') {
                        int a, b, c;
                        a = num.top();
                        num.pop();
                        b = num.top();
                        num.pop();
                        c = a*b;
                        num.push(c);
                        oper.pop();
                        if(oper.empty()) break;
                    }
                } else oper.push(temp[i]);
            }
        }
        while(oper.top() != '+') {
            int a, b, c;
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            c = a*b;
            num.push(c);
            oper.pop();
            if(oper.empty()) break;
        }
        while(!num.empty()) {
            sum += num.top();
            num.pop();
        }
        cout << "#" << testCase << " " << sum << endl;
    }
    return 0;
}
