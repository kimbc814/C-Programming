#include <iostream>
#include <string>

using namespace std;

int main() {

	//////////////////////////////////////////			ex1
	string s;
	double n[5];
	double max;

	cout << "5개의 실수를 입력하라 >> ";
	for (int i = 0; i < 5; i++) {
		cin >> n[i];
		if (i == 0)max = n[i];
		if (n[i] > max)max = n[i];
	}
	cout << " 가장 큰 수는 " << max << endl;

	//////////////////////////////////////////			ex2
	string s1;
	double n1[5];
	double max1;

	cout << "5개의 실수를 입력하라 >> ";

	for (int i = 0; i < 5; i++) {
		cin >> n1[i];
		if (i == 0)max1 = n1[i];
		if (n1[i] > max1)max1 = n1[i];
	}
	cout << " 가장 큰 수는 " << max1 << endl;

	//////////////////////////////////////////			ex3
	char str2[100];
	char find2;
	int cnt2 = 0;

	cout << "문자들을 입력하라(100개 미만). " << endl;
	cin.getline(str2, 100);
	cout << "찾으려는 문자 입력 : ";
	cin >> find2;

	for (int i = 0; i < strlen(str2); i++) {
		if (str2[i] == find2) cnt2++;
		cout << find2 << "의 개수는 " << cnt2 << endl;
	}

	//////////////////////////////////////////			ex4
	string name3;
	string longName3;
	int len3 = 0;
	cout << "5 명의 이름을 ','으로 구분하여 입력하시오" << endl << ">> ";
	for (int i = 0; i < 5; i++) {
		getline(cin, name3, ',');
		cout << i + 1 << " : " << name3 << endl;
		if (name3.length() > len3) {
			len3 = name3.length();
			longName3 = name3;
		}
	}
	cout << "가장 긴 이름은 " << longName3 << ", 길이가 " << len3 << endl;

	//////////////////////////////////////////			ex5
	string s4;
	char op4;
	int n4, n5, res4;

	cout << "종료는 exit 입력하기" << endl;

	while (1) {
		cout << "? ";
		getline(cin, s4);
		if (s4 == "exit")break;
		int index = 0;
		index = s4.find(' ');
		n4 = stoi(s4);
		char op4 = s[index + 1];

		index = (s4, index + 1);
		string sub = s4.substr(index + 1);
		n5 = stoi(sub);

		switch (op4) {
		case '+':res4 = n4 + n5; break;
		case '-':res4 = n4 - n5; break;
		case '*':res4 = n4 * n5; break;
		case '/':res4 = n4 / n5; break;
		default:break;
		}
		cout << n4 << ' ' << op4 << ' ' << n5 << " = " << res4 << endl;
	}




}
