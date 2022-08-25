 int dijkstra(vector<vector<int>>& edges,int source)
    {
        
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(n,INT_MAX);//0-indexed array for calculating shortest paths
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,source)
        while( !pq.empty() ){
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            vector<pair<int,int> >::iterator it;
            for( it = g[prev].begin() ; it != g[prev].end() ; it++){
                int next = it->first;
                int nextDist = it->second;
                if( distTo[next] > distTo[prev] + nextDist){
                    distTo[next] = distTo[prev] + nextDist;
                    pq.push(make_pair(distTo[next], next));
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=disTo[i];
        return sum;
            
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v[i] = dijkstra(edges,i);
        }
        return v;
    }