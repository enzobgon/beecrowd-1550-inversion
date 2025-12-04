#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VAL 10000 // Constraint from problem (0 < A < B < 10000)

// Structure to represent a state in the BFS
typedef struct {
    int value;
    int steps;
} State;

// Simple Queue implementation for BFS
typedef struct {
    State data[MAX_VAL * 2]; // Safety buffer size
    int front;
    int rear;
} Queue;

// Queue Operations
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int value, int steps) {
    q->data[q->rear].value = value;
    q->data[q->rear].steps = steps;
    q->rear++;
}

State dequeue(Queue *q) {
    return q->data[q->front++];
}

// Function to reverse the integer (The "Inversion" button)
// Example: 123 -> 321, 150 -> 51
int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

// Breadth-First Search (BFS) algorithm to find the shortest path
int bfs(int start, int target) {
    // Visited array to avoid cycles and redundant processing
    bool visited[MAX_VAL + 1];
    memset(visited, false, sizeof(visited));

    Queue q;
    initQueue(&q);

    // Start BFS
    enqueue(&q, start, 0);
    visited[start] = true;

    while (!isEmpty(&q)) {
        State current = dequeue(&q);

        if (current.value == target) {
            return current.steps;
        }

        // Operation 1: Add 1 button
        int next_add = current.value + 1;
        if (next_add <= MAX_VAL && !visited[next_add]) {
            visited[next_add] = true;
            enqueue(&q, next_add, current.steps + 1);
        }

        // Operation 2: Reverse button
        int next_rev = reverseNumber(current.value);
        if (next_rev <= MAX_VAL && !visited[next_rev]) {
            visited[next_rev] = true;
            enqueue(&q, next_rev, current.steps + 1);
        }
    }
    return -1; // Should not reach here given problem constraints
}

int main() {
    int testCases;
    
    // Reads number of test cases
    if (scanf("%d", &testCases) != 1) return 0;

    while (testCases--) {
        int start, target;
        scanf("%d %d", &start, &target);

        int result = bfs(start, target);
        printf("%d\n", result);
    }

    return 0;
}
