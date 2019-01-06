#include <iostream> //  1219    길찾기
#include <vector>
#include <stack>

using namespace std;

int main() {
    int T = 10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int t, n;
        cin >> t >> n;
        
        vector <vector <int> > Map(100);
        for(int i=0; i<n; i++) {
            int start, end;
            cin >> start >> end;
            Map[start].push_back(end);
        }
        
        stack <int> store;
        vector <bool> visited(100, false);
        store.push(0);
        bool op = false;
        while(!store.empty()) {
            int temp = store.top();
            store.pop();
            if(temp==99) {
                op = true;
                break;
            }
            if(!visited[temp]) {
                visited[temp] = true;
                for(int j=0; j<Map[temp].size(); j++)
                    if(!visited[Map[temp][j]])
                        store.push(Map[temp][j]);
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
