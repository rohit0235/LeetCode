       int i=0;
        int j=nums.size()-1;
        vector<int>res;
        while (i<=j){
            if (abs(nums[i])>=abs(nums[j])){
                   res.push_back(nums[i]*nums[i]);
       
                   i++;
            }
            else{
                    res.push_back(nums[j]*nums[j]);
 
                   j--;
            }

        }
       reverse(res.begin(),res.end());
         return res;
