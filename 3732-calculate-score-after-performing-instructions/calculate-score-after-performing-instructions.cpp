class Solution {
public:
    long long calculateScore(vector<string>& inst, vector<int>& values) {
          
           long long ans =0;
           long long i=0;
           long long n = inst.size();
           vector<bool>vis(n,0);
            
           while (i<n && i>=0){
                if(vis[i]) break;
                vis[i]= true;
                if(inst[i]=="jump"){
                     i+=values[i];
                }
                else{
                    ans+=values[i];
                    i++;
                }

           }
           return ans;

    }
};