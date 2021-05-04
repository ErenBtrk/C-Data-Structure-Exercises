#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n* next;
}node;

void bastir(node * r){
        while(r!=NULL){
            printf("%d\n",r->x);
            r=r->next;
        }

}

void ekle(node * r,int x){
        while(r->next!=NULL){
            r=r->next;
        }
        r->next=(node*)malloc(sizeof(node));
        r->next->x=x;
        r->next->next=NULL;


}


int main(){
        node * root;
        root=(node*)malloc(sizeof(node));
        root->next=NULL;
        root->x=500;
        int i=0;
        for(i=0;i<5;i++){
            ekle(root,i*10);
        }
        bastir(root);






	getch();
	return 0;
}
