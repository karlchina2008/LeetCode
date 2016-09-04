/*
Given two 1d vectors, implement an iterator to return their elements alternately.
*/
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        _v1=v1;_v2=v2;pos1=pos2=count=0;
    }

    int next() {
        //cout<<pos1<<" "<<pos2<<endl;
        if(pos1==_v1.size() or (pos2<_v2.size() and count==1)) {count=0;return _v2[pos2++];}
        if(pos2==_v2.size() or (pos1<_v1.size() and count==0)) {count=1;return _v1[pos1++];}
        return 0;
    }

    bool hasNext() {
        if(pos1>=_v1.size() and pos2>=_v2.size()) return false;
        return true;
    }
private:
    vector<int> _v1,_v2;
    int pos1,pos2,count;
};
