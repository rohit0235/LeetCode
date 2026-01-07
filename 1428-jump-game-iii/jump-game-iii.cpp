class Solution {
public:
      
 
    int solve(vector<int>&arr , int n , int start){
       if (start < 0 || start >=n|| arr[start] < 0) return false;
       if (arr[start] == 0) return true;
        arr[start] = -arr[start];
        
        return solve(arr, n,start + arr[start]) || 
               solve(arr,n, start - arr[start]);

    }

    bool canReach(vector<int>& arr, int start) {
     int    n = arr.size();

         return solve(arr, n, start);
    }
};