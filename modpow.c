#include<stdio.h>


//最小２乗法で計算
long long modpow(long long x,long long n,long long mod){
    long long ans=1;
    long long tmp_x=x%mod;
    while(n!=0){
        if((n%2)==1){
            ans*=tmp_x%mod;
        }
        tmp_x*=tmp_x%mod;
        n/=2;
    }
    return ans;
}

int main(void){
    printf("%lld",modpow(3,8,10));
    return 0;
}
