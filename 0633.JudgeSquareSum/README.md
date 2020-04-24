# 633. 平方数之和
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。  
示例1:  
&emsp;&emsp;输入: `5`  
&emsp;&emsp;输出: `True`  
解释:   
&emsp;&emsp;`1 * 1 + 2 * 2 = 5`  
示例2:  
&emsp;&emsp;输入: `3`  
&emsp;&emsp;输出: `False`

# 双指针解法

```c++
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (long)sqrt(c);
        while(left <= right){
            long sum = left * left + right * right;
            if(sum == c)
                return true;
            else if(sum > c)
                right--;
            else
                left++;
        }
        return false;
    }
};
```

&emsp;&emsp;可以看成是在元素为 `0~target` 的有序数组中查找两个数，使得这两个数的平方和为 `target`，如果能找到，则返回 `true`，可以使用双指针得到两个数，使其平方和为 `target`。  
&emsp;&emsp;本题的关键是**右指针的初始化**，实现剪枝，从而降低时间复杂度。设右指针为 `x`，左指针固定为 `0`，为了使平方和尽可能接近 `target`，可以将 `x` 取为 `sqrt(target)`。  
&emsp;&emsp;最多只需要遍历一次 `0~sqrt(target)`，所以时间复杂度为 `O(sqrt(target))`。只使用了两个额外的变量，因此空间复杂度为 `O(1)`。