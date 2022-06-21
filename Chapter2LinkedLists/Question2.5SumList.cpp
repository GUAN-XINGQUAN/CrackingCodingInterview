/*

Two numbers are represented by two linked list in the reverse order. Write an algorithm to sum these two numbers and return the result in a linked list.

You are not allowed to convert the linked list to integer and sum them.

Example:
Input:
    3->1->9
    2->1->3

Output:
    913 + 312 = 1225

Follow up: what is the number is stored in the forward order?
Example:
Input:
    3->1->9
    2->1->3

Output:
    319 + 213 = 532
*/

#include<iostream>
#include<vector>
#include<cassert>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() { val = 0; next = nullptr; }
    ListNode(int value) { val = value; next = nullptr; }
    ListNode(int value, ListNode* ptr) { val = value; next = ptr; }
};

void printList(ListNode* head)
{
    ListNode* cur = head;
    while (cur != nullptr)
    {
        cout << cur->val << '\t';
        cur = cur->next;
    }
    cout << endl;
}

// Original questions:
ListNode* sumList(ListNode* num1, ListNode* num2)
{
    ListNode* cur1 = num1, * cur2 = num2;
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    int s = 0, carry = 0;
    while (cur1 != nullptr || cur2 != nullptr)
    {
        int n1 = cur1 == nullptr ? 0 : cur1->val;
        int n2 = cur2 == nullptr ? 0 : cur2->val;
        s = (n1 + n2 + carry) % 10;
        carry = (n1 + n2 + carry) / 10;
        cur->next = new ListNode(s);
        if (cur1 != nullptr)
            cur1 = cur1->next;
        if (cur2 != nullptr)
            cur2 = cur2->next;
        cur = cur->next;
    }
    if (carry > 0)
        cur->next = new ListNode(carry);
    return dummy->next;
}


int main()
{
    ListNode* ptr0 = new ListNode(9);
    ListNode* ptr1 = new ListNode(7);
    ListNode* ptr2 = new ListNode(8);
    ListNode* ptr3 = new ListNode(6);
    ListNode* ptr4 = new ListNode(8);
    ListNode* ptr5 = new ListNode(5);

    ptr0->next = ptr1;
    ptr1->next = ptr2;
    ptr2->next = nullptr;

    ptr3->next = ptr4;
    ptr4->next = ptr5;
    ptr5->next = nullptr;

    ListNode* head = sumList(ptr0, ptr3);
    printList(head);
    cout << "Pass all test cases\n";
}