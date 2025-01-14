class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
         
         vector<int>ans;
         set<int>s;
         int count=0;
         for (int i=0;i<A.size();i++){
               if (!s.insert(A[i]).second){
                   count++;
               }
               s.insert(A[i]);
               if (!s.insert(B[i]).second){
                   count++;
               }
             s.insert(B[i]);

               ans.push_back(count);
         }
         return ans;
    }
};