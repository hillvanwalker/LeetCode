#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    解法1：暴力解法，遍历所有连续子数组
    时间：O(n^3)，空间：O(1)
    */
    int minSubArrayLen1(int s, vector<int>& nums) {
        assert(s > 0);
        int res = nums.size() + 1;
        for(int l = 0 ; l < nums.size() ; l ++)
            for(int r = l ; r < nums.size() ; r ++){
                int sum = 0;
                for(int i = l ; i <= r ; i ++)
                    sum += nums[i];
                if(sum >= s)
                    res = min(res, r - l + 1);
            }
        if(res == nums.size() + 1)
            return 0;
        return res;
    }
    /*
    解法2：优化暴力解法
    时间：O(n^2)，空间复杂度：O(n)
    */
    int minSubArrayLen2(int s, vector<int>& nums) {
        assert(s > 0);
        // sums[i]存放nums[0...i-1]的和
        vector<int> sums(nums.size() + 1, 0);
        for(int i = 1 ; i <= nums.size() ; i ++)
            sums[i] = sums[i-1] + nums[i-1];
        int res = nums.size() + 1;
        for(int l = 0 ; l < nums.size() ; l ++)
            for(int r = l ; r < nums.size() ; r ++){
                // 使用sums[r+1] - sums[l] 快速获得nums[l...r]的和
                if(sums[r+1] - sums[l] >= s)
                    res = min(res, r - l + 1);
            }
        if(res == nums.size() + 1)
            return 0;
        return res;
    }
    /*
    解法3：滑动窗口的思路
    时间：O(n)，空间：O(1)
    */
    int minSubArrayLen3(int s, vector<int>& nums) {
        assert(s > 0);
        int l = 0 , r = -1;         // nums[l...r]为我们的滑动窗口，初始化不包含任何元素
        int sum = 0;                // 初始化sum为0
        int res = nums.size() + 1;  // 默认当前为数组长度+1
        while(l < nums.size()){     // 窗口的左边界在数组范围内,则循环继续
            if(r + 1 < nums.size() && sum < s)
                sum += nums[++r];
            else // r已经到头 或者 sum >= s
                sum -= nums[l++];
            if(sum >= s)
                res = min(res, r - l + 1);
        }
        if(res == nums.size() + 1)
            return 0;
        return res;
    }
    /*
    解法4：二分搜索，对于每一个l, 可以使用二分搜索法搜索r
    时间：O(nlogn)，空间：O(n)
    */
    int minSubArrayLen4(int s, vector<int>& nums) {
        assert(s > 0);
        // sums[i]存放nums[0...i-1]的和
        vector<int> sums(nums.size() + 1, 0);
        for(int i = 1 ; i <= nums.size() ; i ++)
            sums[i] = sums[i-1] + nums[i-1];
        int res = nums.size() + 1;
        for(int l = 0 ; l < (int)nums.size(); l ++){
            auto r_bound = lower_bound(sums.begin(), sums.end(), sums[l] + s);
            if(r_bound != sums.end()){
                int r = r_bound - sums.begin();
                res = min(res, r - l);
            }
        }
        if(res == nums.size() + 1)
            return 0;
        return res;
    }



};

int main() {
    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int s = 7;
    cout << Solution().minSubArrayLen4(s, vec) << endl;
    cin.get();
    return 0;
}