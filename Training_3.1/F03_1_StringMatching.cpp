#include <iostream>
#include <string>

using namespace std;

void initLPS(string &pat, int &pat_len, int *lps){ //LongestPrefixSufix
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

int KMPsearch(string &txt, string &pat){
    int pat_len = pat.length();
    int txt_len = txt.length();

    int lps[pat_len];

    initLPS(pat, pat_len, lps);

    int i = 0, j = 0, counter = 0;

    while(i < txt_len){
        if (txt[i] == pat[j]){
            ++i;
            ++j;
        }

        if (j == pat_len){
            ++counter;
            //cout << "Found pattern at index " << i - j << endl;

            j = lps[j - 1];
        }
        else if (i < txt_len && txt[i] != pat[j]){
            if (j != 0)  j = lps[j - 1];
            else
                ++i;
        }
    }

    return counter;
}

int main(int argc, char **argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string pat;  getline(cin, pat);
    string txt;  getline(cin, txt);
    
    cout << KMPsearch(txt, pat) << endl;

    return 0;
}