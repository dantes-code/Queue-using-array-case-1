#include<stdio.h>
#define max 50
typedef struct{
	int arr[max];   //array of size 50
	int front;
	int rear;
 } Queue;
int insert(Queue *q,int val){       //insertion function which will insert at the rear of the queue
	if(q->front==-1 && q->rear==-1){
		q->front++;
		q->rear++;
		q->arr[q->rear] = val;
		return 0;
	}
	else if(q->rear == max-1){
		printf("Line is Full");
		return 1;
	}
	else{
		q->rear++;
		q->arr[q->rear] = val;	
		return 0;
	}
 }
int del(Queue *q){            //deletion function which will remove people(or values) from the front of the queue
    int Val;
    if(q->rear == -1){              
        printf("Empty Queue\n");
        return 1;
    }
    else{
        Val = q->arr[q->front];
        for(int i=1; i <= q->rear; i++){
            q->arr[i-1] = q->arr[i];
        }
        q->rear--;
        return Val;
    }
}
int main(){
	Queue q1;
	int rVal,value,num,i,j;
	char ans;
	q1.front = -1;
	q1.rear = -1;
	printf("How Many Are To Be There In The Queue? :- ");       //asking for how many totatl people(values) to be inserted in the queue
	scanf("%d",&num);
	for(i=0;i<num;i++){                                         //this loop will run till the number of poeple(values) reach the required point
		printf("Enter Number : ");
		scanf("%d",&value);
		for(j=0;j<value;j++){                                     //this loop will insert the value , that many number of times
			insert(&q1,value);		
		}
	 }  
	printf("The Queue is :- " );                                //display function
	int f = q1.front;
	int r = q1.rear;
	for(i=f;i<=r;i++){
		printf("%d   ",q1.arr[i]);	
	}
	
		printf("How many people you want to remove?");            //asking how many poeple has to be removed from the line
		scanf("%d",&num);
		for(i=0;i<num;i++){                                       //this loop runs till the number of poeple getting removed is met
			rVal = del(&q1);                                        //the designated value is stored here in rVal which is used to delete the value that many times
			for(j=1;j<rVal;j++){                                    
				del(&q1);			
			}		
		}	
	printf("The Queue is :- " );
	f = q1.front;
	r = q1.rear;
	for(i=f;i<=r;i++){
		printf("%d   ",q1.arr[i]);	
	}
 }
