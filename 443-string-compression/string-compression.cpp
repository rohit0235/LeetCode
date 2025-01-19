class Solution {
public:

    int compress(vector<char>& chars) {
        
            int n =chars.size();
            if (n==1) return 1;
           

           int i=0;
           int index=0;
           while (i<n){
               int count=0;
               char currchar=chars[i];
               while (i<n && chars[i]==currchar){
                      count++;
                      i++;
               }

               chars[index]=currchar;
               index++;
               if (count>1){
                      
                      string total=to_string(count);
                      for (char j:total){
                                            
                            chars[index]=j;
                            index++;
                      }


               }

           }            

           return index;

    }
};