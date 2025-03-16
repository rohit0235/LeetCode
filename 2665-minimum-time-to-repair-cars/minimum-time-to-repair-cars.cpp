class Solution {
public:
   bool ispossible(vector<int>& ranks, long long  mid,long long  totalCars){
             long long carsRepaired = 0;

        for (int i = 0; i < ranks.size(); i++) {
            // Max cars mechanic i can repair in 'mid' time
            long long maxCars = sqrt(mid / (double)ranks[i]);
            carsRepaired += maxCars;
            if (carsRepaired >= totalCars) return true;  // Early exit
        }
        return false;
   }
  
    long long repairCars(vector<int>& ranks, int cars) {
            
            // 4 2 3 1   cars=10
            
  long long int minimum=min_element(ranks.begin(),ranks.end())-ranks.begin();
 long long    int maximum=max_element(ranks.begin(),ranks.end())-ranks.begin();

                long long l = 1;
        long long r = (long long)(*min_element(ranks.begin(), ranks.end())) * (long long)cars * cars;
        long long ans = -1;
        
           while (l<=r){
                 
                 long long  mid = l+(r-l)/2;

                 if (ispossible(ranks,mid,cars)){
                         ans=mid;
                         r=mid-1;
                 }
                 else{
                    l=mid+1;
                 }
           }
           
           return ans;
         
              
    }

};