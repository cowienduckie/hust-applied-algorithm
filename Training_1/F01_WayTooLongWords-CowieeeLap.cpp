#include <bits/stdc++.h>

using namespace std;

struct word{
	string str;
	int len;
};

ostream& operator << (ostream& out, word w) {	
	if (w.len >	 10){
		out << w.str[0] << w.len-2 << w.str[w.len-1];
	} else {
		out << w.str;
	}
    return out;
}

int main() {
	int num = 0; cin >> num;
	word arr[num];	

	for (int i = 0; i < num; ++i){
		fflush(stdin);
		cin >> arr[i].str;
		arr[i].len = arr[i].str.length();
	}
	
	for (int i = 0; i < num; ++i){
		cout << arr[i];
		if (i < (num - 1))	cout << endl;
	}

	return 0;
}
