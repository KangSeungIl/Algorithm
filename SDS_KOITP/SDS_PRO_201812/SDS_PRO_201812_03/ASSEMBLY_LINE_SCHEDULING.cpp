#include <iostream> // ASSEMBLY_LINE_SCHEDULING   Assembly Line Scheduling

using namespace std;

int Line1[300001];
int Line2[300001];
int Cross1[300000];
int Cross2[300000];

int my_min(int a, int b) {
    if(a < b)
        return a;
    else
        return b;
}

int main() {
    int T = 1;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int N;
        cin >> N;
        
        cin >> Line1[0] >> Line2[0] >> Line1[N] >> Line2[N];
        
        for(int i=0; i<N; i++) {
            int temp;
            cin >> temp;
            if(i == 0)
                Line1[i] += temp;
            else
                Line1[i] = temp;
        }
        
        for(int i=0; i<N; i++) {
            int temp;
            cin >> temp;
            if(i == 0)
                Line2[i] += temp;
            else
                Line2[i] = temp;
        }
        
        for(int i=1; i<N; i++)
            cin >> Cross1[i];
        
        for(int i=1; i<N; i++)
            cin >> Cross2[i];
        
        for(int i=1; i<N; i++) {
            Line1[i] = my_min(Line2[i-1] + Line1[i] + Cross2[i], Line1[i-1] + Line1[i]);
            Line2[i] = my_min(Line1[i-1] + Line2[i] + Cross1[i], Line2[i-1] + Line2[i]);
        }
        
        cout << my_min(Line1[N-1] + Line1[N], Line2[N-1] + Line2[N]) << endl;
    }
    return 0;
}
