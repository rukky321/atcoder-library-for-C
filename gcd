#include<stdio.h>

//ユークリッドの互除法で最大公約数を計算

long long gcd(long long a,long long b){
  long long tmp=1;
  while(b!=0){
    tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

//テスト
int main(void){
  printf("%lld",gcd(11,10));
  return 0;
}
