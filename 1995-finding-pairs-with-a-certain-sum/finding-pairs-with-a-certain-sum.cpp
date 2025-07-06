class FindSumPairs {
public:
  
      vector<int>a;
      vector<int>b;
      unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
         
          a =nums1;
          b =nums2;
               for(int i:b) mp[i]++;
       
    }
    
    void add(int index, int val) {
          
          int ele = b[index];
          mp[ele]--;
          if (mp[ele]==0) mp.erase(ele);
          int d=ele+val;
          b[index]+=val;
           mp[d]++;
    }
    
    int count(int tot) {
          int c =0;
          for(int i:a){
              
                //  if (mp.find(i-tot)!=mp.end()){
                     c+=mp[tot-i];
                //  }
                
          }

          return c;
         
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */