class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            int n = digits.size();
            int carry=1;

            for(int i=n-1;i>=0;i--){
                   int sum = digits[i]+carry;
                   if (sum>=10){
                 
                       carry=1;
                   }else{
                     carry =0;
                   }
                         digits[i]=sum%10;
            }
            if (carry==1){ 
                  digits.insert(digits.begin(),1);
            }
            return digits;
    }
};