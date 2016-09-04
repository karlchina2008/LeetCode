/*
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
*/
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        _vec2d=vec2d;v_pos=cur=0;n=vec2d.size();
        for(int i=vec2d.size()-1;i>=0;i--){
            if(vec2d[i].size()!=0) break;
            n--;
        }
        //cout<<"here"<<endl;
    }

    int next() {
        if(cur<_vec2d[v_pos].size()) return _vec2d[v_pos][cur++];
        else{
            cur=0;v_pos++;
            return next();
        }
    }

    bool hasNext() {
        if(n==0 or (v_pos==n-1 and cur==_vec2d[n-1].size())) return false;
        return true;
    }
private:
    vector<vector<int>> _vec2d;
    int v_pos,cur,n;
};
