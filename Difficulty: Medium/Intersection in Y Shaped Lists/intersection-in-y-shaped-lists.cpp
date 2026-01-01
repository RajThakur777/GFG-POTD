/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
   
    int len(Node* node) {
        Node* temp = node;
        int cnt = 0;
        
        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
  
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int la = len(head1);
        int lb = len(head2);
        
        if(la == lb) {
            Node* l1 = head1;
            Node* l2 = head2;
            
            while(l1 != nullptr && l2 != nullptr) {
                l1 = l1->next;
                l2 = l2->next;
                
                if(l1 == l2) {
                    return l1;
                }
            }
        }
        else if(lb > la) {
            int diff = lb - la;
            Node* l1 = head1;
            Node* l2 = head2;
            
            while(diff--) {
                l2 = l2->next;
            }
            
            while(l1 != nullptr && l2 != nullptr) {
                l1 = l1->next;
                l2 = l2->next;
                
                if(l1 == l2) {
                    return l1;
                }
            }
        }
        else {
            int diff = la - lb;
            Node* l1 = head1;
            Node* l2 = head2;
            
            while(diff--) {
                l1 = l1->next;
            }
            
            while(l1 != nullptr && l2 != nullptr) {
                l1 = l1->next;
                l2 = l2->next;
                
                if(l1 == l2) {
                    return l1;
                }
            }
        }
    }
};