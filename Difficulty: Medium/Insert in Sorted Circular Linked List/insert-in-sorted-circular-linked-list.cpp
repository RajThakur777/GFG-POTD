/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        if(!head){
            Node* newNode=new Node(data);
            newNode->next=newNode;
            return newNode;
        }
        
        if(head->data > data){
            Node* last = head;
            while(last->next != head){
                last = last->next;
            }
            Node* newNode = new Node(data);
            last->next = newNode;
            newNode->next = head;
            head = newNode;
            
            return head;
        }
        
        Node* temp = head->next;
        Node* prev = head;
        
        while(temp->data < data && temp != head) {
            prev = temp;
            temp = temp->next;
        }
        
        Node* newNode = new Node(data);
        prev->next = newNode;
        newNode->next = temp;
        
        return head;
    }
};