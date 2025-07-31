class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
             
             unordered_set<int>curr;  
             unordered_set<int>prev;  
             unordered_set<int>result;


             for(int i:arr){
                      
                        for(const int &x:prev){
                               result.insert(i | x);
                               curr.insert(i | x);
                        }

                        curr.insert(i);
                        result.insert(i);
                       
                        prev=  curr;

                        curr.clear();
                   
             }  


             return result.size();
    }
};