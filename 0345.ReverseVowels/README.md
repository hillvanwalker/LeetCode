# 345. 反转字符串中的元音字母
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。  
示例 1:  
&emsp;&emsp;输入: `"hello"`  
&emsp;&emsp;输出: `"holle"`  
示例 2:  
&emsp;&emsp;输入: `"leetcode"`  
&emsp;&emsp;输出: `"leotcede"`   
说明:  
&emsp;&emsp;元音字母不包含字母`"y"`

# 双指针解法
```c++
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
```

&emsp;&emsp;使用双指针，一个指针从头向尾遍历，一个指针从尾到头遍历，当两个指针都遍历到元音字符时，交换这两个元音字符。   
&emsp;&emsp;为了快速判断一个字符是不是元音字符，定义额外的`find()`函数。  
&emsp;&emsp;时间复杂度为 `O(N)`：只需要遍历所有元素一次  
&emsp;&emsp;空间复杂度 `O(1)`：只需要使用两个额外变量  