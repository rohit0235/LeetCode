class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        
                //   int min1= *min_element(nums1.begin(),nums1.end());
                //   int min2= *min_element(nums2.begin(),nums2.end());
                //   int max1= *max_element(nums1.begin(),nums1.end());
                //   int max2= *max_element(nums2.begin(),nums2.end());

                //     int diff = min1-min2;
                //     int diff2 = min1-min2;


                int sum1 = accumulate(nums1.begin(), nums1.end(),0);
                int sum2 = accumulate(nums2.begin(), nums2.end(),0);
                   
                if (sum1<=sum2)return (sum2-sum1)/nums1.size();
               else return -1*( (sum1-sum2)/nums1.size());
    }  
};