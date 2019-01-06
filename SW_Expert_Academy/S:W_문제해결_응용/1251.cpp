#include <iostream> //  1251    하나로
#include <vector>
#include <math.h>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::priority_queue;

typedef struct Tunnel {
    int end;
    long double cost;
    bool operator<(const Tunnel &o) const {
        return cost > o.cost;
    }
} Tunnel;

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        vector <pair<int, int> > island(N);
        
        for(int i=0; i<N; i++)
            cin >> island[i].first;
        for(int i=0; i<N; i++)
            cin >> island[i].second;
        
        long double E;
        cin >> E;
        
        vector < vector <long double> > table(N, vector<long double> (N, 2000000));
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(j != i) table[i][j] = sqrt(pow(island[i].first - island[j].first, 2) + pow(island[i].second - island[j].second, 2));
        
        priority_queue <Tunnel> store;
        vector <bool> visit(N, false);
        visit[0] = true;
        
        for(int i=1; i<(int)table[0].size(); i++) {
            Tunnel temp;
            temp.end = i;
            temp.cost = table[0][i];
            store.push(temp);
        }
        
        long double sum = 0;
        while(!store.empty()) {
            Tunnel temp = store.top();
            store.pop();
            if(visit[temp.end] == false) {
                sum += pow(temp.cost, 2);
                visit[temp.end] = true;
                for(int i=0; i<N; i++) {
                    if(i != temp.end) {
                        Tunnel temp1;
                        temp1.end = i;
                        temp1.cost = table[temp.end][i];
                        store.push(temp1);
                    }
                }
            }
        }
        sum *= E;
        long long result = round(sum);
        
        cout << "#" << testCase << " "<< result <<endl;
    }
    return 0;
}

