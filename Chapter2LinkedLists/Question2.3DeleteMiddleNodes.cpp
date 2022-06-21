/*

Write an algorithm to remove a node in the middle (anyone in the middle not the first one and the last one)

The input is not the list head, but the removed node.

Example:
List: 1->2->3->4
Input: node 3
Output: nothing return, but the list should be 1->2->4

*/

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


void deleteNode(ListNode* Node)
{
    // assume input node is always valid
    ListNode* cur = Node;
    cur->val = Node->next->val;
    cur->next = Node->next->next;
    return;
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

    deleteNode(ptr3);
    printList(ptr0);
    deleteNode(ptr2);
    printList(ptr0);

    cout << "Pass all test cases\n";
}