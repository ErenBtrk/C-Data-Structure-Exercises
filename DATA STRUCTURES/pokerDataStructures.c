#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int i=0;
int j=0;
int kartNo=0;

typedef struct n{
    const char *grup;
    const char *rakam;
    int grupFrekans;
    int rakamFrekans;
    struct n*next;
    struct n*prev;
}node;

struct s{
    const char *grup;
    const char *rakam;
    int grupFrekans;
    int rakamFrekans;
};

typedef struct s S;

S player1[5];
S player2[5];

struct el{
    int pair;
    int three;
    int ilkCiftinDegeri;
    int ikinciCiftinDegeri;
    int ciftlerArasindaDegeriBuyukOlan;
    int ciftlerArasindaDegeriKucukOlan;
    int uclu;
    int four;
    int besli;
    int eslerDisindaEnBuyukKart;
    int eslerDisindaEnBuyukKartinGrubu;
    int enBuyukKartinDegeri;
    int enBuyukKartinGrubu;
    int frekansBulRakam[15];
    int frekansBulGrup[4];
    int kartlarinToplami;
    int sonuc;
};
typedef struct el El;






void bastir(node *r);
node* ekle(node *r,const char *gruplar[],const char *rakamlar[]);
void kar(node *r);
node* deque(node **r,S player[]);
El eliDegerlendir(S player[5],const char *gruplar[],const char *rakamlar[]);
int ardisikMi(S player[]);
void elSonucuBelirle(El el1,El el2);


int main(){
    const char *gruplar[4]={"","","",""};
	const char *rakamlar[13]={"2","3","4","5","6","7",
                                          "8","9","10","J","Q","K","A"};
    const char* degerHiyerarsisi[10]={"High Hand","One Pair","Two Pairs","Three Of a Kind",
                                                "Straight","Flush","Full House","Four of a Kind",
                                                "Straight Flush","Royal Flush"};
	node *root;
	root=NULL;
	srand(time(NULL));

	int a;
	El el1;
	El el2;
    for(a=0;a<52;a++){
        root=ekle(root,gruplar,rakamlar);
    }

    for(a=0;a<100;a++){
        kar(root);
    }
    for(a=0;a<5;a++){
        root=deque(&root,player1);
    }
     for(a=0;a<5;a++){
        printf("*****\n"
                   "*%2s *\n"
                   "*%2s *\n"
                   "*%2s *\n"
                   "*****\n\n" ,player1[a].grup,player1[a].rakam,player1[a].grup);
    }
    el1=eliDegerlendir(player1,gruplar,rakamlar);
     printf("Pair=%d\nThree=%d\nilkCiftinDegeri=%d\nikinciCiftinDegeri=%d\nEslerDisindaEnBuyukKart=%d\nuclu=%d\nfour=%d\nbesli=%d\nenBuyukKart=%d\nEnBuyukKartinGrubu=%d\nEslerDisindaEnBuyukKartinGrubu=%d\nCiftlerinBuyugu=%d\nKartlarinToplami=%d\nSonuc=%d\n",el1.pair,el1.three,el1.ilkCiftinDegeri,el1.ikinciCiftinDegeri,el1.eslerDisindaEnBuyukKart,el1.uclu,el1.four,el1.besli,el1.enBuyukKartinDegeri,el1.enBuyukKartinGrubu,el1.eslerDisindaEnBuyukKartinGrubu,el1.ciftlerArasindaDegeriBuyukOlan,el1.kartlarinToplami,el1.sonuc);

    for(a=0;a<15;a++){
        printf("%d > %d\n",a,el1.frekansBulRakam[a]);
    }
    printf("\n");
    for(a=0;a<5;a++){
        root=deque(&root,player2);
    }
    printf("\n");
    for(a=0;a<5;a++){
        printf("*****\n"
                   "*%2s *\n"
                   "*%2s *\n"
                   "*%2s *\n"
                   "*****\n\n" ,player2[a].grup,player2[a].rakam,player2[a].grup);
    }
    printf("\n");


    el2=eliDegerlendir(player2,gruplar,rakamlar);

    printf("Pair=%d\nThree=%d\nilkCiftinDegeri=%d\nikinciCiftinDegeri=%d\nEslerDisindaEnBuyukKart=%d\nuclu=%d\nfour=%d\nbesli=%d\nenBuyukKart=%d\nEnBuyukKartinGrubu=%d\nEslerDisindaEnBuyukKartinGrubu=%d\nCiftlerinBuyugu=%d\nKartlarinToplami=%d\nSonuc=%d\n",el2.pair,el2.three,el2.ilkCiftinDegeri,el2.ikinciCiftinDegeri,el2.eslerDisindaEnBuyukKart,el2.uclu,el2.four,el2.besli,el2.enBuyukKartinDegeri,el2.enBuyukKartinGrubu,el2.eslerDisindaEnBuyukKartinGrubu,el2.ciftlerArasindaDegeriBuyukOlan,el2.kartlarinToplami,el2.sonuc);

    for(a=0;a<15;a++){
        printf("%d > %d\n",a,el2.frekansBulRakam[a]);
    }


    printf("\n\n\n\n");

    elSonucuBelirle(el1,el2);





	getch();
	return 0;
}




