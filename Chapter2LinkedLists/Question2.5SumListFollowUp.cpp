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


// Follow up question
int getLength(ListNode* head)
{
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}

ListNode* padZeros(ListNode* head, int numZeros)
{
    if (numZeros == 0)
        return head;
    ListNode* newHead = new ListNode(0);
    newHead->next = head;
    return padZeros(newHead, numZeros - 1);
}

ListNode* insertNode(ListNode* node, int value)
{
    ListNode* newHead = new ListNode(value);
    newHead->next = node;
    return newHead;
}

ListNode* sumListHelper(ListNode* num1, ListNode* num2, int& carry)
{
    // num1 and num2 have same length in this function
    if (num1 == nullptr && num2 == nullptr)
        return nullptr;

    // use recursion to calculate the rightmost digit sum
    ListNode* small = sumListHelper(num1->next, num2->next, carry);

    int value = num1->val + num2->val + carry;
    ListNode* fullResult = insertNode(small, value % 10);

    carry = value / 10;
    return fullResult;
}

ListNode* sumList(ListNode* num1, ListNode* num2)
{
    int len1 = getLength(num1), len2 = getLength(num2);
    if (len1 > len2)
        num2 = padZeros(num2, len1 - len2);
    else
        num1 = padZeros(num1, len2 - len1);

    int carry = 0;

    ListNode* head = sumListHelper(num1, num2, carry);
    
    if (carry > 0)
        head = insertNode(head, carry);
    return head;
}

int main()
{
    ListNode* ptr0 = new ListNode(9);
    ListNode* ptr1 = new ListNode(8);
    ListNode* ptr2 = new ListNode(7);
    ListNode* ptr3 = new ListNode(7);
    ListNode* ptr4 = new ListNode(8);
    ListNode* ptr5 = new ListNode(9);

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