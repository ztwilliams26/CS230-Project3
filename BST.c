#include "BST.h"

int main(int argc, char* argv[]){  //to test
  Node* newTree(char*);
  Node* addWord(Node*, char*);
  void printTree(Node*);
  Node* root;
  
  root = newTree("map");
  addWord(root, "apple");
  addWord(root, "orange");
  addWord(root, "grape");
  addWord(root, "grape");
  addWord(root, "nothing");
  addWord(root, ".-kl!");
  
  printTree(root);
  return 0;
}

Node* newTree(char* word){
  Node* addWord(Node*, char*);
  return addWord(NULL, word);
}

//Checks for invalid input then adds the word to the root's tree (either incrementing the freq for existing words or makeing a new node for new ones)
//Returns Node* as it works recursively
Node* addWord(Node* root, char* word){
  int isAlpha(char*);
  if(!isAlpha(word) || word==NULL){
    return NULL;
  }
  if(root == NULL){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> word = word;
    newNode -> frequency = 1;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
  }
  int wordCompare = strcmp((root->word), word);
  if(wordCompare==0){
    root -> frequency++;
    return root;
  }
  else if(wordCompare < 0){
    root -> left = addWord(root->left, word);
    return root;
  }
  else{
    root -> right = addWord(root->right, word);
    return root;
  }
  
}

// Prints the entire contents of the BST using the write() system call
void printTree(Node* root){
  void nodePrint(Node*);

  if(root->left!=NULL){
    printTree(root->left);
  }
  nodePrint(root);
  if(root->right!=NULL){
    printTree(root->right);
  }
}

//Safely prints the word from a tree node using the write() system call. 
//FUTURE WORK ~~~~~~~~~ Include the frequency and proper formatting
void nodePrint(Node* root){
  char* outNewLine(char*);
  if(root->word!=NULL){
    char* output = outNewLine(root->word);
    int written = write(1, output, sizeof(output));
    free(output);
    if(written<0){
      //Throw error somehow... perror? Or maybe that's not allowed
      exit(-1);
    }
  }    
}

//Assuming word ends with the end of string character, decides if the string uses alphabetic characters (true=1 or false=0)
//Might have problems without the EOS char present in a word
int isAlpha(char* word){
  for(int i=0; word[i]!='\0'; i++){
    if( ((int) word[i] < 65) || 
        (((int) word[i] > 90) && ((int) word[i] < 97)) || 
        ((int) word[i] > 122)
      ){
        return 0;
      }
  }
  return 1;
}

//Adds the \n character to a string 
//DONT FORGET to FREE the returned string AFTER USE
//FUTURE WORK ~~~~~~~~~ Include the frequency and proper formatting
char* outNewLine(char* input){
  char* output = (char*) malloc(sizeof(input)+1);
  strcpy(output, input);
  strcat(output, "\n");
  return output;
}

// NOT NECESSARY - future improvements, use bubble sort to sort the tree by frequency after all words are stored. 
// WILL SCREW UP TREE if used before all words added
void sortByFrequency(Node* root){

}
