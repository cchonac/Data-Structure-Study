#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	//c++ �˰����� Ǯ�� ����ӵ��� ���̱� ����,iostream�� stdio�� ���۸� ��Ȱ��ȭ ���ش�.
	//cin,cout�� c�� ����� ���۸� ������ �� ���� �����. c�� ����� ���ۿ� �Բ� ���� �ȵȴ�.
	//cin�� cout�� ������ Ǯ���ش�. ����� ���۰� �Է¹��۷θ� ��ü��.


	
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
					break; //for k�� ������ �ȴ�. break�� ���ԵǸ� ���� ����� �ݺ����� ���� ������ �ȴ�. 
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