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
    long long solve(int n, vector<int> &a, vector<int> &b) {
        long long diffOfArr = 0, count = 0;
        int oddCountIna = 0, evenCountIna = 0, oddCountInb = 0, evenCountInb = 0;
        vector<int> aeven, beven, aodd, bodd;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        for(int i=0; i<n; i++) {
            diffOfArr+=(a[i]-b[i]);
            if(a[i]%2) {
                oddCountIna++;
                aodd.push_back(a[i]);
            } else {
                evenCountIna++;
                aeven.push_back(a[i]);
            }
            if(b[i]%2) { 
                oddCountInb++;
                bodd.push_back(b[i]);
            } else {
                evenCountInb++;
                beven.push_back(b[i]);
            }
        }
        if(diffOfArr!=0 || (evenCountIna!=evenCountInb) || (oddCountIna!=oddCountInb)) 
            return -1;
        
        for(int i=0; i<aeven.size(); i++) 
            count+=(long long)(abs(aeven[i]-beven[i])); 
        for(int i=0; i<aodd.size(); i++) 
            count+=(long long)(abs(aodd[i]-bodd[i]));
            
        return (long long)count/4;
    }
};

/*

- sum should be same 
- no. of even odd ele should be same 



10 1 
0  11

*/


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends