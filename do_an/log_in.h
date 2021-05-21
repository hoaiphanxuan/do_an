#pragma once
#include"Header.h"
void menu();
void log_in();
void log_in_success(int luachon,char* ten);
void show_inf(int luachon,char* ten);
void account(int luachon, char* ten);
struct vanban
{
	char vb[100];
};
struct Inf
{
	char* id,* pass;
};
struct Node
{
	Inf inf;
	Node* pNext;
};
struct List
{
	Node* pHead;
	Node* pTail;
};
void change_Pass(int luachon, char* ten, char* pas_o, char* pas_n);
void change_Pass_1(int luachon, List& l, char* ten, char* pas_o, char* pas_n);
void CreateList(List& l);
Node* CreateNode(char u[], char m[]);
void addLast(List& l, Node* node);