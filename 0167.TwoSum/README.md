 # 167. 两数之和 II - 输入有序数组

 给定一个已按照**升序排列**的有序数组，找到两个数使得它们相加之和等于目标数。  
 函数应该返回这两个下标值 `index1` 和 `index2`，其中 `index1` 必须小于 `index2`。

说明:   
&emsp;&emsp;返回的下标值`(index1,index2)`不是从零开始的。  
&emsp;&emsp;你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。  
示例:   
&emsp;&emsp;输入: `numbers = [2, 7, 11, 15], target = 9`  
&emsp;&emsp;输出: `[1,2]`   
解释:   
&emsp;&emsp;2 与 7 之和等于目标数 9 。因此 `index1 = 1, index2 = 2` 。


 # O(n)的双指针解法
 ```c++
vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size()-1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum < target) {
            i++;
        } else if (sum > target) {
            j--;
        } else {
            return vector<int>{i+1, j+1};
        }
    }
    return vector<int>{-1, -1};
}
 ```
&emsp;&emsp;为什么双指针往中间移动时，不会漏掉某些情况？解答这个问题，要从**缩减搜索空间**的角度思考这个解法。要寻找的是符合条件`A[i] + A[j] == target` 的下标，它们需要满足条件是两个下标均合法，即 0 <= i < j < n .   
&emsp;&emsp;如果用暴力解法求解，一次只检查一个单元格，时间复杂度一定是O(n^2)，要想得到O(n)的解法，就需要能够一次排除多个单元格。  

&emsp;&emsp;以 n=8 为例，首先检查 (0,7) ，计算`A[0] + A[7]`，如果不等于`target`，则要么大要么小。  
&emsp;&emsp;若`A[0] + A[7]` 小于 `target`。应该去找更大的两个数。由于 `A[7]` 已经是最大的，所以 `A[0] + A[6]`直到`A[0] + A[1]`，也都小于 `target`，可以一次排除。对应用双指针解法的代码，就是 `i++`，对应于搜索空间，就是削减了一行的搜索空间。  
&emsp;&emsp;接着检查 (1,7) ，计算 `A[1] + A[7]` 与 `target` 进行比较。若 `A[0] + A[7]` 大于 `target`。应该去找和更小的两个数。由于 `A[1]` 已经是当前搜索空间最小的数，可以排除 `A[1] + A[7]`直到`A[6] + A[7]`。对应用双指针解法的代码，就是 `j++`，对应于搜索空间，就是削减了一列的搜索空间。  
&emsp;&emsp;无论 `A[i] + A[j]` 的结果是大了还是小了，都可以排除掉一行或者一列的搜索空间。经过 n 步以后，就能排除所有的搜索空间，检查完所有的可能性。









