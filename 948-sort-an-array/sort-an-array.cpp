class Solution {
public:
   
    static bool myc(int a ,int b){
     return a<b;
    }
    
    vector<int> sortArray(vector<int>& vec) {
             sort(begin(vec),end(vec),myc);
             return vec;
    }
};