#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct n{
    int *dizi;
    int tepe;
    int boyut;
};
typedef struct n N;

N* tanim(void){
    N *s;
    s=(N*)malloc(sizeof(N));
    s->dizi=NULL;
    s->tepe=0;
    s->boyut=2;
    return s;
}

void push(N*s,int a){
    if(s->dizi==NULL){
        s->dizi=(int*)malloc(sizeof(int)*2);
    }
    if(s->tepe >= s->boyut){
        int *dizi2;
        dizi2=(int*)malloc(sizeof(int)*s->boyut*2);
        int i;
        for(i=0;i<s->boyut;i++){
            dizi2[i]=s->dizi[i];
        }
        free(s->dizi);
        s->dizi=dizi2;
        s->boyut*=2;
    }
       s->dizi[s->tepe++]=a ;

}

int pop(N*s){
    if(s->tepe<=0 || s->dizi==NULL){
        printf("Dizi bostur.\n");
        return -1;
    }
    if(s->tepe <= s->boyut/4){
        int *dizi2;
        dizi2=(int *)malloc(sizeof(int)*s->boyut/2);
        int i;
        for(i=0;i<s->tepe;i++){
            dizi2[i]=s->dizi[i];
        }
        free(s->dizi);
        s->dizi=dizi2;
        s->boyut/=2;
    }
    return s->dizi[--s->tepe];
}

void bastir(N*s){
    int i;
    for(i=0;i<s->tepe;i++){
        printf("%d ",s->dizi[i]);
    }
    printf("\n");

}

int main(){
	N *s1;
	N *s2;
	s1=tanim();
	s2=tanim();
    int i;
	for(i=1;i<=10;i++){
        push(s1,i*10);
	}
	bastir(s1);
	for(i=1;i<=10;i++){
        push(s2,pop(s1));
	}
    bastir(s2);


	getch();
	return 0;
}
