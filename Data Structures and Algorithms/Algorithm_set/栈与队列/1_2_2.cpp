/*
	栈的链式存储实现(C语言版)
*/
#include <cstdio>
#include <malloc.h>

typedef char ElemType;
const int MaxSize = 1e5 + 10;

struct LinkStNode
{
    ElemType val;
    LinkStNode * next;
};

void InitStack(LinkStNode *&s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s -> next = NULL;
}

void DestroyStack(LinkStNode *&s)
{
    if (s -> next != NULL) DestroyStack(s -> next);
    free(s);
}

bool StackEmpty(LinkStNode *s)
{
    return s -> next == NULL;
}

bool Push(LinkStNode *&s, ElemType e)
{
    LinkStNode *node = (LinkStNode *)malloc(sizeof(LinkStNode));
    if (node == NULL) return false;
    node -> val = e;
    node -> next = s -> next;
    s -> next = node;
    return true;
}

bool Pop(LinkStNode *&s, ElemType &e)
{
    if (s -> next == NULL) return false;
    e = s -> next -> val;
    LinkStNode *p = s -> next;
    s -> next = p -> next;
    free(p);
    return true;
}

bool GetTop(LinkStNode *&s, ElemType &e)
{
    if (s -> next == NULL) return false;
    e = s -> next -> val = e;
    return true;
}

int main()
{

}
