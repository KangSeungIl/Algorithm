#include <iostream> //  1247    최적경로

using std::cin;
using std::cout;
using std::endl;

typedef struct Location {
    int x;
    int y;
} Location;

int result = 987654321;

int abs(int a) { // absolute about integer a
    if(a >= 0)
        return a;
    else
        return -a;
}

int dist(Location a, Location b) {// distance between a, b
    return abs(a.x-b.x) + abs(a.y-b.y);
}

void delivery (Location location[], bool visited[], int c, int N, int count, int sum) {
    if(count == N) {
        sum += dist(location[c], location[1]);
        if(result > sum)
            result = sum;
        return;
    }
    
    for(int i=2; i<N+2; i++) {
        if(!visited[i]) {
            visited[i] = true;
            delivery(location, visited, i, N, count+1, sum+dist(location[c], location[i]));
            visited[i] = false;
        }
    }
}

int main() {
    int T; // Number of Testcase
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) { // Repeat testcase
        int N; // N : Number of Customer
        cin >> N;
        
        Location location[12];  // Store Location (0 : Company, 1 : Home, 2~N+1 : Customer)
        for(int i=0; i<N+2; i++)
            cin >> location[i].x >> location[i].y;
        
        result = 987654321;
        bool visited[12] = {false, };
        delivery(location, visited, 0, N, 0, 0);
        
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}
