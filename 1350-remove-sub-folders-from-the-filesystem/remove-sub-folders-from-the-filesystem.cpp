class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
          int n=folder.size();
        vector<string> s;
        sort(folder.begin(),folder.end());
        
        s.push_back(folder[0]);
      
        for (int i = 1; i < n; i++){
     
            string lastAdded = s.back();
            if (folder[i].find(lastAdded + "/") != 0) {
                s.push_back(folder[i]);
            }
        }
        return s;
              
    }
};