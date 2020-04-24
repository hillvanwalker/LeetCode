# 88. 合并两个有序数组
给你两个有序整数数组 `nums1` 和 `nums2`，请你将 `nums2` 合并到 `nums1` 中，使 `nums1` 成为一个有序数组。  
说明:  
&emsp;&emsp;初始化 `nums1` 和 `nums2` 的元素数量分别为 `m` 和 `n` 。  
&emsp;&emsp;你可以假设 `nums1` 有足够的空间（空间大小大于或等于 `m + n`）来保存 `nums2` 中的元素。  
示例:  
&emsp;&emsp;输入:  `nums1 = [1,2,3,0,0,0],m = 3`，`nums2 = [2,5,6], n = 3`  
&emsp;&emsp;输出: `[1,2,2,3,5,6]`  

# 双指针解法
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail =  m + n - 1;
        int tail1 = m - 1;
        int tail2 = n - 1;
        while( tail!=tail1 ){
            if( tail1 >= 0 && nums1[tail1] > nums2[tail2] ) 
                nums1[tail--]=nums1[tail1--];
            else 
                nums1[tail--]=nums2[tail2--];
        }
    }
};
```
&emsp;&emsp;1. 最朴素的解法就是将两个数组合并之后再排序，但时间复杂度较差，这是由于这种方法没有利用两个数组本身已经有序这一点。  
&emsp;&emsp;一般而言，对于有序数组可以通过**双指针法**达到`O(n + m)`的时间复杂度。  
&emsp;&emsp;2. 最直接的算法实现是将指针 `tail1` 置为 `nums1` 的开头， `tail2` 为 `nums2` 的开头，在每一步将最小值放入输出数组中。由于 `nums1` 是用于输出的数组，需要将 `nums1` 中的前 `m` 个元素放在其他地方，也就需要 `O(m)` 的空间复杂度。
方法二已经取得了最优的时间复杂度 `O(n+m)`，但需要使用额外空间。这是由于在从头改变 `nums1` 的值时，需要把 `nums1` 中的元素存放在其他位置。

&emsp;&emsp;3. 如果从结尾开始改写 `nums1` 的值又会如何？这里没有信息，因此不需要额外空间。这里的指针 `tail` 用于追踪添加元素的位置。













