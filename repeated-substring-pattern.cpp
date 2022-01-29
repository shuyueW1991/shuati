#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.empty()) return false;
        vector<int> next = getNext(s);
        if (next.back() <= 0) return false;

        int temp = 0;
        cout <<  next.size() - next.back() - 1 << endl;

        
        for ( int i =  next.size() - next.back() - 1; i < s.length(); i++) {
            cout << "i" << i << endl;
            cout << "next[i]" << next[i] << endl;
            cout << "temp" << temp << endl;
            if (next[i] != temp) {
                return false;
            }
            temp++;
        }
        return true;
    }


    vector<int> getNext(string needle) {
        vector<int> next(needle.length(), -8); // you have to assign otherwise the index doesnt work.
        int j = 0;
        next[0] = -99;
        // cout << needle.length();

        for (int i = 1; i <  needle.length() ; i++) {
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
    // aaa = sol.getNext("asdfasdfasdf");
    // aaa = sol.getNext("abcabcabc");
    // cout << "it is " << sol.repeatedSubstringPattern("abcabcabcabc") << endl;
    // cout << "it is " << sol.repeatedSubstringPattern("ababcababc") << endl;
    cout << "it is " << sol.repeatedSubstringPattern("abac") << endl;



    return 1;
}