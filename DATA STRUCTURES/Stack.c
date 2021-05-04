#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n*next;
}node;

void yazdir(node *r){
    if(r == NULL){
        printf("Stack bos");
        return;
    }
    while(r != NULL){
        printf("%d->",r->x);
        r=r->next;
    }
    printf("NULL\n");
    printf("\n");
}

node *push(node *r,int eklenecek){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=eklenecek;
        r->next=NULL;
        return r;
    }
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->x=eklenecek;
    temp->next=r;
    return temp;

}

int pop(node **r){
    node *root;
    root=*r;
    if(root == NULL){
        printf("Stack bostur.\n");
        return -1;
    }
    if(root->next == NULL){
        int rValue;
        rValue=root->x;
        free(root);
        *r=NULL;
        return rValue;
    }
    node *temp;
    temp=root;
    int rValue;
    rValue=root->x;
    *r=root->next;
    free(temp);
    return rValue;

}

int top(node *r){
    if(r == NULL){
        printf("Stack bos oldugundan top degeri yoktur.\n");
        return -1;
    }
    return r->x;
}

int main(){
	node *root;
	root=NULL;
	int i;
	for(i=0;i<10;i++){
        root=push(root,i*5);
        printf("TOP=%d\n",top(root));
        yazdir(root);
	}
	for(i=0;i<10;i++){
        printf("%d popped.\n",pop(&root));
        printf("TOP=%d\n",top(root));
        yazdir(root);
	}





	getch();
	return 0;
}
