#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n *next;
}node;

void bastir(node *r){
    while(r!=NULL){
        printf("%d ",r->x);
        r=r->next;
    }
        printf("\n");
}

void ekle(node *r,int x){
    node *iter;
    iter=r;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    iter->next=(node*)malloc(sizeof(node));
    iter->next->x=x;
    iter->next->next=NULL;

}

node* ekleSirali(node *r,int x){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=x;
        r->next=NULL;
        return r;
    }
    if(r->x > x){
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp->x=x;
        temp->next=r;
        return temp;
    }
    node *temp;
    node *iter;
    iter=r;
        while(iter->next!=NULL && iter->next->x < x){
            iter=iter->next;
        }
    temp=(node*)malloc(sizeof(node));
    temp->x=x;
    temp->next=iter->next;
    iter->next=temp;
    return r;

}

node* sil(node *r,int x){
    if(r->x == x){
        node *temp;
        temp=r;
        free(temp);
        r=r->next;
        return r;
    }
    node *iter;
    iter=r;
    node *temp;
    while(iter->next!=NULL && iter->next->x != x){
        iter=iter->next;
    }
    if(iter->next==NULL){
        printf("Sayi Bulunamadi.\n");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return r;
}

int main(){
	node *root;
	root=NULL;
    root=ekleSirali(root,5);
    root=ekleSirali(root,1);
    root=ekleSirali(root,7);
    root=ekleSirali(root,11);
    root=ekleSirali(root,-2);
    bastir(root);
    root=sil(root,7);
    bastir(root);
    root=sil(root,11);
    bastir(root);
    root=sil(root,99);
    bastir(root);
    root=sil(root,-2);
    bastir(root);


	getch();
	return 0;
}
