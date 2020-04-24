# 141. 环形链表
给定一个链表，判断链表中是否有环。为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 `0` 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。  
示例 1：  
&emsp;&emsp;输入：`head = [3,2,0,-4], pos = 1`  
&emsp;&emsp;输出：`true`  
&emsp;&emsp;解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：  
&emsp;&emsp;输入：`head = [1,2], pos = 0`  
&emsp;&emsp;输出：`true`  
&emsp;&emsp;解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：  
&emsp;&emsp;输入：`head = [1], pos = -1`  
&emsp;&emsp;输出：`false`  
&emsp;&emsp;解释：链表中没有环。

# 双指针解法
```c++
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
```
一个指针每次移动一个节点，一个指针每次移动两个节点，如果存在环，那么这两个指针一定会相遇。