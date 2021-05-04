#include <stdio.h>
#include <conio.h>

typedef struct veri{
    int key;
    int value;
}veri;
veri a[27];



int hash(int x){
    return x%27; //8*x+5 mod 27;
}

int put(veri data){//hash tablosuna veri koyan fonksiyon
    if(a[hash(data.key)].key== -1){
        a[hash(data.key)]=data;
        return 1;
    }
    else{
        int donusSayisi=0;
        int indis=hash(data.key);
            while(a[indis].key != data.key && a[indis].key != -1){
                //printf("%d %d %d\n",a[indis].key,data.key,indis);
                indis++;
                if(indis>=27){
                    if(donusSayisi>=1){
                        printf("hashtable dolu.\n");
                        return -1;
                    }
                    indis = indis%27;
                    donusSayisi++;
                }
            }

            a[indis].value=data.value;
            a[indis].key=data.key;
    }
}

int get(int key){
   if(a[hash(key)].key== key){
        return a[hash(key)].value;
    }
    else{
        int donusSayisi=0;
        int indis=hash(key);
            while(a[indis].key != key ){
                //printf("%d %d %d\n",a[indis].key,data.key,indis);
                indis++;
                if(indis>=27){
                    if(donusSayisi>=1){
                        printf("hashtable bulunamadi.\n");
                        return -1;
                    }
                    indis = indis%27;
                    donusSayisi++;
                }
            }

            return a[indis].value;
    }
}

void bastir(void){
    int i;
    for(i=0;i<27;i++){
        printf("key:%d value:%d\n",a[i].key,a[i].value);
    }
    printf("\n");
}

int main(){
    int i;
    for(i=0;i<27;i++){
        a[i].key=-1;
    }

    veri data;
     for(i=0;i<30;i++){
        data.key=i;
        data.value=i*23;
        put(data);
    }
    data.key=1;
    data.value=66666;
    put(data);
    data.key=100;
    data.value=77777;
    put(data);
    data.key=28;
    data.value=99999;
    put(data);
    data.key=28;
    data.value=42342;
    put(data);

	printf("%d\n",get(10));
	printf("%d\n",get(1));
	printf("%d\n",get(28));
	printf("%d\n",get(100));
	printf("%d\n",get(3424));
    printf("%d\n",get(2));
    bastir();


	getch();
	return 0;
}
