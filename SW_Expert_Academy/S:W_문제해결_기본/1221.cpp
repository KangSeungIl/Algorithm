#include <iostream> //  1221    GNS
#include <vector>
#include <string>

using namespace std;

string number[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        string s1;
        int N;
        cin >> s1 >> N;
        
        vector <int> count(10, 0);
        for(int i=0; i<N; i++) {
            string temp;
            cin >> temp;
            if(temp =="ZRO")
                count[0]++;
            else if(temp=="ONE")
                count[1]++;
            else if(temp=="TWO")
                count[2]++;
            else if(temp=="THR")
                count[3]++;
            else if(temp=="FOR")
                count[4]++;
            else if(temp=="FIV")
                count[5]++;
            else if(temp=="SIX")
                count[6]++;
            else if(temp=="SVN")
                count[7]++;
            else if(temp=="EGT")
                count[8]++;
            else
                count[9]++;
        }
        
        cout << s1 << endl;
        for(int i=0; i<10; i++) {
            for(int j=0; j<count[i]; j++) {
                cout << number[i] << " ";
            }
        }
    }
    return 0;
}
