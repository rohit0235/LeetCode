class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        map<int,pair<int,int>> mp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp.insert({mat[i][j],{i,j}});
            }
        }
        vector<int> a(m,0),b(n,0);
        for(int i=0;i<arr.size();i++)
        {
            int key=arr[i];
            auto it=mp.find(key);
            if(it!=mp.end())
            {
               
                a[mp[key].first]++;
                b[mp[key].second]++;
                if(a[mp[key].first]==n ||
                b[mp[key].second]==m) return i;
            }

           
        }
        return -1;
    }
};
 