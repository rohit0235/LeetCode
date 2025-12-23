class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        //    if (goal.size()!=s.size()) return false;

        if ((a).find(b)!=string::npos){
              return 1;
        }
        // if (a.size()>b.size()) return -1;
        int n = a.size();
        int m = b.size();
        int k =  (m+n-1)/n;
        cout<<k<<endl;
       int count =1;
       string j =a;
        while (k--){
                a=a+j;
                count++;
                // cout<<a<<endl;
                if ((a).find(b)!=string::npos){
                    return count;
                }

        }

        return -1;
    }
};