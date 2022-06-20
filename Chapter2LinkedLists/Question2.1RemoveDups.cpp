/*

Write codes to remove duplicates from an unsorted linked list.

Example:
input: 1->3->2->4->3->3
ouput: 1->3->2->4

Assumption: keep 1st occurence and remove the 2nd or later occurence
*/

struct ListNode {
    int val;
    ListNode* next;

    ListNode() { val = 0; next = nullptr; }
    ListNode(int value) { val = value; next = nullptr; }
    ListNode(int value, ListNode* ptr) { val = value; next = ptr; }
};

void removeDups(ListNode* head)
{
    unordered_set<int> numSet;
    // edge case
    if (head == nullptr)
        return;
    ListNode* cur = head;
    while (cur != nullptr && cur->next != nullptr)
    {
        numSet.insert(cur->val);
        if (numSet.count(cur->next->val) != 0)
        {
            ListNode* temp = cur->next;
            cur->next = temp->next;
        }
        else
            cur = cur->next;
    }
    return;
}

int main()
{
    ListNode* ptr0 = new ListNode(2);
    ListNode* ptr1 = new ListNode(2);
    ListNode* ptr2 = new ListNode(2);
    ListNode* ptr3 = new ListNode(3);
    ListNode* ptr4 = new ListNode(4);

    ptr0->next = ptr1;
    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = nullptr;

    removeDups(ptr0);

    ListNode* cur = ptr0;
    while (cur != nullptr)
    {
        cout << cur->val << '\t';
        cur = cur->next;
    }
    cout << endl;

}