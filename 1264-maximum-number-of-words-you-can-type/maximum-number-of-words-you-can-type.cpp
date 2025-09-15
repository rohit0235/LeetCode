class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
            // stringstream ss(text);

            vector<int>check(26,0);
            for(char i:brokenLetters)check[i-'a']++;
            bool find = true;
            int count =0;
            for(char i:text){ 
                  
                    if (i==' '){
                         if (find) count++;
                         find = true;
                    }
                    else if (check[i-'a']) find = false;
                  
            }
             if (find) count++;
            return count;

            // string token;
            // int count =0;
            // while (ss>>token){
                    
            //          string c =token;
            //          bool find = false;
            //          for(char i:c){ 
            //               if (check[i-'a']) {
            //                  find =true;
            //                  break;
            //               }
            //          }
            //          if (!find)count++;

                   
            // }

            // return count;
    }
};