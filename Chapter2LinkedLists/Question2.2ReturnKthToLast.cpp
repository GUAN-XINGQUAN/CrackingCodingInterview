/*

Write a program to return the Kth element to the end of singly linked list.

Example:
input: 1->3->4->5->7

k=1 return 7
k=2 return 5
k=3 return 4
k=4 return 3
k=5 return 1
k=6 return invalid (-1)
*/

struct ListNode {
    int val;
    ListNode* next;

    ListNode() { val = 0; next = nullptr; }
    ListNode(int value) { val = value; next = nullptr; }
    ListNode(int value, ListNode* ptr) { val = value; next = ptr; }
};


int returnKthToLast(ListNode* head, int k)
{
    if (k <= 0)
        return -1;
    if (head == nullptr)
        return -1;
    ListNode* fast = head, * slow = head;
    for (int i = 0; i < k; i++)
    {
        if (fast != nullptr)
            fast = fast->next;
        else
            return -1;
    }
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->val;
}


int main()
{
    ListNode* ptr0 = new ListNode(1);
    ListNode* ptr1 = new ListNode(2);
    ListNode* ptr2 = new ListNode(3);
    ListNode* ptr3 = new ListNode(4);
    ListNode* ptr4 = new ListNode(5);

    ptr0->next = ptr1;
    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = nullptr;

    assert(returnKthToLast(ptr0, 1) == 5);
    assert(returnKthToLast(ptr0, 2) == 4);
    assert(returnKthToLast(ptr0, 5) == 1);
    assert(returnKthToLast(ptr0, 6) == -1);
    assert(returnKthToLast(ptr0, 0) == -1);
    cout << "Pass all test cases\n";
}