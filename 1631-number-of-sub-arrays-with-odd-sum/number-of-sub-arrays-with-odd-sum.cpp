class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
         const int MOD = 1e9 + 7;
        // int n=arr.size();
        // int sum=accumulate(arr.begin(),arr.end(),0);

        // int e,o=0;
        // for (int i:arr){
        //     if (i%2==0) e++;
        //     else o++;

        // }
         
        // if (sum%2==0) 




        //  int count=0;
        // int n =arr.size();

        // for (int i=0;i<n;i++){
        //        int local=0;
        //      for (int j=i;j<n;j++){
        //             local+=arr[j];

        //             if (local%2!=0) {
        //                  count++;
        //             }
        //      }

        // }

        // return count%1000000007;



        int sum=arr[0];
        int count=0;
        int even=1;
        int odd=0;
        int n=arr.size();
        if (arr[0]%2==1){
            count=1;        
            odd++;
        } 
        else even++;
        for (int i=1;i<n;i++){
                // if (arr[i]%2==1) count++;
                sum+=arr[i];
                if (sum%2!=0) {
                    count =(count+even)%MOD;
                    odd++;
                }
                else{
                  count =(count+odd)%MOD;
                    even++;
                }
        }
        
        return count%MOD;

    }
};