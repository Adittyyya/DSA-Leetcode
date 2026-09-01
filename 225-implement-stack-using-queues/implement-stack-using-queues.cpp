class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){//to copy el of q1 in q2 till q1 becomes mpty
            q2.push(q1.front());
            q1.pop();//baar baar peche vaala el front p aata rhega
        }
        q1.push(x);//after it gets empty we'll push our value

        while(!q2.empty()){//again we'll re copy elemnt of q2 back to q1
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */