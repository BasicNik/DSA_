
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL; 
    }
};

//INSERTION ALGO


void insert_head(node* &head , int value){

    node* n = new node(value);
    n->next = head;
    head = n;
}

void insert_tail(node* &head , int value){

    node* n = new node(value);

    if (head == NULL){

        head = n;
        return;
    }

    node* temp = head;
    
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    
}


void insertbetween(node *head, int index, int val)
{
    node *n = new node(val);
    int i = 0;
    node* temp = head;
    while (i != index-1)
    {
        temp = temp->next;
        i++;
    }
    n->next = temp->next;
    temp->next = n;
}


//DELETING ALGO

void delete_head(node* &head){

    node* todelete = head;
    head = head->next;

    delete todelete;

}


void deletion(node* &head, int val){     //int Val in this fn means the position from where you want to delete 
    node* temp = head;

    if (head == NULL)
    {
        return;
    }
    if (head->next==NULL)
    {
        delete_head(head);
        return;
    }
    while(temp->next->data !=val){

        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}


//PRINTING ALGO

void display(node* head){

    node* temp = head;
    while (temp !=NULL)
    {
        cout<<temp->data<<" -> " ;
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
}

//LINEAR SEARCH ALGO


bool liner_search(node* head , int key){
    node* temp = head;

    while (temp != NULL)
    {
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    
    }
    return false;  
}

int main(){

    node* head = NULL;
    insert_tail(head,1);
    insert_tail(head,2);
    insert_tail(head,3);
    insert_head(head,7);
    insert_head(head,9);

    insertbetween(head,3,69);
    
    display(head);

    delete_head(head);
    
    deletion(head,3);

    display(head);

    cout<<liner_search(head,1);
}