struct lista{
 char c;
 struct lista *np;
};
typedef struct lista stru;
void insert(stru **p,const char l);
void delete(stru **src,const char data);
void display(stru *first);
void menu(stru **source);
void insertSort(stru **src, char data);
void pulizia(stru *lista);