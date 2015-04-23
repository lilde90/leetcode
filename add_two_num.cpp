// Copyright 2015 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//
/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            int carry = 0;
            ListNode *head = new ListNode(0);
            ListNode *sumList = head;
            if (l1 == NULL && l2 == NULL) return NULL;
            if (l1 != NULL && l2 == NULL) return l1;
            if (l1 == NULL && l2 != NULL) return l2;
            while (l1 != NULL && l2 != NULL) {
                int sum = l1->val + l2->val + carry;
                if (sum >= 10) {
                    sum = sum - 10;
                    carry = 1;
                }
                else {
                    carry = 0;
                }
                sumList->val = sum;
                ListNode *node = new ListNode(0);
                sumList->next = node;
                sumList = sumList->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            if(l1 != NULL) {
                while(l1 != NULL) {
                    int sum = l1->val  + carry;
                    if (sum >= 10) {
                        sum = sum - 10;
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    sumList->val = sum;
                    ListNode *node = new ListNode(0);
                    sumList->next = node;
                    sumList = sumList->next;
                    l1 = l1->next;
                }
            }

            if(l2 != NULL) {
                while(l2 != NULL) {
                    int sum = l2->val  + carry;
                    if (sum >= 10) {
                        sum = sum - 10;
                        carry = 1;
                    }
                    else {
                        carry = 0;
                    }
                    sumList->val = sum;
                    ListNode *node = new ListNode(0);
                    sumList->next = node;
                    sumList = sumList->next;
                    l2 = l2->next;
                }
            }

            ListNode *phead = head;
            while (phead->next != sumList) phead = phead->next;
            if (carry == 1) sumList->val = 1;
            else phead -> next = NULL;
            return head;
        }

};
