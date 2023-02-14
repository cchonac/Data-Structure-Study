# Data-Structure-Study
자료구조 공부 by c++
 
이 파일은 자료구조 수업을 듣기이전에 혼자 예습을 진행해보는 레포지토리입니다.


|Number|DataStructure|Assginment|
|:---:|:---:|:---:|
|1|[Array]
|2|[Linked List]
|3|[Stack]|BOJ_10828,BOJ_1935,BOJ_1918|
|4|[Queue]|BOJ_18258|
|5|[Vector]
|6|[Tree]|

---
## 1주차 Array
### [Array 구현.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/1.Array/Array%20%EA%B5%AC%ED%98%84.cpp)
array를 class를 이용하여 구현하였다.


<br/><br/>
## 2주차 Linked List
### [Singly Linked List.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/2.Linked%20list/%EB%A7%81%ED%81%AC%EB%93%9C%EB%A6%AC%EC%8A%A4%ED%8A%B8%20%EA%B5%AC%ED%98%84.cpp)

### [Doubly Linked List.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/2.Linked%20list/Double%20linked%20list.cpp)
-insertion을 해줄때는 head 바로 다음으로 오게끔 구현해주면 된다.

<br/><br/>
## 3주차 Stack
### [Stack 구현.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/3.Stack/array%EB%A5%BC%20%EC%9D%B4%EC%9A%A9%ED%95%B4%20stack%20%EA%B5%AC%ED%98%84.cpp)
array를 이용해서 stack을 구현한 코드이다.
### 문제: [10828 스택 (실버4)](https://www.acmicpc.net/problem/10828)
### [BOJ 10828-스택 코드.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/3.Stack/BOJ%2010828%EB%B2%88-%EC%8A%A4%ED%83%9D.cpp)
<br/><br/>
### 문제: [1935 후위표기식2 (실버3)](https://www.acmicpc.net/problem/1935)
### [BOJ 1935-후위표기식2 코드.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/3.Stack/BOJ%201935%20%ED%9B%84%EC%9C%84%ED%91%9C%EA%B8%B0%EC%8B%9D.cpp)
후위표기식이란 ABC+* 처럼 연산자가 나중에 표시되는 방법이다. <br/><br/>
컴파일러가 사용하는 방식으로 스택을 사용하는 예로 빈번하게 나온다. <br/><br/>
#### 사용법: 
#### 1.숫자를 만나면 스택에다 집어넣는다.<br/><br/>
#### 2.연산자를 만나면 스택에서 값 2개를 꺼내서 연산한다. 그리고 다시 스택에 집어넣는다. 
### 문제: [1918 후위표기식](https://www.acmicpc.net/problem/1918)
### [BOJ 1918-후위표기식 코드.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/BOJ%201918%20%EC%A4%91%EC%9C%84%EB%A5%BC%20%ED%9B%84%EC%9C%84%EB%A1%9C.cpp)
#### 중위->후위 표기식으로 바꾸는 문제이다. 숫자같은 피 연산자들은 스택으로 넣지않고 바로 출력해준다.
#### 연산자들은 우선순위*,/>>+,- 이다. 우선순위가 높은 곱셈이나 나눗셈이 나오면 안에 들어 있는 stack_top과 비교한다.
#### stack_top이 곱셈과 나눗셈으로 같으면 우선순위가 낮은게 나올때까지 stack_top을 출력하고 pop 해버린다.
#### stack_top이 덧셈과 뺄셈으로 우선순위가 낮다면 그대로 해당 연산자를 stack에 push
#### 우선순위가 가장 낮은 +,-이 나왔을때, stack_top과 비교는 현재 저장된 스택에 연산자들을 다 pop 해준다.
#### 소괄호로 묶여있는 경우에는 하나의 부분식이 생겼다고 생각한다.





<br/><br/>
## 4주차 Queue
### [Queue 구현.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/4.Queue/Queue.cpp)
원형 큐의 성질을 띄는 큐를 클래스를 이용하여 구현하였다.
### 문제: [18258 큐2 (실버4)](https://www.acmicpc.net/problem/18258)
### [BOJ 18258-큐2 코드.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/4.Queue/BOJ%2018258-queue.cpp)
endl 대신 '\n'을 사용하면 실행속도를 줄일수있습니다. endl은 개행문자 출력과 함께 출력 버퍼를 비우는 역할까지 같이 하기 때문에 딜레이가 발생합니다.

이 문제에서는 제한시간때문에 실행속도를 높여야합니다. 밑 c++로 알고리즘을 풀때 실행속도를 높일 수 있는 구문입니다.

	ios::sync_with_stdio(false); //c++로 알고리즘을 풀때 실행속도를 높이기 위해,iostream과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생하는 것을 동기화를 비활성화 시켜줍니다. cin,cout과 c의 입출력들을 서로 순서를 구별할수 없게 됩니다. 대신 c++ 버퍼만 사용해서 속도는 빨라집니다. 따라서 이 구문을 쓰게되면 c의 표준 입출력문자와 같이 쓰면 안됩니다. 
	
	cin.tie(NULL); //cin과 cout의 묶음을 풀어줍니다. 입출력버퍼가 입력버퍼로만 대체됨.
	cout.tie(NULL); 
