#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // if (l1->val == 0)
        //     return l2;
        // else if (l2->val == 0)
        //     return l1;
        // else
        // {

            //进位处理
            int flag = 0;
            int num = l1->val + l2->val;
            if (num > 9)
            {
                flag = 1;
                num -= 10;
            }

            //创建节点
            ListNode *res = new ListNode(num);
            ListNode *temp = res;
            l1 = l1->next;
            l2 = l2->next;

            //l1、l2均不为空时
            while (l1 && l2)
            {
                //进位判断与处理
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

                //创建节点
                temp->next = new ListNode(num);
                temp = temp->next;
                l1 = l1->next;
                l2 = l2->next;
            }

            //l1还没计算完
            while (l1)
            {
                //进位判断与处理
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
                
                //创建节点
                temp->next = new ListNode(num);
                temp = temp->next;
                l1 = l1->next;
            }

            //l2还没计算完
            while (l2)
            {
                //进位判断与处理
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

                //创建节点
                temp->next = new ListNode(num);
                temp = temp->next;
                l2 = l2->next;
            }

            //进位判断
            if (flag)
            {
                temp->next = new ListNode(1);
                flag = 0;
            }

            return res;
        // }
    }

    void show(ListNode *l)
    {
        while (l)
        {
            cout << l->val << "->";
            l = l->next;
        }
        cout << endl;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(6);

    Solution s;
    ListNode *res = s.addTwoNumbers(l1, l2);

    s.show(res);
}

// 用例：
//不同位数
// 1：0+11=11
//普通进位
// 2：123+17=140
//最高位进位
// 3：11+90=101