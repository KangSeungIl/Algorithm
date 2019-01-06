#include <iostream> //  1248    공통조상

using namespace std;

int result = 0;

void subtree(int child[][2], int p) {
    result++;
    if(child[p][0] == 0)
        return;
    if(child[p][0] > 0)
        subtree(child, child[p][0]);
    if(child[p][1] > 0)
        subtree(child, child[p][1]);
}
int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int V, E;
        cin >> V >> E;
        
        int A, B;
        cin >> A >> B;
        
        int parent[10001] = { 0, };
        int child[10001][2] = { {0, 0}, };
        bool visited[10001] = { false, };
        for(int i=0; i<E; i++) {
            int p, c;
            cin >> p >> c;
            parent[c] = p;
            if(child[p][0] == 0)
                child[p][0] = c;
            else
                child[p][1] = c;
        }
        
        int temp = A;
        visited[temp] = true;
        while(temp != 1) {
            temp = parent[temp];
            visited[temp] = true;
        }
        
        temp = B;
        while(!visited[temp])
            temp = parent[temp];
        
        result = 0;
        subtree(child, temp);
        
        cout << "#" << testCase << " " << temp << " " << result << endl;
    }
    return 0;
}
