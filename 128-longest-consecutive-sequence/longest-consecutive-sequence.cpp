class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        
               int len=1;
               int maxi=0;
               if (nums.size()==0) return false;
               if (nums.size()==1) return true;
               set<int>s;
                 for (int i=0;i<nums.size();i++){
                          s.insert(nums[i]);
                 }
                 
                 for (auto i:s){
                   
                           if (s.find(i+1)!=s.end()){
                                  len+=1;
                           }
                           else{
                                len=1;
                           }
                           maxi=max(maxi,len);


                 }

                 return maxi;



            //    map<int,int>mp;
            //     int n=nums.size();
            //    for (int i=0;i<n;i++) mp[i]++;

            //    for(auto i:mp){
            //             if ()
            //    }




    }
};