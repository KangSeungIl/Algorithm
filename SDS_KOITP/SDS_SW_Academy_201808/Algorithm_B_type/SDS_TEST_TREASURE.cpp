#include <iostream> // SDS_TEST_TREASURE    보물찾기
#include <vector>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N, M, K;
        cin >> N >> M >> K;
        
        vector <vector <int> > Map(N+1);
        for(int i=0; i<M; i++) {
            int start, end;
            cin >> start >> end;
            Map[start].push_back(end);
        }
        
        queue <pair<int, int> > q;
        vector <bool> visited (N+1, false);
        pair<int, int> init;
        init.first = 1; init.second = 0;
        q.push(init);
        int result = -1;
        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            if(temp.second > K)
                break;
            if(temp.first == N) {
                result = temp.second;
                break;
            }
            if(!visited[temp.first]) {
                visited[temp.first] = true;
                for(int j=0; j<Map[temp.first].size(); j++) {
                    if(!visited[Map[temp.first][j]]) {
                        pair <int, int> addtemp;
                        addtemp.first = Map[temp.first][j]; addtemp.second = temp.second+1;
                        q.push(addtemp);
                    }
                }
            }
        }
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}
