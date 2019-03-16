#include "BST.h"
#include "string.h"

typedef BST Node;

Node* newTree(char* word){
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
    nweNode -> left = NULL;
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

}
    
//Assuming word ends with the end of string character, decides if the string uses alphabetic characters (true=1 or false=0)
//Might have problems without the EOS char present in a word
int isAlpha(char* word){
  for(int i=0; word[i]!='\0'; i++){
    if( ((int) word[i] < 65) || (((int) word[i] > 90) && ((int) word[i] < 97))) || ((int) word[i] > 122)))
      return 0;
  }
  return 1;
}

// NOT NECESSARY - future improvements, use bubble sort to sort the tree by frequency after all words are stored. 
// WILL SCREW UP TREE if used before all words added
void sortByFrequency(Node* root){

}
