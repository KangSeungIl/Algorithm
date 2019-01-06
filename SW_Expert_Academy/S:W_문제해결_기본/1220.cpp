#include <iostream> //  1220    Magnetic
#include <vector>

using namespace std;

int main() {
    int T = 10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector< vector <int> > Map(n, vector <int> (n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> Map[i][j];
        
        int count = 0;
        for(int j=0; j<n; j++) {
            bool op = false;
            for(int i=0; i<n; i++) {
                if(Map[i][j] == 1) {
                    if(!op) {
                        op = true;
                    }
                }
                else if(Map[i][j] == 2) {
                    if(op) {
                        op = false;
                        count++;
                    }
                }
            }
        }
        cout << "#" << testCase << " " << count << endl;
    }
    return 0;
}
