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

### 문제: [13116 30번(실버 4)](https://www.acmicpc.net/problem/13116)
### [BOJ_13116 30번.cpp](https://github.com/cchonac/Data-Structure-Study/blob/main/BOJ%2013116%EB%B2%88%20Tree.cpp)
break 문은 if문을 나가게 하는게 아니라 for,while 같은 반복문을 나가게 한다. <br/>
만약 이중 for문 처럼 여러개라면, 가장 안쪽의 반복문을 나가게 된다. 
#### 삼항연산자
(조건?값1:값2) 조건이 true면 값1 실행, false면 값2 실행
