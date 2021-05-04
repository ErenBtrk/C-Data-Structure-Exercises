#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n *next;
};
typedef struct n node;

void bastir(node *r){
    while(r!=NULL){
        printf("%d ",r->x);
        r=r->next;
    }
    printf("\n");
}

int enque(node **r,int a){
    node *root;
    root=*r;
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->x=a;
        root->next=NULL;
        *r=root;
        return a;
    }
    node *iter;
    iter=root;
    while(iter->next != NULL){
        iter=iter->next;
    }
    iter->next=(node*)malloc(sizeof(node));
    iter->next->x=a;
    iter->next->next=NULL;
    return a;

}

int deque(node **r){
    node *root;
    root=*r;
    if(root==NULL){
        printf("Sira bostur.\n");
        return -1;
    }


    int rValue;
    rValue=root->x;
    node *temp;
    temp=root;
    root=root->next;
    free(temp);
    *r=root;
    return rValue;

}

int main(){
    node *root;
    root=NULL;
    int i;
    for(i=0;i<10;i++){
        printf("%d enqued\n",enque(&root,i+1));
        bastir(root);
    }

    for(i=0;i<10;i++){
        printf("%d dequed\n",deque(&root));
        bastir(root);
    }
    printf("%d dequed\n",deque(&root));
    bastir(root);
    printf("%d enqued\n",enque(&root,5));
    bastir(root);
    printf("%d enqued\n",enque(&root,6));
    bastir(root);
    printf("%d dequed\n",deque(&root));
    bastir(root);
    printf("%d enqued\n",enque(&root,31));
    bastir(root);


	getch();
	return 0;
}
