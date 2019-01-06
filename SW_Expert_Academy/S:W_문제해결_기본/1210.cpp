#include <iostream> //  1210    Ladder1
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int direction[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

int main() {
    int T = 10;
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector <vector <int> > Map(100, vector<int> (100, 0));
        int goal_i = 0;
        int goal_j = 0;
        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                cin >> Map[i][j];
                if(Map[i][j] == 2) {
                    goal_i = i;
                    goal_j = j;
                }
            }
        }
        
        int cur_i = goal_i;
        int cur_j = goal_j;
        while(1) {
            if(cur_i == 0)
                break;
            
            for(int i=0; i<3; i++) {
                int next_i = cur_i + direction[i][0];
                int next_j = cur_j + direction[i][1];
                
                if(next_i < 0 || next_i > 99 || next_j < 0 || next_j > 99)
                    continue;
                
                if(Map[next_i][next_j] == 1) {
                    Map[cur_i][cur_j] = 0;
                    cur_i = next_i;
                    cur_j = next_j;
                    break;
                }
            }
        }
        
        cout << "#" << testCase << " " << cur_j << endl;
    }
    return 0;
}
