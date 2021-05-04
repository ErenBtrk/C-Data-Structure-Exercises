#include <stdio.h>
#include <conio.h>

struct n{
    int key;
    int value;
};

typedef struct n veri;


int hash(int ,int );
void put(veri [],int ,int ,int );
void diziyiYazdir(veri [],int );
int get(int ,veri [],int );
int removeNumber(veri [],int ,int );
int size(veri [],int );
int isEmpty(veri [],int );
void keys(veri [],int);
void values(veri [],int );

//(h(x)+i)%boyut;
int main(){
	int boyut;
	printf("Dizinin boyutunu giriniz:");
	scanf("%d",&boyut);
	veri dizi[boyut];
    int i;
    for(i=0;i<boyut;i++){
        dizi[i].key=-1;
        dizi[i].value=0;
    }
    printf(isEmpty(dizi,boyut) ? "Hashtable bostur.\n" : "Hashtable bos degildir.\n");
    put(dizi,11,boyut,111);
    put(dizi,21,boyut,2121);
    diziyiYazdir(dizi,boyut);
	getch();
	return 0;
}

int hash(int key,int boyut){
    return key%boyut;
}

void put(veri dizi[],int key,int boyut,int x){
    if(dizi[hash(key,boyut)].key == -1){
        dizi[hash(key,boyut)].key=key;
        dizi[hash(key,boyut)].value=x;
    }
    else{
    int i=hash(key,boyut);
    int tur=0;
        while(dizi[hash(key,boyut)+i].key != -1 && dizi[hash(key,boyut)+i].key != key){
            i++;
            if(i>=boyut){
                if(tur>=1){
                    printf("Hashtable dolu.\n");
                    break;
                }
                i=i%27;
                tur++;
            }
        }
        dizi[i].key=key;
        dizi[i].value=x;
    }

}

int get(int key,veri dizi[],int boyut){
    if(dizi[hash(key,boyut)].key == key
       ){
        return dizi[hash(key,boyut)].value;
    }
    else{
        int i=hash(key,boyut);
        int tur=0;

        while(dizi[i].key != key){
            i++;
            if(i>=boyut){
                if(tur>=1){
                    printf("sayi bulunamadi.\n");
                    return -1;
                }
                i=i%boyut;
                tur++;
            }
        }
        return dizi[i].value;

    }
}

int removeNumber(veri dizi[],int key,int boyut){
    if(dizi[hash(key,boyut)].key == key){
        int removedValue=dizi[hash(key,boyut)].value;
        dizi[hash(key,boyut)].key=-1;
        dizi[hash(key,boyut)].value=0;
        return removedValue;
    }
    else{
        int i=hash(key,boyut);
        int tur=0;

        while(dizi[i].key != key){
            i++;
            if(i>=boyut){
                if(tur>=1){
                    printf("sayi bulunamadi.\n");
                    return -1;
                }
                i=i%boyut;
                tur++;
            }
        }
        int removedValue=dizi[i].value;
        dizi[i].key=-1;
        dizi[i].value=0;
        return removedValue;
    }
}

void diziyiYazdir(veri dizi[],int boyut){
    int i;
    for(i=0;i<boyut;i++){
        printf("key=%d -- value=%d\n",dizi[i].key,dizi[i].value);
    }
}

int size(veri dizi[],int boyut){
    int i;
    int count=0;
    for(i=0;i<boyut;i++){
        if(dizi[i].key != -1){
            count++;
        }
    }
    return count;

}

int isEmpty(veri dizi[],int boyut){
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

void keys(veri dizi[],int boyut){
    int i;
        printf("KEYS:\n");
        for(i=0;i<boyut;i++){
            if(dizi[i].key != -1){
                    printf("indis=%d - - key=%d\n",i,dizi[i].key);
            }
        }
        printf("\n");
}

void values(veri dizi[],int boyut){
    int i;
        printf("VALUES:\n");
        for(i=0;i<boyut;i++){
            if(dizi[i].key != -1){
                printf("indis=%d - - value=%d\n",i,dizi[i].value);
            }
        }
        printf("\n");
}
