class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;
        //stores topological sort
        
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int> ());
        
        
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]); //directec par->child
            indegrees[it[0]]++;
        }
        
        //bfs
        queue<int> q;
        
        for(int i=0; i<indegrees.size(); i++)
        {
            if(indegrees[i] == 0)
                //start of bfs
                q.push(i);
        }
        
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            res.push_back(u);
            
            for(auto it : adj[u])
            {
                indegrees[it]--;
                
                if(indegrees[it] == 0)
                {
                    //reached end node
                    q.push(it);
                }
            }
            
            
        }
        
        
        if(res.size() == numCourses)
            return res;
        else
            //empty vector
            return vector<int> ();
        
    }
};
