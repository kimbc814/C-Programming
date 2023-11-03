#include<iostream>
#include<vector>
using namespace std;

int main(void) {
    vector<int> v;

    v.push_back(21);
    v.push_back(32);
    v.push_back(53);
    v.push_back(64);
    v.push_back(15);


    //ex1) 멤버형식 size_type 이용한 반복.
    cout << "ex1-1) [v.at(i)] size_type : ";
    for (vector<int>::size_type i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "ex1-1) [ v[i] ] size_type : ";
    for (vector<int>::size_type i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;


    //ex2) int i 를 이용한 반복.
    cout << "ex2-1) [v.at(i)] int : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "ex2-2) [ v[i] ] int : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;


    //ex3) 반복자 iterator를 이용한 반복. 
    cout << "ex3) [*iter] iterator : ";
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl << endl;

    vector<string> v;

    v1.push_back("Show Me");
    v1.push_back("Tiger JK");
    v1.push_back("Dok2");
    v1.push_back("GAEKO");
    v1.push_back("ZICO");

    //ex4) v.front(), v.back() 
    cout << "//ex4) v.front(), v.back()" << endl;

    cout << "v.front() : " << v1.front() << endl;
    cout << "v.end() : " << v1.back() << endl;
    cout << endl;




    //ex5) v.popback()
    cout << "//ex5) v.popback()" << endl;

    vector<string>::iterator iter;
    for (iter = v1.begin(); iter != v1.end(); iter++) {
        cout << *iter << " / ";
    }
    cout << endl;

    v.pop_back();

    for (iter = v1.begin(); iter != v1.end(); iter++) {
        cout << *iter << " / ";
    }
    cout << endl;
    cout << endl;




    //ex6) v.erase(iter);
    cout << "//ex6) v.erase(iter)" << endl;

    for (iter = v1.begin(); iter != v1.end(); iter++) {
        if (*iter == "Dok2") {
            v1.erase(iter);
            break;
        }
    }
    for (iter = v1.begin(); iter != v1.end(); iter++) {
        cout << *iter << " / ";
    }



    cout << endl << endl;
    //ex7) v.size(), v.capacity();
    cout << "//ex7) v.size(), v.capacity()" << endl;

    cout << "v.size() : " << v1.size() << endl;
    cout << "v.capacity() : " << v1.capacity() << endl;

    return 0;
}
