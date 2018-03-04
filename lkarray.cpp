#include <iostream>
#include <string>

using namespace std;

struct node {
   int data;
   int prev;
   int next;

   // Constructor: 
   node() {
      data = -1;
      prev = -1;
      next = -1;
   }
};

node A[20];    // Array of nodes used to simulate the linked list      
int slot = 1;   // Array index of the next free space (beginning from index 1 initially)
int head = -1;  // Array index of the starting element in the list (-1 implies no entries yet)
int tail = -1;  // Array index of the tail in the list
int elements = 0;   // Number of elements in the list

// Function prototypes:
void insert(int);
void insertAfter(int,int);
void deleteElement(int);
void Sort();
void print();
int findIndex(int);


int main() {
    
    insert(5);
    insert(4);
    insert(3);
    insert(2);

    insert(1);
    print();
   // deleteElement(1);
    Sort();
    print();

    return 0;
}


void insert(int value) {
    if (slot == -1) {
        cout << "\nNo free space available.\n\n";
    } else {
        elements++;
        A[slot].data = value;
        A[slot].next = 0;
        if (head == -1) {
            // If the list is empty prior to the insertion
            A[slot].prev = 0;
            head = slot;
            tail = slot;
        } else {
            A[tail].next = slot;
            A[slot].prev = tail; 
            tail = slot;    
        }
        cout << endl << "Element \'" << value << "\'"<< " successfully inserted\n\n";


        // Finding the index of the next free location:
        do {
            do {
                slot = (slot + 1) % 20;
            } while(slot == 0); 
            if (A[slot].next == -1) return;
        } while(slot != tail);
        slot = -1;
        cout << "\nNo more free space available. Please delete some elements before inserting new.\n\n";
    }   
}


void insertAfter(int value1,int value2) {
    if (slot == -1) {
        cout << "\nNo free space available.\n\n";
    } else {
        int predecessor = findIndex(value1);

        if (predecessor == -1) {
            cout << "\nElement " << value1 << " not found\n\n";
            return;
        }

        if (A[predecessor].next == 0) {
            // If value1 is the last element in the list
            insert(value2);
            return;
        }

        elements++;
        A[slot].data = value2;
        A[slot].prev = predecessor;
        A[slot].next = A[predecessor].next;
        A[A[predecessor].next].prev = slot;
        A[predecessor].next = slot;
        cout << endl << "Element \'" << value2 << "\'"<< " successfully inserted\n\n";

        // Finding the index of the next free location:
        int temp = slot;
        do {
            do {
                slot = (slot + 1) % 20;
            } while(slot == 0); 
            if (A[slot].next == -1) return;
        } while(slot != temp);
        slot = -1;
        cout << "\nNo more free space available. Please delete some elements before inserting new.\n\n";
    }   
}


void deleteElement(int value) {
    if (head == -1) {
        cout << "\nNo elements to delete.\n\n";
        return;
    }

    if (elements == 1) {
        // Deleting the only element in the list
        A[head].data = -1;
        A[head].prev = -1;
        A[head].next = -1;
        head = -1;
        elements--;
        return;
    }

    int index = findIndex(value); 

    if (index == -1) {
        cout << "\nElement not found.\n\n";
        return;
    }

    if (index == head) {
        // Deleting the first element in the list
        int successor = findIndex(A[A[index].next].data);
        A[successor].prev = 0;
        head = successor;       
        A[index].data = -1;
        A[index].prev = -1;
        A[index].next = -1; 
        cout << endl << "Element \'" << value << "\'"<< " successfully deleted\n\n";
        elements--;                 
        return;
    }

    if (index == slot) {    
        // Deleting the last element in the list
        int predecessor = findIndex(A[A[index].prev].data);
        A[predecessor].next = 0;        
        A[index].data = -1;
        A[index].prev = -1;
        A[index].next = -1; 
        cout << endl << "Element \'" << value << "\'"<< " successfully deleted\n\n";
        elements--;
        return; 
    }

    int successor = findIndex(A[A[index].next].data);
    int predecessor = findIndex(A[A[index].prev].data);
    A[predecessor].next = successor;
    A[successor].prev = predecessor;
    A[index].data = -1;
    A[index].prev = -1;
    A[index].next = -1;
    cout << endl << "Element \'" << value << "\'"<< " successfully deleted\n\n";
    elements--;                     
}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void Sort()
{
   int i, j;
   for (i = 0; i < elements-1; i++)      
 {
          
       for (j = 0; j < elements-i; j++) 
           {if (A[j].data > A[A[j].next].data)
              swap(&A[j].data, &A[A[j].next].data);}
          }

cout<<"Sorted";
      
}


void print() {
    cout << "\nThe current list is: ";
    int i = head;
    while (i != 0) {
        cout << A[i].data << " ";
        i = A[i].next;
    }
    cout << endl << endl;
}


int findIndex (int x) {
    // A helper function to return the index of the element x in A
    int i = head;
    while (i != 0) {
        if (A[i].data == x) {
            return i;
        }
        i = A[i].next;
    }
    return (-1);
}
