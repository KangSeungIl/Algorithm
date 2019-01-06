#include <iostream> //  1227    미로2
#include <vector>
#include <string>
#include <stack>

#define mapsize 100

using namespace std;

int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int main() {
    int T=10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector <vector <int> > Map(mapsize, vector <int> (mapsize, 0));
        pair<int, int> start;
        pair<int, int> end;
        for(int i=0; i<mapsize; i++) {
            string s1;
            cin >> s1;
            for(int j=0; j<mapsize; j++) {
                Map[i][j] = s1[j] - '0';
                if(Map[i][j] == 2) {
                    start.first = i; start.second=j;
                }
                else if (Map[i][j] == 3) {
                    end.first = i; end.second=j;
                }
            }
        }
        
        stack <pair<int, int> > store;
        vector <vector <bool> > visited(mapsize, vector <bool>(mapsize, false));
        store.push(start);
        bool op = false;
        while(!store.empty()) {
            pair<int, int> temp = store.top();
            store.pop();
            if(temp.first == end.first && temp.second == end.second) {
                op = true;
                break;
            }
            if(!visited[temp.first][temp.second]) {
                visited[temp.first][temp.second]= true;
                for(int i=0; i<4; i++) {
                    int newi = temp.first + direction[i][0];
                    int newj = temp.second + direction[i][1];
                    if(newi < 0 || newi > mapsize-1 || newj < 0 || newj > mapsize-1)
                        continue;
                    if(Map[newi][newj] != 1 && !visited[newi][newj]) {
                        pair<int, int> newtemp;
                        newtemp.first = newi; newtemp.second = newj;
                        store.push(newtemp);
                    }
                }
            }
        }
        cout << "#" << testCase << " ";
        if(op)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    
    return 0;
}
