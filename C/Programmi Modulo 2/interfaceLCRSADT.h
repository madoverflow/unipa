#include <stdbool.h>
#ifdef intero
 typedef int Item;
#else
 #ifdef virgola
  typedef float Item;
 #else
  #ifdef stringhe
   typedef char * Item;
  #else
   typedef char Item;   
  #endif
 #endif
#endif
void lcrsInit();
bool lcrsIsEmpty();
Item getItem();
void lcrsInsert(const Item a);
void lcrsPrint();
void lcrsToBst();
void bstPrint();