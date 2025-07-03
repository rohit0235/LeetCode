class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
            

             int f=0;
             int s=0;
             int n =nums.size();
             unordered_map<int,int>mp;
             for(int i:nums){
                     mp[i]++;
             }

             for(auto i:mp){
                 if (i.second%2==0)  f+=i.second/2;
                 if (i.second%2!=0)  {f+=i.second/2 ;s++;}
             }


             return {f,s};


    }
};