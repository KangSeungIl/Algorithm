#include <iostream> //  1222    계산기
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    for(int testCase=1; testCase<=10; testCase++) {
        int length;
        cin >> length;
        
        string temp;
        cin >> temp;
        
        int sum = 0;
        
        for(int i=0; i<length; i=i+2) {
            sum += (temp[i]-48);
        }
        
        cout << "#" << testCase << " " << sum << endl;
    }
    return 0;
}

