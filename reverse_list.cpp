// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//Reverse a singly linked list
//
#include <iostream>
#include <cassert>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode *pre = NULL;
            ListNode *cur = head;
            while(cur != NULL) {
                ListNode *tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
            return pre;
        }
};

int main(int argc, char **argv) {
    Solution sol;
    assert(sol.reverseList(NULL) == NULL);
}
