#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>
using namespace std;
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

int main() {
    int target = 5;
    bool result = Solution().judgeSquareSum(5);
    cout << result << endl;
    cin.get();
    return 0;
}