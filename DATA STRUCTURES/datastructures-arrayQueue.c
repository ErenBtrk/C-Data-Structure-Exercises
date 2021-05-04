#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int *dizi=NULL;
int sira=0;
int siraBasi=0;
int boyut=2;

void bastir(void){
    int i;
    for(i=0;i<sira;i++){
        printf("%d ",dizi[i]);
    }
    printf("\n");

}

int deque(){
    if(sira==siraBasi){
        printf("Sira bostur.\n");
        return -1;
    }
    if(sira-siraBasi<=boyut/4){
        int *dizi2;
        dizi2=(int*)malloc(sizeof(int)*boyut/2);
        int i;
        for(i=0;i<sira-siraBasi;i++){
            dizi2[i]=dizi[siraBasi+i];
        }
        sira-=siraBasi;
        siraBasi=0;
        free(dizi);
        dizi=dizi2;
        boyut/=2;
    }
    return dizi[siraBasi++];
}
void toparla(){
    if(siraBasi==0){
        return ;
    }
    int i;
    for(i=0;i<boyut;i++){
        dizi[i]=dizi[i+siraBasi];
    }
    sira -= siraBasi;
    siraBasi=0;
}

void enque(int a){
    if(dizi==NULL){
        dizi=(int*)malloc(sizeof(int)*2);
    }
    if(sira>=boyut){
        int *dizi2;
        dizi2=(int*)malloc(sizeof(int)*boyut*2);
        int i;
        for(i=0;i<boyut;i++){
            dizi2[i]=dizi[i];
        }
        free(dizi);
        dizi=dizi2;
        boyut*=2;

    }
    dizi[sira++]=a;
}

int main(){
	int i;
	for(i=0;i<20;i++){
        enque(i*10);
	}
	printf("boyut:%d    sira:%d     sirabasi:%d\n",boyut,sira,siraBasi);
	bastir();
	for(i=0;i<13;i++){
        printf("%d dequed\n",deque());
	}
	toparla();
	printf("boyut:%d    sira:%d     sirabasi:%d\n",boyut,sira,siraBasi);
    bastir();
    for(i=0;i<20;i++){
        enque(i*10);
    }
    printf("boyut:%d    sira:%d     sirabasi:%d\n",boyut,sira,siraBasi);
    bastir();
    for(i=0;i<30;i++){
        printf("%d dequed\n",deque());
    }
    printf("boyut:%d    sira:%d     sirabasi:%d\n",boyut,sira,siraBasi);
    bastir();
    for(i=0;i<20;i++){
        enque(i*10);
    }
    bastir();


	getch();
	return 0;
}
