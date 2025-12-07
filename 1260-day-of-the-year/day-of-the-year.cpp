class Solution {
public:
 bool isleap(string date){
        
       int year = stoi(date.substr(0,4));
       if (year%100==0){
         return year%400==0;
       }
       return year%4==0;
 }
  
    int dayOfYear(string date) {
         
         int ans =0;
         string t = date.substr(5,2);
        //  cout<<t<<endl;
         int month = stoi(t);

         for(int i=1;i<=month-1;i++){
             if (i==2){
              
                 if (isleap(date)){
                     ans+=29;
                 }
                 else{ 
                      ans+=28;
                 }
             }
              
             else if (i==6 || i==11 || i==9 || i==4){
                 ans+=30;
             }
             else{
                 ans+=31;
             }
         }
         int day = stoi(date.substr(8,2));
        //  int day = stoi(8,2)
         return ans+day;
          
    }
};