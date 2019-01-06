#include <iostream> //  1209    Sum
#include <vector>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::priority_queue;
using std::less;

int main() {
    int T = 10;
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        vector< vector <int> > table(100, vector <int>(100, 0));
        priority_queue<int, vector<int>, less<int> > pq;
        int right_cross = 0;
        int left_cross = 0;
        for(int i=0; i<100; i++) {
            int low_sum = 0;
            for(int j=0; j<100; j++) {
                cin >> table[i][j];
                low_sum += table[i][j];
                if(i == j)
                    right_cross += table[i][j];
                if(i + j == 99)
                    left_cross += table[i][j];
            }
            pq.push(low_sum);
        }
        pq.push(right_cross);
        pq.push(left_cross);
        for(int j=0; j<100; j++) {
            int col_sum = 0;
            for(int i=0; i<100; i++)
                col_sum += table[i][j];
            pq.push(col_sum);
        }
        
        cout << "#" << testCase << " " << pq.top() << endl;
    }
    return 0;
}

