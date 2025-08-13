class Solution {
public:

unordered_map<string , int>mp;

bool ispos(string a, string b){
     
          vector<int>t1(26,0);
          vector<int>t2(26,0);
         
          for(char i:a) t1[i-'a']++;
          for(char i:b) t2[i-'a']++;
           
          for(int i=0;i<26;i++){
               if (t1[i]>0 &&  t2[i]>0 || t1[i]>1 || t2[i]>1) return true;
          }

          return false;

}

    int solve(vector<string>&arr , int n, string temp , int i ){
            
             if (i>=n)  return temp.length();
            if (mp.find(temp)!=mp.end())  return mp[temp];
             int inc=  0;
             int exc =0;

             if (ispos(arr[i],temp)){
                  exc = solve(arr,n,temp,i+1);
             }
             else{
                   exc = solve(arr,n,temp,i+1);
                   inc = solve(arr, n , temp+arr[i], i+1);
             }

             return mp[temp]=max(inc , exc);
           
            
    }
    int maxLength(vector<string>& arr) {
            
             int n =arr.size();
             string temp = "";
             int i=0;
             return solve(arr, n, temp , i);
    }
};