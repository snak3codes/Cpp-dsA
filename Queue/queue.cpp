#include <iostream>
#include <string>

using namespace std;

class Queue {
  private:
    int front;
    int rear;
    int arr[5]; // QueueSize

  public:
    Queue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        } else {
            return false;
        }
    }

    int queueSize() {
        return sizeof(arr) / sizeof(arr[0]);
    }

    bool isFull() {
        if (rear == queueSize() - 1) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        } else if (isEmpty()) {
            rear = front = 0;
            arr[rear] = val;
        } else {
            rear++;
            arr[rear] = val;
        }
        cout << val << " was added to the queue" << endl;
    }

    int dequeue() {
        int x;

        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return 0;
        } else if (front == rear) {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
        } else {
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        cout << x << " was removed from the queue" << endl;
        return x;
    }

    int count() {
        if (isEmpty())
            return 0;
        return (rear - front + 1);
    }

    void display() {
        cout << "All values in the Queue are - " << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// main function
int main() {
    cout << "-- Queue --" << endl;
    int option, value;

    Queue q1;

    do {
        cout << endl
             << "What operation do you want to perform? Select Option Number. Enter 0 to exit" << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;

        switch (option) {
        case 0:
            cout << "Bye!" << endl;
            break;
        case 1:
            cout << "Enqueue Operation\nEnter an item to Enqueue in the Queue" << endl;
            cin >> value;
            q1.enqueue(value);
            break;

        case 2:
            cout << "Dequeue Operation\nDequeued Value: " << q1.dequeue() << endl;
            break;

        case 3:
            if (q1.isEmpty()) {
                cout << "Queue is Empty" << endl;
            } else {
                cout << "Queue is not Empty" << endl;
            }
            break;

        case 4:
            if (q1.isFull()) {
                cout << "Queue is Full" << endl;
            } else {
                cout << "Queue is not Full" << endl;
            }
            break;

        case 5:
            cout << "Count Operation\nCount of items in Queue: " << q1.count() << endl;
            break;

        case 6:
            cout << "Display Operation" << endl;
            q1.display();
            break;

        case 7:
            system("clear");
            break;

        default:
            cout << "Enter a Valid Option Number from 0 to 9!" << endl;
            break;
        }

    } while (option != 0);

    return 0;
} // end of main