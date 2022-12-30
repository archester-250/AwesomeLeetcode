/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = NULL;
        ListNode* tail = l;
        bool c = false;
        while(l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val;
            if(c) sum++;
            if(sum >= 10)
            {
                c = true;
                sum -= 10;
            }
            else c = false;
            if(l == NULL)
            {
                l = new ListNode(sum);
                tail = l;
            }
            else
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            l1 = l1->next; l2 = l2->next;
        }
        while(l1 != NULL)
        {
            if(c)
            {
                l1->val++;
            }
            if(l1->val >= 10)
            {
                c = true;
                l1->val -= 10;
            }
            else c = false;
            tail->next = new ListNode(l1->val);
            tail = tail->next; l1 = l1->next;
        }
        while(l2 != NULL)
        {
            if(c)
            {
                l2->val++;
            }
            if(l2->val >= 10)
            {
                c = true;
                l2->val -= 10;
            }
            else c = false;
            tail->next = new ListNode(l2->val);
            tail = tail->next; l2 = l2->next;
        }
        if(c)
        {
            tail->next = new ListNode(1);
        }
        return l;
    }
};
// @lc code=end

