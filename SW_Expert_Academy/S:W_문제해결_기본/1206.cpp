#include <iostream> //  1206    View
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    for(int i=1; i<=10; i++) {
        int size;
        cin >> size;
        
        vector<int> building(size);
        for(int j=0; j<size; j++) cin >> building[j];
        int count = 0;
        for(int j=2; j<(size-2); j++) {
            int min = 1001;
            
            if(building[j-2] > building[j]) continue;
            else {
                if(building[j] - building[j-2] < min) min = building[j] - building[j-2];
            }
            
            if(building[j-1] > building[j]) continue;
            else {
                if(building[j] - building[j-1] < min) min = building[j] - building[j-1];
            }
            
            if(building[j+1] > building[j]) continue;
            else {
                if(building[j] - building[j+1] < min) min = building[j] - building[j+1];
            }
            
            if(building[j+2] > building[j]) continue;
            else {
                if(building[j] - building[j+2] < min) min = building[j] - building[j+2];
            }
            
            count += min;
        }
        cout << "#" << i << " " << count << endl;
    }
    return 0;
}

