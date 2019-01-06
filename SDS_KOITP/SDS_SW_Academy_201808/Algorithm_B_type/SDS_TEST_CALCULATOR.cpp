#include <iostream> // SDS_TEST_CALCULATOR    오래된 계산기
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        priority_queue<long long, vector <long long>, greater<long long> > pq;
        for(int i=0; i<N; i++) {
            long long temp;
            cin >> temp;
            pq.push(temp);
        }
        
        long long result = 0;
        while(pq.size() != 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long sum = a + b;
            result += sum;
            pq.push(sum);
        }
        
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}
