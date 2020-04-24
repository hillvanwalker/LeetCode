#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if (isPalindrome(s))
            return true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j){
            if (s[i] != s[j]) {
                if (isPalindrome(s.substr(i, j - i)) || isPalindrome(s.substr(i + 1, j - i)))
                    return true;
                return false;
            }
            i++;
            j--;
        }
        return false;
    }
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i])
                return false;
        }
        return true;
    }
};

int main() {
    string input = "abca";
    bool result = Solution().validPalindrome(input);
    cout << result << endl;
    cin.get();
    return 0;
}