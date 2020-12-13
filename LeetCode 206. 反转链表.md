# 反转一个单链表。

示例:
* 输入: 1->2->3->4->5->NULL
* 输出: 5->4->3->2->1->NULL

```cpp

//递归
class Solution {
public:
    ListNode* reverse(ListNode* prev,ListNode* cur){
        if(cur==NULL)
            return prev;
        ListNode* temp=cur->next;
        cur->next=prev;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL,head);
    }
};

//双指针法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head;
        ListNode* prev=NULL;
        ListNode* tmp=cur;
        while(cur){
            tmp=cur->next;//保存cur的下一个节点
            cur->next=prev;//翻转操作
            // 更新pre 和 cur指针
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
};
