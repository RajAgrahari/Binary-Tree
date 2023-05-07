//https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/
void helper(int p,int v,int n,vector<int>& cost,vector<int>& vp)
    {
        if(p >= n)
        return;
        vp[p] = v + cost[p];
        helper(2 * p + 1, vp[p], n, cost, vp);
        helper(2 * p + 2, vp[p], n, cost, vp);
    }
    int helper2(int l,int r,int n,vector<int>& vp,int mv)
    {
        if(l > r)            
        return 0;
        int mx = INT_MIN;
        for(int i=l;i<r+1;i++)
        mx = max(mx,vp[i]);
    
        int ans = mv-mx;

        for(int i=l;i<r + 1;i++)
        {
            vp[i] += mv-mx;
        }

        if(l!=r)
        {
            int m = (l + r)/2;
            ans += helper2(l, m, n, vp, mv);
            ans += helper2(m + 1, r, n, vp, mv);
        }
        return ans;
    }
    int minIncrements(int n, vector<int>& cost) 
    {
        vector<int> vp(n,0);
        helper(0, 0, n, cost, vp);
        int mv = INT_MIN;
        for(int i=(n/2);i<n;i++)
        mv = max(mv,vp[i]);


        int ans = helper2(n/2,n-1,n,vp,mv);

        return ans;
    }
