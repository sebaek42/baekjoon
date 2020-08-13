// 1 ~ K개의 스시를 덱에 집어넣고 종류를 셈
// N -1 번 반복문을 돌리면서 맨앞에 있는 스시를 빼고 다음 스시를 덱에 넣어
// 뺀 스시의 종류가 덱에 더이상 없을경우 cnt를 빼줘
// 집어 넣은 스시의 종류가 기존덱에 존재하지 않을경우  cnt더해
// 덱에 쿠폰으로 제공되는 스시의 종류가 없을 경우 cnt하나 더해
// 구한 값중 최대를 출력

//회전 초밥집이기 때문에 스시 인덱스를 (i + K) % N으로 해줘야함

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std; //이걸 쓰면 헤더 include 할때 뒤에 .h안붙여도댐

const int MAX = 3000000;
deque<int> dq; // deque<데이터타입> 변수명; -> push_front() pop_front(), push_back(), pop_back(), 중간에 원소 삽입 삭제도 가능
int N, D, K, C;
int result;
int sushi[MAX];
int kind[3000 + 1] = {0};

int main()
{
	ios_base::sync_with_stdio(false); // cpp의 iostream을 c의 stdio와 동기화해주는 작업을 하는애인데 1(true)을 주게되면 iostream과 stdio 버퍼를 모두 사용하기 때문에 딜레이가 발생하게 된다. 이 동기화 부분을 0(false)를 줘서 끊어주면 c++만의 독립적인 버퍼를 생성하게되고 C의 버퍼들과는 병행하여 사용할 수 없게 된다 대신 속도가 높아진다
	cin.tie(NULL); // cout, cin이 원랜 tie되어있다. 만약 cout << "hi" cin >> name 순서라면 hi가 먼저 출력되고 name을 입력하게됨. 그러나 untie할 경우 cout으로부터 cin을 untie해주기 때문에 먼저 입력을 받게된다. cout은 버퍼가 가득찼을경우에만 flushed되고 출력되기 때문에 hi는 출력되지 않는다. 따라서 cin을 cout에서 untie하고 싶다면 cin으로 입력하기 전에 cout으로 출력을 할때마다 지속적으로 flush해줘야한다.
	cin >> N >> D >> K >> C;
	for(int i = 0; i < N; i++)
		cin >> sushi[i];
	int cnt = 0;
	for (int i = 0; i < K; i++)
	{
		// 맨뒤 스시 추가
		dq.push_back(sushi[i]);
		// 일단 증가시키되 0이였으면 카운트도 1더해줌
		if (!kind[sushi[i]]++)
		{
			cnt++;
		}
		result = max(result, cnt);
	}
	for(int i = 0; i < N-1; i++)
	{
		// 맨앞 스시 빼기
		dq.pop_front();
		// 뺀 스시의 종류와 같은 스시가 덱에 없다면
		if (!(--kind[sushi[i]]))
		// 카운트를 하나 뺌
			cnt--;
		// 다음 스시 추가. 원형이니까 인덱스 조정
		dq.push_back(sushi[(i + K) % N]);
		// 새로운 종류면 cnt더해줌
		if (!kind[sushi[(i + K) % N]]++)
			cnt++;
		// 쿠폰스시가 없는 상태라면
		if (!kind[C])
			result = max(result, cnt + 1);
		// 쿠폰스시가 있는 상태라면
		else
			result = max(result, cnt);
	}
	cout << result << "\n";
	return 0;
}
