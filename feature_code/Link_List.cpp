#include "Link_List.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

//global function
ostream &operator<<(ostream &output, const Link_List &L)
{

    Int_Node *ptr = L.head;
    while(ptr!= NULL){
        output << ptr->value << " ";
        ptr = ptr->next;
    }

    return output;
}

istream &operator>>(istream &input, Link_List &L)
{
    Int_Node *n = new Int_Node;
    input >> n->value;

    if(L.size==0){
        L.head=n;
        L.tail=n;
        n->pre=NULL;
        n->next=NULL;
    }
    else{
        L.tail->next = n;
        n->pre = L.tail;
        n->next = NULL;
        L.tail = L.tail->next;
    }

    L.size++;
    return input;
}

//default constructor
Link_List::Link_List()
{
    size = 0;
    head=NULL;
    tail=NULL;
}

//copy constructor
Link_List::Link_List(const Link_List &LinkListToCopy)
:size(LinkListToCopy.size)
{
    if(size == 0){
        head=NULL;
        tail=NULL;
    }

    else{
        Int_Node *ptr = LinkListToCopy.head;
        Int_Node *n;

        for(int i=1; i<=size; i++){
            n = new Int_Node;
            n->value = ptr->value;
            if(i == 1){
                head = n;
                tail = n;
                n->pre = NULL;
                n->next = NULL;
            }
            else{
                tail->next = n;
                n->pre = tail;
                n->next = NULL;
                tail = tail->next;
            }
            ptr = ptr->next;
        }
    }
}

//destructor
Link_List::~Link_List()
{
    while(head != NULL){//clear Link List
        Int_Node *current = head;
        delete current;
        current = 0;
        head = head -> next;
    }
    tail = NULL;
    size = 0;
}

int Link_List::getSize() const
{
    return size;
}

//assignment operator
//const return avoids: (L1 = L2) = L3
const Link_List& Link_List::operator=(const Link_List &Right)
{
    if(&Right != this){                     //avoid self-assignment
        if(size != Right.size){
            while(head != NULL){            //clear Link List
                Int_Node *current = head;
                delete current;
                current = 0;
                head = head -> next;
            }

            size = Right.size;
            Int_Node *ptr = Right.head;
            Int_Node *n;

            for(int i=1;i<=size;i++){
                n = new Int_Node;
                n->value = ptr->value;
                if(i == 1){
                    head = n;
                    tail = n;
                    n->pre = NULL;
                    n->next = NULL;
                }
                else{
                    tail->next = n;
                    n->pre = tail;
                    n->next = NULL;
                    tail = tail->next;
                }
                ptr = ptr->next;
            }
        }
    }
    return *this;
}

//equality operator
bool Link_List::operator==(const Link_List &Right) const
{
    if(size != Right.size)
        return false;

    Int_Node *left_ptr = head;
    Int_Node *right_ptr = Right.head;
    for(int i=0; i<size; i++){
        if(left_ptr->value != right_ptr->value)
            return false;
        left_ptr = left_ptr->next;
        right_ptr = right_ptr->next;
    }
    return true;
}

// subscript operator for non-const objects
int &Link_List::operator[](int subscript)
{
    if(subscript < 0 || subscript >= size){
        cerr << "\nError: Subscript " << subscript << "out of range" << endl;
        exit(1);
    }

    Int_Node *ptr = head;
    for(int i=1; i<subscript; i++){
        ptr = ptr->next;
    }
    return ptr->value;
}

// subscript operator for const objects
int Link_List::operator[](int subscript) const
{
    if(subscript < 0 || subscript >= size){
        cerr << "\nError: Subscript " << subscript << "out of range" << endl;
        exit(1);
    }

    Int_Node *ptr = head;
    for(int i=1; i<subscript; i++){
        ptr = ptr->next;
    }
    return ptr->value;
}

// insert an integer at the back of link list
bool Link_List::insert_node(int number)
{
    Int_Node *n = new Int_Node;
    n->value = number;

    if(size == 0){
        head = n;
        tail = n;
        n->pre = NULL;
        n->next = NULL;
    }
    else{
        tail->next = n;
        n->pre = tail;
        tail = tail->next;
        n->next = NULL;
    }
    size++;

    return 1;
}

// insert an integer after the i_th position
bool Link_List::insert_node(int index, int number)
{
    if(index < 0 || index > size)  return false;


    Int_Node *ptr = head;
    Int_Node *n = new Int_Node;
    n->value = number;

    if(index != 0){
        for(int i=1;i<index;i++){
            ptr = ptr->next;
        }
    }


    if(index == size){
        n->next = NULL;
        n->pre = ptr;
        ptr->next = n;
        tail = tail->next;
    }
    else if(index == 0){
        n->next = ptr;
        n->pre = NULL;
        ptr->pre = n;
        head = head->pre;
    }
    else{
        n->next = ptr->next;
        ptr->next->pre = n;
        ptr->next = n;
        n->pre = ptr;
    }
    size++;
    return true;
}

// delete the last node
bool Link_List::delete_node()
{
    if(size == 0)   return false;

    size--;
    Int_Node *current = tail;
    Int_Node *previous = tail->pre;

    if(current == head){
        head = NULL;
        tail = NULL;
        delete current;
        current = NULL;     //
    }
    else{
        previous->next = NULL;
        tail = previous;
        delete current;
        current = NULL;

    }

    return true;
}

// delete the i_th node
bool Link_List::delete_node(int index)
{
    if(index < 0 || index >= size)  return false;


    Int_Node *ptr = head;
    for(int i=1;i<index;i++){
        ptr = ptr->next;
    }
    Int_Node *current = ptr;
    Int_Node *previous = ptr->pre;

    if(size == 1 && index == 0){        //
        tail = NULL;
        delete current;
        current = NULL;
    }

    else if(index == 0){                //
        head = current ->next;
        head -> pre = NULL;
        delete current;
        current = NULL;
    }
    else if(index == size && size != 1){//
        previous->next = NULL;
        tail = previous;
        delete current;
        current = NULL;
    }
    else{
        previous->next = current->next;
        current->next->pre = previous;
        delete current;
        current = NULL;
    }

    size--;
    return true;
}
