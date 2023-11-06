// cpp는 헤더 확장자 없음
#include <iostream>  // cpp표준 입출력을 위한 클래스와 객체가 선언되어 있다.


//한줄주석
/*
	안의 내용 모두 주석
*/

using namespace std; //using 지시어를 사용한 std:: 생략

namespace kitae { // namespace(이름공간) 키워드와 범위 지정 연산자(::)
	int f() { return 0;}
	int m() { return -1; }
}


int main() {
	
	std::cout << "Hi" << std::endl << "Hello" << std::endl;
	/*
		std::접두어 cout의 이름공간
		cout 객체 c++ 표준 출력 스트림 객체
		<< 연산자 : 스트림 삽입 연산자 - 오른쪽 피연산자 데이터를 왼쪽 스트림 객체에 삽입
		endl 조작자 다음 줄로 넘어가기 위한 조작자
	*/

	int n = kitae::f();
	int m = kitae::m();

	cout << n << " " << m << endl;
	int width, height;
	cout << "너비와 높이 입력 : ";
	cin >> width >> height; // cin 단점 공백 문자 전까지 하나의 문자열로 인식
	cout << "width : " << width << " height : " << height << endl;




	return 0; //생략 가능
}
