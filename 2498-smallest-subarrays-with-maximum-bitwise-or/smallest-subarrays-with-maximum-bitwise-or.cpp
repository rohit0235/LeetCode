class Solution {
public:
vector<int>setBit;
int checkBit(int &num, int &idx){
    int endIdx=idx;
    for(int i=0;i<32;i++){
    if(num & (1<<i)){
setBit[i]=idx;
    }  
    else{
       endIdx=max(endIdx,setBit[i]);
    }
     }
    return endIdx;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
int endIdx=0;              setBit.resize(32, -1);
//vector<int>setBit(32,-1);
vector<int>answer(n,0);
for(int i=n-1;i>=0;i--){
endIdx=checkBit(nums[i],i);
    answer[i]=endIdx-i+1;
}
    return answer;
    }
};