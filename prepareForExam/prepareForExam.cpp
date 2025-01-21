#include "binary_tree.h"
#include "trie_tree.h"
#include <iostream>
#include<queue>
#include<stack>

//KIM №3

//1 task
void addLeafLevelRec(const btree::ptrNODE& root)
{
	bool added = false;

	if (!root)
		return;

	if (!root->left)
	{
		root->left = new btree::NODE(0);
		added = true;
	}
	else
		addLeafLevelRec(root->left);

	if (!root->right)
	{
		root->right = new btree::NODE(0);
		added = true;
	}
	else
		addLeafLevelRec(root->right);

}

// 2 task
int findSumToOdd(btree::ptrNODE& root)
{
	if (!root)
		return 0;
	std::stack<btree::ptrNODE> s;
	s.push(root);

	int sum{};
	while (!s.empty())
	{
		bool flag = false;
		btree::ptrNODE current = s.top();
		s.pop();
		sum += current->info;
		if (current->info % 2 == 0)
		{
			flag = true;
		}
		if (current->left && !flag)
			s.push(current->left);
		if (current->right && !flag)
			s.push(current->right);
	}

	return sum;
}

// 3 task
bool is_all_prts_empty1(ttree::ptrNODE t) {
	if (!t) return true;
	for (int i = 0; i < 26; ++i) {
		if (t->ptrs[i]) {
			return false;
		}
	}
	return true;
}

void deleteLastChar(ttree::ptrNODE& t)
{
	if (!t) return;

	for (int i = 0; i < 26; ++i) {
		if (t->ptrs[i]) {
			deleteLastChar(t->ptrs[i]);
			if (t->ptrs[i]->eow && is_all_prts_empty1(t->ptrs[i])) {

				t->ptrs[i]->eow = false;
				t->eow = true;
			}
		}
	}
}


//KIM №4

// 1 task

void deleteLeavesLevel(btree::ptrNODE& root)
{

	if (!root)
		return;
	if (!root->left && !root->right)
	{
		delete root;
		root = nullptr;
	}
	else
	{
		deleteLeavesLevel(root->left);
		deleteLeavesLevel(root->right);
	}
}


int sumToCurrLevel(btree::ptrNODE& root, int level)
{
	if (!root)
		return 0;
	std::queue<btree::ptrNODE> q;
	q.push(root);
	int sum = 0;
	int currLevel = 1;
	while (!q.empty()) {
		int levelSize = q.size(); // Количество узлов на текущем уровне

		for (int i = 0; i < levelSize; ++i) {
			btree::ptrNODE current = q.front();
			q.pop();

			if (currLevel <= level) {
				sum += current->info;
			}

			if (current->left) {
				q.push(current->left);
			}
			if (current->right) {
				q.push(current->right);
			}
		}

		currLevel++;
		if (currLevel > level) break;
	}

	return sum;
}

void add(ttree::ptrNODE& t, const std::string word, short i);

void doubleLastChar(ttree::ptrNODE& root, std::string& word)
{
	if (!root)
		return;
	if (root->eow && !word.empty())
	{
		char lastChar = word.back();

		if (!root->ptrs[lastChar - 'a'])
		{
			root->ptrs[lastChar - 'a'] = new ttree::NODE();
			root->ptrs[lastChar - 'a']->eow = true;
		}

	}
	for (int i = 0; i < 26; i++) {
		if (root->ptrs[i]) {
			word.push_back(char(i + 'a'));
			doubleLastChar(root->ptrs[i], word);
			word.pop_back();
		}
	}
}

int main()
{
	btree::BTREE btree("bin.txt");
	ttree::TTREE ttree("words.txt");
	//btree.print();
	//KIM №3
// 1 task
	//addLeafLevelRec(btree.get_root());
	//btree.print();

// 2 task
	//std::cout << '\n' << findSumToOdd(btree.get_root());

// 3 task
	//ttree.print("");
	//ttree::ptrNODE root = ttree.get_root();
	//deleteLastChar(root);
	//ttree.print("");

	//KIM №4
// 1 task
	//deleteLeavesLevel(btree.get_root());
	//std::cout << "\n------------------\n";
	//btree.print();
// 2 task
	//std::cout << sumToCurrLevel(btree.get_root(), 3);

//3 task
	ttree.print("");
	ttree::ptrNODE root = ttree.get_root();
	std::string word = "";
	doubleLastChar(root, word);
	ttree.print("");
}