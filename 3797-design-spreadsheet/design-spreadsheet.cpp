class Spreadsheet {
public:
   
    unordered_map<string,int>mp;
    Spreadsheet(int rows) {
          
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    
    int getValue(string formula) {
           
           string c = "";
           int i=0;
           bool a = false;
           for( i=1;i<formula.size();i++){
               if (isalpha(formula[i])) a = true;
               if (formula[i]=='+'){
                   break;
               }
               c+=formula[i];
           }
            string ops="";
            bool cek = false;
           for(int j=i+1;j<formula.size();j++){
                 if (isalpha(formula[j]))cek=true;
                  ops+=formula[j];
           }
           if (cek && a) {
                return mp[ops]+mp[c];
           }
           if (!cek && !a) {
                return stoi(ops)+stoi(c);
           }
           if (cek && !a) {
                return mp[ops]+stoi(c);
           }
           else{
               return stoi(ops)+mp[c];
           }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */