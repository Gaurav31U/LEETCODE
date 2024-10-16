int n;
class Graph {
public:
    long long grp[101][101];
    int mx=1e9;
    Graph(int n, vector<vector<int>>& edges) {
        ::n=n;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                grp[i][j]=mx;
            }
        }
        for(int i=0;i<=n;i++)grp[i][i]=0;
        for(auto it:edges){
            grp[it[0]][it[1]]=it[2];
        }
        for(int k=0;k<=n;k++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if (grp[i][j] > (grp[i][k] + grp[k][j])
                    && (grp[k][j] != mx
                        && grp[i][k] != mx))
                    grp[i][j] = grp[i][k] + grp[k][j];
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        int i=edge[0];
        int j=edge[1];
        grp[i][j]=edge[2];
         for(int k=0;k<=n;k++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if (grp[i][j] > (grp[i][k] + grp[k][j])
                    && (grp[k][j] != mx
                        && grp[i][k] != mx))
                    grp[i][j] = grp[i][k] + grp[k][j];
                }
            }
        }
            
        
    }
    
    int shortestPath(int node1, int node2) {
        if(grp[node1][node2]==mx)return -1;
        return grp[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */