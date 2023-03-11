//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int nq, vector<int> &arr,
    vector<vector<int>> &q) {
        vector<int> freq(n, 0);
        //freq array prepared
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(arr[i]==arr[j]) freq[i]++;
            }
        }
        
        vector<int> ans(nq, 0);
        for(int i=0; i<nq; i++) {
            int l=q[i][0], r=q[i][1], val=q[i][2];
            for(int j=l; j<=r; j++) {
                if(freq[j]==val) ans[i]++;
            }
        }
        return ans;
    }
};
/**

1 1 3 4 3
2 1 2 1 1

1 1 1 1 1
5 4 3 2 1


**/

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends