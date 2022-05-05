class MyStack {
    
    queue<int> q1;// using one queue
    
    // USING ONE QUEUE
    // PUSH OPEARION->
    
    // 1. Put in Q1
    // 2. while next element is pushed, for (size-1) time, push the front ele to back of queue, & pop
    
public:
    MyStack() {

    }
    
    void push(int x) {    
        
        //STEP 1.
        q1.push(x);
        
        //STEP 2.
        
        for(int i=0;i<q1.size()-1;i++){
            
            q1.push(q1.front());
            q1.pop();
            
        }
        
       
        
    }
    
    int pop() {
        
        if(q1.empty())
            return -1;
        else{
            int x = q1.front();
            q1.pop();
            return x;
        }            
        
    }
    
    int top() {
        
        if(q1.empty())
            return -1;
        return q1.front();
        
    }
    
    bool empty() {
        
        if(q1.empty())
            return true;
        return false;
        
    }
};

// class MyStack {
    
//     queue<int> q1,q2; // two queues will be used in push operation
//     // int size;
    
//     // USING TWO QUEUES
//     // PUSH OPEARION->
    
//     // 1. Put in Q2
//     // 2. Empty Q1 to Q2 ( element by element )
//     // 3. swap (Q1,Q2)
    
// public:
//     MyStack() {
//         // size = 0;
//     }
    
//     void push(int x) {    
        
//         //STEP 1.
//         q2.push(x);
        
//         //STEP 2.
//         while(!q1.empty()){
            
//             q2.push(q1.front());
//             q1.pop();
//         }
        
//         //STEP 3.
//         swap(q1,q2);
        
//         // size++;
        
//     }
    
//     int pop() {
        
//         if(q1.empty())
//             return -1;
//         else{
//             int x = q1.front();
//             q1.pop();
//             return x;
//         }            
        
//     }
    
//     int top() {
        
//         if(q1.empty())
//             return -1;
//         return q1.front();
        
//     }
    
//     bool empty() {
        
//         if(q1.empty())
//             return true;
//         return false;
        
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */