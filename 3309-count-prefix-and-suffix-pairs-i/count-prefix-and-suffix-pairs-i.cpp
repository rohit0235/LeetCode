class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){
            int k =str1.size();
            int n=str2.size();
            //    cout<<str1.substr(n-k+1,k)<<endl;
                 cout<<str2.substr(0,k)<<endl;
            if (str1.size()>str2.size()){
                return false;
            }
       
           else  if ((str2.substr(0,k)== str1) && (str2.substr(n-k,k)== str1) ){
                return true;
            }
            return false;
            
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        // sort(words.rbegin(),words.rend());
        for (int i=0;i<words.size()-1;i++){
            for (int j=i+1;j<words.size();j++){
        
                           count += isPrefixAndSuffix(words[i],words[j]);

            }
        }
        return count;
    }
};