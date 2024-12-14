#include <iostream>

using namespace std;



class Node{
public:
    int* data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=new int(data);
         next=prev=NULL;
    }
    ~Node(){
        delete data;
    }
};
class LinkedList{
private:
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head=tail=NULL;
    }
    void add(int data){
            Node *newNode=new Node(data);
            if(head == NULL){
                head=tail=newNode;
                return ;
            }
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    void display(){
            Node *current=head;
            if(current == NULL){
                cout<<"Linked List Empty \n";
                return;
            }
            while(current != NULL ){
                cout<<*current->data<<"\t";
                current=current->next;
            }
        }

    void addBefore(int data,int beforeData){
        Node* returnedNode = getNode(beforeData);
        if(returnedNode==head){
            Node *newNode=new Node(data);
            newNode->next=returnedNode;
            returnedNode->prev=newNode;
            newNode->prev=NULL;
            head=newNode;

        }else if(returnedNode==tail){
            Node *newNode=new Node(data);
            newNode->prev=returnedNode->prev;
            newNode->next=returnedNode;
            returnedNode->prev->next=newNode;
            returnedNode->prev=newNode;

        }
        else if(getNode(beforeData)==NULL){
            cout<<"there is no "<<beforeData<<" in our list"<<endl;
        }
        else{
            Node *newNode=new Node(data);
            newNode->prev=returnedNode->prev;
            newNode->next=returnedNode;
            returnedNode->prev->next=newNode;
            returnedNode->prev=newNode;
        }
    }
    int GetCount(){
        int Count=0;
        Node *current=head;
            if(current == NULL){
                cout<<"empty list\n";
                return 0;
            }
            while(current != NULL ){
                Count++;
                current=current->next;
            }
            return Count;
    }
    int GetDataByIndex(int index){
         int Counter=0;
         Node *current=head;
            while(current != NULL ){
                if(Counter == index){
                    return *current->data;
                }
                current=current->next;
                Counter++;
            }
            return NULL;
    }

        void addAfter(Node* newNode,int afterData){
        Node* returnedNode = getNode(afterData);
        if(returnedNode==head){
            newNode->next=returnedNode->next;
            newNode->prev=returnedNode;
            returnedNode->next->prev=newNode;
            returnedNode->next= newNode;
        }else if(returnedNode==tail){
            returnedNode->next=newNode;
            newNode->prev=returnedNode;
            newNode->next=NULL;
        }
        else if(getNode(afterData)==NULL){
            cout<<"there is no "<<afterData<<" in our list"<<endl;
        }
        else{
            newNode->prev=returnedNode;
            newNode->next=returnedNode->next;
            returnedNode->next->prev=newNode;
            returnedNode->next=newNode;
        }
    }
    void Swap(Node* current){
        int temp=*(current->data);
        *(current->data)=*(current->next->data);
        *(current->next->data)=temp;
    }

    void bubbleSort(){
       if(head==NULL){
        cout<<"list is empty";
        return;
       }
       int sorted=0;
       Node* current;
       while(sorted==0)
       {
        sorted=1;
        current=head;
        for(;current->next!=NULL;current=current->next){
            if(*current->data > *current->next->data){
                    Swap(current);
                    sorted=0;
            }
        }
       }

    }


private:
    Node* getNode(int data){
        Node* current=head;
            while(current != NULL ){
                if(*current->data == data){
                    return current;
                }
                current=current->next;
            }
            return NULL;
    }
};
int main()
{
    LinkedList l;
    l.add(6);
    l.add(2);
    l.add(4);
    l.add(3);
    l.display();
    cout<<endl;
    l.bubbleSort();
    l.display();
    return 0;
}

