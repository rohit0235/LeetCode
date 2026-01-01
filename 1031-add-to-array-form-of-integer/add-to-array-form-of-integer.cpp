class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
         int n = num.size();
         int i=n-1;
         int carry =0;
         while (k>0 && i>=0 ){ 
              int rem=k%10;
              k=k/10;
              int sum = rem+num[i]+carry;
              num[i]=sum%10;
              i--;
              
              if (sum>=10){
                 carry =1;
              }else{
                 carry =0;
              }
         }

       while ((carry==1 && i>=0)) {
          int sum = num[i]+carry;

            num[i]=sum%10;
            if (sum>=10) carry=1;
            else carry=0;

            i--;
         }
         while (k && i<0){
            // cout<<"ok"<<endl;
            int sum =(k%10)+carry;
            if (sum>=10 )carry=1;
            else carry=0;
             num.insert(num.begin(),sum%10);
             k=k/10;
         }
         if (carry==1 && i<0)num.insert(num.begin(),1);
         return num;

    }
};