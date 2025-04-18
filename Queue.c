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

int isEmpty(struct Queue *queue)
{
    if(queue->front == queue->rear == -1)
        return 1;
    else
      return 0 ;

}
int isFull(struct Queue *queue){

    if(queue->rear == queue->capacity-1)
        return 1 ;
    else
        return 0;

}

void Enqueue(struct Queue *q, int val){
    if(isFull(q)){
        printf("queue is already full");
    }

    else{
        q->rear = q->rear +1;
        q->array[q->rear] = val;
        printf("%d enqueued successfully\n" , val);
    }


}
void Dequeue(struct Queue *q)
{
    int value ;
    if(isEmpty(q)){
        printf("queue is empty");
    }

    else{
            q->front = q->front +1;
        value = q->array[q->front];

        printf("%d is remove from queue",value);
    }

}

int main(){
       struct Queue *que = createQueue(10);
       Enqueue(que,45);
       Enqueue(que , 20);
       Dequeue(que);
}
