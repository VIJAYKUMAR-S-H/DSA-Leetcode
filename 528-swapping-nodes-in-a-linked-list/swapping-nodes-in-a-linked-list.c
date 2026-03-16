struct ListNode* swapNodes(struct ListNode* head, int k) {
    
    int n = 0;
    struct ListNode* temp = head;

    // find length
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    int pos2 = n - k + 1;

    struct ListNode* node1 = head;
    struct ListNode* node2 = head;

    // reach kth node
    for(int i = 1; i < k; i++)
        node1 = node1->next;

    // reach (n-k+1) node
    for(int i = 1; i < pos2; i++)
        node2 = node2->next;

    // swap values
    int tempVal = node1->val;
    node1->val = node2->val;
    node2->val = tempVal;

    return head;
}