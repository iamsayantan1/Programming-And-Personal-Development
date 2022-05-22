class Solution {
public:
    
    int mD(string s1, int m, string s2, int n){
        if(m==0){
            return n;   /// insert all of s2
        }
        if(n==0){
            return m;    /// del all of s1
        }
        
        if(s1[m-1] == s2[n-1]){
            return mD(s1,m-1,s2,n-1);
        }
        int insert = mD(s1,m,s2,n-1);
        int del = mD(s1,m-1,s2,n);
        int replace = mD(s1,m-1,s2,n-1);
        return 1 + min(insert , min(del,replace));
        
    }
    
    int minDistance(string s1, string s2) {
        ///return mD(word1, word1.size(), word2, word2.size());
        int m = s1.size();
        int n = s2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    dp[i][j] = j;
                }else if(j==0){
                    dp[i][j] = i;
                }else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int insert = dp[i][j-1];
                    int del = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = 1 + min(insert , min(del,replace));
                }
            }
        }
        return dp[m][n];
    }
};









class Solution {
public:

    int change(string s1, int m, string s2, int n)    {
        if(m==0)    {
            return n;
        }
        if(n==0)    {
            return m;
        }
        if(s1[m-1] == s2[n-1])  {
            return change(s1, m-1, s2, n-1);
        }
        int i = change(s1,m,s2,n-1);
        int d = change(s1,m-1,s2,n);
        int r = change(s1,m-1,s2,n-1);
        return 1+min(i,min(d,r));
    }
    
    int minDistance(string s1, string s2) {
        // return change(s1, s1.length(), s2, s2.length());
        int m = s1.length();
        int n = s2.length();
        
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++)   {
            for(int j=0;j<=n;j++)   {
                if(i == 0)    {
                    dp[i][j] = j;
                }
                else if(j == 0)  {
                    dp[i][j] = i;
                }
                else if(s1[i-1] == s2[j-1])  {
                    dp[i][j] = dp[i-1][j-1];
                }
                else    {
                    int i = dp[i][j-1]; 
                    int d = dp[i-1][j];
                    int r = dp[i-1][j-1];
                    dp[i][j] = 1+min(i,min(d,r));
                }
            }
        }
        return dp[m][n];
    }
};