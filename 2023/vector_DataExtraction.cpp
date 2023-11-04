/*
0 - 100개의 수를 랜덤으로 발생하여
30에서 euclidean distance 가 10이내인 수의 배열을 A
70에서 euclidean distance 가 5이내인 수의 배열을 B
*/

#include<iostream>
#include<vector>
#include <random>
#include<algorithm>

using namespace std;

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 100);

	vector<int> v1(100);
	vector<int> A,B;

	for (int i = 0; i < v1.size(); i++) v1[i] = dis(gen);
	for (int i = 0; i < v1.size(); i++) printf("%3d ", v1[i]);
	cout << endl;

	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++) printf("%3d ", v1[i]);
	cout << endl;

	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	for (int i = 0; i < v1.size(); i++) printf("%3d ",v1[i]);
	cout << endl;

	for (int i = 0; i < v1.size(); i++){
		if (v1[i] >= 20 && v1[i] <= 40) {
			A.push_back(v1[i]);
		} 
		if (v1[i] >= 65 && v1[i] <= 75) {
			B.push_back(v1[i]);
		}
	}
	cout << endl << " A : ";
	for (int i = 0; i < A.size(); i++) printf("%3d ", A[i]);
	cout << endl;
	cout << " B : ";
	for (int i = 0; i < B.size(); i++) printf("%3d ", B[i]);
	cout << endl;
}
