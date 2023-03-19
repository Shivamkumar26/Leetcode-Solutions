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
    vector<int> getDistinctDifference(int n, vector<int> &arr) {
        // code here
        vector<int> v1(n), v2(n);
        set<int> s1, s2;
        
        for(int i=0; i<n; i++) {
            int sz1 = s1.size();
            s1.insert(arr[i]);
            if(sz1==s1.size()) 
                v1[i] = v1[i-1];
            else {
                if(i==0) v1[i] = 1;
                else v1[i] = v1[i-1]+1;
            }
        }
        for(int i=n-1; i>=0; i--) {
            int sz2 = s2.size();
            s2.insert(arr[i]);
            if(sz2==s2.size()) 
                v2[i] = v2[i+1];
            else {
                if(i==n-1) v2[i] = 1;
                else v2[i] = v2[i+1]+1;
            }
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            //cout << v1[i] << " " << v2[i] << endl;
            int a = 0;
            if(i==0) a=0;
            else a = v1[i-1];
            int b = 0;
            if(i==n-1) b=0;
            else b = v2[i+1];
            ans[i] =  a-b;
        }
        return ans;    
    }
};

/*

1  2    2   3 3 3 
4   3   3   2 4 3 
-3 -2  -1   0 2 3
 
 
 4, 4
 3, 5
 2, 3  
 
 if(mp[ele]!=curr_ind) curr_dist-size+1
 
 3  3  3  3 2 1 s
 4  3  3  2 4 3 
 1  2  2  3 3 3 p

 
 -3 -2  -1   0 2 3
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
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends