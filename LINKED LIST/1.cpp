#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 11, 5, 8, 7, 9, 6, 5, 10};
    stack<int> st;
    int n = v.size();
    vector<int> ans(n);

    // for (int i = n - 1; i >= 0; i--) {
    //     while (!st.empty() && st.top() <= v[i]) {
    //         st.pop();  // Pop elements until we find a greater element
    //     }

    //     if (st.empty()) {
    //         ans[i] = -1;  // No greater element found
    //     } else {
    //         ans[i] = st.top();  // Next greater element
    //     }

    //     st.push(v[i]);  // Push current element onto stack
    // }

    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top() <= v[i]){
            st.pop();
        }
        if(i < n){
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
                st.push(v[i]);
            }
        }
        st.push(v[i%n]);
    }

    // Print result
    for (int i = 0; i < n; i++) {
        cout << v[i] << " -> " << ans[i] << endl;
    }

    return 0;
}
