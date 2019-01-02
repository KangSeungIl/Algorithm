#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define MAX_N 100000

template <typename T>
class stack {
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
            return array[index-1];
        return -1;
    }
    void push(T value) {
        if(!full()) {
            array[index] = value;
            index++;
        }
    }
    void pop() {
        if(!empty())
            index--;
    }
    
private:
    int index;
    T array[MAX_N];
};

int main() {
    int n;
    cin >> n;
    
    stack <int> s;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        s.push(temp);
    }
    
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}
