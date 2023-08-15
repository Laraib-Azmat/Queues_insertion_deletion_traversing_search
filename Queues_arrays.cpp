#include<iostream>
using namespace std;

const int MAX_SIZE = 3;



 	int front=-1;
    int rear=-1;
    int arr[MAX_SIZE];
   

    // Function to insert an element at the rear end of queue
    void enqueue(int value) {
        if (rear==MAX_SIZE - 1 ) {
            cout << "Queue is full. Cannot insert element." << endl;
            return;
        }
        
        if (front == -1 && rear == -1) {
            front = rear = 0;
        }
      
        else {
            rear++;
        }
        arr[rear] = value;
    }

    // Function to delete an element from the front end of queue
    void dequeue() {
        if (front == -1 && rear == -1) {
            cout << "Queue is empty. Cannot delete element." << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
    }

    // Function to search an element in the queue
    void search(int value) {
        bool found = false;
        for (int i = front; i <= rear; i++) {
            if (arr[i] == value) {
                cout << "Element " << value << " found at position " << i + 1 << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Element " << value << " not found in the queue." << endl;
        }
    }

    // Function to traverse the queue and print its elements
    void traverse() {
        if (front == -1 && rear == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


int main() {


    int choice, value;

    do {
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Search element" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> value;
               enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> value;
               search(value);
                break;
            case 4:
                traverse();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}