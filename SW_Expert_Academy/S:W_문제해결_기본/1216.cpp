#include <iostream> //  1216    회문2
#include <vector>
#include <string>

#define mapsize 100

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
        
        int max = 1;
        for(int i=0; i<mapsize; i++) {
            for(int j=0; j<mapsize; j++) {
                for(int k=mapsize-1; k>=0; k--) {
                    int front = j;
                    int back = k;
                    while(Map[i][front] == Map[i][back]) {
                        front++;
                        back--;
                        if(front > back) {
                            if(max < (k-j+1))
                                max = k-j+1;
                            break;
                        }
                    }
                }
            }
        }
        
        for(int j=0; j<mapsize; j++) {
            for(int i=0; i<mapsize; i++) {
                for(int k=mapsize-1; k>=0; k--) {
                    int front = i;
                    int back = k;
                    while(Map[front][j] == Map[back][j]) {
                        front++;
                        back--;
                        if(front > back) {
                            if(max < (k-i+1))
                                max = k-i+1;
                            break;
                        }
                    }
                }
            }
        }
        
        cout << "#" << testCase << " " << max << endl;
    }
    return 0;
}
