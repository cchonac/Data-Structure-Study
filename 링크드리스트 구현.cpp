/*#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

};
void printList(Node* head) {//노드가 갖고있는 데이터를 출력해주는 함수 
	Node* cursor = new Node(); //cursor 라는 노드를 동적할당으로 생성 
	if (head == NULL) {
		cout << "The head is NULL";
	}
	else {
		cursor = head->next;// 커서에 next를 할당 
		while (cursor != NULL) {
			cout << cursor->data << " ";
			cursor = cursor->next;// next가 가리키는걸 커서가 가리키도록 즉, 다음 노드
		}
	}
}
Node* insert(Node* head, int new_data) {
	if (head == NULL) {
		cout << "The head is NULL";
		return head;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = head->next; //원래 head가 가리키던걸 새로 삽입된 애가 가리키고
	head->next = new_node;//기존 head는 새로 삽인된 노드를 가리키도록

}
Node* deleteNode(Node* head, int key) {
	if (head == NULL) {
		cout << "The head is NULL";
		return head;
	}
	Node* cursor = new Node(); //커서라는 포인터 동적할당 
	cursor = head; //헤드가 가리키는걸 노드도 가리키도록
	while (cursor->next->data != key) {// 커서 다음노드의 data가 key랑 다르면 
		cursor = cursor->next; //삭제하려는 값에 도달할때 까지 넘어감 
	}
	Node* temp = new Node();
	temp = cursor->next; //temp가 커서의 다음 노드를 가리키도록,temp보고 삭제될 그 노드를 가리키도록 하고 
	cursor->next = cursor->next->next;// 커서는 자기가 가리키고 있는 노드의 다음 노드를 가리코도록 
	delete temp;
	return head;
}*/
/*int main() {
	Node* head = new Node();
	head = insert(head, 1);
	head = insert(head, 2); 
	head = insert(head, 3); //맨 앞이 3
	printList(head);
	cout << endl;
	head = deleteNode(head, 1);
	printList(head);
	cout << endl;
	return 0;

}*/