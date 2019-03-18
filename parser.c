#include "parser.h"

/*
//I need to find a way to move from word to word. Once that happens can easily increment it
struct BSTNode fileTokenization(int fd){
//int fd = open("pathname",flags, mode);
struct *parsedWord = NULL;
char buffer[50];
//use lseek to find position
char *c;
//curr = lseek(fd,malloc(sizeOf(char *c),SEEK_CUR);
//read(fd,buffer,count
c = read(fd,buffer,malloc(sizeof(char *c)));
//pass position to helper funtion to get next word
addWord(parsedWord->word);
close(fd);
//return BST
}
*/
int fileTokenizer(int fd){
//lseek
off_t lseek(int,off_t, int);
//read
ssize_t read(int, void *, size_t );
//strtok
char *strtok(char *,const char *);
//addWord
struct Node* addWord(struct Node*, char*);
//strstr
char* strstr(const char*, const char*);

//newTree
Node* newTree(char *);
if(fd == -1){
return 1;
}
//***Use lseek to jump to end of file record num bytes then jump back to beginning offset***//
off_t fileSize = lseek(fd,0,SEEK_END);
lseek(fd,0,SEEK_SET);

//***Uses file size to create char buffer array the size of the file***//
char buffer[fileSize];

//***copies the contents of the into buffer***//
ssize_t readFileSize = read(fd ,buffer, sizeof(*buffer)-1);

//***split into smaller words***//
char *nextWord = strtok(buffer," ");
Node* node = NULL;
while(nextWord != NULL){
	if(strstr(".,;:",&nextWord[0]) != NULL){
		nextWord++;
	}
	if(strstr(".,;:",&nextWord[strlen(nextWord)-1]) !=NULL){
		nextWord[strlen(nextWord)-1] = '\0';
	}
	if(node == NULL){
		newTree(nextWord);
	}
	else{
		addWord(node,nextWord);
	}
	nextWord = strtok(buffer," ");
}
//use lseek to get size of file, use read to pull entire file into an giant string, split up string into smaller 
//words
return 0;
}
