/*

Write an algorithm to determine if the number represented by a linked list is a palindrome.

an empty string is a palindrome.

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


bool isPalindrome(ListNode* head)
{
    if (head == nullptr)
        return true;
    // Step 1: find the exact middle node
    ListNode* fast = head, * slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // Step 2: flip the 2nd half of the linked list
    ListNode* prev = nullptr, * cur = slow->next, * next = nullptr;
    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    slow->next = prev;

    // Step 3: determine if this is a palindrome: compare 1st half with the reversed 2nd half
    fast = head;
    slow = prev;
    while (slow != nullptr)
    {
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    ListNode* ptr0 = new ListNode(1);
    ListNode* ptr1 = new ListNode(3);
    ListNode* ptr2 = new ListNode(2);
    ListNode* ptr3 = new ListNode(7);
    ListNode* ptr4 = new ListNode(8);
    ListNode* ptr5 = new ListNode(9);

    ptr0->next = ptr1;
    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = ptr5;
    ptr5->next = nullptr;

    assert(isPalindrome(ptr0) == false);
    cout << "Pass all test cases\n";
}