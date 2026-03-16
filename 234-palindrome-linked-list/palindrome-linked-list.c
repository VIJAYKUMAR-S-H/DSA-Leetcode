bool isPalindrome(struct ListNode* head) {

    if(head == NULL || head->next == NULL)
        return true;

    // find middle (slow & fast pointer)
    struct ListNode *slow = head, *fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    struct ListNode *prev = NULL, *curr = slow->next, *next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // compare both halves
    struct ListNode *p1 = head;
    struct ListNode *p2 = prev;

    while(p2 != NULL){
        if(p1->val != p2->val)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}