class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
           sort(tasks.rbegin(),tasks.rend());
           sort(processorTime.begin(),processorTime.end());

           int ans =0;
        //    for(int i=1;i<tasks.size();i++) tasks[i]+=tasks[i-1];

            int n = tasks.size();
            int j = 0;
           for(int i=0;i<n;i+=4){
                  int idx = i-1;
                //   int sum = tasks[idx];
                //   if(idx-4>=0){
                //         sum-=tasks[idx-4];
                //   }
                //   cout<<sum<<endl;
                //    ans+=sum+processorTime[j]*4;
                //    j++;
                ans = max(ans , tasks[i]+processorTime[j]);
                j++;
           }

           return ans;
    }
};