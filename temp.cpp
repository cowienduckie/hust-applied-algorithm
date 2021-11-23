#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int  N, K, S;  cin >> N >> K >> S;

	vector<int> arr;

	for (int i = 0; i < N; ++i)
	{
		int tmp = 0;  cin >> tmp;
		arr.push_back(tmp);
	}



	return 0;
}