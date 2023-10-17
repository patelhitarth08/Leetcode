//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
          vector<int> prefixSum(n);
          int sum = 0;
          for (int i = 0; i < n; i++)
          {
                sum += nums[i];
                prefixSum[i] = sum;
                // cout << prefixSum[i] << " ";
          }
        //   cout << endl;
          unordered_map<int, int> map;
          int lastZero = -1;
          for (int i = n - 1; i >= 0; i--)
          {
                map[prefixSum[i]] = i;
                if (lastZero == -1 && prefixSum[i] == 0)
                      lastZero = i;
          }
          int ans = -1;
          for (int i = 0; i < n; i++)
          {
                ans = max(ans, abs(map[prefixSum[i]] - i));
          }
          ans = max(lastZero + 1, ans);
          return ans;    
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends