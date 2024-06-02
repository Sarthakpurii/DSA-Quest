/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        // unordered_map<Node*,Node*> nMap;
        // Node* temp=head,*dcopy=new Node(-1);
        // Node *dhead=dcopy;
        // while(temp){
        //     dcopy->next=new Node(temp->val);
        //     dcopy=dcopy->next;
        //     nMap[temp]=dcopy;
        //     temp=temp->next;
        // }
        // dcopy->next=nullptr;
        // temp=head;
        // dcopy=dhead->next;
        // while(temp){
        //     dcopy->random=(temp->random)?nMap[temp->random]:nullptr;
        //     dcopy=dcopy->next;
        //     temp=temp->next;
        // }
        // return dhead->next;

        Node *temp=head;
        while(temp){
            Node* dummy=new Node(temp->val);
            dummy->next=temp->next;
            temp->next=dummy;
            temp=temp->next->next;
        }
        temp=head;
        Node *dcopy=temp->next;
        Node *dhead=dcopy;
        // while(temp){
        //     dcopy->random=(temp->random)?temp->random->next:nullptr;
        //     temp->next=dcopy->next;
        //     temp=temp->next;
        //     dcopy->next=(temp)?temp->next:nullptr;
        //     dcopy=dcopy->next;
        // }
        // return dhead;

        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }

        temp=head;
        while(temp){
            temp->next=dcopy->next;
            temp=temp->next;
            if(temp){
                dcopy->next=temp->next;
                dcopy=dcopy->next;
            }

        }
        return dhead;
    }
};
