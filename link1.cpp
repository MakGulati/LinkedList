#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node * next;
        Node * prev;
    };
    Node * head, * tail;
public:
    LinkedList();
    void add(int val);
    void print() const;
    
};

LinkedList::LinkedList()
{head = nullptr;
 tail=nullptr;
        
}


void LinkedList::add(int val)
{
    Node * newNode;

    newNode = new Node;  //Creates new node
    newNode->data = val; //Stores val
    newNode->next = nullptr;

    

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode; //Insert new node at the end of the list
        tail = newNode;
    }


    //return head;
}


void LinkedList::print() const
{
    Node * current;

    current = head;

    while (current != nullptr)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

int main()
{
    LinkedList aList;

    aList.add(3);
    aList.add(10);
    aList.add(1);
    aList.add(7);
    aList.add(9);
    aList.add(12);
    aList.print();
    
    return 0;
}

