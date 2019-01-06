#include <iostream> //  1249    보급로
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef struct Location {
    int i;
    int j;
} Location;

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector <vector <int> > map(n, vector <int> (n, 0));
        for(int i=0; i<n; i++){
            string s1;
            cin >> s1;
            for(int j=0; j<n; j++)
                map[i][j] = s1[j] - '0';
        }
        
        queue <Location> store;
        Location init;
        init.i = 0; init.j = 0;
        store.push(init);
        vector <vector <int> > minmap(n, vector <int> (n, 987654321));
        minmap[0][0] = 0;
        while(!store.empty()) {
            Location temp = store.front();
            store.pop();
            Location next;
            if(temp.i != 0) {
                if(minmap[temp.i-1][temp.j] > (minmap[temp.i][temp.j]+map[temp.i-1][temp.j])) {
                    minmap[temp.i-1][temp.j] = minmap[temp.i][temp.j]+map[temp.i-1][temp.j];
                    next.i = temp.i-1; next.j = temp.j;
                    store.push(next);
                }
            }
            if(temp.i != n-1) {
                if(minmap[temp.i+1][temp.j] > (minmap[temp.i][temp.j]+map[temp.i+1][temp.j])) {
                    minmap[temp.i+1][temp.j] = minmap[temp.i][temp.j]+map[temp.i+1][temp.j];
                    next.i = temp.i+1; next.j = temp.j;
                    store.push(next);
                }
            }
            if(temp.j != 0) {
                if(minmap[temp.i][temp.j-1] > (minmap[temp.i][temp.j]+map[temp.i][temp.j-1])) {
                    minmap[temp.i][temp.j-1] = minmap[temp.i][temp.j]+map[temp.i][temp.j-1];
                    next.i = temp.i; next.j = temp.j-1;
                    store.push(next);
                }
            }
            if(temp.j != n-1) {
                if(minmap[temp.i][temp.j+1] > (minmap[temp.i][temp.j]+map[temp.i][temp.j+1])) {
                    minmap[temp.i][temp.j+1] = minmap[temp.i][temp.j]+map[temp.i][temp.j+1];
                    next.i = temp.i; next.j = temp.j+1;
                    store.push(next);
                }
            }
        }
        cout << "#" << testCase << " " << minmap[n-1][n-1] << endl;
    }
    return 0;
}
