#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s = skinnyWords(s);
        cout << s << endl;
        // reverse(s.begin, s.end());
        for (int i = 0,  j = s.length() - 1; i < s.length()/2 ; i++, j-- ) swap(s[i], s[j]);

        int slow = 0;
        for (int fast = 0; fast < s.length(); fast++) {
            if (s[fast] == ' ') {
                for (int i = slow,  j = fast - 1; i < (slow + fast - 1)/2 + 1; i++, j-- ) swap(s[i], s[j]);
                slow = fast + 1;
                
            }  else if (fast == s.length() - 1) {
                for (int i = slow,  j = fast ; i < (slow + fast )/2 + 1; i++, j-- ) swap(s[i], s[j]);
            }

        }
        cout << s << endl;
        return s;


    }


    string skinnyWords(string s) {
        int slowInd = -1;
        for (int fastInd = 0; fastInd < s.length() ; fastInd++) {
            if (slowInd == -1 && s[fastInd] == ' ') continue;
            if (slowInd > -1 && s[slowInd] == ' '  && s[fastInd] == ' ') continue;

            slowInd++;
            s[slowInd] = s[fastInd];

        }
        
        // erase the last spaces
        while (s[slowInd] == ' ')  {
            slowInd--;
        }

        s.resize(slowInd+1);
        return s;
            
        
    }

    
};


int main() {
    Solution sol;
    // cout << sol.skinnyWords("    alllahuakh   bar...     ");
    cout << sol.reverseWords("    alllahuakh   bar...     ");

    return 1;
}
