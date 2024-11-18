  bool uniqueOccurrences(vector<int>& arr) {
        
         unordered_map<int,int>mp;
         for (int i:arr) mp[i]++;  
          set<int>S;
         for (auto i:mp){

         
            if (!S.insert(i.second).second){
                      return false;
            }
            else{
                S.insert(i.second);
            }
         }
         return true;




    }
