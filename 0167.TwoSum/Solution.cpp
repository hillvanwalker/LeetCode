#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    /*
    解法1：暴力枚举、双层遍历数据对。
    时间：O(n^2)，空间：O(1)
    */
    vector<int> twoSum1(vector<int>& numbers, int target) {
        assert(numbers.size() >= 2);
        // assert(isSorted(numbers));
        for(int i = 0 ; i < numbers.size() ; i ++)
            for(int j = i+1 ; j < numbers.size() ; j ++)
                if(numbers[i] + numbers[j] == target){
                    int res[2] = {i+1, j+1};
                    return vector<int>(res, res+2);
                }
        throw invalid_argument("the input has no solution");
    }
    /*
    解法2：二分查找，暴力解法没有利用数组有序的性质
          利用二分搜索法对索引当前i的，剩余数组再进行二分搜索
    时间：O(nlogn)，空间：O(1)
    */
    vector<int> twoSum2(vector<int>& numbers, int target) {
        assert(numbers.size() >= 2);
        // assert(isSorted(numbers));
        for(int i = 0 ; i < numbers.size() - 1 ; i ++){
            int j = binarySearch(numbers, i+1, numbers.size()-1, target - numbers[i]);
            if(j != -1){
                int res[2] = {i+1, j+1};
                return vector<int>(res, res+2);
            }
        }
        throw invalid_argument("the input has no solution");
    }
    /*
    解法3：对撞指针，首尾两个指针，根据计算结果分别对向搜索
    时间：O(n)，空间：O(1)
    */
    vector<int> twoSum3(vector<int>& numbers, int target) {
        assert(numbers.size() >= 2);
        // assert(isSorted(numbers));
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                int res[2] = {l+1, r+1};
                return vector<int>(res, res+2);
            }
            else if(numbers[l] + numbers[r] < target)
                l ++;
            else // numbers[l] + numbers[r] > target
                r --;
        }
        throw invalid_argument("the input has no solution");
    }

private:
    int binarySearch(const vector<int> &nums, int l, int r, int target){
        assert(l >= 0 && l < nums.size());
        assert(r >= 0 && r < nums.size());
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target)
                return mid;
            if(target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    bool isSorted(const vector<int>& numbers){
        for(int i = 1 ; i < numbers.size() ; i ++)
            if(numbers[i] < numbers[i-1])
                return false;
        return true;
    }
};

int main() {

    int nums[] = {2, 7, 11, 15};
    vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));
    int target = 9;

    vector<int> res = Solution().twoSum3(vec, target);
    for(int i = 0 ; i < res.size() ; i ++)
        cout << res[i] << " ";
    cout << endl;
    cin.get();
    return 0;
}