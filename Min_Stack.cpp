//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.

class MinStack {

public:
    /** initialize your data structure here. */
    stack<int> min;
    stack<int> data;
    
    MinStack() {}
    
    void push(int x) {
        
        if (min.empty()){
            min.push(x);
            data.push(x);
        }
        else {
            data.push(x);
            if(x < min.top())
                min.push(x);
        }
    }
    
    void pop() {
        if(!min.empty()){
            if(min.top() == data.top()){
                min.pop();
            }
            data.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */