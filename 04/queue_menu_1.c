#include <stdio.h>
#define MAX 10
int q[MAX],front=-1,rear=-1;
void enqueue(){
    int x;
    if(rear==MAX-1) printf("Full\n");
    else{
        printf("Enter: ");
        scanf("%d",&x);
        if(front==-1) front=0;
        q[++rear]=x;
    }
}
void dequeue(){
    if(front==-1||front>rear) printf("Empty\n");
    else printf("Deleted: %d\n",q[front++]);
}
void display(){
    if(front==-1||front>rear) printf("Empty\n");
    else{
        for(int i=front;i<=rear;i++) printf("%d ",q[i]);
        printf("\n");
    }
}
void peek(){
    if(front==-1||front>rear) printf("Empty\n");
    else printf("Front: %d\n",q[front]);
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
