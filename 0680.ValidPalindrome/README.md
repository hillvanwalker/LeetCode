# 680. 验证回文字符串 Ⅱ
给定一个非空字符串 `s`，最多删除一个字符。判断是否能成为回文字符串。  
示例 1:  
&emsp;&emsp;输入: `"aba"`  
&emsp;&emsp;输出: `True`  
示例 2:  
&emsp;&emsp;输入: `"abca"`  
&emsp;&emsp;输出: `True`  
解释:   
&emsp;&emsp;你可以删除`c`字符。  
注意:  
&emsp;&emsp;字符串只包含从 `a-z` 的小写字母。字符串的最大长度是`50000`。

# 双指针解法
```c++
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
```
&emsp;&emsp;使用双指针可以很容易判断一个字符串是否是回文字符串：令一个指针从左到右遍历，一个指针从右到左遍历，这两个指针同时移动一个位置，每次都判断两个指针指向的字符是否相同，如果都相同，字符串才是具有左右对称性质的回文字符串。  
&emsp;&emsp;本题的关键是处理**删除一个字符**。在使用双指针遍历字符串时，如果出现两个指针指向的字符不相等的情况，就试着删除一个字符，再判断删除完之后的字符串是否是回文字符串。  
&emsp;&emsp;在判断是否为回文字符串时，不需要判断整个字符串，因为左指针左边和右指针右边的字符之前已经判断过具有对称性质，所以只需要判断**中间的子字符串**即可。  
&emsp;&emsp;在删除字符时，既可以删除左指针指向的字符，也可以删除右指针指向的字符。