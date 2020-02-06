/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int flag = 0;
        int num = l1->val + l2->val;
        if (num > 9)
        {
            flag = 1;
            num -= 10;
        }
        ListNode *res = new ListNode(num);
        ListNode *temp = res;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 && l2)
        {
            num = l1->val + l2->val;
            if (flag)
            {
                num++;
                flag = 0;
            }
            if (num > 9)
            {
                flag = 1;
                num -= 10;
            }
            temp->next = new ListNode(num);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            num = l1->val;
            if (flag)
            {
                num++;
                flag = 0;
            }
            if (num > 9)
            {
                flag = 1;
                num -= 10;
            }
            temp->next = new ListNode(num);
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2)
        {
            num = l2->val;
            if (flag)
            {
                num++;
                flag = 0;
            }
            if (num > 9)
            {
                flag = 1;
                num -= 10;
            }
            temp->next = new ListNode(num);
            temp = temp->next;
            l2 = l2->next;
        }
        if (flag)
        {
            temp->next = new ListNode(1);
            flag = 0;
        }
        return res;
    }
};
// @lc code=end

