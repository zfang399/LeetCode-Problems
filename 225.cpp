class MyStack {
    queue<int> qin,qout;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        qout.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret=top();
        qout.pop();
        return ret;
    }

    /** Get the top element. */
    int top() {
        if(!qout.empty()){
            while(qout.size()!=1){
                qin.push(qout.front());
                qout.pop();
            }
            return qout.front();
        }
        while(qin.size()!=1){
            qout.push(qin.front());
            qin.pop();
        }
        int ret=qin.front();
        qin.pop();
        while(!qout.empty()){
            qin.push(qout.front());
            qout.pop();
        }
        qout.push(ret);
        return ret;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return qin.empty()&&qout.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
