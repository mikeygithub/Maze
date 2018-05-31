// E3.cpp: 定义控制台应用程序的入口点。
#include <stdio.h>
#include <stdlib.h>
#define  MAX 50
int num = 0;
typedef struct node {
	char data;
	char *Message;
	struct node *lchild;
	struct node *rchild;
}BTNode;
void CreateBTree(BTNode * &b, char *str, char str1[15][20])//create tree
{
	BTNode *St[MAX], *p;
	int top = -1, k, j = 0,s=0; 
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':top++; St[top] = p; k = 1; break;
		case ')':top--; break;
		case ',':k = 2; break;
		default:p = (BTNode *)malloc(sizeof(BTNode));
			p->Message = str1[s]; s++;
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k) {
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void PreOrder(BTNode *b) {//out print tree
	 
	if (b != NULL) {
		printf("%c\n", b->data);
		printf("%s\n", b->Message);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
	
}
void PrintFind(BTNode *b) {//print find tree

	if (b != NULL) {
		num++;
		printf("%c\n", b->data);
		printf("%s\n", b->Message);
		PrintFind(b->lchild);
		PrintFind(b->rchild);
	}

}
BTNode *FindNode(BTNode *b, char x) {
	BTNode *p;
	if(b==NULL){
		return NULL;
	}
	else if (b->data == x)return b->lchild;
	else {
		p = FindNode(b->lchild,x);
		if (p != NULL) {
			return p;
		}
		else
		{
			return FindNode(b->rchild, x);
		}
	}
}

int main()
{
	printf("Hello, World!\n");
	BTNode *p; char x;
	char str[] = "A(B(F(,G(,H(,I))),C(J(,K),D(L(,M(,N)),E(O)))))";
	char str1[15][20] = {"信电学院", "计算机类","软件工程","物联网工程","数字媒体技术","计算机科学与技术","数学类","数学与应用数学","信息与计算科学","电子类","通信工程","电子科学与技术","电子信息工程","物理类","应用物理学"};
	CreateBTree(p, str,str1);
	PreOrder(p);
	printf("请输入任一专业的大类编号：\n");
	while (true) {
		scanf("%c", &x);
		if (FindNode(p, x)) {
			PrintFind(FindNode(p, x));
			printf("专业个数：%d\n", num);
			num= 0;
		}
		else {
			printf("查找不到，请检查输入的编号\n");
		}
	}
return 0;
}
