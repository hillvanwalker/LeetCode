#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    /*
    解法1: 使用额外空间，一个辅助数组nonZeroElements存放非零元素
           然后按顺序覆盖原数组nums，最后补零
    时间、空间均为O(n)
    */
    void moveZeroes1(vector<int>& nums) {
        vector<int> nonZeroElements;
        // 将vec中所有非0元素放入nonZeroElements中
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                nonZeroElements.push_back(nums[i]);
            }
        }
        // 将nonZeroElements中的所有元素依次放入到nums开始的位置
        for(int i = 0; i < nonZeroElements.size(); i++){
            nums[i] = nonZeroElements[i];
        }
        // 将nums剩余的位置放置为0
        for(int i = nonZeroElements.size(); i < nums.size(); i++){
            nums[i] = 0;
        }
    }
    /*
    解法2：双指针：k记录非零元素，i遍历数组
    时间为O(n)，空间为O(1)
    */
    void moveZeroes2(vector<int> &nums){
        int k = 0;      // 遍历数组，保证[0,...i]中所有非零元素排列在[0,...k)中
        for( int i = 0; i < nums.size(); i++ ){
            if( nums[i] ){
                nums[k++] = nums[i];    // 先赋值到nums[k]后k+1
            }
        }
        // [k,->else]均为0
        for( int i = k; i < nums.size(); i++ ){
            nums[i] = 0;
        }
    }
    /*
    解法3：双指针交换，无需最后的为0赋值
    时间：O(n)，空间：O(1)
    */
    void moveZeroes3(vector<int> &nums){
        int k = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( nums[i] ){      
                if ( i != k)
                    swap(nums[k++], nums[i]);
                else        // i = k，特殊情况所有元素均非零，会与自身交换
                    k++;    // 无需交换
            }
        }
    }
};

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));
    Solution().moveZeroes3(vec);
    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;
    cin.get();
    return 0;
}