const int xoxo = 100010;
class Solution {
public:
   int white=0,grey=1,black=2;
    bool backEdgeFound=false;
    
    // node not visited -> white
    // node entered for current dfs -> grey
    // node has been visted by some dfs -> black
    
    void dfs(int i,int visited[],vector<int> adjList[]){
        if(backEdgeFound) return;
        visited[i] = grey;
        for(int j=0;j<adjList[i].size();j++){ // iterate through adjacency list
            int v = adjList[i][j];// child node 
            if(visited[v]==white)
                dfs(v,visited,adjList);
            else if(visited[v]==grey)// back edge present; v is already part of current dfs thread.
                backEdgeFound=true;
        }
        visited[i]=black;
    }
    
    
    
    bool canFinish(int n, vector<vector<int>>& p) {
        int visited[n]; memset(visited,white,sizeof(visited));
        vector<int> adjList[n];        
        int len = p.size();
        // make adjacency list
        for(int i=0;i<len;i++){
            adjList[p[i][0]].push_back(p[i][1]);
        }
        
        for(int i=0;i<n;i++){// run dfs for each non visited node.
            if(visited[i]==white){
                dfs(i,visited,adjList);
                if(backEdgeFound) return false;
            }
        }
        return true;
    }
    
};
