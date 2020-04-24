#include <iostream>
#include <string.h>
#include <cassert>
#include <ctime>
using namespace std;

class Solution {
public:
    /*
    解法1：滑动窗口
    时间：O(len(s))，空间：O(len(charset))
    */
    int lengthOfLongestSubstring1(string s) {
        int freq[256] = {0};    // 初始化所有字母的频率为0
        int l = 0, r = -1;      // 滑动窗口为s[l...r]
        int res = 0;            // 满足条件的长度
        // 整个循环从 l == 0; r == -1 这个空窗口开始
        // 到l == s.size(); r == s.size()-1 这个空窗口截止
        // 在每次循环里逐渐改变窗口, 维护freq, 并记录当前窗口中是否找到了一个新的最优值
        while(l < s.size()){
            if(r + 1 < s.size() && freq[s[r+1]] == 0)
                freq[s[++r]] ++;
            else    //r已经到头 || freq[s[r+1]] == 1
                freq[s[l++]] --;
            res = max(res, r-l+1);
        }
        return res;
    }
    /*
    解法2：滑动窗口
    时间：O(len(s))，空间：O(len(charset))
    */
    int lengthOfLongestSubstring2(string s) {
        int freq[256] = {0};
        int l = 0, r = -1; //滑动窗口为s[l...r]
        int res = 0;
        // 在这里, 循环中止的条件可以是r + 1 < s.size(), 想想看为什么?
        // 感谢课程QQ群 @千千 指出 :)
        while(r + 1 < s.size()){
            if( freq[s[r + 1]] == 0 )
                freq[s[++r]] ++;
            else    //freq[s[r+1]] == 1
                freq[s[l++]] --;
            res = max(res, r - l + 1);
        }
        return res;
    }
    /*
    解法3：滑动窗口
    时间：O(len(s))，空间：O(len(charset))
    */
    int lengthOfLongestSubstring3(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;
        int res = 0;
        while(r + 1 < s.size()){
            while(r + 1 < s.size() && freq[s[r + 1]] == 0)
                freq[s[++r]] ++;
            res = max(res, r - l + 1);
            if(r + 1 < s.size()){
                freq[s[++r]] ++;
                assert(freq[s[r]] == 2);
                while(l <= r && freq[s[r]] == 2)
                    freq[s[l++]] --;
            }
        }
        return res;
    }
    /*
    解法4：滑动窗口
    其中使用last[c]保存字符c上一次出现的位置, 用于在右边界发现重复字符时, 快速移动左边界
    使用这种方法, 时间复杂度依然为O(n), 但是只需要动r指针, 实际上对整个s只遍历了一次
    相较而言, 之前的方法, 需要移动l和r两个指针, 相对于对s遍历了两次
    时间：O(len(s))，空间：O(len(charset))
    */
    int lengthOfLongestSubstring4(string s) {
        int last[256];
        memset(last, -1, sizeof(last));
        int l = 0, r = -1; //滑动窗口为s[l...r]
        int res = 0;
        while(r + 1 < s.size()){
            r ++;
            if(last[s[r]] != -1)
                l = max(l, last[s[r]] + 1);
            res = max(res, r - l + 1);
            last[s[r]] = r;
        }
        return res;
    }

    void testPerformance(const string& algoName,
                        int (*lengthOfLongestSubstring)(const string&),
                        const string& s){
        clock_t startTime = clock();
        int res = lengthOfLongestSubstring(s);
        clock_t endTime = clock();
        cout << algoName << " : res = " << res << " ";
        cout << "Time = " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
};
int isDuplicateChar(const string& s, int l, int r);

int main() {

    cout << Solution().lengthOfLongestSubstring1( "abcabcbb" )<<endl; //3
    cout << Solution().lengthOfLongestSubstring2( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring3( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring4( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring1( "" )<<endl;         //0
    cin.get();

    int n = 1000000;
    // 测试, 使用长度为1000万的完全随机字符串
    // 每一个字符是asc ii码从32-126之间的随机字符
    string s = "";
    for(int i = 0 ; i < n ; i ++)
        s += (rand()%95 + 32);
    cout << "Test: 10,000,00 length of completely random string:" << endl;
    testPerformance("algo1", Solution().lengthOfLongestSubstring1, s);
    testPerformance("algo2", Solution().lengthOfLongestSubstring2, s);
    testPerformance("algo3", Solution().lengthOfLongestSubstring3, s);
    testPerformance("algo4", Solution().lengthOfLongestSubstring4, s);
    cin.get();
    return 0;
}

int isDuplicateChar(const string& s, int l, int r){
    for(int i = l ; i < r ; i ++)
        if(s[i] == s[r])
            return i;
    return -1;
}

