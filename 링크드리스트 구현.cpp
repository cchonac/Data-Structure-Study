/*#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

};
void printList(Node* head) {//��尡 �����ִ� �����͸� ������ִ� �Լ� 
	Node* cursor = new Node(); //cursor ��� ��带 �����Ҵ����� ���� 
	if (head == NULL) {
		cout << "The head is NULL";
	}
	else {
		cursor = head->next;// Ŀ���� next�� �Ҵ� 
		while (cursor != NULL) {
			cout << cursor->data << " ";
			cursor = cursor->next;// next�� ����Ű�°� Ŀ���� ����Ű���� ��, ���� ���
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
	new_node->next = head->next; //���� head�� ����Ű���� ���� ���Ե� �ְ� ����Ű��
	head->next = new_node;//���� head�� ���� ���ε� ��带 ����Ű����

}
Node* deleteNode(Node* head, int key) {
	if (head == NULL) {
		cout << "The head is NULL";
		return head;
	}
	Node* cursor = new Node(); //Ŀ����� ������ �����Ҵ� 
	cursor = head; //��尡 ����Ű�°� ��嵵 ����Ű����
	while (cursor->next->data != key) {// Ŀ�� ��������� data�� key�� �ٸ��� 
		cursor = cursor->next; //�����Ϸ��� ���� �����Ҷ� ���� �Ѿ 
	}
	Node* temp = new Node();
	temp = cursor->next; //temp�� Ŀ���� ���� ��带 ����Ű����,temp���� ������ �� ��带 ����Ű���� �ϰ� 
	cursor->next = cursor->next->next;// Ŀ���� �ڱⰡ ����Ű�� �ִ� ����� ���� ��带 �����ڵ��� 
	delete temp;
	return head;
}*/
/*int main() {
	Node* head = new Node();
	head = insert(head, 1);
	head = insert(head, 2); 
	head = insert(head, 3); //�� ���� 3
	printList(head);
	cout << endl;
	head = deleteNode(head, 1);
	printList(head);
	cout << endl;
	return 0;

}*/