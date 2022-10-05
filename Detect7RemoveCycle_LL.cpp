// Detect and remove cycle in a Linked list 

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

bool DetectandRemoveCycle(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    slow = slow->next;
    fast = fast->next->next;

    while(fast!=NULL || fast->next!=NULL){
        if(slow==fast){
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow==fast){
        slow = head;

        if(slow==fast){
            while(fast->next!=slow){
                fast = fast->next;
            }
        }
        else{
            while(slow->next!=fast->next){
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
        return true;
    }
    return false;

}

int main(){
    
    return 0;
}