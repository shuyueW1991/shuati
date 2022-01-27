#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        path.push_back(-1);
        // cout << path.back() << endl;
        path_str.clear();

        backtracking(s, 0);

        for (auto i : result) {
            for (auto j : i) {
                cout << j << "  ";
            }
            cout << endl;
        }
        return result;
    }

    int test(string text, int begi, int endi) {
        if (palindrome(text, begi, endi)) cout << "yes" << endl;
        else cout << "no" << endl;
        return 1;
    }

private:
    vector<vector<string>> result;
    vector<int> path;
    vector<string> path_str;

    void backtracking(string text, int startIndex) {
        cout << "insdie" << path.back() << endl;


        if (startIndex == text.length()  ) {
            for (vector<string>::iterator iter = path_str.begin(); iter != path_str.end(); iter++) {
                cout << "path_str: " << *iter << " " << endl;
            }
            result.push_back(path_str);
            return;
        }

        for ( int i = startIndex; i < text.length()  ; i++) {
            if (palindrome(text, path.back(), i)) {
                // cout << "path.back() " << path.back() << endl;
                // cout << "i " << i << endl;
                // cout << "i - path.back() " << i - path.back() << endl;
                // cout <<  "yes " << text.substr(path.back() + 1, i - path.back() ) << endl;
                path_str.push_back(text.substr(path.back() + 1, i - path.back() ));
                path.push_back(i);

                backtracking(text, i + 1);
                path.pop_back();
                path_str.pop_back();
            } else continue;
        }
    }


    bool palindrome(string&  text, int beg, int end) {
        string chuan = text.substr(beg + 1, end- beg);
        string chuan_ren = chuan;
        reverse(chuan_ren.begin(), chuan_ren.end());
        if (chuan == chuan_ren) {
            // cout << chuan << endl;
            return true;
        }
        else return false;
    }

};



int main() {
    Solution solute;
    // solute.test("alaala", -1, 5);
    // solute.partition("alahala");
    solute.partition("alla");
    return 1;
}