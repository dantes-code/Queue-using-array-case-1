#include<stdio.h>
#define max 10
typedef struct{   //here we are defining the adt of queue
	int arr[max];   //array of size 10
	int front;
	int rear;
 } Queue;
int insert(Queue *q,int val){           //this is the insert function where we are inserting a value equal to val at the rear of the queue
	if(q->front==-1 && q->rear==-1){      //the first case states that the queue is empty
		q->front++;
		q->rear++;
		q->arr[q->rear] = val;
		return 0;
	}
	else if(q->rear == max-1){            //the 2nd case states that if the queue is full
		printf("Line is Full");
		return 1;
	}
	else{
		q->rear++;
		q->arr[q->rear] = val;	
		return 0;
	}
 }
int del(Queue *q,int *Val){               //this function helps the user to delete a value from the front of the queue
	if(q->front ==-1 && q->rear == -1){      // this case states that the queue is empty already and thus can't be deleted further
		printf("Queue Empty Already");
		return 1;
		}
	else if(q->front == q->rear){           //in any situation it may happen that the position of front and rear be same, so in such cases we r going to
		*Val = q->arr[q->front];		          //put both the values of rear and front back to -1 so the queue here again becomes empty
		q->front = -1;
		q->rear = -1;
		return 0;	
	}
	else{
		*Val = q->arr[q->front];
		q->front++;	
		return 0;
	}
 }
int main(){
Queue q1;
int rVal;
q1.front = -1;
q1.rear = -1;
int ins=insert(&q1,1);
ins=insert(&q1,2);
int delete = del(&q1,&rVal);
printf("%d",q1.arr[q1.front]);
printf("%d",q1.arr[q1.rear]);
 }
