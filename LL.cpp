// Linked List
// We can store data in non contigous fashion with each node is connected with other

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

// First approach is we can create a LinkedList object

// class LinkedList
// {

//     node* head;
//     node* tail;

// public:
//     LinkedList()
//     {
//         head=NULL;
//         tail=NULL;
//     }
// };

void insertAtHead(node *&head, int data) // We will pass by reference since we want changes in head pointer to be reflected in main() function also.
{
    node *n = new node(data);
    n->next = head;
    head = n;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
}

int length(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len += 1;
    }
    return len;
}

void insertAtTail(node *&head, int data)
{
    // This is the case when there is only one node.
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    // If there are already nodes present.
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(data); // When we finally reach null node we will append new node at the end of the linked list.
    return;
}

void insertInMiddle(node *head, int data, int p)
{
    if (head == NULL || p == 0)
    {
        insertAtHead(head, data);
    }
    else if (p > length(head))
    {
        insertAtTail(head, data);
    }
    else
    {
        node *temp;
        temp = head;
        for (int i = 1; i < p; i++)
        {
            temp = temp->next;
        }
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(node *head)
{
    node *prev = NULL;
    node *temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL; // Making second last node as the last node.
}

void deleteAtMiddle(node *head, int p)
{
    node *temp = head;
    node *prev;
    for (int i = 1; i < p; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}

bool searchRecursive(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    // Rec Case
    if (head->data == key)
    {
        return true;
    }
    searchRecursive(head->next, key); // we search on remaining linked list.
}

bool searchIterative(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void buildList(node *&head)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertAtTail(head, data);
        cin >> data;
    }
}

istream &operator>>(istream &is, node *&head)
{
    buildList(head);
    return is;
}

ostream &operator<<(ostream &os, node *&head)
{
    print(head);
    return os;
}

void reverse(node *&head)
{
    node *C = head;
    node *P = NULL;
    node *N;

    while (C != NULL)
    {
        // Save value of current node
        N = C->next;
        // Make current node point to previous.
        C->next = P;

        // Update previous and current
        P = C;
        C = N;
    }
    head = P;
}

node *reverseRec(node *head)
{
    // Base Case
    if (head->next == NULL || head == NULL)
    { // Having one node or we dont have a linked list created yet.
        return head;
    }
    // Rec Case
    node *smallHead = reverseRec(head->next);
    node *C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;
}

node *midPoint(node *head)
{
    if (head == NULL || head->next == NULL) // Base Case with only one node or no nodes at all.
    {
        return head;
    }

    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *printKthFromLast(node *&head, int k)
{
    node *temp = head;
    int len = length(head);
    for (int i = 0; i < len - k; i++)
    {
        temp = temp->next;
    }
    return temp;
}

node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node *mergeSort(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Find Midpt
    node *mid = midPoint(head);
    // Recursively Sort
    node *a = head;
    node *b = mid->next;
    mid->next = NULL; // to break the linked list
    a = mergeSort(a);
    b = mergeSort(b);
    // Merge
    node *c;
    c = merge(a, b);
    return c;
}

bool Cycle(node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// Another Way of implementing the same.
//  node *midPoint(node*head){
//      if(head==NULL||head->next==NULL){
//          return head;
//      }
//      node*temp=head;

//     for(int i=0;i< length(head)/2;i++){
//         temp=temp->next;
//     }
//     return temp;

// }

int main()
{
    node *head = NULL;
    node *head2 = NULL;
    // cin>>head;
    // cout<<head<<endl;
    // head=mergeSort(head);
    // cout<<head;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    // insertInMiddle(head,6,2);
    // print(head);
    // cout<<endl;
    // deleteAtHead(head);
    // deleteAtTail(head);
    // deleteAtMiddle(head,2);
    // print(head);
    // cout<<endl;
    // if(searchRecursive(head,10)){
    //  cout<<"Element is present"<<endl;
    // }
    // else
    // {
    //  cout<<"Element is absent"<<endl;
    // }

    // cin>>head>>head2;
    // cout<<head<<endl<<head2;
    //  buildList(head);
    // //print(head);

    // reverse(head);
    // //head=reverseRec(head);
    // print(head);

    // cout<<endl;

    // node*m=midPoint(head);
    // cout<<m->data<<endl;
    // node*k=printKthFromLast(head,2);
    // cout<<k->data<<endl;

    insertAtHead(head2, 5);
    insertAtHead(head2, 4);
    insertAtHead(head2, 3);
    insertAtHead(head2, 10);
    insertAtHead(head2, 12);
    insertAtTail(head2, 7);
    // print(head2);
    // cout<<endl;
    node *head3 = merge(head, head2);
    print(head3);
    // node*head4=mergeSort(head3);
    // print(head4);

    return 0;
}

// List STL for implementing a graph

/*
#include<iostream>
#include<list>

using namespace std;

int main(){
    list<pair<int,int>> *l;

    //No of nodes
    int n;
    cin>>n;

    l=new list<pair<int,int>>[n];  //Here we are creating an array of lists

    int e;  //No of edges
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        //Creating a bidirectional graph
        l[x].push_back(make_pair(y,wt));
        l[y].push_back(make_pair(x,wt));
    }
  //Printing the graph
    for(int i=0;i<n;i++){
           //Print every linked list
        cout<<"Linked List "<<i;
           for(auto xp:l[i]){    //Every element of the linked list is a pair.So we are using an iterator
             cout<<'('<<xp.first<<','<<xp.second<<')';
           }
           cout<<endl;
    }
}


//Circular Linked List

#include<iostream>
using namespace std;


class node{

public:
int data;
node*next;

node(int d)
{
    this->data=d;
}

};

void push(node*&head,int data)
{
    node*n=new node(data);
    node*temp=head;
    n->next=head;
    if(head!=NULL)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=n;
    }else //Case when head pointer is initially NULL,ie we are adding first node
    {
        n->next=n;
    }

    head=n;

}

void print(node*&head)
{
    node*temp=head;
    while(temp->next!=head){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<temp->data; //For printing the last node in circular Linked List

}

node* getNode(node*&head,int data)
{
    node*temp=head;
    while(temp->next!=head)
    {
        if(temp->data==data)
        {
            return temp;
        }
        temp=temp->next;
    }
    if(temp->data==data){
        return temp;
    }
    else
    {
        return NULL;
    }
}

void deleteNode(node*head,int data)
{
    node*d=getNode(head,data);
    if(d==NULL)
    {
        cout<<"Node is not present in Linked list"<<endl;
    }
    if(d==head)
    {
        head=d->next;
    }
    node*temp=head;
    while(temp->next!=d)
    {
        temp=temp->next;
    }
    temp->next=d->next;
    delete d;
}

int main()
{
   node*head=NULL;
   push(head,5);
   push(head,4);
   push(head,3);
   push(head,2);
   push(head,1);
   deleteNode(head,5);
   print(head);
   return 0;
}

*/
