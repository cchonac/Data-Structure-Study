## 4주차 Queue
### [Queue 구현.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/4.Queue/Queue.cpp)
원형 큐의 성질을 띄는 큐를 클래스를 이용하여 구현하였다.
### 문제: [18258 큐2 (실버4)](https://www.acmicpc.net/problem/18258)
### [BOJ 18258-큐2 코드.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/4.Queue/BOJ%2018258-queue.cpp)
버퍼(임시 저장소)를 비우는데 시간이 많이 걸린다.
endl 대신 '\n'을 사용하면 실행속도를 줄일수있습니다. endl은 개행문자 출력과 함께 출력 버퍼를 비우는 역할까지 같이 하기 때문에 딜레이가 발생합니다.

이 문제에서는 제한시간때문에 실행속도를 높여야합니다. 밑 c++로 알고리즘을 풀때 실행속도를 높일 수 있는 구문입니다.

	ios::sync_with_stdio(false); //c++로 알고리즘을 풀때 실행속도를 높이기 위해,iostream과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생하는 것을 동기화를 비활성화 시켜줍니다. cin,cout과 c의 입출력들을 서로 순서를 구별할수 없게 됩니다. 대신 c++ 버퍼만 사용해서 속도는 빨라집니다. 따라서 이 구문을 쓰게되면 c의 표준 입출력문자와 같이 쓰면 안됩니다. 
	
	cin.tie(NULL); //cin과 cout의 묶음을 풀어줍니다. 입출력버퍼가 입력버퍼로만 대체됨.
	cout.tie(NULL); 
	//입출력 작업을 수행할 때 데이터의 효율적인 이동과 관리를 위해 버퍼라는 임시 저장소를 사용한다.

만약 어떤 변수에 문자값을 입력받는다고 하면 바로 변수에 저장되는게 아니라 입력한 데이터가 입력버퍼에 저장되고, 이 저장된 값을 버퍼에서 읽어서 변수에 저장하게 된다.
