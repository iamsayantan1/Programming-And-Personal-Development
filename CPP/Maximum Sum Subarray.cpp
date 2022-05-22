#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int maximumSubarraySum(vector < int > arr) {
  int n = arr.size();
  int maxSum = INT_MIN;

  for (int i = 0; i <= n - 1; i++) {
    int currSum = 0;
    for (int j = i; j <= n - 1; j++) {
      currSum += arr[j];
      if (currSum > maxSum) {
        maxSum = currSum;
      }
    }
  }

  return maxSum;
}
int main() {
    // Your code goes here;
    vector<int> a = {1, 3, 8, -2, 6, -8, 5};
    cout << maximumSubarraySum(a) << endl;
    return 0;
}









long long maxSubarraySum(int arr[], int n){
        // Your code here
        long long curMax = 0;
        long long sumMax = 0;
        long long max = INT_MIN;
        
        for(int i=0; i<n;i++)   {
            if(arr[i]>max)  {
                max = arr[i];
            }
        }
        if(max<=0)  {
            return max;
        }
        
        for(int i=0; i<n;i++)   {
            curMax += arr[i];
            if(curMax<0)    {
                curMax = 0;
            }
            if(curMax>sumMax)   {
                sumMax = curMax;
            }
        }
        return sumMax;
    }