//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     /* 
        Function to find majority element in the array
        a: input array
        size: size of input array
        
        15
        17 19 9 5 3 6 17 7 18 16 18 11 3 15 2
    */
    int majorityElement(int arr[], int n) {
       int count = 0, ele = 0;
       for(int i=0; i<n; i++) {
           if(count == 0) {
               count = 1;
               ele = arr[i];
           }
           else if(arr[i] == ele) count++;
           else {
               if(count == 1) ele = arr[i];
               else count--;
           }
       }
       count = 0;
       for(int i=0; i<n; i++) {
           if(arr[i] == ele) count++;
       }
       return count > n/2 ? ele : -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends