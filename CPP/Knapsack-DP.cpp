int knapsack(int n, int C, vector<int> A, vector<int> B){
    if(n==0 || C==0){
        return 0;
    }
    
    if(B[n-1] > C){
        return knapsack(n-1, C, A , B);
    }else{
        int inc = A[n-1] + knapsack(n-1, C - B[n-1], A, B);
        int exl = knapsack(n-1 , C, A, B);
        return max(inc,exl);
    }
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    ///return knapsack(A.size(), C, A , B);
    int n = A.size();
    int dp[n+1][C+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=C;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else if(B[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                int inc = A[i-1] + dp[i-1][j - B[i-1]];
                int exl = dp[i-1][j];
                dp[i][j] = max(inc, exl);
            }
        }
    }
    return dp[n][C];
}
