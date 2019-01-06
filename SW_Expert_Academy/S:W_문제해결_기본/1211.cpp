#include <iostream> // 1211 Ladder2
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pair;
int direction[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

int main() {
    int T = 10;
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector <vector <int> > Map(100, vector<int> (100, 0));
        vector <pair<int, int> > startpoint;
        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                cin >> Map[i][j];
                if(i == 99 && Map[i][j] == 1) {
                    pair<int, int> temp;
                    temp.first = i; temp.second = j;
                    startpoint.push_back(temp);
                }
            }
        }
        
        int min = 987654321;
        int min_num = 0;
        for(int i=0; i<startpoint.size(); i++) {
            int cur_i = startpoint[i].first;
            int cur_j = startpoint[i].second;
            int count = 0;
            vector <vector <bool> > visited(100, vector <bool> (100, false));
            while(1) {
                if(cur_i == 0)
                    break;
                
                for(int j=0; j<3; j++) {
                    int next_i = cur_i + direction[j][0];
                    int next_j = cur_j + direction[j][1];
                    
                    if(next_i < 0 || next_i > 99 || next_j < 0 || next_j > 99)
                        continue;
                    
                    if(!visited[next_i][next_j] && Map[next_i][next_j] == 1) {
                        visited[cur_i][cur_j] = true;
                        cur_i = next_i;
                        cur_j = next_j;
                        count++;
                        break;
                    }
                }
            }
            if(min > count) {
                min = count;
                min_num = cur_j;
            }
        }
        
        cout << "#" << testCase << " " << min_num << endl;
    }
    return 0;
}

