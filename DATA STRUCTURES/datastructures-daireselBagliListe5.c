#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n *next;
}node;

void bastir(node *r){
    int i;
    node *iter;
    iter=r;
    if(iter==NULL){
        printf("Liste bos.\n");
        return;
    }
    printf("%d ",iter->x);
    iter=iter->next;
    while(iter != r){
        printf("%d ",iter->x);
        iter=iter->next;
    }
    printf("\n");
}

node* ekle(node *r,int a){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=a;
        r->next=r;
        return r;
    }
    node *iter;
    iter=r;
    while(iter->next != r){
        iter=iter->next;
    }
    iter->next=(node*)malloc(sizeof(node));
    iter->next->x=a;
    iter->next->next=r;
    return r;
}

node* ekleSirali(node *r,int a){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->x=a;
        r->next=r;
        return r;
    }
    if(r->x > a){
        node *iter;
        node *temp;
        iter=r;
        while(iter->next != r){
            iter=iter->next;
        }
        temp=(node*)malloc(sizeof(node));
        temp->x=a;
        temp->next=r;
        iter->next=temp;
        return temp;
    }
    node *temp;
    node *iter;
    iter=r;
    while(iter->next != r && iter->next->x < a){
        iter=iter->next;
    }
    temp=(node*)malloc(sizeof(node));
    temp->x=a;
    temp->next=iter->next;
    iter->next=temp;
    return r;

}

node* sil(node *r,int a){
    if(r==NULL){
        printf("Liste bos.\n");
        return r;
    }
    if(r->next==r && r->x == a){
        free(r);
        return NULL;
    }
    if(r->x == a){
        node *iter;
        iter=r;
        while(iter->next != r){
            iter=iter->next;
        }
        node *temp;
        temp=r;
        r=r->next;
        iter->next=r;
        free(temp);
        return r;
    }
    node *iter;
    node *temp;
    iter=r;
    while(iter->next != r && iter->next->x != a){
        iter=iter->next;
    }
    if(iter->next ==r ){
        printf("Eleman bulunamadi.\n");
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
	root=ekleSirali(root,-1);
    bastir(root);
    root=ekleSirali(root,5);
    bastir(root);
    root=ekleSirali(root,-11);
    bastir(root);
    root=ekleSirali(root,10);
    bastir(root);
    root=sil(root,99);
    bastir(root);
    root=sil(root,-11);
    bastir(root);
    root=sil(root,10);
    bastir(root);
    root=sil(root,5);
    bastir(root);
    root=sil(root,-1);
    bastir(root);
    bastir(root);
    bastir(root);
    int i;
    for(i=0;i<10;i++){
        root=ekleSirali(root,i-1);
        bastir(root);
    }
    for(i=9;i>=0;i--){
        root=sil(root,i-1);
        bastir(root);
    }


	getch();
	return 0;
}
