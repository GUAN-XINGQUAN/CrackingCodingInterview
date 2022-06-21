/*

Write an algorithm to partition the linked list such that all node with value < x comes before all nodes with value >= x.

Example:

Input: 3->5->8->5->10->2->1; value=5
Output: 3->1->2->10->5->5->8

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

ListNode* partition(ListNode* head, int x)
{
    ListNode* smallDummy = new ListNode(-1);
    ListNode* bigDummy = new ListNode(-1);
    ListNode* cur = head, * smallCur = smallDummy, * bigCur = bigDummy;
    while (cur != nullptr)
    {
        if (cur->val < x)
        {
            smallCur->next = cur;
            smallCur = smallCur->next;
        }
        else
        {
            bigCur->next = cur;
            bigCur = bigCur->next;
        }
        cur = cur->next;
    }
    smallCur->next = bigDummy->next;
    bigCur->next = nullptr;
    return smallDummy->next;
}

int main()
{
    ListNode* ptr0 = new ListNode(4);
    ListNode* ptr1 = new ListNode(99);
    ListNode* ptr2 = new ListNode(1);
    ListNode* ptr3 = new ListNode(10);
    ListNode* ptr4 = new ListNode(5);

    ptr0->next = ptr1;
    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = nullptr;

    ListNode* newHead = partition(ptr0, 10);
    printList(newHead);

    cout << "Pass all test cases\n";
}