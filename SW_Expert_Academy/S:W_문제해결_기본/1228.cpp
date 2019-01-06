#include <iostream> //  1228    암호문1
#include <vector>

using namespace std;

int main() {
    int T = 10;
    for(int testCase=1; testCase <=T; testCase++) {
        int N;
        cin >> N;
        
        vector <int> result(10);
        for(int i=0; i<N; i++) {
            int temp;
            cin >> temp;
            if(i<10)
                result[i] = temp;
        }
        
        cin >> N;
        for(int i=0; i<N; i++) {
            char command;
            cin >> command;
            int x, y;
            cin >> x >> y;
            if(x < 10) {
                if(x+y-1 > 9) {
                    for(int j=x; j<10; j++)
                        cin >> result[j];
                    for(int j=10; j<x+y; j++) {
                        int temp;
                        cin >> temp;
                    }
                }
                else {
                    for(int j=9-y; j>=x; j--)
                        result[j+y] = result[j];
                    for(int j=x; j<x+y; j++)
                        cin >> result[j];
                }
            }
            else {
                for(int j=0; j<y; j++) {
                    int temp;
                    cin >> temp;
                }
            }
        }
        cout << "#" << testCase << " ";
        for(int i=0; i<10; i++)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
