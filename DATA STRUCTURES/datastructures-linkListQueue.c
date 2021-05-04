#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n *next;
}node;


node *r=NULL;
node *son=NULL;





void enque(int a){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=a;
        r->next=NULL;
        son=r;
    }
    else{
        son->next=(node*)malloc(sizeof(node));
        son->next->x=a;
        son=son->next;
        son->next=NULL;
    }
        printf("%d ",a);
}

int deque(void){
    if(r==NULL){
        printf("Queue bostur.\n");
        return -1;
    }
    int rValue;
    rValue=r->x;
    node *temp;
    temp=r;
    r=r->next;
    free(temp);
    return rValue;
}

int main(){

   int i;
	for(i=0;i<20;i++){
        enque(i*10);
	}
	printf("\n");


	for(i=0;i<13;i++){
        printf("%d dequed\n",deque());
	}

    printf("\n");

    for(i=0;i<20;i++){
        enque(i*5);
    }

    printf("\n");

    for(i=0;i<30;i++){
        printf("%d dequed\n",deque());
    }
    enque(5555);
    enque(5555);
    enque(5555);
    enque(5555);
    enque(5555);






	getch();
	return 0;
}
