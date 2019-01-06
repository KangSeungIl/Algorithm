#include <iostream> // MOST_ELEMENT    가장 많은 수
#include <map>

using namespace std;

int main() {
    int T = 1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        std::ios::sync_with_stdio(false);
        int N;
        cin >> N;
        
        map <int, int> number;
        map <int, int>::iterator it;
        
        int max_count = 0;
        int result = -987654321;
        for(int i=0; i<N; i++) {
            int temp;
            cin >> temp;
            it = number.find(temp);
            if(it == number.end()) {
                number.insert(make_pair(temp, 1));
                if(max_count < 1) {
                    max_count = 1;
                    result = temp;
                }
                else if(max_count == 1) {
                    if(result > temp) {
                        max_count = 1;
                        result = temp;
                    }
                }
            }
            else {
                it->second++;
                if(max_count < it->second) {
                    max_count = it->second;
                    result = it->first;
                }
                else if((max_count == it->second) && (it->first < result)) {
                    max_count = it->second;
                    result = it->first;
                }
            }
        }
        
        cout << result << endl;
    }
    return 0;
}


