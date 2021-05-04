#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n*next;
}node;

void bastir(node *r){
    while(r!=NULL){
        printf("%d ",r->x);
        r=r->next;
    }
    printf("\n");
}

node* push(node *r,int a){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=a;
        r->next=NULL;
        return r;
    }
    node *iter;
    iter=r;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    iter->next=(node*)malloc(sizeof(node));
    iter->next->x=a;
    iter->next->next=NULL;
    return r;
}

int pop(node **r){
    node *root;
    root=*r;
    if(root==NULL){
        printf("Liste bostur.\n");
        return -1;
    }
    node *iter;
    iter=root;
    if(root->next==NULL && iter->next==NULL){
        int rValue;
        rValue=iter->x;
        free(iter);
        *r=NULL;
        return rValue;
    }
    while(iter->next->next != NULL){
        iter=iter->next;
    }
    node *temp;
    temp=iter->next;
    int rValue;
    rValue=temp->x;
    iter->next=NULL;
    free(temp);
    return rValue;

}






int main(){
	node *root;
	root=NULL;
	int i;
	for(i=1;i<=10;i++){
        root=push(root,i*5);
        
	}
    bastir(root);
    for(i=1;i<=11;i++){
        printf("%d popped\n",pop(&root));
    }
    bastir(root);
    for(i=1;i<=5;i++){
        root=push(root,i-5);
    }
    bastir(root);
	getch();
	return 0;
}
