#include <iostream> // SDS_TEST_CLOCK    고장난시계
#include <math.h>
#include <queue>

using namespace std;

int number[10] = { 126, 6, 91, 79, 39, 109, 125, 70, 127, 111};

unsigned int count_bits_set(unsigned int data)
{
    unsigned int count = 0;
    while(data) {
        data = data & (data - 1);
        count++;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    
    for(int testCase=1; testCase<=T; testCase++) {
        unsigned int clock[4];
        for(int i=0; i<4; i++) {
            clock[i] = 0;
            for(int j=0; j<7; j++) {
                int temp;
                cin >> temp;
                clock[i] += temp*pow(2, 6-j);
            }
        }
        
        unsigned int result[4];
        queue <int> abnormal;
        queue <int> normal;
        for(int i=0; i<4; i++) {
            for(int j=0; j<10; j++) {
                if(clock[i] == number[j]) {
                    result[i] = j;
                    if((i == 0 && j > 2) || (i == 1 && result[0] == 2 && j > 3) || (i == 2 && j > 5)) {
                        abnormal.push(i);
                        break;
                    }
                    normal.push(i);
                    break;
                }
                if(j == 9)
                    abnormal.push(i);
            }
        }
        
        int modify = 2;
        while(!abnormal.empty()) {
            if(modify <= 0)
                break;
            int i = abnormal.front();
            abnormal.pop();
            int size = 10;
            if(i == 0)
                size = 3;
            else if(i == 2)
                size = 5;
            for(int j=0; j<size; j++) {
                unsigned int temp = clock[i] ^ number[j];
                unsigned int count = count_bits_set(temp);
                if(count <= modify) {
                    result[i] = j;
                    modify -= count;
                    break;
                }
            }
        }
        
        while(!normal.empty()) {
            if(modify <= 0)
                break;
            int i = normal.front();
            normal.pop();
            int size = 10;
            if(i == 0)
                size = 3;
            else if(i == 2)
                size = 5;
            for(int j=0; j<size; j++) {
                unsigned int temp = clock[i] ^ number[j];
                unsigned int count = count_bits_set(temp);
                if(count <= modify) {
                    result[i] = j;
                    modify -= count;
                    break;
                }
            }
        }
        
        int hour = result[0]*10 + result[1];
        int minute = result[2]*10 + result[3];
        cout << "#" << testCase << " " << hour << " " << minute << endl;
    }
    return 0;
}


