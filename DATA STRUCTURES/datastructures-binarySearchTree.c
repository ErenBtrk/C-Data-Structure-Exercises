#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n*left;
    struct n*right;
}node;

void dolasNodedanBasla(node *tree){
    if(tree==NULL){
        return ;
    }
    printf("%d ",tree->x);
    dolasNodedanBasla(tree->right);
    dolasNodedanBasla(tree->left);
}

void dolasKucuktenBuyuge(node *tree){
    if(tree==NULL){
        return ;
    }
    dolasKucuktenBuyuge(tree->left);
    printf("%d ",tree->x);
    dolasKucuktenBuyuge(tree->right);
}

void dolasBuyuktenKucuge(node *tree){
    if(tree==NULL){
        return ;
    }
    dolasBuyuktenKucuge(tree->right);
    printf("%d ",tree->x);
    dolasBuyuktenKucuge(tree->left);
}

node* ekle(node *tree,int a){
    if(tree==NULL){
        node *root;
        root=(node*)malloc(sizeof(node));
        root->x=a;
        root->right=NULL;
        root->left=NULL;
        return root;
    }
    if(tree->x < a){
        tree->right=ekle(tree->right,a);
        return tree;
    }
    else{
        tree->left=ekle(tree->left,a);
    }
    return tree;
}

int bul(node *tree,int aranan){
    if(tree==NULL){
        return -1;
    }
    if(tree->x == aranan){
        return 1;
    }
    if(bul(tree->right,aranan)==1){
        return 1;
    }
     if(bul(tree->left,aranan)==1){
        return 1;
    }
    return -1;

}

int max(node *tree){
    while(tree->right != NULL){
        tree=tree->right;
    }
    return tree->x;
}

int min(node *tree){
    while(tree->left != NULL){
        tree=tree->left;
    }
    return tree->x;
}

node* sil(node *tree,int a){
    if(tree==NULL){
        return NULL;
    }
    if(tree->x ==a ){
        if(tree->right==NULL && tree->left==NULL){
            return NULL;
        }
        if(tree->right != NULL){
            tree->x=min(tree->right);
            tree->right=sil(tree->right,min(tree->right));
            return tree;
        }
        else{
        tree->x=max(tree->left);
        tree->left=sil(tree->left,max(tree->left));
        return tree;
        }
    }
    if(tree->x < a){
        tree->right=sil(tree->right,a);
        return tree;
    }
    tree->left=sil(tree->left,a);
    return tree;

}
int main(){
	node *tree;
	tree=NULL;
    tree=ekle(tree,56);
    tree=ekle(tree,200);
    tree=ekle(tree,26);
    tree=ekle(tree,190);
    tree=ekle(tree,213);
    tree=ekle(tree,18);
    tree=ekle(tree,28);
    tree=ekle(tree,12);
    tree=ekle(tree,24);
    tree=ekle(tree,27);
    dolasKucuktenBuyuge(tree);
    printf("\n");
    dolasBuyuktenKucuge(tree);
    printf("\n");
    dolasNodedanBasla(tree);
    printf("\narama sonucu: %d\n",bul(tree,100));
    printf("\narama sonucu: %d\n",bul(tree,12));
    printf("Max sayi=%d\n",max(tree));
    printf("Min sayi=%d\n",min(tree));
    tree=sil(tree,56);
    dolasNodedanBasla(tree);


	getch();
	return 0;
}
