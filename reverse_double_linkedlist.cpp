/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    
};

void push(node** h_ref,int data ){
    node * new_node = new node();
    if(*h_ref == NULL){
        *h_ref = new_node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        return;
    }
    new_node->data = data;
    new_node->next = *h_ref;
    new_node->prev= NULL;
    (*h_ref)->prev = new_node;
    *h_ref = new_node;
}
void print(node* head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
        
    }
}
bool isPallindrom(node* head){
    node* temp = head;
    int len=1;
    while(temp->next!=NULL){
        temp=temp->next;
        len++;
    }
    int flag=1;
    for(int i=0;i<len/2;i++){
        if(temp->data!=head->data){
            flag=0;
            break;
        }
        temp=temp->prev;
        head=head->next;
    }
    if(flag==1){
        return true;
    }
    else
       return false;
    
}
node* add(node* head1,node* head2){
    node* head3=NULL;
    int carry = 0;
    while(head1 || head2){
        int sum=0;
        sum = head1->data+head2->data+carry;
        carry = sum/10;
        sum=sum%10;
        push(&head3,sum);
        head1=head1->next;
        head2=head2->next;
    }
    return head3;
}
void reverse(node **head_ref)  
{  
    node *temp = NULL;  
    node *current = *head_ref;  
      
    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  
      
    if(temp != NULL )  
        *head_ref = temp->prev;  
}  
int main()
{
    node* head= NULL;
    push(&head,10);
    push(&head,2);
    push(&head,8);
    push(&head,5);
    push(&head,6);
    print(head);
    cout<<endl;
    reverse(&head);
    print(head);
    

    return 0;
}
