#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next = getNext(needle);
        int i = 0;
        int j = 0;
        while (j != needle.length() && i != haystack.length()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {i++; continue;}
                else if (j < 0) {
                    i++;
                    j = 0;
                    continue;
                }
                j = next[j-1] + 1;
            }
        }
        
        if (i == haystack.length()) return -1;
        else return i - needle.length() ;
    
    }


    vector<int> getNext(string needle) {
        vector<int> next(needle.length(), -8); // you have to assign otherwise the index doesnt work.
        int j = 0;
        next[0] = -99;
        // cout << needle.length();

        for (int i = 1; i <  needle.length() ; i++) {
            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;
            // cout << "needel[i]: " << needle[i] << endl;
            // cout << "needel[j]: " << needle[j] << endl;
            // for (auto k : next) {
            //     cout << k << ' ';
            // }
            // cout << endl;

            while (j > 0 && needle[i] != needle[j]) {
                // j = next[j];// wrong. the next[j] is not present yet. 
                j = next[j-1];
            }

            if (needle[i] == needle[j]) {
                next[i] = j;
                j++;
            } else {
                next[i] = -99; 
                j = 0;    
            }
        }
        
        for (auto k : next) {
            cout << k << ' ';
        }

        return next;
    }


};


int main() {
    vector<int> aaa;
    Solution sol;
    // aaa = sol.getNext("aabaaz");
    // aaa = sol.getNext("ll");
    // aaa = sol.getNext("bba");

    // cout << sol.strStr("hello", "ll") << endl;
    cout << sol.strStr("aaaaa", "bba") << endl;
    // cout << sol.strStr("salafier", "lafi") << endl;

    return 1;
}