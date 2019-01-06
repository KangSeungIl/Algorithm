#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Point {
    int x;
    int y;
    int num;
} Point;

bool cmp_x(Point a, Point b){
    if(a.x < b.x) return true;
    else if(a.x==b.x) return a.y < b.y;
    else return false;
}

bool cmp_y(Point a, Point b){
    if(a.y < b.y) return true;
    else if(a.y==b.y) return a.x<b.x;
    else return false;
}

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        vector <Point> Pointset(N);
        for(int i=0; i<N; i++) {
            Pointset[i].num = i + 1;
            cin >> Pointset[i].x >> Pointset[i].y;
        }
        
        sort(Pointset.begin(), Pointset.end(), cmp_y);
        int min_coordinate = 1000000001;
        for(int i=0; i<N; i++) {
            if(min_coordinate > Pointset[i].x)
                min_coordinate = Pointset[i].x;
            else
                Pointset[i].num = 0;
        }
        
        sort(Pointset.begin(), Pointset.end(), cmp_x);
        min_coordinate = 1000000001;
        for(int i=0; i<N; i++) {
            if(min_coordinate > Pointset[i].y)
                min_coordinate = Pointset[i].y;
            else
                Pointset[i].num = 0;
        }
        
        cout << "#" << testCase << " ";
        for(int i=0; i<N; i++)
            if(Pointset[i].num != 0)
                cout << Pointset[i].num << " ";
        cout << endl;
    }
    return 0;
}
