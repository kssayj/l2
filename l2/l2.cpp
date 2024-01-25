#include <iostream>
#include<random>
using namespace std;

struct Node //структура ветки
{
	int data; //поле данных
	Node* left; //указатель на левое поддерево
	Node* right; //указатель на правое поддерево
}; 

void add(int adata, Node*& anode) //функция внесения данных
{
	if (anode == NULL) //проверка на существование какого-либо элемента в дереве
	{
		anode = new Node;
		anode->data = adata;
		anode->left = NULL;
		anode->right = NULL;
		return;
	}
	else {             //иначе сверяем вносимые данные
		random_device rd;  
		if (rd() % 2 == 0) // рандомное число в остатке от деления случайных чисел может быть либо 0, либо 1
			add(adata, anode->left); //если 0, то добавляем в влевое поддерево
		else add(adata, anode->right); //если 1, то добавляем в вправое поддерево
	}
}

void pr_obhod(Node*& anode)  //прямой обход
{
	if (anode == NULL) return;
	cout << anode->data << " ";
	pr_obhod(anode->left);
	pr_obhod(anode->right);
}

void sim_obhod(Node*& anode)  //симметричный обход
{
	if (anode == NULL) return;
	sim_obhod(anode->left);
	cout << anode->data << " ";
	sim_obhod(anode->right);
}

void obr_obhod(Node*& anode) //обратный обход
{  
	if (anode == NULL) return;
	obr_obhod(anode->left);
	obr_obhod(anode->right);
	cout << anode->data << " ";
}

void FreeTree(Node* anode) // освобождение памяти
{
	if (anode == NULL) return;
	FreeTree(anode->left);
	FreeTree(anode->right);
	delete anode;
	return;
}

int CountLeafs(Node*& anode) // подсчет листьев дерева
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
	cout << "Введите кол-во узлов дерева: "; cin >> count;
	for (int i = 0; i < count; i++)
	{
		random_device rd;
		add(rd() % 56, root);
	}
	cout << endl;
	cout << "Прямой обход бинарного дерева: " << endl;
	pr_obhod(root);
	cout << endl;
	cout << "Симметричный обход бинарного дерева: " << endl;
	sim_obhod(root);
	cout << endl;
	cout << "Обратный обход бинарного дерева: " << endl;
	obr_obhod(root);
	cout << endl;
	cout << endl;
	cout << "Количество листьев дерева: " << CountLeafs(root) << endl;
	cout << endl;
	FreeTree(root);
	cout << "Вся динамическая память очищена..." << endl;
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
	cout << "Прямой обход: ";
	pr_obhod(tree.root);
	cout << endl;
	cout << "Симметричный обход: ";
	sim_obhod(tree.root);
	cout << endl;
	cout << "Обратный обход: ";
	obr_obhod(tree.root);
	cout << endl;
	cout << "Количество листов: " << LeafsCount(tree.root);
	Clear(tree.root);
}*/