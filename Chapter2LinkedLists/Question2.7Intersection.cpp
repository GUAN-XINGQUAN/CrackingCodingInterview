/*

Write an algorithm to determine if two linked list have an intersection and return the intersection.

Intersection: two list share one common node (by reference not by value).

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

bool hasIntersection(ListNode* l1, ListNode* l2)
{
    ListNode* cur1 = l1, * cur2 = l1;
    if (l1 == nullptr || l2 == nullptr)
        return false;
    while (cur1->next != nullptr)
        cur1 = cur1->next;
    while (cur2->next != nullptr)
        cur2 = cur2->next;
    if (cur1 == cur2)
        return true;
    else
        return false;
}

ListNode* returnIntersection(ListNode* l1, ListNode* l2)
{
    if (hasIntersection(l1, l2) == false)
        return nullptr;
    ListNode* cur1 = l1, * cur2 = l2;
    while (cur1 != cur2)
    {
        if (cur1 == nullptr)
            cur1 = l2;
        if (cur2 == nullptr)
            cur2 = l1;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

int main()
{
    ListNode* ptr0 = new ListNode(1);
    ListNode* ptr1 = new ListNode(2);
    ListNode* ptr2 = new ListNode(3);
    ListNode* ptr3 = new ListNode(4);
    ListNode* ptr4 = new ListNode(5);
    ListNode* ptr5 = new ListNode(6);
    ptr0->next = ptr1;
    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = ptr5;
    ptr5->next = nullptr;


    ListNode* pptr0 = new ListNode(10);
    ListNode* pptr1 = new ListNode(30);
    ListNode* pptr2 = new ListNode(20);

    pptr0->next = pptr1;
    pptr1->next = pptr2;
    pptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = ptr5;
    ptr5->next = nullptr;

    ListNode* node = returnIntersection(ptr0, pptr0);
    cout << node->val << endl;
    cout << "Pass all test cases\n";
}