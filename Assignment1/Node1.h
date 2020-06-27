#ifndef Node
#define Node
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef struct node{
    char ID[128];
    char Name[128];
    char Sex[128];
    char Age[128];
    char Height[128];
    char Weight[128];
    char Team[128];
    char NOC[128];
    char Games[128];
    char Year[128];
    char Season[128];
    char City[128];
    char Sport[128];
    char Event[128];
    char Medal[128];
    struct bTree *leftChild;
    struct bTree *rightChild;
}bTree;

bTree *Ini_Node();
bTree *insertToTree(bTree *tree1,bTree *tree2);
bTree *buildTree(char filename[]);
void append_value(char *token,bTree *aNode,int i);
void printNode(bTree *aTree,FILE *fp);
void searchTree(bTree *aTree,char *token,FILE *fp);
char *delstr(char *src, const char *sub);


#endif
