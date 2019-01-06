#include <iostream> //  1213    String
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int result = 0;

void ImproveInitNext(string pattern, vector <int> &next) {
    next[0] = -1;
    int j = 0;
    for(int i=1; i<pattern.length(); i++) {
        if(pattern[i]==pattern[j]) {
            next[i]=next[j];
        } else {
            next[i] = j;
        }
        while((j>=0) && (pattern[i] != pattern[j])) {
            j = next[j];
        }
        j++;
    }
}

void KMP(string text, string pattern, vector <int> next) {
    for (int i = 0, j = 0; i < text.length(); i++, j++) {
        while ((j >= 0) && (text[i] != pattern[j]))
            j = next[j];
        if (j == pattern.length()-1 && text[i] == pattern[j]) {
            result++;
            j = -1;
        }
    }
}

int main() {
    int T = 10;
    
    for(int testCase=1; testCase<=T; testCase++) {
        int n;
        cin >> n;
        
        string pattern;
        cin >> pattern;
        
        string text;
        cin >> text;
        
        vector <int> next(pattern.length());
    
        ImproveInitNext(pattern, next);
        
        result = 0;
        KMP(text, pattern, next);
        
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}
