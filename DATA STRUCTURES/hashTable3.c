#include <stdio.h>
#include <conio.h>

struct v{
    int key;
    int value;
};
typedef struct v Veri;

void diziyiTanimla(Veri [],int );
void diziyiYazdir(Veri [],int);
int hash(int,int);
void put(Veri [],int,int,int);
int get(Veri [],int,int);
int removeNumber(Veri [],int,int);
int size(Veri [],int);
int isEmpty(Veri [],int);
void keys(Veri [],int);
void values(Veri [],int);


int main(){
	int boyut;
	printf("Dizinin boyutunu giriniz:");
	scanf("%d",&boyut);
	Veri dizi[boyut];
	diziyiTanimla(dizi,boyut);
    diziyiYazdir(dizi,boyut);
    printf(isEmpty(dizi,boyut) ? "Hashtable bostur.\n" : "Hashtable bos degildir.\n");
    int i;
    for(i=0;i<boyut;i++){
        if(i==5){
            continue;
        }
        put(dizi,i*5,i+5,boyut);
    }
    diziyiYazdir(dizi,boyut);
    put(dizi,9,9999,boyut);
    diziyiYazdir(dizi,boyut);
    put(dizi,999,1231231,boyut);
    diziyiYazdir(dizi,boyut);
    printf("Sayi=%d\n",get(dizi,999,boyut));
    printf("Sayi=%d\n",get(dizi,11,boyut));
    printf("Sayi=%d\n",get(dizi,0,boyut));
    printf("Silinen sayi=%d\n",removeNumber(dizi,5,boyut));
    diziyiYazdir(dizi,boyut);
    printf("Hashtable'in boyutu=%d\n",size(dizi,boyut));
    put(dizi,41,66666666,boyut);
    diziyiYazdir(dizi,boyut);
    printf("Hashtable'in boyutu=%d\n",size(dizi,boyut));
    printf(isEmpty(dizi,boyut) ? "Hashtable bostur.\n" : "Hashtable bos degildir.\n");
    keys(dizi,boyut);
    values(dizi,boyut);

	getch();
	return 0;
}

void diziyiTanimla(Veri dizi[],int boyut){
    int i;
        for(i=0;i<boyut;i++){
            dizi[i].key=-1;
            dizi[i].value=0;
        }
}

void diziyiYazdir(Veri dizi[],int boyut){
    int i;
        for(i=0;i<boyut;i++){
            printf("Indis=%d - - Key=%d - - Value=%d\n",i,dizi[i].key,dizi[i].value);
        }
        printf("\n");
}

int hash(int key,int boyut){
    return key%boyut;
}

void put(Veri dizi[],int key,int value,int boyut){
    if(dizi[hash(key,boyut)].key == -1){
        dizi[hash(key,boyut)].key=key;
        dizi[hash(key,boyut)].value=value;
    }
    else{
        int i=0;
        int tur=0;

            while(dizi[(hash(key,boyut)+i)%boyut].key != -1 ){
                i++;
                if(i>=boyut){
                    if(tur>=1){
                        printf("Hashtable doludur.\n\n");
                        return;
                    }
                    i=0;
                    tur++;
                }
            }

            dizi[(hash(key,boyut)+i)%boyut].key=key;
            dizi[(hash(key,boyut)+i)%boyut].value=value;
    }
}

int get(Veri dizi[],int key,int boyut){
    if(dizi[hash(key,boyut)].key == key){
        return dizi[hash(key,boyut)].value;
    }
    else{
        int i=0;
        int tur=0;
            while(dizi[(hash(key,boyut)+i)%boyut].key != key){
                i++;
                if(i>=boyut){
                    if(tur>=1){
                        printf("key bulunamadi.");
                        return -1;
                    }
                    i=0;
                    tur++;
                }
            }
            return dizi[(hash(key,boyut)+i)%boyut].value;
    }
}

int removeNumber(Veri dizi[],int key,int boyut){
    if(dizi[hash(key,boyut)].key == key){
        int silinen=dizi[hash(key,boyut)].value;
        dizi[hash(key,boyut)].key=-1;
        dizi[hash(key,boyut)].value=0;
        return silinen;
    }
    else{
        int i=0;
        int tur=0;
            while(dizi[(hash(key,boyut)+i)%boyut].key != key ){
                i++;
                if(i>=boyut){
                    if(tur>=1){
                        printf("Silmek istediginiz key bulunamadi.\n");
                        return -1;
                    }
                    i=0;
                    tur++;
                }
            }
            int silinen=dizi[(hash(key,boyut)+i)%boyut].value;
            dizi[(hash(key,boyut)+i)%boyut].key=-1;
            dizi[(hash(key,boyut)+i)%boyut].value=0;
            return silinen;
    }
}

int size(Veri dizi[],int boyut){
    int i;
    int count=0;
    for(i=0;i<boyut;i++){
        if(dizi[i].key!=-1){
            count++;
        }
    }

    return count;

}

int isEmpty(Veri dizi[],int boyut){
    int i;
    int flag=1;
        for(i=0;i<boyut;i++){
            if(dizi[i].key != -1){
                flag=0;
                break;
            }
        }
        if(flag==1){
            return 1;
        }
        else{
            return 0;
        }
}

void keys(Veri dizi[],int boyut){
    int i;
        printf("KEYS:\n");
        for(i=0;i<boyut;i++){
            if(dizi[i].key != -1){
                printf("%d ",dizi[i].key);
            }
        }
        printf("\n");

}

void values(Veri dizi[],int boyut){
    int i;
        printf("VALUES:\n");
        for(i=0;i<boyut;i++){
            if(dizi[i].key != -1){
                printf("%d ",dizi[i].value);
            }
        }
        printf("\n");
}
