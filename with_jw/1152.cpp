#include <iostream>
#include <string>

using namespace std;
int bmain() {

	string arr;

	cin >> arr;

	int count = 0;
	cout << arr.size() << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << count << " " << i << endl;
		if (arr[i] == ' ') {
			count++;
		}
	}

	cout << count;

	return 0;
}