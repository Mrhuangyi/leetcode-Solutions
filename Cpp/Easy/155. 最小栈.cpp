设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        while(!st.empty()){
            st.pop();
        }
        while(!minSt.empty()){
            minSt.pop();
        }
    }
    
    void push(int x) {
        st.push(x);
        if(minSt.size()==0){
            minSt.push(x);
        }else{
            if(x<=minSt.top()){
                minSt.push(x);
            }else{
                minSt.push(minSt.top());
            }
        }
    }
    
    void pop() {
        if(st.size()!=0){
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        if(st.size()==0){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if(minSt.size()==0){
            return -1;
        }
        return minSt.top();
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
