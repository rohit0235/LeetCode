class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       
       sort(nums.begin(),nums.end());
         int n=nums.size();
       int oper=0;
       int i=0;
       int j=n-1;
       while (i<j){
           int sum=nums[i]+nums[j];
           if (sum==k) {
            oper++;
            i++;
            j--;
           }

           else if (sum<k){
                 i++;
           }

           else{
                j--;
           }
           
       }
       
       return oper++;







    //     unordered_map<int,int>mp;
    //    int maxo=0;
    //     for (int i:nums){
    //             if (i>=k) continue;
    //             if (mp.find(abs(i-k))!=mp.end()){
    //                 cout<<i<<" "<<k<<endl;
    //                  maxo++;
    //                   mp[abs(i-k)]--;
    //                   if (mp[abs(i-k)]<=0){
    //                     mp.erase(abs(i-k));
    //                   }
    //             }
    //             else{
    //                 mp[i]++;
    //             }
    //     }
    //     return maxo;



    }
};