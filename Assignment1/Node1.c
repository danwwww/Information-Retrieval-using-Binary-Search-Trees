#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "Node1.h"


//The function to initialize the node;
bTree *Ini_Node(){
    bTree *bt;
    bt=(bTree *)malloc(sizeof(bTree));
    bt->leftChild=NULL;
    bt->rightChild=NULL;

    return bt;
}


//Insert the Node tree2 to the tree1
bTree *insertToTree(bTree *tree1,bTree *tree2){
//if the tree 1 is empty,make tree2 as the root
    if(tree1==NULL){
        tree1 = (bTree *)malloc(sizeof(bTree));
        strcpy(tree1->Name,tree2->Name);
        strcpy(tree1->City,tree2->City);
        strcpy(tree1->Age,tree2->Age);
        strcpy(tree1->Event,tree2->Event);
        strcpy(tree1->Games,tree2->Games);
        strcpy(tree1->Height,tree2->Height);
        strcpy(tree1->ID,tree2->ID);
        strcpy(tree1->Medal,tree2->Medal);
        strcpy(tree1->NOC,tree2->NOC);
        strcpy(tree1->Season,tree2->Season);
        strcpy(tree1->Sex,tree2->Sex);
        strcpy(tree1->Sport,tree2->Sport);
        strcpy(tree1->Team,tree2->Team);
        strcpy(tree1->Weight,tree2->Weight);
        strcpy(tree1->Year,tree2->Year);


        tree1->leftChild=NULL;
        tree1->rightChild=NULL;

    }
//if the weight of tree 2 is less or equal to the weight of tree1, insert it to tree1's left child 
    else if(strcmp(tree2->Name,tree1->Name)<=0){
	tree1->leftChild=insertToTree(tree1->leftChild,tree2);
    }
//if the weight of tree 2 is greater than the weight of tree1, insert it to tree1's right child
    else if(strcmp(tree2->Name,tree1->Name)>0){
        tree1->rightChild=insertToTree(tree1->rightChild,tree2);
    }


    return tree1;}

//read eachline from the csv file and store the information in a temp node,at last insert it to the maintree
bTree *buildTree(char filename[]){
    FILE *f;
    char eachLine[512];
    bTree *mainTree=NULL;
    f=fopen(filename,"r");

    while (!feof(f)) {
        char *token;
        fgets(eachLine,512,f);
        token = strtok(eachLine, ",");
        bTree *aNode;
        aNode = Ini_Node();
        int i=0;
//this part is using to remove the double quote from the token, and apend the value into node,and insert the node 
        while( token != NULL ) {
            char *newToken;
            char *dQuotes="\"";
            newToken=strpbrk(token,"\"" );
            if(newToken!=NULL) {
                newToken=delstr(newToken,dQuotes);
                append_value(newToken, aNode, i);
            }
            else{
                append_value(token, aNode, i);
            }
            token = strtok(NULL, ",");
            i=i+1;
        }
        mainTree=insertToTree(mainTree,aNode);

    }
    fclose(f);
    return mainTree;
};

//the function to append the value into the given node 
void append_value(char *token,bTree *aNode,int i){
    if (i==0) {
        strcpy(aNode->ID,token);
    }
    else if (i==1) {
        strcpy(aNode->Name,token);
    }
    else if (i==2) {
        strcpy(aNode->Sex,token);
    }
    else if (i==3) {
        strcpy(aNode->Age,token);
    }
    else if (i==4) {
        strcpy(aNode->Height,token);
    }
    else if (i==5) {
        strcpy(aNode->Weight,token);
    }
    else if (i==6) {
        strcpy(aNode->Team,token);
    }
    else if (i==7) {
        strcpy(aNode->NOC,token);
    }
    else if (i==8) {
        strcpy(aNode->Games,token);
    }
    else if (i==9) {
        strcpy(aNode->Year,token);
    }
    else if (i==10) {
        strcpy(aNode->Season,token);
    }
    else if (i==11) {
        strcpy(aNode->City,token);
    }
    else if (i==12) {
        strcpy(aNode->Sport,token);
    }
    else if (i==13) {
        strcpy(aNode->Event,token);
    }
    else if (i==14) {
        strcpy(aNode->Medal,token);
    }
}

//print the data out
void printNode(bTree *aTree,FILE *fp){

    printf("ID: %s||\t",aTree->ID);
    printf("Name: %s||\t",aTree->Name);
    printf("Sex: %s||\t",aTree->Sex);
    printf("Age: %s||\t",aTree->Age);
    printf("Height: %s||\t",aTree->Height);
    printf("Weight: %s||\t",aTree->Weight);
    printf("Team: %s||\t",aTree->Team);
    printf("NOC: %s||\t",aTree->NOC);
    printf("Games: %s||\t",aTree->Games);
    printf("Year: %s||\t",aTree->Year);
    printf("Season: %s||\t",aTree->Season);
    printf("City: %s||\t",aTree->City);
    printf("Sport: %s||\t",aTree->Sport);
    printf("Event: %s||\t",aTree->Event);
    printf("Medal: %s||\t",aTree->Medal);
    printf("\n%s\n","------------------------------------------------------------------------------------------------------------------");


}
//search function, the main logic is the same as the insert
void searchTree(bTree *aTree,char *token,FILE *fp){

    if(aTree==NULL){
        return;
    }


    if(strcmp(aTree->Name,token)==0){
        printNode(aTree,fp);

    }

    if(strcmp(aTree->Name,token)<0){
     
        searchTree(aTree->rightChild,token,fp);
    }
    else if(strcmp(aTree->Name,token)>=0){
    
        searchTree(aTree->leftChild,token,fp);
    }
};




//the function use to delet the double quote from the data 
char *delstr(char *src, const char *sub) {
    char *st = src, *s1 = NULL;
    const char *s2 = NULL;
    while (*st && *sub) {
        s1 = st;
        s2 = sub;
        while (*s1 && *s2 && !(*s1 - *s2)) {
            s1++;
            s2++;
        }
        if (!*s2) {
            while (*st++ = *s1++);
            st = src;
        }
        st++;
    }
    return (src);
}











