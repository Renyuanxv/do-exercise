# LeetCode 21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

链接：https://leetcode-cn.com/problems/merge-two-sorted-lists

```cpp
//迭代法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        ListNode* begin=head;
        if(l1==NULL&&l2==NULL)
            return head->next;
        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val>=l2->val){
                begin->next=l2;
                begin=begin->next;
                l2=l2->next;
            }else{
                begin->next=l1;
                begin=begin->next;
                l1=l1->next;
            }
        }
        begin->next=l1!=nullptr?l1:l2;
        return head->next;
    }
};


//递归法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr)
            return l1;

        if(l1->val<=l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
        
    }
};
```
