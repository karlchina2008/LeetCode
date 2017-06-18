/*
Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input:

48 
Output:
68
Example 2
Input:

15
Output:
35
*/
class Solution {
public:
    int smallestFactorization(int a) {
        if(a <= 9) return a;
        signed max_int = (1<<31) - 1;
        //cout << max_int << endl;
        long long res = 0;
        int data[10] = {0};
        for(int i = 9; i >=2; i--){
            if(a == 1) break;
            int count = 0;
            while(a%i == 0){
                a = a/i;
                count++;
            }
            data[i] = count;
            //cout << data[i] << " " << a << endl;
        }
        if(a != 1) return 0;
        //cout <<"here" << endl;
        for(int i = 2; i <=9; i++){
            if(data[i] > 0){
                for(int j = 0; j < data[i]; j++){
                    res = res*10 + i;
                    if(res > max_int) return 0;
                }
            }
            //cout << data[i] << endl;
        }
        return res;
    }
    
};
