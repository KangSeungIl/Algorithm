
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e, s, k; // 정점 수 , 간선 수, 시작 정점 번호, 가야한 마을수
int result = 987654321;
vector<vector<int>> graph;
vector<vector<int>> min_table;
vector<int> k_arr;
vector<bool> visit;

void dijstra(int start_point) {
    vector<int> s, d;
    s.assign(v, false);
    min_table[start_point][start_point] = 0;
    while (true) {
        int m = 987654321, n = -1;
        for (int j = 0; j < v; j++) {
            if (!s[j] && (m > min_table[start_point][j])) {
                m = min_table[start_point][j];
                n = j;
            }
        }
        if (m == 987654321) break;
        s[n] = true;
        for (int j = 0; j < v; j++) {
            if (s[j]) continue;
            int via = min_table[start_point][n] + graph[n][j];
            if (min_table[start_point][j] > via) min_table[start_point][j] = via;
        }
    }
    
}

void dfs(int start_point, int s_index, int sum, int count) {
    if (sum >= result) return;
    if (count == 0) {
        sum =sum + min_table[start_point][s-1];
        if (result > sum) {
            result = sum;
        }
    }
    for (int i = 0; i < k; i++) {
        if (visit[i] == false) {
            visit[i] = true;
            dfs(k_arr[i]-1, i, sum + min_table[start_point][k_arr[i]-1], count-1);
            visit[i] = false;
        }
        
    }
    
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        int n, m;
        cin >> n >> m >> k >> s;
        
        v = n;
        e = m;
        graph.assign(v, vector<int>(v, 987654321));
        min_table.assign(v, vector<int>(v, 987654321));
        k_arr.assign(k, 0);
        visit.assign(k, 0);
        result = 987654321;
        
        for (int j = 0; j < k; j++) {
            cin >> k_arr[j];
            
        }
        for (int j = 0; j < m; j++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            graph[temp1 - 1][temp2 - 1] = 1;
            graph[temp2 - 1][temp1 - 1] = 1;
            
        }
        dijstra(s-1);
        for (int j = 0; j < k; j++) {
            dijstra(k_arr[j]-1);
        }
        
        dfs(s-1, 0, 0, k);
        
        cout << "#" << i << " " << result << endl;
    }
    
    
    return 0;
}
