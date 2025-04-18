#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
};


struct Queue* createQueue(int queuesize)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = queuesize;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
/*
int isFull() {
  if ((front == (rear + 1)) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}*/

int isFull(struct Queue *q) {
  if ((q->front == (q->rear + 1) % q->capacity)) return 1;
  return 0;
}

int isEmpty(struct Queue *q) {
  if (q->front == -1) return 1;
  return 0;
}

void enQueue(struct Queue *q ,int val) {
  if (isFull(q))
    printf("\n Queue is full!! \n");
  else {
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = val;
    printf("\n Inserted -> %d", val);
  }
}

int deQueue(struct Queue *q) {

   int val;
   if (isEmpty(q)) {
    printf("\n Queue is empty !! \n");
    return (-1);
  }
    else {
    val = q->array[q->front];
    if (q->front == q->rear) {
      q->front = -1;
      q->rear = -1;
    }

    else {
      q->front = (q->front + 1) % q->capacity;
    }
    printf("\n Deleted element -> %d \n", val);
    return (val);
  }
}

int main()
{
    struct Queue *q = createQueue(5);

    enQueue(q,11);
  enQueue(q,22);
  enQueue(q,33);
  enQueue(q,44);
  enQueue(q,55);
  enQueue(q,66);
  deQueue(q);
  deQueue(q);
  deQueue(q);
  deQueue(q);
  deQueue(q);
  deQueue(q);
  enQueue(q,77);
  enQueue(q,88);
  printf(" front = %d and rear = %d ", q->front , q->rear);

}



