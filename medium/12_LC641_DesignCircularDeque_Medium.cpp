
class MyCircularDeque {
    vector<int> v;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        v.resize(k);
        front = 0;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        front = (front - 1 + capacity) % capacity;
        v[front] = value;

        if (size == 0) rear = front;

        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        rear = (rear + 1) % capacity;
        v[rear] = value;

        if (size == 0) front = rear;

        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : v[front];
    }

    int getRear() {
        return isEmpty() ? -1 : v[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
