#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution{
public:
    /*
    解法1：暴力求解。时间：O(n)，空间O(k)，k为元素种类
    */
    void sortColors1(vector<int> &nums){
        int count[3] = {0};     // 存放0，1，2三个元素的频率
        for( int i = 0; i < nums.size(); i++){
            assert( nums[i] >= 0 &&  nums[i]<= 2 );
            count[nums[i]] ++;
        }
        int index = 0;
        for( int i = 0; i < count[0]; i++ )
            nums[index++] = 0;
        for( int i = 0; i < count[1]; i++ )
            nums[index++] = 1;
        for( int i = 0; i < count[2]; i++ )
            nums[index++] = 2;
    }
    /*
    解法2：三路快排，时间：O(n)，空间：O(1)，只需遍历1遍数组
    */
   void sortColors2(vector<int> &nums){
        int zero = -1;              // [0,...,zero] 存放0，索引为-1是使初始存放空
        int two = nums.size();      // [two,...,n-1] 存放2
        for( int i = 0; i < two; ){
            if( nums[i]==1 )
                i++;                // 当前元素为1，直接++      
            else if( nums[i] == 2 ){
                two--;             // 当前元素为2，two索引前移并交换
                swap( nums[i], nums[two] );
            }
            else{
                assert( nums[i] == 0 );
                zero++;            // 当前元素为0，zero索引后移并交换
                swap( nums[zero], nums[i] );
                i++;
            }
       }
   }
};

int main() {

    int nums[] = {2, 2, 2, 1, 1, 0, 1, 2, 0, 2, 0};
    vector<int> vec = vector<int>(nums, nums + sizeof(nums)/sizeof(int));

    Solution().sortColors2(vec);
    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << " ";
    cout << endl;
    cin.get();
    return 0;
}

