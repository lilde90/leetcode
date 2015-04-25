// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5

/**
 *  Definition for singly-linked list.
 *  struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *  };
 */
class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {
           while (head != NULL && head->val == val) {
               ListNode *node = head;
               head = head->next;
               delete node;
           }

           if (head == NULL) {
               return NULL;
           }

           ListNode *pre = head;
           ListNode *cur = head->next;
           while (cur != NULL) {
               if (cur->val == val) {
                   ListNode *node = cur;
                   pre->next = cur->next;
                   cur = cur->next;
                   delete node;
               } else {
                   pre = cur;
                   cur = cur->next;
               }
           }
           return head;
        }
};

