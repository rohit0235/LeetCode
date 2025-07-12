class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
             
             int n =nums.size();
             // ok we have vote 0 canditatate =-1;
             
             int canditate1 = -1;
             int canditate2 = -1;
             int votes1=0;
             int votes2=0;

             for(int i:nums){
                 
          

                  if (i==canditate1){
                     votes1++;
                   }
              
                  else if (i==canditate2){
                     votes2++;
                   }
                 else    if (votes1==0){
                        canditate1 = i;
                        votes1++;
                   }
                  else  if (votes2==0){
                        canditate2 = i;
                        votes2++;
                   }
                   else{
                     votes1--;
                     votes2--;
                   }
              
                   
             }
             
             int count1 =0;
             int count2 =0;
             for(int i:nums){
                 if (i==canditate1) count1++;
               else  if (i==canditate2) count2++;
             }
               vector<int>res;
             if (count1>n/3) res.push_back(canditate1);
             if (count2>n/3) res.push_back(canditate2);

                    return res;
    }
};