#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>
using namespace std;

class Solution {
public:
    bool find(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            while(!find(s[i])&&i<j)
                i++;
            while(!find(s[j])&&i<j)
                j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};

int main() {
    string input1 = "hello";
    string input2 = "leetcode";
    string result1 = Solution().reverseVowels(input1);
    string result2 = Solution().reverseVowels(input2);
    cout << result1 << " and " << result2 << endl;
    cin.get();
    return 0;
}