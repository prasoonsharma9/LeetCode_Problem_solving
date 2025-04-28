#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    stack<long long> st;  // store long long to avoid overflow
    long long mini;       // mini should also be long long

    MinStack() {
        mini = LLONG_MAX; // Use LLONG_MAX instead of INT_MAX
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()) {
            st.push(value);
            mini = value;
        }
        else {
            if(value >= mini) st.push(value);
            else {
                st.push(2*value - mini); // encoded value, safe now
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long topVal = st.top();
        st.pop();
        if(topVal < mini) {
            mini = 2*mini - topVal;
        }
        // if(st.empty()) mini = LLONG_MAX;
    }
    
    int top() {
        if(st.empty()) return -1;
        long long topVal = st.top();
        if(topVal < mini) return (int)mini;
        return (int)topVal;
    }
    
    int getMin() {
        return (int)mini;
    }
};
