class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // 2 3 4 6
        // 6 8 12  12 18  24 

        // 2 4 5 10 8 10 20 20 40 50

        // 10 10 se comb - 8
        // 20 20 -8 

        unordered_map<int,int>mp;
        int n=nums.size();
         int count=0;
        for (int i=0;i<n;i++){

            for (int j=i+1;j<n;j++){
                  int check=nums[i]*nums[j];
                  if (mp.find(check)!=mp.end()){
                        count+=mp[check]*8;
                  }
                  mp[check]++;
            }
        }


        return count;

    }
};