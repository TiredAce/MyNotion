/*
	’ªµƒÀ≥–Ú¥Ê¥¢ µœ÷(C”Ô—‘∞Ê) 
*/
#include <cstdio>
#include <malloc.h>

typedef char ElemType;
const int MaxSize = 1e5 + 10;

typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof( SqStack));
    s -> top = -1;
}

void DestroyStack(SqStack *&s)
{
    free(s);
}

bool StackEmpty(SqStack *s)
{
    return s->top == -1;
}

bool Push(SqStack *&s, ElemType e)
{
    if (s -> top == MaxSize - 1) return false;
    s->data[++ s->top] = e;
    return true;
}

bool Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1) return false;
    e = s -> data[s -> top --];
    return true;
}

bool GetTop(SqStack *&s, ElemType &e)
{
    if (s->top == -1) return false;
    e = s -> data[s -> top];
    return true;
}

int main()
{
    SqStack *st;
    InitStack(st);
    Push(st, 'a');
    char e;
    GetTop(st, e);
    printf("%c\n", e);
    Pop(st, e);
    DestroyStack(st);
}
