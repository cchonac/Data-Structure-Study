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
