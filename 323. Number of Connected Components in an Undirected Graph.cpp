/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to find the number of connected components in an undirected graph.
*/
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> id(n,0);
        vector<int> size(n,1);//
        for(int i=0;i<n;i++)
            id[i]=i;
        for(auto edge:edges){
            int i=edge.first,j=edge.second;
            while(id[i]!=i) {id[i]=id[id[i]];i=id[i];}
            while(id[j]!=j) {id[j]=id[id[j]];j=id[j];}
            if(i==j) continue;
            else{
                if(size[i]>size[j]){
                    id[j]=i;
                    size[i]+=size[j];
                }
                else{
                    id[i]=j;
                    size[j]+=size[i];
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
            if(id[i]==i) count++;
        return count;
    }
};