void bastir(node *r){

    int a;
    printf("\n");
    while(r!=NULL){
        printf("%d-%s %s\n",a+1,r->grup,r->rakam);
        r=r->next;
        a++;
    }
    printf("\n");
}

node* ekle(node *r,const char *gruplar[],const char *rakamlar[]){

    if(j>12){
        i++;
        j=0;
    }
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->grup=gruplar[i];
        r->rakam=rakamlar[j];
        r->grupFrekans=i;
        r->rakamFrekans=j+2;
        r->next=NULL;
        r->prev=NULL;
        j++;
        return r;
    }
    node *iter;
    iter=r;
    while(iter->next != NULL){
        iter=iter->next;
    }
    iter->next=(node*)malloc(sizeof(node));
    iter->next->grup=gruplar[i];
    iter->next->rakam=rakamlar[j];
    iter->next->grupFrekans=i;
    iter->next->rakamFrekans=j+2;
    iter->next->prev=iter;
    iter->next->next=NULL;
    j++;
    return r;
}

void kar(node *r){
    const char *tempGrup;
    const char *tempRakam;
    int tempGrupFrekans;
    int tempRakamFrekans;
    node *iter1;
    node *iter2;
    iter1=r;
    iter2=r;
    while(iter2->next != NULL){
        iter2=iter2->next;
    }
    int a=rand()%52;
    int b=rand()%52;
    int c=0;
    while(c<=a && iter1->next!=NULL){

        iter1=iter1->next;
        c++;
    }
    c=0;
    while(c<=b && iter2->prev !=NULL){

        iter2=iter2->prev;
        c++;
    }
    c=0;
    tempGrup=iter1->grup;
    iter1->grup=iter2->grup;
    iter2->grup=tempGrup;

    tempRakam=iter1->rakam;
    iter1->rakam=iter2->rakam;
    iter2->rakam=tempRakam;

    tempGrupFrekans=iter1->grupFrekans;
    iter1->grupFrekans=iter2->grupFrekans;
    iter2->grupFrekans=tempGrupFrekans;

    tempRakamFrekans=iter1->rakamFrekans;
    iter1->rakamFrekans=iter2->rakamFrekans;
    iter2->rakamFrekans=tempRakamFrekans;
}

node* deque(node **r,S player[]){
    if(kartNo==5){
        kartNo=0;
    }
    node *root;
    root=*r;
    if(root==NULL){
        printf("deste bos.\n");
        return root;
    }
    if(root->next==NULL){
        node *temp;
        temp=root;
        player[kartNo].grup=root->grup;
        player[kartNo].rakam=root->rakam;
        player[kartNo].grupFrekans=root->grupFrekans;
        player[kartNo].rakamFrekans=root->rakamFrekans;
        kartNo++;
        free(temp);
        return NULL;
    }
    node *temp;
    temp=root;
    player[kartNo].grup=root->grup;
    player[kartNo].rakam=root->rakam;
    player[kartNo].grupFrekans=root->grupFrekans;
    player[kartNo].rakamFrekans=root->rakamFrekans;
    kartNo++;
    root=root->next;
    free(temp);
    return root;
}

El eliDegerlendir(S player[5],const char *gruplar[],const char *rakamlar[]){
    El el;
    int a,b;
    int pair=0;
    int three=0;
    int frekansBulRakam[15]={0};
    int frekansBulGrup[4]={0};
    int ilkCiftinDegeri=0;
    int ikinciCiftinDegeri=0;
    int ciftlerArasindaDegeriBuyukOlan=0;
    int ciftlerArasindaDegeriKucukOlan=0;
    int eslerDisindaEnBuyukKart=0;
    int eslerDisindaEnBuyukKartinGrubu=0;
    int uclu=0;
    int four=0;
    int besli=0;
    int sonuc;


    for(a=0;a<5;a++){
        frekansBulRakam[player[a].rakamFrekans]++;
        frekansBulGrup[player[a].grupFrekans]++;
    }
    for(a=0;a<15;a++){
        switch(frekansBulRakam[a]){
        case 1:
            if(a>eslerDisindaEnBuyukKart){
                eslerDisindaEnBuyukKart=a;
            }
            break;
        case 2:
            pair++;
            if(pair==1){
                ilkCiftinDegeri=a;
            }
            if(pair==2){
                ikinciCiftinDegeri=a;
            }
            if(ilkCiftinDegeri>ikinciCiftinDegeri){
                ciftlerArasindaDegeriBuyukOlan=ilkCiftinDegeri;
                ciftlerArasindaDegeriKucukOlan=ikinciCiftinDegeri;
            }
            else{
                ciftlerArasindaDegeriBuyukOlan=ikinciCiftinDegeri;
                ciftlerArasindaDegeriKucukOlan=ilkCiftinDegeri;
            }
            break;
        case 3:
            three++;
            uclu=a;
            break;
        case 4:
            four++;
            four=a;
            break;
        }
    }
    for(a=0;a<4;a++){
        switch(frekansBulGrup[a]){
        case 1:
            printf("%s grubundan %d tane vardir.\n",gruplar[a],frekansBulGrup[a]);
            break;
        case 2:
            printf("%s grubundan %d tane vardir.\n",gruplar[a],frekansBulGrup[a]);
            break;
        case 3:
            printf("%s grubundan %d tane vardir.\n",gruplar[a],frekansBulGrup[a]);
            break;
        case 4:
            printf("%s grubundan %d tane vardir.\n",gruplar[a],frekansBulGrup[a]);
            break;
        case 5:
            printf("%s grubundan %d tane vardir.\n",gruplar[a],frekansBulGrup[a]);
            besli=a;
            break;
        }
    }
    int kartDegerSiralamasi[5]={0};
    int temp;
    int flag=0;
    int enBuyukKartinDegeri=0;
    int enBuyukKartinGrubu=0;
    int kartlarinToplami=0;
    for(a=0;a<5;a++){
        kartDegerSiralamasi[a]=player[a].rakamFrekans;
        kartlarinToplami+=kartDegerSiralamasi[a];
    }

    for(a=0;a<5;a++){
        for(b=a+1;b<5;b++){
            if(kartDegerSiralamasi[a]>kartDegerSiralamasi[b]){
                temp=kartDegerSiralamasi[a];
                kartDegerSiralamasi[a]=kartDegerSiralamasi[b];
                kartDegerSiralamasi[b]=temp;
            }
        }
    }
    enBuyukKartinDegeri=kartDegerSiralamasi[4];
    for(a=0;a<5;a++){
        if(player[a].rakamFrekans==enBuyukKartinDegeri){
            enBuyukKartinGrubu=player[a].grupFrekans;
        }
        if(player[a].rakamFrekans==eslerDisindaEnBuyukKart){
            eslerDisindaEnBuyukKartinGrubu=player[a].grupFrekans;
        }
    }

    printf("Deger siralamasi:\n");
    for(a=0;a<5;a++){
        printf("%d ",kartDegerSiralamasi[a]);
    }
    printf("\n");

     if(pair==0&&three!=1){
            sonuc=0;
            printf("\nHigh Hand\n\n");
        }
        if(pair==1&&three==0){
            sonuc=1;
            printf("\nOne Pair\n\n");
        }
        if(pair==2){
            sonuc=2;
            printf("\nTwo Pairs\n\n");
        }
        if(three==1&&pair!=1){
            sonuc=3;
            printf("\nThree Of a Kind\n\n");
        }
        if(besli!=1&&ardisikMi(player)==1){
            sonuc=4;
            printf("\nStraight\n\n");
        }
        if(besli==1&&ardisikMi(player)==0){
            sonuc=5;
            printf("\nFlush\n\n");
        }
        if(three==1&&pair==1){
            sonuc=6;
            printf("\n*Full House*\n\n");
        }
        if(four==1){
            sonuc=7;
            printf("\n**Four of a Kind**\n\n");
        }
        if(besli==1&&ardisikMi(player)==1){
            sonuc=8;
            printf("\n***Straight Flush***\n\n");
        }
        if(besli==1&&ardisikMi(player)==1&&kartlarinToplami==60){
            sonuc=9;
            printf("\n****Royal Flush****\n\n");
        }
    el.pair=pair;
    el.ilkCiftinDegeri=ilkCiftinDegeri;
    el.ikinciCiftinDegeri=ikinciCiftinDegeri;
    el.ciftlerArasindaDegeriBuyukOlan=ciftlerArasindaDegeriBuyukOlan;
    el.ciftlerArasindaDegeriKucukOlan=ciftlerArasindaDegeriKucukOlan;
    el.eslerDisindaEnBuyukKart=eslerDisindaEnBuyukKart;
    el.three=three;
    el.uclu=uclu;
    el.four=four;
    el.enBuyukKartinDegeri=enBuyukKartinDegeri;
    el.enBuyukKartinGrubu=enBuyukKartinGrubu;
    el.eslerDisindaEnBuyukKartinGrubu=eslerDisindaEnBuyukKartinGrubu;
    el.besli=besli;
    el.kartlarinToplami=kartlarinToplami;
    el.sonuc=sonuc;

    for(a=0;a<15;a++){
        el.frekansBulRakam[a]=frekansBulRakam[a];
    }
    for(a=0;a<4;a++){
        el.frekansBulGrup[a]=frekansBulGrup[a];
    }

    return el;

}

