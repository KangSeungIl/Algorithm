#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int min(int a, int b) {
    if(a < b)
        return a;
    else
        return b;
}

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N, M, B;
        cin >> N >> M >> B;
        
        vector <int> Count(20001, 0);
        priority_queue <int, vector<int>, greater<int> > Total;
        vector <int> Missile;
        int result = 0;
        for(int i=0; i<M; i++) {
            int power, num;
            cin >> power >> num;
            if(power > B) {
                Total.push(power);
                Count[power] = num;
            }
            else if(power == B) {
                result += (power * num);
                N -= num;
            }
            else {
                Missile.push_back(power);
                Count[power] = num;
            }
        }
        
        sort(Missile.begin(), Missile.end(), less<int>());
        
        for(int i=0; i<Missile.size(); i++) {
            if(N == 0)
                break;
            if(Count[Missile[i]] < 1)
                continue;
            if(Count[Missile[i]] >= 2 && 2*Missile[i] >= B) {
                int sum = 2*Missile[i];
                int num = Count[Missile[i]]/2;
                if(Count[sum] == 0)
                    Total.push(sum);
                Count[Missile[i]] -= 2*num;
                Count[sum] += num;
            }
            for(int j=i+1; j<Missile.size(); j++) {
                if(Count[Missile[i]] < 1)
                    break;
                if(Count[Missile[j]] < 1)
                    continue;
                int sum = Missile[i] + Missile[j];
                if(sum >= B) {
                    int num = min(Count[Missile[i]], Count[Missile[j]]);
                    if(Count[sum] == 0)
                        Total.push(sum);
                    Count[Missile[i]] -= num;
                    Count[Missile[j]] -= num;
                    Count[sum] += num;
                }
            }
        }
        
        while(!Total.empty()) {
            if(N == 0)
                break;
            int temp = Total.top();
            Total.pop();
            int num = min(Count[temp], N);
            result += (temp * num);
            Count[temp] -= num;
            N -= num;
        }
        
        cout << "#" << testCase << " ";
        if(N == 0)
            cout << result << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}
