#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //
    int n = 0;  cin >> n;

    vector <int> a;

    for (int i = 0; i < n; ++i){

        int tmp; cin >> tmp;

        a.push_back(tmp);
    }

    //
    vector <int> b;
    vector <int> s;//0 -> dinh, 1 -> day

    b.push_back(0);
    s.push_back(0);

    int doi = 0, thungLung = 0;

    for (int i = 1; i < n - 1; ++i){

        if (a[i - 1] < a[i] && a[i] > a[i + 1]){ //dinh

            b.push_back(i);
            s.push_back(0);
        }
        else if (a[i - 1] > a[i] && a[i]< a[i + 1]){ //day

            b.push_back(i);
            s.push_back(1);
        }
    }

    if (b.size() > 1){

        b.push_back(n - 1);
    }

    int len = b.size();

    for (int i = 1; i <= len - 2; ++i){

        if (s[i] == 0){

            doi = max(doi, min(b[i] - b[i - 1], b[i + 1] - b[i]));
        }
        else{

            thungLung = max(thungLung, min(b[i] - b[i - 1], b[i + 1] - b[i]));
        }
    }
      
    cout << doi << " " << thungLung << endl;

    return 0;
}