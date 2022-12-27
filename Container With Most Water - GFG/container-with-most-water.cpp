//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long nums[], int n) {
    
    long long water = 0;
    long long leftmax = 0, rightmax = 0;
    int li = 0, ri = n-1;
    
    while(li < ri) {
        int diff = ri - li;
        leftmax = nums[li];
        rightmax = nums[ri];
        water = max(water, diff*min(leftmax, rightmax));
        if(leftmax <= rightmax) li++;
        else ri--;
    }
    
    return water;
}

/**

293265
297396


3 1 2 4 5 

leftmax 
rightmax
index diff
water it contain = id * min(l, r)

3 5 4 12



0 1 2  3 4 5 6 7 
2 3 10 2 3 1 3 1 

ans = 15

**/


//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends