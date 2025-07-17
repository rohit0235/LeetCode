class Solution {
public:
    int compareVersion(string version1, string version2) {
             
             int n =version1.size();
             int m = version2.size();
                 int i=0;
                 int j=0;
             while (i<n && j<m){
                  
                        string temp1="";
                        string temp2="";
                        while (i<n && version1[i]!='.'){
                             temp1.push_back(version1[i]);
                             i++;
                        }
                        while (j<m && version2[j]!='.'){
                             temp2.push_back(version2[j]);
                             j++;
                        }
                        //  cout<<temp1<<" "<<temp2;
                        int t1 = stoi(temp1);
                        int t2 = stoi(temp2);
                        
                        if (t1<t2) return -1;
                        if (t1>t2) return 1;
                        
                        i++;
                        j++;
                        if (i==m && j==n){
                             return 0;
                        }
                  
             }


                        while (i<n ){

                            if (version1[i]!='.' && version1[i]!='0'){
                                 return 1;
                            }

                             i++;
                        }

                        while (j<m ){

                            if (version2[j]!='.' && version2[j]!='0'){
                                 return -1;
                            }

                             j++;
                        }

                        return 0;
    }
};