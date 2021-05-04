#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct n{
    int *dizi;
    int sira;
    int siraBasi;
    int boyut;
};

typedef struct n N;

N* tanim(void){
    N *s;
    s=(N*)malloc(sizeof(N));
    s->sira=0;
    s->siraBasi=0;
    s->boyut=2;
    s->dizi=NULL;
    return s;
}


void enque(N *s,int a){
    if(s->dizi==NULL){
        s->dizi=(int*)malloc(sizeof(int)*2);
    }
    if(s->sira >= s->boyut){
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
        s->dizi[s->sira++]=a;
}

int deque(N*s){
    if(s->sira==s->siraBasi){
        printf("Sira bostur.\n");
        s->sira=0;
        s->siraBasi=0;
        return -1;
    }
    if(s->sira - s->siraBasi <= s->boyut/4){
        int *dizi2;
        dizi2=(int*)malloc(sizeof(int)*s->boyut/2);
        int i;
        for(i=0;i<s->sira - s->siraBasi;i++){
            dizi2[i]=s->dizi[i+s->siraBasi];
        }
        s->sira -= s->siraBasi;
        s->siraBasi=0;
        free(s->dizi);
        s->dizi=dizi2;
        s->boyut/=2;
    }
    return s->dizi[s->siraBasi++];
}

void bastir(N*s){
    int i;
    for(i=0;i<s->sira;i++){
        printf("%d ",s->dizi[i]);
    }
    printf("\n");
}
void toparla(N*s){
    if(s->siraBasi==0){
        return ;
    }
    int i;
    for(i=0;i<s->boyut;i++){
        s->dizi[i]=s->dizi[i+s->siraBasi];
    }
    s->sira -= s->siraBasi;
    s->siraBasi=0;
}

int main(){
	N *s1;
	s1=tanim();
	printf("boyut:%d    sira:%d     sirabasi:%d\n",s1->boyut,s1->sira,s1->siraBasi);
    int i;
    for(i=0;i<20;i++){
        enque(s1,i+1);
    }
    bastir(s1);
    printf("boyut:%d    sira:%d     sirabasi:%d\n",s1->boyut,s1->sira,s1->siraBasi);
    for(i=0;i<21;i++){
        printf("%d dequed\n",deque(s1));
    }
    toparla(s1);
    bastir(s1);
    printf("boyut:%d    sira:%d     sirabasi:%d\n",s1->boyut,s1->sira,s1->siraBasi);
    for(i=0;i<10;i++){
        enque(s1,i*5);
    }
    bastir(s1);
    printf("boyut:%d    sira:%d     sirabasi:%d\n",s1->boyut,s1->sira,s1->siraBasi);

	getch();
	return 0;
}
