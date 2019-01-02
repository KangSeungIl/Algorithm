#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define MAX_N 100000

template <typename T>
class queue {
public:
    void init() {
        front = 0;
        rear = 0;
    }
    bool empty() {
        return (front == rear);
    }
    bool full() {
        return ((rear+1) % MAX_N == front);
    }
    T top() {
        if(!empty())
            return array[front];
        return -1;
    }
    void push(T value) {
        if(!full()) {
            array[rear] = value;
            rear++;
            if(rear == MAX_N)
                rear = 0;
        }
    }
    void pop() {
        if(!empty()) {
            front++;
            if(front == MAX_N)
                front = 0;
        }
    }
    
private:
    int front;
    int rear;
    T array[MAX_N];
};

int main() {
    int n;
    cin >> n;
    
    queue <int> q;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}
