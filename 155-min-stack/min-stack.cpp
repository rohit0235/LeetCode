class MinStack {
public:

     stack<pair<int,int>>st;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if (st.empty())st.push({val,val});
        
        else{
            
             int mini = st.top().second;

             int secondmini = min(mini, val);
             st.push({val, secondmini});
             
        }
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        
          if (!st.empty()) return st.top().first;
          else return -1;
    }
    
    int getMin() {
          
         if (st.empty()) return -1;

         else return st.top().second;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */