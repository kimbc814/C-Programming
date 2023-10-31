#include <iostream>
#include <tuple>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
	tuple<int, string, char> t1(21, "Nov", 'M');
	//////////////////////////////////////////////////////////////
	tuple<int, string, char> t2;
	t2 = make_tuple(22, "Nov", 'M');

	cout << get<0>(t2) << endl;
	cout << get<1>(t2) << endl;
	cout << get<2>(t2) << endl;
	//////////////////////////////////////////////////////////////
	int x;
	string y;
	char z;
	tie(x, y, z) = t1;
	cout << x << " " << y << " " << z << " " << endl;
	//////////////////////////////////////////////////////////////
	tuple<int, int> t3(1, 2);
	tuple<int, int> t4(3, 4);
	tuple<int, int, int, int> t5 = tuple_cat(t3,t4);

	cout << get<0>(t5) << " " << get<1>(t5) << " " 
		 << get<2>(t5) << " " << get<3>(t5) <<endl;
	//////////////////////////////////////////////////////////////
	cout << "Befor Swap" << endl;
	cout << "t3 tuple : ";
	cout << get<0>(t3) << " " << get<1>(t3) << endl;
	cout << "t4 tuple : ";
	cout << get<0>(t4) << " " << get<1>(t4) << endl;


	t3.swap(t4);
	cout << "After Swap" << endl;
	cout << "t3 tuple : ";
	cout << get<0>(t3) << " " << get<1>(t3) << endl;
	cout << "t4 tuple : ";
	cout << get<0>(t4) << " " << get<1>(t4) << endl;

	return 0;

}


