/*
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger*> nstack;
        int i=0;
        while(i<s.size()){
            if(s[i]=='['){
                nstack.push(new NestedInteger());i++;
            }
            else if(s[i]==',') i++;
            else if(s[i]<='9' and s[i]>='0'){
                string temp="";
                while(s[i]<='9' and s[i]>='0' and i<s.size()) temp.push_back(s[i++]);
                //cout<<temp<<endl;
                if(nstack.empty()) return stoi(temp);
                else{
                    auto top=nstack.top();
                    top->add(NestedInteger(stoi(temp)));
                }
            }
            else if(s[i]=='-'){
                string temp="";i++;
                while(s[i]<='9' and s[i]>='0' and i<s.size()) temp.push_back(s[i++]);
                //cout<<temp<<" "<<i<<endl;
                if(nstack.empty()) return -stoi(temp);
                else{
                    auto top=nstack.top();
                    top->add(NestedInteger(-stoi(temp)));
                }
            }
            else{
                auto top=nstack.top();nstack.pop();
                if(nstack.empty()){
                    return *top;
                }
                else{
                    auto top_1=nstack.top();
                    top_1->add(*top);
                }
                i++;
            }
        }
        
        return NULL;
        
    }
};
