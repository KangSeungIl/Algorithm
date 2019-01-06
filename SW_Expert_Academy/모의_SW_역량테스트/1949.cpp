#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

int path = 0;
int K = 0;
int N = 0;
int direct[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

void search(vector <vector <int> > Map, int i, int j, bool cut, int count, int direction) {
    for(int t=0; t<4; t++) {
        int newi = i + direct[t][0];
        int newj = j + direct[t][1];
        
        if(newi < 0 || newi > N-1 || newj < 0 || newj > N-1 || t == (direction+2)%4)
            continue;
        
        if(Map[newi][newj] < Map[i][j]) {
            search(Map, newi, newj, cut, count+1, t);
        }
    }
    if(path < count)
        path = count;
    
    if(!cut) {
        bool cut = true;
        for(int t=0; t<4; t++) {
            int newi = i + direct[t][0];
            int newj = j + direct[t][1];
            
            if(newi < 0 || newi > N-1 || newj < 0 || newj > N-1 || t == (direction+2)%4)
                continue;
            
            if(Map[newi][newj] < Map[i][j])
                continue;
            
            if(Map[newi][newj]-Map[i][j] < K) {
                Map[newi][newj] -= Map[newi][newj] - Map[i][j] + 1;
                search(Map, newi, newj, cut, count+1, t);
                Map[newi][newj] += Map[newi][newj] - Map[i][j] + 1;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        cin >> N >> K;
        
        vector <vector <int> > Map(N, vector <int> (N));
        vector <pair<int, int> > Mhieght;
        int maxHight = 0;
        for(int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cin >> Map[i][j];
                if(maxHight < Map[i][j]) {
                    Mhieght.clear();
                    maxHight = Map[i][j];
                    pair<int, int> temp;
                    temp.first = i; temp.second = j;
                    Mhieght.push_back(temp);
                } else if(maxHight == Map[i][j]) {
                    pair<int, int> temp;
                    temp.first = i; temp.second = j;
                    Mhieght.push_back(temp);
                }
            }
        }
        
        for(int i=0; i<(int)Mhieght.size(); i++)
            search(Map, Mhieght[i].first, Mhieght[i].second, false, 1, -3);
        
        cout << "#" << testCase << " " << path <<endl;
        path = 0;
    }
    return 0;
}
