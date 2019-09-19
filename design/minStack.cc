#include<iostream>
#include<stack>

using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    /* two stacks
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top())
        {
            s2.push(x);
        }
    }
    
    void pop() {
        if (s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
    */
    // one stack
    /** initialize your data structure here. */
    MinStack() {
        min_val = INT64_MAX;
    }
    
    void push(int x) {
        if (x <= min_val)
        {
            st.push(min_val);
            min_val = x;
        }
        st.push(x);
    }
    
    void pop() {
        int x = st.top();
        st.pop();
        if (min_val == x)
        {
            min_val = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_val;
    }
private:
    stack<int> st;
    int min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(3);
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin();

    return 0;  
}