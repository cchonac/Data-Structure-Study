#include<iostream>
using namespace std;

class Node {
	friend class DLL; //DLL이 Node의 private 멤버변수 접근 가능 
private:
	int data;
	Node* pNext;
	Node* pPrev;
public:
	Node();
	Node(int data);
	~Node();
};

class DLL {
private:
	Node* pHead;
	Node* pTail;
	Node* pCursor;
public:
	DLL();
	~DLL();
	void insertion(int);
	void deletion(int);
	void traversal();
	void reverseTraversal();
	int size();
};

Node::Node() { //범위지정 연산자
	this->pPrev = NULL;
	this->pNext = NULL;
}
Node::Node(int data) {
	this->data = data;
	this->pPrev = NULL;
	this->pNext = NULL;

}
Node::~Node() {}

DLL::DLL() {
	pHead = new Node();
	pTail = new Node();
	pCursor = new Node();
	pHead->pNext = pTail;//원래는 private으로 선언된 것 클래스 외부에서 접근 불가
	pTail->pPrev = pHead;
}

DLL::~DLL(){}

void DLL::insertion(int data) { //data 값을 헤드 바로 그다음으로 넣어줘야한다.
	Node* temp = new Node(data);
	pCursor = pHead->pNext; //커서가 헤드의 다음 노드를 가리킨다 temp를 헤드와 커서 사이의 삽입시켜준다 
	pHead->pNext = temp;
	temp->pNext = pCursor;
	pCursor->pPrev = temp;
	temp->pPrev = pHead;

}
void DLL::deletion(int data) {
	if (pHead->pNext == pTail) { cout << "No node exists." << endl; }
	else {
		pCursor = pHead->pNext;//커서는 헤드 바로 다음 노드 
		while (pCursor != pTail) {
			if (pCursor->data == data) {
				pCursor->pPrev->pNext = pCursor->pNext;//커서가 가리키는 전 노드로 가서 전 노드의 pNext를 커서가 가리키는 다음 노드의 할당
				pCursor->pNext->pPrev = pCursor->pPrev;//커서가 가리키는 다음 노드로 가서 다음 노드의 pPrev를 커서가 가리키는 전 노드로 할당
				delete pCursor; 
				return ;
			}
			else {
				pCursor = pCursor->pNext;
			}
		}
	}
}

void DLL::traversal() {
	if (pHead->pNext == pTail) { cout << "No node exists." << endl; }
	else {
		pCursor = pHead->pNext;
		while (pCursor != pTail) { //while문은 조건안이 참이면 실행된다. 
			cout << pCursor->data << " ";
			pCursor = pCursor->pNext;
		}
		cout << endl;
	}
}

void DLL::reverseTraversal() {
	if (pTail->pPrev == pHead) { cout << "No node exists." << endl; }
	else {
		pCursor = pTail->pPrev;
		while (pCursor != pHead) {
			cout << pCursor->data << " ";
			pCursor = pCursor->pPrev;
		}
		cout << endl;
	}
}
int DLL::size() {
	int size = 0;
	if (pHead->pNext == pTail) { return size; }
	else {
		pCursor = pHead->pNext;
		while (pCursor != pTail) {
			size++;
			pCursor = pCursor->pNext;
		}
		return size;
	}
}
int main() {
	DLL dll;
	dll.insertion(1);
	dll.insertion(2);
	dll.insertion(3); //3 2 1 식으로 먼저 들어간게 젤 뒤로간다.
	dll.traversal();
	dll.reverseTraversal();
	dll.deletion(3);
	dll.traversal();
	cout << "size: " << dll.size() << endl; //head랑 tail은 사이즈에 포함되지 않는다
}
