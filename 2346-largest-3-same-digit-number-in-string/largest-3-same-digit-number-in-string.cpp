class Solution {
public:
    string largestGoodInteger(string num) {
            string ans ="";
        //   unordered_map<char,int>mp;

        //   for(int i=0;i<3;i++)mp[num[i]]++;
        //   if (mp.size()==1){
        //          string k = num.substr(0,3);
        //          ans =k;
        //   }
          
         int n = num.size();
        //   for(int i=3;i<n;i++){
                  
        //           mp[num[i-3]]--;
        //           if (mp[num[i-3]]==0) mp.erase(num[i-3]);
        //           mp[num[i]]++;
        //                 //  cout<<mp.size();
        //           if (mp.size()==1){
        //                 string k = num.substr(i-2,3);
        //             //    cout<<ans<<" ";
        //                 if (ans<k){
        //                      ans =k;
        //                 }  
        //           }
                

        //   }

             int i=0;
             int j=1;
             int k=2;

             while (k<n){
                 
                     if (num[i]==num[j] && num[j]==num[k]) {
                             string k = num.substr(i,3);
                             if (ans<k)ans=k;
                     } 

                     i++;
                     j++;
                     k++;
                 
                    
             }



          return ans; 
      


             
    }
};