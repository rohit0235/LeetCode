class Solution {
public:
    int bestClosingTime(string customers) {
        // open and no customer , closed and customer came

  
         int y=0;
         int n=0;

       for(char i:customers){
         if (i=='Y') y++;
       }
        // int count =0;
        int mini =INT_MAX;
        int ans =0;
        if (y==0) return 0;
       for(int i=0;i<customers.size();i++){
              
             int  count=y+n;
              if (count<mini){
                     mini = count;
                     ans =i;
              }
             cout<<count<<endl;
              if (customers[i]=='Y')y--;
              if (customers[i]=='N')n++;
              


       }
       if (y+n<mini){
         ans =customers.size();
       }
   
    //   if (ans==customers.size()-1) return customers.size();
       return ans;

    }
};