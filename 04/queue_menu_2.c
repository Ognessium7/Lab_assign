#include <stdio.h>
#define MAX 5
int cq[MAX],front=-1,rear=-1;
void enqueue(){
    int x;
    if((front==0 && rear==MAX-1) || (rear+1)%MAX==front) printf("Full\n");
    else{
        printf("Enter: ");
        scanf("%d",&x);
        if(front==-1) front=0;
        rear=(rear+1)%MAX;
        cq[rear]=x;
    }
}
void dequeue(){
    if(front==-1) printf("Empty\n");
    else{
        printf("Deleted: %d\n",cq[front]);
        if(front==rear) front=rear=-1;
        else front=(front+1)%MAX;
    }
}
void display(){
    if(front==-1) printf("Empty\n");
    else{
        int i=front;
        while(1){
            printf("%d ",cq[i]);
            if(i==rear) break;
            i=(i+1)%MAX;
        }
        printf("\n");
    }
}
void peek(){
    if(front==-1) printf("Empty\n");
    else printf("Front: %d\n",cq[front]);
}
int main(){
    int ch;
    while(1){
        printf("1-Enq 2-Deq 3-Disp 4-Peek 5-Exit\n");
        scanf("%d",&ch);
        if(ch==1) enqueue();
        else if(ch==2) dequeue();
        else if(ch==3) display();
        else if(ch==4) peek();
        else break;
    }
}
