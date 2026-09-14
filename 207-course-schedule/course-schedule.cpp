class Solution {
public:
    bool isCycledfs(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& edges){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if(u == src){
                if(!vis[v]){
                    if(isCycledfs(v, vis, recPath, edges)){
                        return true;
                    }
                    }else if(recPath[v]){
                        return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(isCycledfs(i, vis, recPath, edges)){
                    return false;//if cycle exits
                }
            }
        }
        return true;//if cycle not exist
    }
};