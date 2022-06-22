/*
Given a linked list. A loop might exist. Write an algorithm to detect such a loop and return the head of the loop.

If no loop exists, return nullptr.
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

bool hasLoop(ListNode* head)
{
    ListNode* fast = head, *slow = head;
    while (fast != nullptr & fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

ListNode* findLoopHead(ListNode* head)
{
    if (hasLoop(head) == false)
        return nullptr;
    ListNode* fast = head, *slow=head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    slow = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
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
    ptr5->next = ptr2;


    ListNode* node = findLoopHead(ptr0);
    cout << node->val << endl;
    cout << "Pass all test cases\n";
}
