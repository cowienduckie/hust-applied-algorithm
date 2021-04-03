#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void initLPS(string &pat, int &pat_len, int *lps);
vector <int> KMPsearch(string &txt, string &pat);
void fibword_gen(int len);
void fiblen_gen(int num);
ll fibwords(int &num, string &pat);

string fib[101];    //Fibonacci words
ll fib_len[101];        //Fibonacci words' length


int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case = 0, num = 0;  string pat;

    fiblen_gen(100);
    fibword_gen(10000);
    
    while(cin >> num >> pat){   //INPUT 

        cout << "Case " << ++test_case << ": " << fibwords(num, pat) << endl;  //OUTPUT
    }

    return 0;
}

void initLPS(string &pat, int &pat_len, int *lps){ 
    int ind = 1, len = 0; lps[0] = 0;

    while (ind < pat_len){
        if (pat[len] == pat[ind]){
            ++len;
            lps[ind] = len;
            ++ind;
        }
        else{
            if (len != 0){
                len = lps[len - 1];
            }
            else{
                lps[ind] = 0;
                ++ind;
            }
        }
    }
}

vector<int> KMPsearch(string &txt, string &pat){
    int pat_len = pat.length();
    int txt_len = txt.length();

    int lps[pat_len];
    vector <int> occurrences;

    initLPS(pat, pat_len, lps);

    int i = 0, j = 0;

    while(i < txt_len){
        if (txt[i] == pat[j]){
            ++i;
            ++j;
        }

        if (j == pat_len){
            occurrences.push_back(i - j);

            j = lps[j - 1];
        }
        else if (i < txt_len && txt[i] != pat[j]){
            if (j != 0)  j = lps[j - 1];
            else
                ++i;
        }
    }

    return occurrences;
}

void fibword_gen(int len){

    fib[0] = "0";
    fib[1] = "1";

    for (int i = 1; i < 3 || fib_len[i - 3] < len; ++i){
        fib[i + 1] = fib[i] + fib[i - 1];
    }
}

void fiblen_gen(int num){
    fib_len[0] = 1;
    fib_len[1] = 1;

    for (int i = 2; i <= num; ++i){
        fib_len[i] = fib_len[i - 1] + fib_len[i - 2];
    }
}

ll fibwords(int &num, string &pat){

    if (pat == "0"){
        if (num < 2){
            return num == 0 ? 1 : 0;
        }
        return fib_len[num - 2];
    }

    if (pat == "1"){
        if (num < 2){
            return num == 1 ? 1 : 0;
        }
        return fib_len[num - 1];
    }

    int pat_len = pat.length();

    int min = 3;
    while (fib_len[min - 3] <= pat_len){
        ++min;
    }

    if (min > num){
        min = num;
    }

    //With every fibonacci words that n >= 3
    //fib[n] = fib[n - 2] + fib[n - 3] + fib[n - 2] --> fn = f2 + f3 + f2
    //
    //Pattern p have 4 possibilities:
    //p in f2,  p in f3,  p overlaps f23,  p overlaps f32
    ll f3 = 0;  
    ll f2 = 0;
    ll f23[2] = {0, 0};  //f23[0] = f23,  f23[1] = f32

    vector <int> occurrences = KMPsearch(fib[min], pat);

    //Calc occurrences of base case with minimum index
    for (int o : occurrences){

        if (o < fib_len[min - 2]){  //o in f2's indexes

            if (o + pat_len - 1 < fib_len[min - 2]){
                
                ++f2;
            }
            else  ++f23[0];
        }
        else if (o < fib_len[min - 1]){ //o in f3's indexes

            if (o + pat_len - 1 < fib_len[min - 1]){

                ++f3;
            }
            else ++f23[1];
        }
    }

    for (int i = 0; i <= num - min + 1; ++i){
        ll temp = f2;
        f2 = f2 + f3 + f23[i % 2];
        f3 = temp;
    }

    return f2;
}