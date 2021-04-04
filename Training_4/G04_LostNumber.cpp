#include <cstdio>
#include <cmath>

using namespace std;

int a[7] = {0, 4, 8, 15, 16, 23, 42};
int r[7];
int q[5]; 
int mark[7];

int query(int l, int r){
    printf ("? %d %d\n", l, r);
    fflush(stdout);

    int res; scanf("%d", &res);

    return res;
}

int flag = 0;

void dfs(int pos, int prev){
    
    if (flag == 1){
        return;
    }

    if (pos == 6){
        for (int i = 1; i <= 6; ++i){

            if (mark[i] == 0){

                r[pos] = a[i];
                flag = 1;
                return;
            }
        }
    }

    for (int i = 1; i <=6; ++i){

        if (pos == 1 && mark[i] == 0){

            if (flag == 1)  return;
            r[pos] = a[i];
            mark[i] = 1;

            dfs(pos + 1, a[i]);

            mark[i] = 0;
        }
        else if(pos > 1 && mark[i] == 0 && q[pos - 1] == a[i] * prev){

            if (flag == 1)  return;
            r[pos] = a[i];
            mark[i] = 1;

            dfs(pos + 1, a[i]);

            mark[i] = 0;
        }
    }
}

int main(int argc, char **argv){

    //Store 4 queries
    q[1] = query(1, 2); q[2] = query(2, 3); q[3] = query(3, 4); q[4] = query(4, 5);

    for (int &m : mark) m = 0;

    dfs(1, 1);

    //OUTPUT
    printf("! %d %d %d %d %d %d\n", r[1], r[2], r[3], r[4], r[5], r[6]);
    
    return 0;
}