int ardisikMi(S player[]){
    int a,b;
    int kartDegerSiralamasi[5]={0};
    int temp;
    int flag=0;
    int enBuyukKartinDegeri=0;
    for(a=0;a<5;a++){
        kartDegerSiralamasi[a]=player[a].rakamFrekans;
    }

    for(a=0;a<5;a++){
        for(b=a+1;b<5;b++){
            if(kartDegerSiralamasi[a]>kartDegerSiralamasi[b]){
                temp=kartDegerSiralamasi[a];
                kartDegerSiralamasi[a]=kartDegerSiralamasi[b];
                kartDegerSiralamasi[b]=temp;
            }
        }
    }
    enBuyukKartinDegeri=kartDegerSiralamasi[4];
    for(a=0;a<5;a++){
        for(b=a+1;b>a&&b<5;b--){
            if(kartDegerSiralamasi[b]-kartDegerSiralamasi[a]!=1){
                return 0;
            }
            else{
                flag++;
            }
        }
    }
        if(flag==4){
            return 1;
        }



}

void elSonucuBelirle(El el1,El el2){
    if(el1.sonuc>el2.sonuc){
        printf("1.Oyuncu Kazandi.\n");
    }
    else if(el2.sonuc>el1.sonuc){
        printf("2.Oyuncu Kazandi.\n");
    }
    else{
        switch(el1.sonuc){
        case 0:
            if(el1.enBuyukKartinDegeri>el2.enBuyukKartinDegeri){
                printf("1.Oyuncu Kazandi.\n");
            }
            else if(el2.enBuyukKartinDegeri>el1.enBuyukKartinDegeri){
                printf("2.Oyuncu Kazandi.\n");
            }
            else{
                if(el1.enBuyukKartinGrubu>el2.enBuyukKartinGrubu){
                    printf("1.Oyuncu Kazandi.\n");
                }
                else{
                    printf("2.Oyuncu Kazandi.\n");
                }
            }
            break;
        case 1:
            if(el1.ciftlerArasindaDegeriBuyukOlan>el2.ciftlerArasindaDegeriBuyukOlan){
                printf("1.Oyuncu Kazandi.\n");
            }
            else if(el2.ciftlerArasindaDegeriBuyukOlan>el1.ciftlerArasindaDegeriBuyukOlan){
                printf("2.Oyuncu Kazandi.\n");
            }
            else{
                if(el1.eslerDisindaEnBuyukKart>el2.eslerDisindaEnBuyukKart){
                    printf("1.Oyuncu Kazandi.\n");
                }
                else if(el2.eslerDisindaEnBuyukKart>el1.eslerDisindaEnBuyukKart){
                    printf("2.Oyuncu Kazandi.\n");
                }
                else{
                    if(el1.eslerDisindaEnBuyukKartinGrubu>el2.eslerDisindaEnBuyukKartinGrubu){
                        printf("1.Oyuncu Kazandi.\n");
                    }
                    else if(el2.eslerDisindaEnBuyukKartinGrubu>el1.eslerDisindaEnBuyukKartinGrubu){
                        printf("2.Oyuncu Kazandi.\n");
                    }
                }
            }
            break;
        case 2:
            if(el1.ciftlerArasindaDegeriBuyukOlan>el2.ciftlerArasindaDegeriBuyukOlan){
                printf("1.Oyuncu Kazandi.\n");
            }
            else if(el2.ciftlerArasindaDegeriBuyukOlan>el1.ciftlerArasindaDegeriBuyukOlan){
                printf("2.Oyuncu Kazandi.\n");
            }
            else{
                if(el1.ciftlerArasindaDegeriKucukOlan>el2.ciftlerArasindaDegeriKucukOlan){
                    printf("1.Oyuncu Kazandi.\n");
                }
                else if(el2.ciftlerArasindaDegeriKucukOlan>el1.ciftlerArasindaDegeriKucukOlan){
                    printf("2.Oyuncu Kazandi.\n");
                }
                else{
                    if(el1.eslerDisindaEnBuyukKart>el2.eslerDisindaEnBuyukKart){
                        printf("1.Oyuncu Kazandi.\n");
                    }
                    else if(el2.eslerDisindaEnBuyukKart>el1.eslerDisindaEnBuyukKart){
                        printf("2.Oyuncu Kazandi.\n");
                    }
                    else{
                        if(el1.eslerDisindaEnBuyukKartinGrubu>el2.eslerDisindaEnBuyukKartinGrubu){
                            printf("1.Oyuncu Kazandi.\n");
                        }
                        else{
                            printf("2.Oyuncu Kazandi.\n");
                        }
                    }
                }
            }
            break;
        case 3:
            if(el1.uclu>el2.uclu){
                printf("1.Oyuncu Kazandi.\n");
            }
            else{
                printf("2.Oyuncu Kazandi.\n");
            }
            break;
        case 4:
            if(el1.enBuyukKartinDegeri>el2.enBuyukKartinDegeri){
                printf("1.Oyuncu Kazandi.\n");
            }
            else if(el2.enBuyukKartinDegeri>el1.enBuyukKartinDegeri){
                printf("2.Oyuncu Kazandi.\n");
            }
            else{
                printf("Berabere.\n");
            }
        case 5:
            if(el1.enBuyukKartinGrubu>el2.enBuyukKartinGrubu){
                printf("1.Oyuncu Kazandi.\n");
            }
            else{
                printf("2.Oyuncu Kazandi.\n");
            }
            break;
        case 6:
            if(el1.uclu>el2.uclu){
                printf("1.Oyuncu Kazandi.\n");
            }
            else{
                printf("2.Oyuncu Kazandi.\n");
            }
            break;
        case 7:
            if(el1.four>el2.four){
                printf("1.Oyuncu Kazandi.\n");
            }
            else{
                printf("2.Oyuncu Kazandi.\n");
            }
            break;
        case 8:
            if(el1.enBuyukKartinDegeri>el2.enBuyukKartinDegeri){
                printf("1.Oyuncu Kazandi.\n");
            }
            else if(el2.enBuyukKartinDegeri>el1.enBuyukKartinDegeri){
                printf("2.Oyuncu Kazandi.\n");
            }
            else{
                if(el1.enBuyukKartinGrubu>el2.enBuyukKartinGrubu){
                    printf("1.Oyuncu Kazandi.\n");
                }
                else{
                    printf("2.Oyuncu Kazandi.\n");
                }
            }
            break;
        case 9:
                if(el1.enBuyukKartinGrubu>el2.enBuyukKartinGrubu){
                    printf("1.Oyuncu Kazandi.\n");
                }
                else{
                    printf("2.Oyuncu Kazandi.\n");
                }
                break;
        }
    }
}
