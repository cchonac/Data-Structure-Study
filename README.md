# Data-Structure-Study
자료구조 공부 by c++
 
이 파일은 자료구조 수업을 듣기이전에 혼자 예습을 진행해보는 레포지토리입니다.


|Number|DataStructure|Assginment|
|:---:|:---:|:---:|
|1|[Array]
|2|[Linked List]
|3|[Stack]|BOJ_10828|
|4|[Queue]|BOJ_18258|

---
## 1주차 Array
### [Array 구현.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/Array%20%EA%B5%AC%ED%98%84.cpp)
array를 class를 이용하여 구현하였다.


<br/><br/>
## 2주차 Linked List
### [Singly Linked List.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/%EB%A7%81%ED%81%AC%EB%93%9C%EB%A6%AC%EC%8A%A4%ED%8A%B8%20%EA%B5%AC%ED%98%84.cpp)

### [Doubly Linked List.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/Double%20linked%20list.cpp)

<br/><br/>
## 3주차 Stack
### [Stack 구현.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/array%EB%A5%BC%20%EC%9D%B4%EC%9A%A9%ED%95%B4%20stack%20%EA%B5%AC%ED%98%84.cpp)
array를 이용해서 stack을 구현한 코드이다.
### 문제: [10828 스택 (실버4)](https://www.acmicpc.net/problem/10828)
### [BOJ 10828-스택 코드.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/BOJ%2010828%EB%B2%88-%EC%8A%A4%ED%83%9D.cpp)

<br/><br/>
## 4주차 Queue
### [Queue 구현.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/array%EB%A1%9C%20%EB%A7%8C%EB%93%9C%EB%8A%94%20queue.cpp)
원형 큐의 성질을 띄는 큐를 클래스를 이용하여 구현하였다.
### 문제: [18258 큐2 (실버4)](https://www.acmicpc.net/problem/18258)
### [BOJ 18258-큐2 코드.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/BOJ%2018258-queue.cpp)
endl 대신 '\n'을 사용하면 실행속도를 줄일수있습니다. endl은 개행문자 출력과 함께 출력 버퍼를 비우는 역할까지 같이 하기 때문에 딜레이가 발생합니다.
이 문제에서는 제한시간때문에 실행속도를 높여야합니다. c++로 알고리즘을 풀때 실행속도를 높일 수 있는 구문입니다.

	ios::sync_with_stdio(false); //c++로 알고리즘을 풀때 실행속도를 높이기 위해,iostream과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생하는 것을 동기화를 비활성화 시켜줍니다. cin,cout과 c의 입출력들을 서로 순서를 구별할수 없게 됩니다. 대신 c++ 버퍼만 사용해서 속도는 빨라집니다. 따라서 이 구문을 쓰게되면 c의 표준 입출력문자와 같이 쓰면 안됩니다. 
	
	cin.tie(NULL); //cin과 cout의 묶음을 풀어줍니다. c++은 다른 입출력이 올때 기존의 입출력을 flush(비우기)합니다. 
	cout.tie(NULL); 


