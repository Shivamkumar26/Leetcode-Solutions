//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1000000007;
	long long inv(long long int r){
	    if(r==1) return 1;
	    return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
	}
	int compute_value(int n)
	{
	    long long int ans = 1, ncr=1;
	    for(int i=1; i<=n; i++){
	        ncr=(((ncr*(n+1-i))%mod)*inv(i))%mod;
	        ans=(ans+(ncr*ncr)%mod)%mod;
	    }
	    return ans%mod;
    }
};

/**

n = 3 ; 20

n = 2

all 0 all 1 -> 1 + 1

1 zero  
2*2C1 = 4

2*2C1


3

1+1 = 2 

1 zero 
3C1

2 zero
2C1

places = 6

000 000 
111 111

011 011
001 001



**/



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends