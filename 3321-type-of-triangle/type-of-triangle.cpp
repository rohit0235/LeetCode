class Solution {
public:
    string triangleType(vector<int>& nums) {
           
          int a=nums[0];
          int b=nums[1];
          int c=nums[2];
          
          if (a+b<=c || b+c<=a || a+c<=b) return "none";

           if (nums[0]==nums[1] && nums[0]==nums[2]) return "equilateral";

           if (nums[0]!=nums[1] && nums[1]!=nums[2] && nums[2]!=nums[0]){
                     return "scalene";
           }
          
           return "isosceles";
 

    }
};