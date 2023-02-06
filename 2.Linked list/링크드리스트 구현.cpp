#include<iostream>
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
}//***새로운 노드가 헤드 바로앞에 삽입된다. new_node를 할당했고 얘가 삽입될 애다.  
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
//***노드 커서를 만들어서 하나 하나 움직여 가면서 삭제할 노드를 찾는다. 
//***커서가 삭제할 노드를 찾으면 커서의 next가 다음 한번 더 다음 노드를 가리킨다. 그리고 임시 노드 포인터를 만들어서 삭제할 노드를 가리키게 만들고 해제시켜 버린다. 
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
	return head;//기존 노드를 그대로 반환하되, 삭제가 필요한 부분은 삭제해서 반환
	
}
int main() {
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

}
