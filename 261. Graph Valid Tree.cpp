/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
*/
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> size(n,0);
        vector<int> id(n,0);
        for(int i=0;i<n;i++){
            id[i]=i;
        }
        for(auto edge:edges){
            int i=edge.first,j=edge.second;
            while(id[i]!=i){id[i]=id[id[i]];i=id[i];}
            while(id[j]!=j){id[j]=id[id[j]];j=id[j];}
            if(i==j) return false;
            if(size[i]>size[j]){
                id[j]=i;size[i]+=size[j];
            }
            else{
                id[i]=j;size[j]+=size[i];
            }
        }
        //cout<<"here"<<endl;
        int count=0;
        for(int i=0;i<n;i++){
            //cout<<id[i]<<" "<<i<<endl;
            if(id[i]==i) count++;
            if(count>1) return false;
        }
        return true;
    }
};
