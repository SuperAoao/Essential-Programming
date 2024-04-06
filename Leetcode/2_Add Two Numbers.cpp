#include <iostream>


 //Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

void testA(Solution& s)
{
    ListNode a0(2);
    ListNode a1(4);
    ListNode a2(3);
    a0.next = &a1;
    a1.next = &a2;

    ListNode b0(5);
    ListNode b1(6);
    ListNode b2(4);
    b0.next = &b1;
    b1.next = &b2;

    ListNode* res = s.addTwoNumbers(&a0, &b0);
    if (res->val == 7)
    {
        /* code */
    }
    else
    {
        std::cout << "failed at 1st elem" << std::endl;
    }
    
    res = res->next;
    if (res && res->val == 0)
    {
        /* code */
    }
    else
    {
        std::cout << "failed at 2nd elem" << std::endl;
    }
     res = res->next;
    if (res && res->val == 8)
    {
        std::cout << "passed testA." << std::endl;
    }
    else
    {
        std::cout << "failed at 3rd elem" << std::endl;
    }

};

int main()
{
    Solution s;
    testA(s);
    return 0;
}
