#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <string>
using namespace std;
const int N = 100010;
deque<int> q;
int a[N];
int head = 0, tail = 0;

void enqueue(int value, int n) {
    if (tail - head >= n) {
        printf("Queue is Full\n");
        return;
    }
    a[tail] = value;
    while (!q.empty() && a[q.back()] < value) {
        q.pop_back();
    }
    q.push_back(tail);
    tail++;
}

void dequeue() {
    if (head == tail) {
        printf("Queue is Empty\n");
        return;
    }
    if (q.front() == head) {
        q.pop_front();
    }
    printf("%d\n", a[head]);
    head++;
}

void get_max() {
    if (head == tail) {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d\n", a[q.front()]);
}

void quit() {
    for (int i = head; i < tail; i++) {
        printf("%d ", a[i]);
    }
    //printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    char op[10];
    while (scanf("%s", op) != EOF) {
        if (strcmp(op, "dequeue") == 0) {
            dequeue();
        }
        else if (strcmp(op, "enqueue") == 0) {
            int value;
            scanf("%d", &value);
            enqueue(value, n);
        }
        else if (strcmp(op, "max") == 0) {
            get_max();
        }
        else if (strcmp(op, "quit") == 0) {
            quit();
            break;
        }
    }
    return 0;
}
