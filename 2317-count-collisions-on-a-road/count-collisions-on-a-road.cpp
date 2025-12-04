class Solution {
public:
    int countCollisions(string directions) {
        // "LRSLRS"
        // "RSLLRSL"
        //  "LSR"  

        int i=0;
        int j=directions.size()-1;
        while (i<=j){
             if (directions[i]=='L')i++;
             if (directions[j]=='R')j--;
             else if (directions[i]!='L' && directions[j]!='R')break;
             
        }
        cout<<i<<" "<<j<<endl;
        int ans =0;
        while (i<=j){
             if (directions[i]!='S') ans++;
             i++;
        }
        return ans;
    }
};