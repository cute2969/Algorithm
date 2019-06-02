#include <iostream>
#include <vector>

#define ALPHA_LENG 26 //¾ËÆÄºª

using namespace std;

int checkMatch(int targ[], int stat[]) {
	int ifMatch = true;
	for (int i = 0; i < ALPHA_LENG; i++)
		if (targ[i] != stat[i]) {
			return false;
			break;
		}
	return true;
}

int main() {
	//string A, B;
	//cin >> A >> B;
	// ex 
	// string A = "CADBCAABDACAB";
	// string B = "CAADB";
	// 2. 
	string A = "NPHGHHFEHG";
	string B = "GFEHHH";

	// set target
	int targ[ALPHA_LENG];
	for (int i = 0; i < ALPHA_LENG; i++) targ[i] = 0;
	for (int i = 0; i < B.length(); i++) targ[B[i] - 'A']++;

	// init
	int stat[ALPHA_LENG];
	for (int i = 0; i < ALPHA_LENG; i++) stat[i] = 0;
	for (int i = 0; i < B.length(); i++) stat[A[i] - 'A']++;

	// start counting
	int match = 0;
	if (checkMatch(targ, stat))
		match++;

	for (int i = B.length(); i < A.length(); i++) {
		int start = i - B.length();
		int end = i;

		// for (int j = start; j < end; j++)
		//     cout << A[j];
		// cout << " " << start << " ~ " << end;

		// minus front
		stat[A[start] - 'A']--;

		// plus back
		stat[A[end] - 'A']++;

		// check if match
		if (checkMatch(targ, stat))
			match++;
	}

	cout << match << endl;

	// print targ and stat value
	// cout << "" << endl;
	// for (int i = 0; i < ALPHA_LENG; i++)
	//     cout << (char) ('A' + i) << " " << targ[i] << endl;
	// for (int i = 0; i < ALPHA_LENG; i++)
	//     cout << (char) ('A' + i) << " " << stat[i] << endl;

	return 0;
}