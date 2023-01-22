//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  //https://www.youtube.com/watch?v=3t20MtxVL5U
    int solve(int n, int k, vector<int> &arr) {
        int sum = 0;
        for(int i=0; i<n; i++) sum+=arr[i];
        
        vector<int> factors;
        int m = sqrt(sum)+1;
        for(int i=1; i<=m; i++) {
            if(sum%i==0) {
                factors.push_back(i);
                factors.push_back(sum/i);
            }
        }
        int ans = 1;
        for(int i=1; i<n; i++) arr[i]+=arr[i-1];
        
        for(int i=0; i<factors.size(); i++) {
            int subarray_count=0;
            for(int j=0; j<n; j++) {
                if(arr[j]%factors[i]==0) subarray_count++;
            }
            if(subarray_count >= k) ans = max(ans, factors[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends