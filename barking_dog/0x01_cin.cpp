#include <iostream>
using namespace std;

int main()
{
    // cout 시간 단축을 위함
    ios::sync_with_stdio(0); // printf 방식과 cout 방식의 동기화를 하지 않도록 설정 (printf, scanf 사용 금지)
    cin.tie(0); // 버퍼를 비우지 않도록 설정

    // 공백이 포함된 문자 입력 받기
    string s;
    getline(cin, s);
    cout << s;

    return 0;
}