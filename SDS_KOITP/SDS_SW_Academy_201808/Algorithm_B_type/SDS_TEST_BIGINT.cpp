#include <iostream> // SDS_TEST_BIGINT    큰수만들기
#include <algorithm>

using namespace std;

typedef struct Number{
    long long num;
    bool sign;
    bool operator<(const Number &o) const {
        return num > o.num;
    }
} Number;

long long abs_s(long long a) {
    if(a < 0)
        return -a;
    else
        return a;
}

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N, P, M;
        cin >> N >> P >> M;
        
        Number number[100000];
        for(int i=0; i<N; i++) {
            long long temp;
            cin >> temp;
            number[i].num = abs_s(temp);
            if(temp < 0)
                number[i].sign = false;
            else
                number[i].sign = true;
        }
        
        sort(number+1, number+N);
        
        long long result;
        if(number[0].sign)
            result = number[0].num;
        else
            result = -1*number[0].num;
        for(int i=1; i<N; i++) {
            if(number[i].sign) {
                if(P > 0) {
                    result += number[i].num;
                    P--;
                }
                else {
                    result -= number[i].num;
                    M--;
                }
            }
            else {
                if(M > 0) {
                    result += number[i].num;
                    M--;
                }
                else {
                    result -= number[i].num;
                    P--;
                }
            }
        }
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}
