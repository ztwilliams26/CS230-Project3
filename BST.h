#ifndef STRING_H
#define STRING_H
#include "string.h"
#endif  //STRING_H

#ifndef STDLIB_H
#define STDLIB_H
#include "stdlib.h"
#endif  //STDLIB_H

#ifndef UNISTD_H
#define UNISTD_H
#include "unistd.h"
#endif  //UNISTD_H

struct BST{
  char* word;
  int frequency;
  struct BST* left;
  struct BST* right;
};
