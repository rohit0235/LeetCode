class Solution {
public:
    bool isValid(string num, int target){
        if(num== "" && target==0) return true;
        if(target<0) return false;
        for(int i=0;i<num.size();i++){
            if(isValid(num.substr(i+1), target- stoi(num.substr(0,i+1)))) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum=0;
        if(n<9) return 1;
        for(int i=9;i<=n;i++){
            int val = i*i;
            if(isValid(to_string(val),i)){
                sum+=val;
            }
        }
        return sum+1;
    }
};