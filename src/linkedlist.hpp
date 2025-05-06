#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head);

#endif
