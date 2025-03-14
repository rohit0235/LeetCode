class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
            
            // 5 8 6 
            // 
            int n =candies.size();
            int maxi=*max_element(candies.begin(),candies.end());
            // cout<<maxi;
              
            sort(candies.begin(),candies.end());
            int low=1;
            int high=maxi;
            int ans=0;
            while(low<=high){
                int mid=low+(high-low)/2;
                     long long count=0;
                    for(int j=n-1;j>=0;j--){
                        if (candies[j]<mid) break;
                           count+=candies[j]/mid;
                        //    if (count>=k) return i;
                    }
                    
                    if(count<k){
                          high=mid-1;
                    }
                    else{
                        ans=mid;
                        low=mid+1;
                    }
                   
            }

            return ans;
    }
};