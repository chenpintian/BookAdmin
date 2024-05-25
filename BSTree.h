//
// Created by 陈品天 on 24-5-25.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef struct  {
    // 图书信息数据类型定义
    string id; // 定义ISBN字段为id
    string name; // 定义书名字段为name
    int price; // 定义定价字段为 price;
    int num; // 定义库存字段为num;
} Book; // 定义图书信息数据类型

typedef string Keytype; // 补充代码，定义查找关键字类型Keytype为string类型
typedef Book ElemType;

typedef struct BSTNode{
    Book data;	// 结点数据域,存数据元素
    BSTNode *lchild,*rchild;	// 左右孩子指针
} BSTNode,* BSTree; // 二叉排序树结点及二叉排序树类型定义

BSTree SearchBST(BSTree T, Keytype key) {
    // 二叉排序树的递归查找图书的id字段值为key
    if(!T || key==T->data.id){
        return T;
    }
    else if(key<T->data.id){
        return SearchBST(T->lchild,key);
    }
    else if(key>T->data.id){
        return SearchBST(T->rchild,key);
    }
} // SearchBST

void InsertBST(BSTree &T, ElemType e) {
    // 当二叉排序树T中不存在关键字等于e.id的数据元素时，则插入该元素
    // T不存在，直接新建节点
    if(!T){
        BSTNode *S=new BSTNode;
        S->data=e;
        S->lchild=S->rchild=NULL;
        T=S;
    }
    // T存在，按照设计逻辑走
    if(e.id<T->data.id){
        InsertBST(T->lchild,e);
    }
    else if(e.id>T->data.id){
        InsertBST(T->lchild,e);
    }
} // InsertBST

BSTNode* FindMin( BSTree T ) {
    // 查找最小元素
    BSTNode *p;
    if(T==NULL){
        return NULL; // 空树返回空指针
    }
    p=T;
    while(p->lchild) //找最左边的
    {
        p=p->lchild;
    }
    return p;
}

void DeleteBST(BSTree &T,Keytype key) {
    // 二叉树的删除操作
    BSTNode *temp;
    if(!T) return; // 空树，删除失败

    // 从根开始查找关键字等于key的结点*p，若T->data.id>key，则在T的左子树中递归删除，若T->data.id<key，则在T的右子树中递归删除
    else{  // 找到，分情况讨论删除
        if ((T->lchild)&& (T->rchild)) { // 左右孩子都有
            temp=FindMin(T->rchild); // 右子树找最小的节点temp
            T->data=temp->data; // 用后继替代T结点
            DeleteBST(T->rchild,temp->data.id); // 到右子树删除temp结点
        }
        else {
            temp=T;
            if(!T->lchild){ // 只有右孩子
                T=T->rchild; // 直接拿右孩子替代
            }
            else if(!T->rchild){ // 只有左孩子
                T=T->lchild; // 直接拿左孩子替代
            }
            free(temp); // 叶子直接删除
        }
    }
} // DeleteBST