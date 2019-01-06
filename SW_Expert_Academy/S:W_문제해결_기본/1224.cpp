#include <iostream> //  1224    계산기3
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
            if(48 <= temp[i] && temp[i] <= 57) {
                num.push(temp[i]-48);
            } else {
                if(!oper.empty() && temp[i] == '+'  && oper.top() == '*') {
                    while(oper.top() != '+' && oper.top() != '(') {
                        int a, b, c;
                        a = num.top();
                        num.pop();
                        b = num.top();
                        num.pop();
                        c = a*b;
                        num.push(c);
                        oper.pop();
                        if(oper.empty()) {
                            oper.push(temp[i]);
                            break;
                        }
                    }
                    oper.push(temp[i]);
                } else if(temp[i] == ')') {
                    if(oper.top() == '*') {
                        while(oper.top() != '+' && oper.top() != '(') {
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
                    }
                    while(oper.top() != '(') {
                        int a, b, c;
                        a = num.top();
                        num.pop();
                        b = num.top();
                        num.pop();
                        c = a+b;
                        num.push(c);
                        oper.pop();
                    }
                    oper.pop();
                }
                else oper.push(temp[i]);
            }
        }
        cout << "#" << testCase << " " << num.top() << endl;
    }
    return 0;
}

