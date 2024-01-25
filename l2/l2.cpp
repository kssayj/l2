#include <iostream>
#include<random>
using namespace std;

struct Node //��������� �����
{
	int data; //���� ������
	Node* left; //��������� �� ����� ���������
	Node* right; //��������� �� ������ ���������
}; 

void add(int adata, Node*& anode) //������� �������� ������
{
	if (anode == NULL) //�������� �� ������������� ������-���� �������� � ������
	{
		anode = new Node;
		anode->data = adata;
		anode->left = NULL;
		anode->right = NULL;
		return;
	}
	else {             //����� ������� �������� ������
		random_device rd;  
		if (rd() % 2 == 0) // ��������� ����� � ������� �� ������� ��������� ����� ����� ���� ���� 0, ���� 1
			add(adata, anode->left); //���� 0, �� ��������� � ������ ���������
		else add(adata, anode->right); //���� 1, �� ��������� � ������� ���������
	}
}

void pr_obhod(Node*& anode)  //������ �����
{
	if (anode == NULL) return;
	cout << anode->data << " ";
	pr_obhod(anode->left);
	pr_obhod(anode->right);
}

void sim_obhod(Node*& anode)  //������������ �����
{
	if (anode == NULL) return;
	sim_obhod(anode->left);
	cout << anode->data << " ";
	sim_obhod(anode->right);
}

void obr_obhod(Node*& anode) //�������� �����
{  
	if (anode == NULL) return;
	obr_obhod(anode->left);
	obr_obhod(anode->right);
	cout << anode->data << " ";
}

void FreeTree(Node* anode) // ������������ ������
{
	if (anode == NULL) return;
	FreeTree(anode->left);
	FreeTree(anode->right);
	delete anode;
	return;
}

int CountLeafs(Node*& anode) // ������� ������� ������
{
	if (anode == NULL) {
		return 0;
	}
	if (anode->left == NULL && anode->right == NULL) {
		return 1;
	}
	return CountLeafs(anode->left) + CountLeafs(anode->right);
}
int main()
{
	setlocale(LC_ALL, "ru");
	Node* root = 0;
	int count;
	cout << "������� ���-�� ����� ������: "; cin >> count;
	for (int i = 0; i < count; i++)
	{
		random_device rd;
		add(rd() % 56, root);
	}
	cout << endl;
	cout << "������ ����� ��������� ������: " << endl;
	pr_obhod(root);
	cout << endl;
	cout << "������������ ����� ��������� ������: " << endl;
	sim_obhod(root);
	cout << endl;
	cout << "�������� ����� ��������� ������: " << endl;
	obr_obhod(root);
	cout << endl;
	cout << endl;
	cout << "���������� ������� ������: " << CountLeafs(root) << endl;
	cout << endl;
	FreeTree(root);
	cout << "��� ������������ ������ �������..." << endl;
	return 0;
}

/*
#include<iostream> 
#include<random> 

int tabs = 0;
struct Node {
	int data;
	Node* left;
	Node* right;
};

struct Tree {
	Node* root;
};

Node* Add(int data, Node* node, random_device& rd) {
	if (node == NULL) return new Node{ data, NULL, NULL };

	if (rd() % 2 == 0) {
		node->left = Add(data, node->left, rd);
	}
	else {
		node->right = Add(data, node->right, rd);
	}
	return node;
}

Tree BuildTree() {
	random_device rd;
	tabs += 5;
	int size = rd() % 4 + 10;
	Tree tree;
	tree.root = NULL;
	for (int i = 0; i < size; ++i) {
		int data = rd() % 101 - 50;
		tree.root = Add(data, tree.root, rd);
	}
	tabs -= 5;
	return tree;
}

void Clear(Node* node) {
	if (node == NULL) return;
	
	Clear(node->left);
	Clear(node->right);
	delete node;
}

void pr_obhod(Node* node) {
	if (node == NULL) return;

	cout << node->data << " ";
	pr_obhod(node->left);
	pr_obhod(node->right);
}

void sim_obhod(Node* node) {
	if (node == NULL) return;

	sim_obhod(node->left);
	cout << node->data << " ";
	sim_obhod(node->right);
}

void obr_obhod(Node* node) {
	if (node == NULL) return;

	obr_obhod(node->left);
	obr_obhod(node->right);
	cout << node->data << " ";
}

int LeafsCount(Node* node) {
	if (node == NULL) return 0;
	if (node->left == NULL && node->right == NULL) return 1;
	return LeafsCount(node->left) + LeafsCount(node->right);
}

int main() {
	setlocale(LC_ALL, "ru");
	Tree tree = BuildTree();
	cout << "������ �����: ";
	pr_obhod(tree.root);
	cout << endl;
	cout << "������������ �����: ";
	sim_obhod(tree.root);
	cout << endl;
	cout << "�������� �����: ";
	obr_obhod(tree.root);
	cout << endl;
	cout << "���������� ������: " << LeafsCount(tree.root);
	Clear(tree.root);
}*/