//https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-104/problems/#
long double density(int N, vector<int> par)
    {
        vector<int> dp(N,0);
        dp[0] = 1;
        for(int i=1;i<N;i++)
        {
            dp[i] = dp[par[i]]+1;
        }
        int mx = 0;
        for(int i=0;i<N;i++)
        {
            mx = max(mx,dp[i]);
        }
        long double den = (long double)N/mx;
        return den;
        
    }
