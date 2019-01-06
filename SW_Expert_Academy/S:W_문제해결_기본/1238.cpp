#include <iostream> //  1238    Contact
#include <vector>
#include <queue>

using namespace std;

int main() {
    int T=10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n, start;
        cin >> n >> start;
        
        vector <vector <int> > Map(101);
        for(int i=0; i<n/2; i++) {
            int from, to;
            cin >> from >> to;
            Map[from].push_back(to);
        }
        
        int max = 0;
        int max_num = 0;
        vector <bool> visited (101, false);
        queue <pair<int, int> > store;
        pair<int, int> init;
        init.first = 1; init.second = start;
        store.push(init);
        while(!store.empty()) {
            pair <int, int> temp = store.front();
            store.pop();
            if(!visited[temp.second]) {
                visited[temp.second] =true;
                for(int i=0; i<Map[temp.second].size(); i++) {
                    if(!visited[Map[temp.second][i]]) {
                        pair<int, int> newadd;
                        newadd.first = temp.first+1;
                        newadd.second = Map[temp.second][i];
                        store.push(newadd);
                    }
                }
                if(max < temp.first) {
                    max = temp.first;
                    max_num = temp.second;
                }
                else {
                    if(max_num < temp.second) {
                        max_num = temp.second;
                    }
                }
            }
        }
        cout << "#" << testCase << " " << max_num << endl;
    }
    return 0;
}
