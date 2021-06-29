#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int leaf = 0;

typedef struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* createTree(int);
TreeNode* insertLevelOrder(int arr[], TreeNode* , int , int );
void left_boundary(struct TreeNode*);
void right_boundary(struct TreeNode*);
void display_leaf(struct TreeNode*);
void count_leaves(struct TreeNode*);

int main()
{
	int num;
	printf("Enter number of nodes : ");
	scanf("%d", &num);
	TreeNode *root = createTree(num);

	count_leaves(root);
	printf("Number of leaf nodes : %d \n\n", leaf);
	if (root)
	{
		printf("root -> %d  ", root->data);

		printf("\n\nleft boundary : ");
		left_boundary(root->left);
		printf("\n\nright boundary : ");
		right_boundary(root->right);
		printf("\n\nleaf nodes : ");
		display_leaf(root);
	}

	_getch();
}

TreeNode* createTree(int num)
{ 
	if (num == 0)
		return NULL;

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));

	int* arr = (int*)malloc(num * sizeof(int));
	for (int i = 1; i <= num; i++)
		arr[i - 1] = i;
	// arr = 1,2,3,4...10
	root = insertLevelOrder(arr, root, 0, num);

	return root;
}

TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n)
{
	// Base case for recursion
	if (i < n)
	{

		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->data = arr[i];
		temp->left = NULL;
		temp->right = NULL;
		root = temp;

		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);		// insert left child
																			//arr   = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
																			//index = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);		// insert right child
	}
	return root;
}

void count_leaves(struct TreeNode* root)
{	
  if (root)
	{
		if (root->left == NULL && root->right == NULL)
			leaf++;
		else
		{
			if (root->left)
				count_leaves(root->left);
			if (root->right)
				count_leaves(root->right);
		}
	}
}

void left_boundary(struct TreeNode *node)
{
	if (node)
	{
		if (node->left)
		{
			printf("%d  ",node->data);
			left_boundary(node->left);
		}
		else if(node->right)
		{
			printf("%d  ", node->data);
			left_boundary(node->right);
		}
	}
}

void right_boundary(struct TreeNode *node)
{
	if (node)
	{
		if (node->right)
		{
			printf("%d  ", node->data);
			right_boundary(node->right);
		}
		else if (node->left)
		{
			printf("%d  ", node->data);
			right_boundary(node->left);
		}
	}
}

void display_leaf(struct TreeNode *node)
{
	if (node)
	{
		display_leaf(node->left);
		if (node->left == NULL && node->right == NULL)
			printf("%d  ", node->data);

		display_leaf(node->right);
	}
}