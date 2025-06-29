class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
              
               int n =nums2.size();
             vector<int>nextgreater(n,-1);
          stack<int>pq;

            //  pq.push(-1);
            //  nextgreater[n-1]=-1;

             for(int i=n-1;i>=0;i--){
                      
                      while  (!pq.empty() && nums2[i]>=pq.top()){
                      
                             pq.pop();
                          
                      }
                     
                      if (pq.empty()){
                          nextgreater[i]=-1;
                      }
                      else{
                          nextgreater[i]=pq.top();
                      }
                       pq.push(nums2[i]);

             }
     
             for(int i:nextgreater) cout<<i<<endl;
             unordered_map<int,int>mp;

              for(int i=0;i<n;i++){
                mp[nums2[i]]=i;
             }

             vector<int>ans;
             for(int i:nums1){
                if (i<nextgreater[mp[i]])
                 ans.push_back(nextgreater[mp[i]]);
                 else            ans.push_back(-1);
             }
               return ans;


          
    }
};