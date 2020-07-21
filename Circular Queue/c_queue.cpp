#include <iostream>
#include <string>

using namespace std;

class CircularQueue {
  private:
    int front;
    int rear;
    int arr[5]; // QueueSize
    int itemCount;

  public:
    CircularQueue() {
        front = -1;
        rear = -1;
        itemCount = 0;
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
        if ((rear + 1) % queueSize() == front) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "CircularQueue is Full" << endl;
            return;
        } else if (isEmpty()) {
            rear = front = 0;
        } else {
            rear = (rear + 1) % queueSize();
        }
        arr[rear] = val;
        itemCount++;
        cout << val << " was added to the queue" << endl;
    }

    int dequeue() {
        int x;

        if (isEmpty()) {
            cout << "CircularQueue is Empty" << endl;
            return 0;
        } else if (front == rear) {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
        } else {
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % queueSize();
        }
        itemCount--;
        cout << x << " was removed from the queue" << endl;
        return x;
    }

    int count() {
        return itemCount;
    }

    void display() {
        cout << "All values in the CircularQueue are - " << endl;
        for (int i = 0; i < queueSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// main function
int main() {
    cout << "-- CircularQueue --" << endl;
    int option, value;

    CircularQueue q1;

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
            cout << "Enqueue Operation\nEnter an item to Enqueue in the CircularQueue" << endl;
            cin >> value;
            q1.enqueue(value);
            break;

        case 2:
            cout << "Dequeue Operation\nDequeued Value: " << q1.dequeue() << endl;
            break;

        case 3:
            if (q1.isEmpty()) {
                cout << "CircularQueue is Empty" << endl;
            } else {
                cout << "CircularQueue is not Empty" << endl;
            }
            break;

        case 4:
            if (q1.isFull()) {
                cout << "CircularQueue is Full" << endl;
            } else {
                cout << "CircularQueue is not Full" << endl;
            }
            break;

        case 5:
            cout << "Count Operation\nCount of items in CircularQueue: " << q1.count() << endl;
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