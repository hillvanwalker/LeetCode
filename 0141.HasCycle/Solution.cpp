#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* faster{ head };
        ListNode* slower{ head };
        if (head == NULL)
            return false;
        while (faster != NULL && faster->next != NULL){
            faster = faster->next->next;
            slower = slower->next;
            if (faster == slower)
                return true;
        }
        return false;
    }
};
// head = [3,2,0,-4], pos = 1
int main() {

    cin.get();
    return 0;
}
