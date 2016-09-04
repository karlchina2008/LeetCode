/*
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.
*/
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        record.emplace_back(0,0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if(record.empty())
            record.emplace_back(timestamp,1);
        else{
            if(timestamp==record.back().first)
                record[record.size()-1].second++;
            else
                record.emplace_back(timestamp,record.back().second+1);
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int begin_time=timestamp-300;
        auto it=lower_bound(record.begin(),record.end(),begin_time,[](pair<int,int> a,int b){return a.first<b;});
        if((*it).first==begin_time)
            return record.back().second-(*it).second;
        else{
            return record.back().second-(*(--it)).second;
        }
    }
private:
    vector<pair<int,int>> record;
};
