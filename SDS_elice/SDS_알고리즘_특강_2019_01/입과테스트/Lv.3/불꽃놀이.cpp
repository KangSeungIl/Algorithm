#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct Path {
    int start;
    int end;
    int cost;
} Path;

typedef struct Node {
    long long orignal;
    long long max;
} Node;

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        vector <vector<Path> > Powder(2*N+1);
        for(int i=0; i<(2*N-1); i++) {
            int a, b, c;
            cin >> a >> b >> c;
            Path temp;
            temp.start = a;
            temp.end = b;
            temp.cost = c;
            Powder[a].push_back(temp);
            temp.start = b;
            temp.end = a;
            Powder[b].push_back(temp);
        }
        
        stack <Path> store;
        stack <Path> deep;
        store.push(Powder[2*N][0]);
        vector <bool> visited(2*N+1, false);
        visited[2*N] = true;
        vector <Node> sum(2*N+1);
        long long result = 0;
        while(!store.empty()) {
            Path temp = store.top();
            store.pop();
            bool op = false;
            if(!visited[temp.end]) {
                visited[temp.end] = true;
                deep.push(temp);
                sum[temp.end].orignal = temp.cost;
                sum[temp.end].max = temp.cost;
                for(int j=0; j<Powder[temp.end].size(); j++) {
                    if(!visited[Powder[temp.end][j].end]) {
                        store.push(Powder[temp.end][j]);
                        op = true;
                    }
                }
            }
            if(!op) {
                while(!deep.empty()) {
                    Path current = deep.top();
                    deep.pop();
                    bool oper = false;
                    long long new_add = sum[current.start].orignal + sum[current.end].max;
                    if(sum[current.start].max == sum[current.start].orignal)
                        sum[current.start].max = new_add;
                    else if(new_add > sum[current.start].max) {
                        result += (new_add - sum[current.start].max);
                        sum[current.start].max = new_add;
                    }
                    else {
                        result += (sum[current.start].max - new_add);
                    }
                    for(int j=0; j<Powder[current.start].size(); j++){
                        if(!visited[Powder[current.start][j].end]) {
                            oper = true;
                        }
                    }
                    if(oper)
                        break;
                }
            }
        }
        
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}
