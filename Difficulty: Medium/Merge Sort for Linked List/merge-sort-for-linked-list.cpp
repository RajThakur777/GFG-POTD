/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    // Merge two sorted linked lists
    Node* merge(Node* head1, Node* head2) {
        // Dummy node to simplify merging
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        // Traverse both lists and compare nodes
        while (head1 && head2) {
            int val1 = head1->data, val2 = head2->data;
            if (val1 > val2) {
                temp->next = head2;
                head2 = head2->next;
            } else {
                temp->next = head1;
                head1 = head1->next;
            }
            temp = temp->next;
        }
        
        // Attach the remaining nodes of the non-empty list
        if (head1) temp->next = head1;
        else if (head2) temp->next = head2;
        
        // Return the merged list (skip dummy)
        return dummy->next;
    }
  
    // Find the middle node and return it (using slow and fast pointers)
    Node* secondHead(Node* head) {
        Node* slow = head;
        Node* fast = head;
        // Move fast two steps and slow one step
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // Slow is the middle node
    }
  
    // Recursive merge sort function
    Node* merge_sort(Node* head) {
        // Base case: empty list or single node
        if (!head) return head;
        if (head->next == NULL) return head;
        
        Node* start = head;
        // Find the middle node
        Node* temp = secondHead(head);
        // Split the list into two halves
        Node* middle = temp->next;
        temp->next = NULL; // Break the link
        
        // Recursively sort both halves
        Node* head1 = merge_sort(start);
        Node* head2 = merge_sort(middle);
        
        // Merge the sorted halves
        return merge(head1, head2);
    }
  
    // Entry point for merge sort
    Node* mergeSort(Node* head) {
        return merge_sort(head);
    }
};