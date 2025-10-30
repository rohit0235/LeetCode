class Solution {
public:
    int minNumberOperations(vector<int>& target) {
            
            int n =  target.size();
            int op=0;
            int prev=0;
            for(int i:target){
                  op+=max(0,i-prev);
                  prev= i;
            }
            return op;

    }
};