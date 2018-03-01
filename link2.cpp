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
    void insert_position(int pos, int value);
    void print();
    void delete_position(int pos);
    void search_value(int value);
    void sort();
    
};

LinkedList::LinkedList()
{head = nullptr;
 tail=nullptr;
        
}
void LinkedList::add(int val)
{
    Node * newNode=new Node;

      //Creates new node
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


    
}

void LinkedList::insert_position(int pos, int value)
{
    
  
    Node *pre=new Node;
    Node *cur=new Node;
    Node *temp=new Node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
      
    temp->data=value;
    pre->next=temp; 
    temp->next=cur;


    
}
void LinkedList::search_value(int value)
{
    Node * cur=head;
    int i=0;
    while (cur != nullptr)
    {   
        if(cur->data==value)
        {
            cout<<"Found at:"<<i<<endl;
            break;
        }
        i++;
        cur = cur->next;   
       
    }
    


}
void LinkedList::sort()
{
    Node *cur = head;
    Node *curNext = cur->next;
    Node *temp=new Node;
    while((cur->next->next)!= nullptr)
    {
        if(cur->data > curNext->data)
        {
            temp->data = cur->data;
            cur->data = curNext->data;
            curNext->data = temp->data;
        }
        cur = cur->next;
    }
    cout<<"Sorted"<<endl;
}


void LinkedList::print() 
{
    Node * cur;

    cur = head;

    while (cur->next != nullptr)
    {
        cout << cur->data << endl;
        cur = cur->next;
    }
}
void LinkedList::delete_position(int pos)
  {
    Node *cur=new Node;
    Node *pre=new Node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
    pre->next=cur->next;
  }

int main()
{
    LinkedList aList;
     aList.add(2);
     aList.add(3);
     aList.add(4);
     aList.add(0);
     aList.add(1);
     
     //aList.insert_position(5,5);
     //aList.insert_position(0,5);
     //aList.delete_position(0);
    //aList.search_value(5);


    aList.print();
    aList.sort();
    aList.print();
   
    
    return 0;
}

