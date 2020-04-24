#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>
using namespace std;

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

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    Solution().merge(nums1, m, nums2, n);
    for(int i = 0; i < nums1.size(); i++)
        cout << nums1[i] ;
    cin.get();
    return 0;
}