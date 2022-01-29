#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getNext(string needle) {
        vector<int> next(needle.length(), -8); // you have to assign otherwise the index doesnt work.
        int j = 0;
        next[0] = -99;
        cout << needle.length();

        for (int i = 1; i <  needle.length() ; i++) {
            cout << "i: " << i << endl;
            cout << "j: " << j << endl;
            cout << "needel[i]: " << needle[i] << endl;
            cout << "needel[j]: " << needle[j] << endl;
            for (auto k : next) {
                cout << k << ' ';
            }
            cout << endl;

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
        
        // for (auto k : next) {
        //     cout << k << ' ';
        // }

        return next;
    }

};


int main() {
    vector<int> aaa;
    Solution sol;
    aaa = sol.getNext("aabaac");
    cout << "fini" << endl;
    return 1;
}