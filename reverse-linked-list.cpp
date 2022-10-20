struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head, bool reverse_recursively = false) {
        // End case of having to deal with an empty list
        if (head == nullptr) return head;

        ListNode* new_head;

        if (reverse_recursively) {
            bool head_found = false;
            this->reverseListRecursively(head, &head_found, &new_head);
        } else {
            new_head = this->reverseListIteratively(head);
        }

        return new_head;
    }

private:
    /* This recursive solution reaches the last element,
     * and then unfolds the stack to find "parent nodes" and swap subsequent nodes.
     * The new head of the linked list is located using external logic. */

    ListNode* reverseListRecursively(ListNode* head, bool* head_found, ListNode** new_head) {
        if (head->next == nullptr) {
           if (!*head_found) {
               *head_found = true;
               *new_head = head;
           }
           return head;
        }

        ListNode* new_parent = reverseListRecursively(head->next, head_found, new_head);

        new_parent->next = head;
        head->next = nullptr;

        return head;
    }

    /* This iterative solution uses the following logic:
     * 1) Separately maintain two lists: the current reversed list, and the remaining old one.
     * 2) Take the head of the remaining old list and make it the head of the reversed.
     * 3) Keep doing this process until the remaining old list is empty. */

    ListNode* reverseListIteratively(ListNode* head) {
        if (!head->next) return head;

        ListNode* old_list_node = head->next; // From old list
        ListNode* new_tail = head;
        ListNode* new_head;

        while (old_list_node->next) {
            ListNode* new_parent = old_list_node;
            old_list_node = old_list_node->next;

            new_parent->next = new_tail;
            new_tail = new_parent;
        }

        new_head = old_list_node;
        new_head->next = new_tail;

        // Make sure last node points to nullptr
        head->next = nullptr;

        return new_head;

    }

};
