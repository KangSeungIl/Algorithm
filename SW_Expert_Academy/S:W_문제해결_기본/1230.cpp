#include <iostream> //  1230    암호문3
#include <vector>

using namespace std;

int main() {
    int T=10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        vector <vector <int> > table(2, vector <int> (n, 0));
        for(int i=0; i<n; i++) {
            cin >> table[0][i];
            table[1][i] = i;
        }
        
        cin >> n;
        for(int i=0; i<n; i++) {
            char command;
            cin >> command;
            
            int x, y;
            
            if(command == 'I') {
                cin >> x >> y;
                for(int j=0; j<table[1].size(); j++)
                    if(table[1][j] >= x)
                        table[1][j] += y;
                for(int j=0; j<y; j++) {
                    int temp;
                    cin >> temp;
                    table[0].push_back(temp);
                    table[1].push_back(x+j);
                }
            }
            else if(command == 'D') {
                cin >> x >> y;
                for(int j=0; j<table[1].size(); j++) {
                    if(x <= table[1][j] && table[1][j] < x+y)
                        table[1][j] = -1;
                    else if(x+y <= table[1][j])
                        table[1][j] -= y;
                }
            }
            else {
                cin >> x;
                for(int j=0; j<x; j++) {
                    int temp;
                    cin >> temp;
                    int size = (int) table[0].size();
                    table[0].push_back(temp);
                    table[1].push_back(size);
                }
            }
        }
        vector <int> result(10);
        for(int i=0; i<table[1].size(); i++)
            if(0 <= table[1][i] && table[1][i] < 10)
                result[table[1][i]] = table[0][i];
        
        cout << "#" << testCase << " ";
        for(int i=0; i<result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
