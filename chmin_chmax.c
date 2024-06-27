#include<stdio.h>

// a<bとなるように値を入れ替え
void chmin(int *a,int *b){
    if(*a>*b){
        *a=*b;
    }
}

// a>bとなるように値を入れ替え
void chmax(int *a,int *b){
    if(*a<*b){
        *a=*b;
    }
}

// テスト
int main(void){
    int a=3,b=2,c=5;
    chmin(&a,&b);
    chmin(&b,&c);
    printf("%d %d %d\n",a,b,c);
    a=7;
    chmax(&b,&c);
    chmax(&a,&b);
    printf("%d %d %d\n",a,b,c);
    return 0;
}
