class Solution {
public:

    bool isCyclic(int curr, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& edges){
        vis[curr] = true;
        recPath[curr] = true;

        for(int i = 0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == curr){
                if(!vis[v]){
                    if (isCyclic(v, vis, recPath, edges)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[curr] = false;
        return false;
    }

    void topo(int curr, vector<bool>&vis, stack<int> &s, vector<vector<int>>& edges){
        vis[curr] = true;

        for(int i =0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == curr){
                if(!vis[v]){
                    topo(v, vis, s, edges);
                }
            }
        }
        s.push(curr);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;//it's empty here
        stack<int>s;

        for(int i= 0; i< n; i++){
            if(!vis[i]){
                if(isCyclic(i, vis, recPath, edges)){
                    return ans;//which is empty in cyclic
                }
            }
        }

        //Topological sorting
        vis.assign(n, false);

        for(int i= 0; i< n; i++){
            if(!vis[i]){
                topo(i, vis, s, edges);
            }
        }
        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};