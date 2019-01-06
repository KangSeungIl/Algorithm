#include <iostream> //  1215    회문1
#include <vector>
#include <string>

#define mapsize 8

using namespace std;

int main() {
    int T = 10;
    
    for(int testCase = 1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector <vector <char> > Map(mapsize, vector <char>(mapsize));
        for(int i=0; i<mapsize; i++) {
            string s1;
            cin >> s1;
            for(int j=0; j<mapsize; j++)
                Map[i][j] = s1[j];
        }
        
        int result = 0;
        for(int i=0; i<mapsize; i++) {
            for(int j=0; j+n<mapsize+1; j++) {
                int front = j;
                int back = j+n-1;
                while(Map[i][front] == Map[i][back]) {
                    if(front > back) {
                        result++;
                        break;
                    }
                    front++;
                    back--;
                }
            }
        }
        
        for(int j=0; j<mapsize; j++) {
            for(int i=0; i+n<mapsize+1; i++) {
                int front = i;
                int back = i+n-1;
                while(Map[front][j] == Map[back][j]) {
                    if(front > back) {
                        result++;
                        break;
                    }
                    front++;
                    back--;
                }
            }
        }
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}
