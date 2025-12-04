#include <iostream>
using namespace std;

#define MAX 10

struct Queue {
    char data[MAX];
    int front;
    int rear;
    int count;
};

void init(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool isFull(Queue q) {
    return q.count == MAX;
}

bool isEmpty(Queue q) {
    return q.count == 0;
}

void insert(Queue &q, char value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak bisa insert.\n";
        return;
    }
    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = value;
    q.count++;
}

char remove(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong! Tidak bisa remove.\n";
        return '\0';
    }
    char value = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    q.count--;
    return value;
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Isi Queue: ";
    int idx = q.front;

    for (int i = 0; i < q.count; i++) {
        cout << q.data[idx] << " ";
        idx = (idx + 1) % MAX;
    }

    cout << endl;
}

int main() {
    Queue q;
    init(q);

    insert(q, 'H');
    insert(q, 'A');
    insert(q, 'K');
    insert(q, 'I');
    insert(q, 'M');

    cout << "Setelah insert H, A, K, I, M:\n";
    display(q);

    cout << "\nRemove 1: " << remove(q) << endl;
    cout << "Remove 2: " << remove(q) << endl;

    cout << "\nSetelah remove 2 elemen:\n";
    display(q);

return 0;
}