//Largest Rectangular Area in a Histogram
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int num = 0; cin >> num;
    vector <long long> result;

    while (num != 0){
        long long hist[num];
        for (int i = 0; i < num; ++i) cin >> hist[i];

        stack <int> st;
        long long max_area = 0;
        int ind = 0, top = 0; 

        while(ind < num){
            if (st.empty() || hist[ind] >= hist[st.top()]){
                st.push(ind++);
            }
            else {
                top = st.top();
                st.pop();

                long long area = hist[top] * (st.empty() ? ind : ind - st.top() - 1);

                if (area > max_area) max_area = area;
            }
        }
        
        while (!st.empty()){
            top = st.top();
            st.pop();

            long long area = hist[top] * (st.empty() ? ind : ind - st.top() - 1);

            if (area > max_area) max_area = area;
        }

        result.push_back(max_area);

        cin >> num;
    }

    for (long long i : result) cout << i << endl;

    return 0;
}
