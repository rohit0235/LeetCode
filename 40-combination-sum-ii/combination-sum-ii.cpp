class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>&curr,vector<int>&candidates,int target,int i){
                if (target<0){
                    return ;
                }
               if (target==0){
                      result.push_back(curr);
                      return ;
               }
            //    int n=;
               for(int j=i;j<candidates.size();j++){
                     
                     if (j>i && candidates[j]==candidates[j-1]) continue;

                     curr.push_back(candidates[j]);
                     solve(curr,candidates,target-candidates[j],j+1);
                     curr.pop_back();

               }






    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
             vector<int>curr;
             sort(candidates.begin(),candidates.end());
             solve(curr,candidates,target,0);

             return result;
                


    }
};