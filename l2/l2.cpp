#include <iostream>
#include<random>
using namespace std;

struct Node //ñòðóêòóðà âåòêè
{
	int data; //ïîëå äàííûõ
	Node* left; //óêàçàòåëü íà ëåâîå ïîääåðåâî
	Node* right; //óêàçàòåëü íà ïðàâîå ïîääåðåâî
}; 

void add(int adata, Node*& anode) //ôóíêöèÿ âíåñåíèÿ äàííûõ
{
	if (anode == NULL) //ïðîâåðêà íà ñóùåñòâîâàíèå êàêîãî-ëèáî ýëåìåíòà â äåðåâå
	{
		anode = new Node;
		anode->data = adata;
		anode->left = NULL;
		anode->right = NULL;
		return;
	}
	else {             //èíà÷å ñâåðÿåì âíîñèìûå äàííûå
		random_device rd;  
		if (rd() % 2 == 0) // ðàíäîìíîå ÷èñëî â îñòàòêå îò äåëåíèÿ ñëó÷àéíûõ ÷èñåë ìîæåò áûòü ëèáî 0, ëèáî 1
			add(adata, anode->left); //åñëè 0, òî äîáàâëÿåì â âëåâîå ïîääåðåâî
		else add(adata, anode->right); //åñëè 1, òî äîáàâëÿåì â âïðàâîå ïîääåðåâî
	}
}

void pr_obhod(Node*& anode)  //ïðÿìîé îáõîä
{
	if (anode == NULL) return;
	cout << anode->data << " ";
	pr_obhod(anode->left);
	pr_obhod(anode->right);
}

void sim_obhod(Node*& anode)  //ñèììåòðè÷íûé îáõîä
{
	if (anode == NULL) return;
	sim_obhod(anode->left);
	cout << anode->data << " ";
	sim_obhod(anode->right);
}

void obr_obhod(Node*& anode) //îáðàòíûé îáõîä
{  
	if (anode == NULL) return;
	obr_obhod(anode->left);
	obr_obhod(anode->right);
	cout << anode->data << " ";
}

void FreeTree(Node* anode) // îñâîáîæäåíèå ïàìÿòè
{
	if (anode == NULL) return;
	FreeTree(anode->left);
	FreeTree(anode->right);
	delete anode;
	return;
}

int CountLeafs(Node*& anode) // ïîäñ÷åò ëèñòüåâ äåðåâà
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
