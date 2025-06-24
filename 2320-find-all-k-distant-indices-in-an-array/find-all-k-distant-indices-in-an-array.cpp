class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
                
                int n =nums.size();
                // k-i>=j

                vector<int>idx;
                for(int i=0;i<n;i++) if (nums[i]==key) idx.push_back(i);

        


              
            vector<int>ans;

            for(int i=0;i<n;i++){
                 
                  
                   for(int j=0;j<idx.size();j++){
                         
                       if (abs(i-idx[j])<=k){  
                         ans.push_back(i);break;
                       }
                     
                   }
            }

        //         for(int j=0;j<n;j++){
                      
        //                 int diff = abs(k-j);

        //   int lowerbound = lower_bound(idx.begin(),idx.end(),diff)-idx.begin();

        //                 if (lowerbound<idx.size()) ans.push_back(j); 
                      
        //         }

          return ans;

                

                
    }
}; 