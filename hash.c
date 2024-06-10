#include<stdio.h>
#include<stdlib.h>

//チェイン法によるハッシュ

//データを格納する配列のサイズ
#define HASHSIZE 100000

//格納するデータと次のセルへのポインタを含んだ構造体
typedef struct cell{
  long long value;
  int count;
  struct cell *next;
  struct cell *prev;
} cell;

//セルを初期化
void initcell(cell *c){
  c->value=-1;
  c->count=1;
  c->next=NULL;
  c->prev=NULL;
}

// data一つ分の領域を確保
// valueは-1,nextはNULLで初期化
cell *createcell(){
  cell *newcell;
  newcell=(cell*)malloc(sizeof(cell));
  initcell(newcell);
  return newcell;
}

//ハッシュを作成
cell *createhash(){
  cell *hash_array;
  hash_array=(cell*)malloc(sizeof(cell)*HASHSIZE);
  for(int i=0;i<HASHSIZE;i++){
    initcell(&hash_array[i]);
  }
  return hash_array;
}

//ハッシュ関数の定義
int hash(int value){
  return value%HASHSIZE;
}

//入力したデータが格納されているか調べる
//格納されていなければNULL
cell *searchdata(cell *hash_array,long long value){
  cell *c;
  int h=hash(value);
  for(c=&hash_array[h];c->next!=NULL;c=c->next){
    if(c->next->value==value){
      return c->next;
    }
  }
  return NULL;
}

// add時に既にデータが格納されていた時の操作
void countup(cell *c){
  c->count++;
}

// 新しくデータを格納する
// すでにデータが格納されていた場合の操作は上で定義可能
int adddata(cell *hash_array,long long value){
  cell *c;
  int h=hash(value);
  for(c=&hash_array[h];c->next!=NULL;c=c->next){
    if(c->next->value==value){
        countup(c->next);
        return -1;
    }
  }
  cell *newcell=createcell();
  newcell->value=value;
  c->next=newcell;
  newcell->prev=c;
  return 0;
}

// データを指定して要素を削除
void deletedata(cell *hash_array,cell *c){
    if(c->prev!=NULL){
        if(c->next!=NULL){
            c->prev->next=c->next;
            c->next->prev=c->prev;
            free(c);
        }
        else{
            c->prev->next=c->next=NULL;
            free(c);
        }
    }
}

//テスト (下記URLの問題の解となるプログラムです)
//https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_b
int main(void){
  cell *h=createhash();
  int n,m;
  int tmp;
  scanf("%d",&n);

  //hashにデータを追加
  for(int i=0;i<n;i++){
    scanf("%d",&tmp);
    adddata(h,tmp);
  }

  scanf("%d",&m);

  //hashからデータがあるか調べる
  for(int i=0;i<m;i++){
    scanf("%d",&tmp);
    cell *c=searchdata(h,tmp);
    if(c!=NULL){
      if(c->count>0){
        c->count--;
        if(c->count==0){
            deletedata(h,c);
        }
      }
      else{
        printf("NO\n");
        return 0;
      }
    }
    else{
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
