#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {

        stack<int> st;
        int n = mat.size();


        for(int i = n - 1; i >= 0; i--){
            st.push(i);
        }


        while(st.size() > 1){
           
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();

            // we have four cases for match 
            /**
             * => yes & yes  => nothing pushed
             * => no & no    => nothing pushed
             * => no & yes   => first ele pushed
             * => yes & no   => second ele pushed
             */
            if(mat[first][second] && !mat[second][first]){
                // first knows second -> first can't be celebrity
                st.push(second);
            } else if(!mat[first][second] && mat[second][first]){
                // first doesn't know second -> second can't be celebrity
                st.push(first);
            }
            // no push in no no and yes yes
        }

        // edge cases
        if (st.empty()){
            return -1;
        }

        int num = st.top();
        st.pop();
        int row = 0, col = 0;
        for (int i = 0; i < n; i++) {
            row += mat[num][i];    
            col += mat[i][num];     
        }
      return row == 0 && col == n-1 ? num : -1;
    }
};
