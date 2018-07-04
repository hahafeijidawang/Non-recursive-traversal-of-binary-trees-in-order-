#include <iostream>
#include <stdio.h>
#include<string.h>
#include<stack>
using namespace std;


//二叉链表示法
typedef struct BiTNode BiTNode;

typedef struct BiTNode *BiTree;
struct BiTNode{

    int data;

    struct BiTNode *lchild,*rchild;


};
//一直向左走找到中序遍历的起点

BiTNode * goLeft(BiTNode *T,stack<BiTNode *>&s){

    if(T==NULL){


         return NULL;
    }
    //判断T有没有左孩子，没有return
    //如果有T入栈，再往左走。

    while(T->lchild!=NULL){

        s.push(T);
        T = T->lchild;

    }

    return T;

}

void Inorder2(BiTNode *T){

    BiTNode *t = NULL;

    stack<BiTNode *> s;


    t = goLeft(T,s);//1

    while(t){

        printf("%d",t->data);

        //如果t有右子树， 重复步凑1

        if(t->rchild!=NULL){

            t = goLeft(t->rchild,s);//右子树中序遍历的起点

        }else if(!s.empty())//如果t没有右子树 根据栈顶指示 回退

        {

           t = s.top();

           s.pop();


        }
        else//如果t没有右子树 并且栈为空。
        {

            t=NULL;


        }

    }



}



void inOrder(BiTNode *root){

    if(root==NULL){

        return;
    }
    //遍历左子树
    inOrder(root->lchild);

    printf("%d",root->data);

    //遍历右子树

    inOrder(root->rchild);

}
int main(void)
{
    BiTNode t1,t2,t3,t4,t5;

     memset(&t1,0,sizeof(BiTNode));
     memset(&t2,0,sizeof(BiTNode));
     memset(&t3,0,sizeof(BiTNode));
     memset(&t4,0,sizeof(BiTNode));
     memset(&t5,0,sizeof(BiTNode));

     t1.data = 1;
     t2.data = 2;
     t3.data = 3;
     t4.data = 4;
     t5.data = 5;
     //建立关系

     t1.lchild = &t2;
     t1.rchild = &t3;
     t2.lchild = &t4;
     t3.lchild = &t5;
     printf("\n older inorder\n");

     inOrder(&t1);

     printf("\n Non-recursive  inOrder\n");

     Inorder2(&t1);

    return 0;
}


