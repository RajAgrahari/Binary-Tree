//https://practice.geeksforgeeks.org/problems/fbcd1787378ed396a8f24b47872cbc0ad2624f1d/1
int dfs(int node,int ctr,vector<int> adj[])
    {
        int temp = adj[node].size()>1?1:0;
        for(auto it:adj[node])
        {
            if(it!=ctr)
            {
                temp += dfs(it,node,adj);
            }
        }
        return temp;
    }
    int solve(int N, vector<int> p)
    {
        vector<int> adj[N];
        for(int i=1;i<N;i++){
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
        
        int ctr=0;
        for(int i=1;i<N;i++)
        {
            if(adj[i].size()>adj[ctr].size()) ctr=i;
        }
        
        int ans=0;
        for(auto x:adj[ctr])
        {
            if(adj[x].size()>1)
            {
                ans+=dfs(x,ctr,adj);
            }
        }
        return ans;
    }
