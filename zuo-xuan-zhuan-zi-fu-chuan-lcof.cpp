#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s = rotatePiece(s, 0, n - 1);
        cout << s << endl; 
        rotatePiece(s, n, s.length() - 1);
                cout << s << endl; 

        rotatePiece(s, 0, s.length() - 1);
                cout << s << endl; 

        return s;

    }

private:
    string rotatePiece(string s, int b, int e) {
        for (int i = b, j = e; i <= (b + e)/2 + 1; i++, j--) {
            swap(s[i], s[j]);
        }
        return s;
    }
};

int main(){
    Solution sol;
    cout << sol.reverseLeftWords("abcdefd", 2) << endl; 
    return 1;

}