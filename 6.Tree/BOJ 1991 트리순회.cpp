#include<iostream>
using namespace std;
pair<char, char> node[26]; //node[0]�� A�� left,right ���� ��� ���� 
//pair Ŭ���� p.first:p�� ù��° ���� ��ȯ p.second:p�� �ι�° ���� ��ȯ
int N;
void preorder(char cur) {
	if (cur == '.') { return; }

	cout << cur;
	preorder(node[cur - 'A'].first);
	preorder(node[cur - 'A'].second);
}
void inorder(char cur) {
	if (cur == '.') { return; }
	inorder(node[cur - 'A'].first);
	cout << cur;
	inorder(node[cur - 'A'].second);
}
void postorder(char cur) {
	if (cur == '.') { return; }
	postorder(node[cur - 'A'].first);
	postorder(node[cur - 'A'].second);
	cout << cur;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		node[parent - 'A'].first = left;
		node[parent - 'A'].second = right;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}