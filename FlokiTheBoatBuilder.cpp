//https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-104/problems/#
bool find(int s,int d,vector<int> adj[])
    {
        if(s==d)
        return true;
        for(auto it:adj[s])
        {
            if(find(it,d,adj))
            return true;
        }
    }
    void dfs(int s,int& g,vector<int> adj[],vector<int>& val)
    {
        g = __gcd(g,val[s]);
        for(auto it:adj[s])
        dfs(it,g,adj,val);
    }
	int gcdTree(int n, vector<vector<int>> &edges, vector<int> &val, int x, int y)
	{
		vector<int> adj[n];
		for(int i=0;i<edges.size();i++)
		{
		    adj[edges[i][0]].push_back(edges[i][1]);
		}
		if(find(x,y,adj) || find(y,x,adj))
		return -1;
		int gX = 0,gY = 0;
		dfs(x,gX,adj,val);
		dfs(y,gY,adj,val);
		return __gcd(gX,gY);
	}
