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

void del_last_letter(ttree::TTREE& tree, ttree::ptrNODE& root)
{
	if (root)
	{
		for (int i = 0; i < 26; ++i)
		{
			if (root->ptrs[i])
			{
				if (root->ptrs[i]->eow)
				{
					delete root->ptrs[i];
					root->ptrs[i] = nullptr;
					root->eow = true;
				}
				else
					del_last_letter(tree, root->ptrs[i]);
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

// 2 task
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

//  3 task
void doubleLastChar(ttree::TTREE& tree, ttree::ptrNODE& root)
{
	if (root)
	{
		for (int i = 0; i < 26; ++i)
		{
			if (root->ptrs[i])
			{
				if (root->ptrs[i]->eow)
				{
					root->ptrs[i]->ptrs[i] = new ttree::NODE();
					root->ptrs[i]->eow = false;
					root->ptrs[i]->ptrs[i]->eow = true;

				}
				else
					doubleLastChar(tree, root->ptrs[i]);
			}
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
	//del_last_letter(ttree, root);
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
	doubleLastChar(ttree, root);
	ttree.print("");
}