#include<stdio.h>


//最小２乗法で計算
long long longpow(long long x,long long n){
    long long ans=1;
    long long tmp_x=x;
    while(n!=0){
        if((n%2)==1){
            ans*=tmp_x;
        }
        tmp_x*=tmp_x;
        n/=2;
    }
    return ans;
}


//テスト
int main(void){
    printf("%lld",longpow(3,1));
    return 0;
}
