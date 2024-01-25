#include <iostream>
#include<random>
using namespace std;

struct Node 
{
	int data; 
	Node* left; 
	Node* right; 
}; 

void add(int adata, Node*& anode) 
{
	if (anode == NULL) 
	{
		anode = new Node;
		anode->data = adata;
		anode->left = NULL;
		anode->right = NULL;
		return;
	}
	else {           
		random_device rd;  
		if (rd() % 2 == 0) 
			add(adata, anode->left); 
		else add(adata, anode->right); 
	}
}

void pr_obhod(Node*& anode)  
{
	if (anode == NULL) return;
	cout << anode->data << " ";
	pr_obhod(anode->left);
	pr_obhod(anode->right);
}

void sim_obhod(Node*& anode)  
{
	if (anode == NULL) return;
	sim_obhod(anode->left);
	cout << anode->data << " ";
	sim_obhod(anode->right);
}

void obr_obhod(Node*& anode) 
{  
	if (anode == NULL) return;
	obr_obhod(anode->left);
	obr_obhod(anode->right);
	cout << anode->data << " ";
}

void FreeTree(Node* anode) 
{
	if (anode == NULL) return;
	FreeTree(anode->left);
	FreeTree(anode->right);
	delete anode;
	return;
}

int CountLeafs(Node*& anode) 
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
	cout << "Ââåäèòå êîë-âî óçëîâ äåðåâà: "; cin >> count;
	for (int i = 0; i < count; i++)
	{
		random_device rd;
		add(rd() % 56, root);
	}
	cout << endl;
	cout << "Ïðÿìîé îáõîä áèíàðíîãî äåðåâà: " << endl;
	pr_obhod(root);
	cout << endl;
	cout << "Ñèììåòðè÷íûé îáõîä áèíàðíîãî äåðåâà: " << endl;
	sim_obhod(root);
	cout << endl;
	cout << "Îáðàòíûé îáõîä áèíàðíîãî äåðåâà: " << endl;
	obr_obhod(root);
	cout << endl;
	cout << endl;
	cout << "Êîëè÷åñòâî ëèñòüåâ äåðåâà: " << CountLeafs(root) << endl;
	cout << endl;
	FreeTree(root);
	cout << "Âñÿ äèíàìè÷åñêàÿ ïàìÿòü î÷èùåíà..." << endl;
	return 0;
}
