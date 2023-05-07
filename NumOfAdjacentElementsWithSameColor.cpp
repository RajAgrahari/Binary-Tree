//https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/
 vector<int> colorTheArray(int n, vector<vector<int>>& queries) 
    {
        unordered_map<int,int> mp;
        int m = queries.size();
        int cnt=0;
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            int idx = queries[i][0];
            if(idx>0 && mp[idx]!=0 && mp[idx-1]==mp[idx])
            {
                cnt--;
            }
            if(idx<n-1 && mp[idx]!=0 && mp[idx+1]==mp[idx])
            {
                cnt--;
            }
            int c= queries[i][1];
            mp[idx]=c;
            if(idx>0 && mp[idx-1]==c)
            {
                cnt++;
            }
            if(idx<n-1 && mp[idx+1]==c)
            {
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
            
    }
