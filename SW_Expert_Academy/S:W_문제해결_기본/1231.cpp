#include <iostream> //  1231    중위순회
#include <vector>
#include <string>

using namespace std;

void inorder(vector <char> tree, int i) {
    if(tree[2*i] != '0')
        inorder(tree, 2*i);
    cout << tree[i];
    if(tree[2*i+1] != '0')
        inorder(tree, 2*i+1);
}
int main() {
    int T=10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        cin.ignore();
        vector <char> tree(101, '0');
        for(int i=0; i<n; i++) {
            string s1;
            getline(cin, s1);
            int index = 0;
            if(s1[1] != ' ') {
                if(0 <= s1[2]-'0' && s1[2]-'0' <= 9) {
                    index = (s1[0]-'0')*100 + (s1[1]-'0')*10 + (s1[2]-'0');
                    tree[index] = s1[4];
                }
                else {
                    index = (s1[0]-'0')*10 + (s1[1]-'0');
                    tree[index] = s1[3];
                }
            }
            else {
                index = s1[0]-'0';
                tree[index] = s1[2];
            }
        }
        cout << "#" << testCase << " ";
        inorder(tree, 1);
        cout << endl;
    }
    return 0;
}
