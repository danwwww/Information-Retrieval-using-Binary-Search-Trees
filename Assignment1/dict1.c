//Date created : 2/9/18
//Date last modifield: 5/9/18
//implemented by: Dan Wu
//Email: danw8@student.unimelb.edu.au
//The program will read the data from a given csv file and store the data into a binary search tree,the user can search the name in the database and get all the record of this athlete





#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Node1.h"
int times=0;
int found=0;

//this function is almost the same as the function in Node.c, but the assignment require us to count the number of comparing, so I adjust the search a bit.
int searchTree2(bTree *aTree,char *token,FILE *fp){
    times++;
	
    if(aTree==NULL){
        return;
    }



    if(strcmp(aTree->Name,token)==0){
	found=1;
        printNode(aTree,fp);

    }

    if(strcmp(aTree->Name,token)<0){
     
        searchTree2(aTree->rightChild,token,fp);
    }
    else if(strcmp(aTree->Name,token)>=0){
    
        searchTree2(aTree->leftChild,token,fp);
    }
};



int main(int argc, char *argv[]) {
    FILE *fp;
    bTree *mainTree=NULL;
//1st arg:program name 2nd arg:source file 3rd arg:outputfile
    mainTree=buildTree(argv[1]);
    fp= fopen(argv[2], "w");

    char line[512] = {0};
//using ctrl+D to exit the program
    while(fgets(line, 512, stdin) != NULL)
    {	//initialization the found and times for each search
	times = 0;
	found =0;

        line[strlen(line) - 1] = '\0';        
        searchTree2(mainTree,line,fp);

//according to result ,put the data in to outputfile/
	if(found==0){
	fprintf(fp,"%s-->NOTFOUND\n",line);
	printf("%s-->NOTFOUND\n",line);
	
        } 	

	fprintf(fp,"%s --> %d\n", line, times);
        printf("%s --> %d\n", line, times);
	
    }
    fclose(fp);


}


