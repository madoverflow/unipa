#include <stdbool.h>
#ifdef intero
 typedef int ItemTree;
#else
 #ifdef virgola
  typedef float ItemTree;
 #else
  #ifdef stringhe
   typedef char * ItemTree;
  #else
   typedef char ItemTree;   
  #endif
 #endif
#endif
void treeInit();
bool treeIsEmpty();
void treeInsertNode(ItemTree a);
ItemTree getItem();
void printTree();
bool search(ItemTree a, size_t *count);
ItemTree generateItem();
size_t distance(ItemTree a, ItemTree b);
void treePreOrder();
void treePostOrder();
void treeInOrder();
ItemTree *minimum();
void putItem(ItemTree a);
void deleteMin();
void treeDelete(ItemTree a);
void treeLevelOrder();