<br/><br/>
## 5주차 Vector
#### STL(Standard Temlplate Library):c++을 위한 라이브러리, 이것은 알고리즘,컨테이너,함수자,반복자라고 불리는 네가지 구성요소를 제공한다.
#### - 컨테이너란? 원소의 모음을 저장하는 자료구조이다 
#### vector,deque,list,stack,queue,priority_queue,set,map 등이 컨테이너 클래스이다.
#### Vector 컨테이너는 동적배열의 클래스 템플릿 표현이라 할 수 있다.
#### Vector 객체는 요소가 추가되거나 삭제될때마다 자동으로 메모리를 재할당하여 크기를 동적으로 변경한다.
### [Vector 구현.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/vector%20%EA%B5%AC%ED%98%84.cpp)
<br/><br/>
## 6주차 Tree
#### Tree는 노드로 이루어진 자료구조로 스택이나 큐와 같은 선형구조가 아닌 비선형 자료구조이다.
#### Tree는 계층적 관계를 표현하는 자료구조이다. 
### Tree의 특징
#### 1.트리는 하나의 루트 노드를 갖는다.
#### 2.루트 노드는 0개 이상의 자식 노드를 갖는다.
#### 3.자식 노드또한 0개 이상의 자식 노드를 갖는다.
#### 4.노드들과 노드들을 연결하는 간선(Edge)들로 구성되어 있다.

### Tree 용어 정리
#### -Root node: 부모가 없는 노드로, 트리는 단하나의 루트 노드를 가진다.
#### -Leaf node(단말 노드): 자식이 없는 노드로, terminal node라고도 부른다.
#### -internal node(내부 노드): 단말노드가 아닌 노드.
#### -edge(간선): 노드를 연결하는 선
#### -sibling(형제): 같은 부모 노드를 갖는 노드들.
#### -depth(노드의 깊이): 루트노드에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수
#### -level: 트리의 특정 깊이를 가지는 노드의 집합
#### -degree(노드의 차수): 자식노드의 개수
#### -degree of tree(트리의 차수): 트리의 최대 차수

### Tree의 종류
#### 1.이진트리(Binary Tree)
![image](https://user-images.githubusercontent.com/77561827/218643739-972f9761-7a0d-4a22-9189-6aea8102cd65.png)
<br/><br/>
#### 이진트리는 각 노드가 최대 두 개의 자식을 갖는 트리를 뜻한다. 즉, 각 노드는 자식이 없거나 한개 최대 두개만을 갖는다.

#### 2-1.완전 이진트리(Complete Binary Tree)
![image](https://user-images.githubusercontent.com/77561827/218644363-9d729dcb-70f6-4df7-a46f-56725148a605.png)
<br/><br/>
#### 1)완전 이진트리는 마지막 레벨을 제외하고 모든 레벨이 채워져 있다.
#### 2)마지막 레벨은 꽉 차있지않아도 되지만, 노드가 왼쪽에서 오른쪽으로 채워져야한다.
#### 3)마지막 레벨 h에서 1~2h-1 개의 노드를 가질 수 있다.
#### 4)완전 이진 트리는 배열을 사용해 효율적으로 표현이 가능하다.

#### 2-2. 전 이진트리(Full Binary Tree)
![image](https://user-images.githubusercontent.com/77561827/218648155-cf8e8ff3-7256-4c37-ae5d-8b9f8d5acdea.png)
<br/><br/>

#### 1)전 이진트리는 모든노드가 0개 또는 2개의 자식노드를 갖는 트리이다. 

#### 2-3. 포화 이진트리(Perfect Binary Tree)
![image](https://user-images.githubusercontent.com/77561827/218648180-908fcace-0033-425f-81b3-db3e3904f30f.png)
<br/><br/>

#### 1)포화 이진트리는 모든 레벨이 노드로 꽉 차 있는 트리를 뜻한다.
#### 2)전 이진트리의 성질도 만족해야한다. 즉 모든 노드가 0개 혹은 2개의 자식노드를 갖는다. 
#### 3)모든 말단 노드가 동일한 깊이 또는 레벨을 갖는다.
#### 4)트리의 노드 개수가 정확히 2^k-1개 여야한다. 여기서 k는 트리의 높이다.
<br/><br/>

#### 3.이진 탐색 트리(Binary Search Tree)
![image](https://user-images.githubusercontent.com/77561827/218649240-c9075509-b39e-4a53-b40b-7c9c0d51d28c.png)
<br/><br/>

#### 이진 탐색 트리는 이진트리이면서 아래와 같은 속성을 갖는 트리이다.

#### 1) 이진 탐색 트리의 노드에 저장된 키(key)는 유일하다.
#### 2) 부모의 key가 왼쪽 자식 노드의 key보다 크다. 
#### 3) 부모의 key가 오른쪽 자식노드의 key 보다 작다.
#### 4) 왼쪽과 오른쪽 서브 트리도 이진 탐색 트리이다.


