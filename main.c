#include "main.h"


//NEED TO ADD ERROR HANDLING FOR OPEN AND CLOSE
int main(int argc, char* argv){
	int fileTokenizer(int fd);	

	//parse environmental variable if it exists
	char* wordFreakEnv = getenv("WORD_FREAK");
	if(wordFreakEnv != NULL){
		int envFileDes = open(wordFreakEnv);		
		fileTokenizer(envFileDes);
		close(wordFreakEnv);
	}	

	//parse main arguments if they exist
	for(int i=1; i<argc+1; i++){
		int currentArgFile = open(argv[i]);
		fileTokenizer(currentArgFile);
		close(currentArgFile;
	}
	
	//parse stdin for any contents (might not have any)
	//open(stdin) ~~~ already open as file descriptor 0	
	fileTokenizer(0);
	//close(stdin) ~~~ doesn't need to be closed
	
}
