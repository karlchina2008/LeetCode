/*
Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

Example 1:
Input: 
pid =  [1, 3, 10, 5]
ppid = [3, 0, 5, 3]
kill = 5
Output: [5,10]
Explanation: 
           3
         /   \
        1     5
             /
            10
Kill 5 will also kill 10.
*/
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>> mymap;
        for(int i = 0; i < ppid.size(); i++){
            mymap[ppid[i]].push_back(pid[i]);
        }
        vector<int> res = {kill};
        helpfind(mymap,kill,res);
        return res;
    }
    void helpfind(unordered_map<int,vector<int>>& mymap,int kill,vector<int>& res){
        if(mymap.count(kill) == 0) return;
        vector<int> temp = mymap[kill];
        for(auto p : temp){
            res.push_back(p);
            helpfind(mymap,p,res);
        }
    }
};
