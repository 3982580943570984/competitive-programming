#include <iostream>
#include <cmath>
#include <stdint.h>

#define int long long
using namespace std;

int32_t main () {
	int n;cin>>n;
	if(n&1){
		cout<<0<<endl;
	}else{
		int dp[65];dp[0]=dp[1]=1; //base cases
		for(int i=0;i<n;++i){
			dp[i+2]=dp[i]*2; //transitions
		}
		cout<<dp[n]<<endl;
	}
}
