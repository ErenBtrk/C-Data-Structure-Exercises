#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n *next;
    struct n *prev;
}node;

void bastir(node *r){
    if(r==NULL){
        printf("Liste bos...\n");
    }
    while(r!=NULL){
        printf("%d ",r->x);
        r=r->next;
    }
    printf("\n");
}

node* ekle(node *r,int a){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=a;
        r->next=NULL;
        r->prev=NULL;
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

node* ekleSirali(node *r,int a){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=a;
        r->next=NULL;
        r->prev=NULL;
        return r;
    }
    if(r->x > a){
        node *temp;
        temp=(node*)malloc(sizeof(node));
        temp->x=a;
        temp->next=r;
        r->prev=temp;
        return temp;
    }
    node *iter;
    node *temp;
    iter=r;
    while(iter->next != NULL && iter->next->x < a){
        iter=iter->next;
    }
    temp=(node*)malloc(sizeof(node));
    temp->x= a;
    temp->next=iter->next;
    temp->prev=iter;
    if(temp->next != NULL){
        temp->next->prev=temp;
    }
    iter->next=temp;
    return r;
}

node* sil(node *r,int a){
    if(r==NULL){
        printf("Liste bostur.\n");
        return r;
    }
    if(r->x == a){
        node *temp;
        temp=r;
        free(temp);
        r=r->next;
        return r;
    }
    node *iter;
    node *temp;
    iter=r;
    while(iter->next != NULL && iter->next->x != a){
        iter=iter->next;
    }
    if(iter->next==NULL){
        printf("Sayi bulunamadi.\n");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    if(iter->next != NULL){
        iter->next->prev=iter;
    }
    return r;

}

int main(){
    node *root;
    root=NULL;
    root=ekleSirali(root,25);
    bastir(root);
    root=ekleSirali(root,11);
    bastir(root);
    root=ekleSirali(root,21);
    bastir(root);
    root=ekleSirali(root,1);
    bastir(root);
    root=sil(root,21);
    bastir(root);
    root=sil(root,25);
    bastir(root);
    root=sil(root,1);
    bastir(root);
    root=sil(root,99);
    bastir(root);
    root=sil(root,11);
    bastir(root);
    root=sil(root,11);
	bastir(root);
	root=ekleSirali(root,3252);
	bastir(root);
	root=ekleSirali(root,32423);
	bastir(root);

    getch();
    return 0;
}
