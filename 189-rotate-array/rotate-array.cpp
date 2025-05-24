class Solution {
public:
    void rotate(vector<int>& nums, int k) {
                
            int n =nums.size();
            k=k%n;

            k =n-k;
            reverse(nums.begin(),nums.begin()+k);
            reverse(nums.begin()+k,nums.end());
            reverse(nums.begin(),nums.end());


 
 

           
            //  int n=nums.size();
            //  k=k%n;
            //    reverse(nums.begin(),nums.end()-k);
            //    reverse(nums.end()-k,nums.end());
            //    reverse(nums.begin(),nums.end());
    }
};