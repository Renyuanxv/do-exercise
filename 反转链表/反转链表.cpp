
//µü´ú·¨£º

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* curnext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = curnext;
        }
        return prev;
    }
};

//µÝ¹é·¨£º
class Solution {
public:
    ListNode* newlist(ListNode* prev, ListNode* cur) {
        if (cur == nullptr)
            return prev;
        ListNode* next = cur->next;
        cur->next = prev;
        return newlist(cur, next);
    }
    ListNode* reverseList(ListNode* head) {
        return newlist(nullptr, head);
    }
};
