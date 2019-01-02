#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define MAX_N 100000

template <typename T>
class priority_queue {
public:
    void init() {
        index = 0;
    }
    bool empty() {
        return (index == 0);
    }
    bool full() {
        return (index == MAX_N);
    }
    T top() {
        if(!empty())
            return array[0];
        return -1;
    }
    void push(T value) {
        if(!full()) {
            array[index] = value;
            
            int child = index;
            int parent = (child-1)/2;
            while(child > 0 && cmp(child, parent)) {
                swap(child, parent);
                child = parent;
                parent = (child-1)/2;
            }
            
            index++;
        }
    }
    void pop() {
        if(!empty()) {
            index--;
            array[0] = array[index];
            
            int parent = 0;
            while(parent*2+1 < index) {
                int child;
                if(parent*2+2 == index)
                    child = parent*2+1;
                else
                    child = cmp(parent*2+1, parent*2+2) ? parent*2+1 : parent*2+2;
                if(!cmp(child, parent))
                    break;
                swap(child, parent);
            }
        }
    }
    bool cmp(int a, int b) {
        if(array[a] < array[b])
            return 1;
        else
            return 0;
    }
    void swap(int a, int b) {
        T temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }
private:
    int index;
    T array[MAX_N];
};

int main() {
    int n;
    cin >> n;
    
    priority_queue <int> pq;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    return 0;
}
