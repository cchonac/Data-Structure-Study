#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	//c++ 알고리즘을 풀때 실행속도를 높이기 위해,iostream과 stdio의 버퍼를 비활성화 해준다.
	//cin,cout과 c의 입출력 버퍼를 구분할 수 없게 만든다. c의 입출력 버퍼와 함께 쓰면 안된다.
	//cin과 cout의 묶음을 풀어준다. 입출력 버퍼가 입력버퍼로만 대체됨.


	
	for (int i =0; i < N; i++) {
		int arr1[10]{ 0 };
		int arr2[10]{ 0 };
		int a;
		int b;
		int max = 1;
		int idx = 0;
		
		cin >> a >> b;
		arr1[0] = a;
		arr2[0] = b;
		while (a > 1) {
			arr1[idx] = a;
			a /= 2;
			idx++;
		}
		idx = 0;
		while (b > 1) {
			arr2[idx] = b;
			b /= 2;
			idx++;
		}
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (arr1[j] == arr2[k]) {
					max=(max < arr1[j] ? arr1[j] : max);
					break; //for k문 나가게 된다. break를 쓰게되면 가장 가까운 반복문을 빠져 나가게 된다. 
				}
				else if (arr1[j] == 0 || arr2[k] == 0) {
					break;
				}
			}
		}
	
		cout << max*10 << '\n';
		

	}
	return 0;
}