#include<stdio.h>

//2数の積を最大公約数で割って最小公倍数を計算

long long gcd(long long a,long long b){
  long long tmp;
  if(a<b){
    tmp=a;
    a=b;
    b=tmp;
  }
  while(b!=0){
    tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

long long lcm(long long a,long long b){
  return a*b/gcd(a,b);
}

int main(void){
  printf("%lld",lcm(10,11));
  return 0;
}
