class Solution {
public:
    bool isPalindrome(string s) {

         int n=s.size();
         int l=0;
         int r=n-1;
        
         while (l<r){ 
              while (l<r && !isalnum(s[l])){
                   l++;
              }
              
              while (l<r && !isalnum(s[r])){
                   r--;
              }

              if (tolower(s[l])!=tolower(s[r])){
                 return false;
              }

              l++;
              r--;
              
         }

         return true;



        //  while(l<r){
                 
        //         while (l<r && !isdigit(tolower(s[l])) && (tolower(s[l])<97 || tolower(s[l])>122  ) ){
        //              l++;
        //         }
        //         while (l<r &&  !isdigit(tolower(s[r])) && (tolower(s[r])<97 || tolower(s[r])>122)  ){
        //              r--;
        //         }         
        //      cout<<tolower(s[l])<<" "<<tolower(s[r])<<endl;
                 
        //         if( tolower(s[l])!=tolower(s[r])) return false;
        //         else{
        //             l++;
        //             r--;
        //         }
                
        //  }
        //  return true;
    }
};