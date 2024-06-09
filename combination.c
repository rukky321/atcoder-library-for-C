#include<stdio.h>

//  組み合わせnCrを求める。

long long combination(int n,int r){
  long long ans=1;
  if(r>=n/2){
    r=n-r;
  }
  for(int i=1;i<=r;i++){
    ans=ans*(n-i+1)/i;
  }
  return ans;
}

//テスト
int main(){
  printf("%lld",combination(13,5));
  return 0;
}
