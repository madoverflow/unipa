#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 52
#define HAND_SIZE 5

typedef struct card{
 size_t faccia;
 size_t numero;
 size_t seme; 
}Carta;

static void createDeck();
static void displayDeck();
static void createPlayer(size_t player[], char lookuptable[]);
static void displayHand(size_t player[]);
static void mergesortHand(size_t player[]);
static void mergesort(size_t player[], size_t a, size_t b);
static void merge(size_t player[], size_t a, size_t middle1, size_t middle2, size_t b);
static void couple(size_t player[], size_t a, size_t punteggi[]);
static int score(size_t player[], size_t *card);
static void dCouple(size_t player[], size_t punteggi[]);
static void tris(size_t player[], size_t punteggi[]);
static void fp(size_t player[], size_t punteggi[]);
static void scala(size_t player[], size_t punteggi[]);
static void colore(size_t player[], size_t punteggi[]);
static void winner(size_t player[], size_t banco[], int pointsPlayer, int pointsBanco, size_t Pplayer, size_t Pbanco);
static void changeCards(size_t player[], char lookuptable[]);

static char array_facce[2]={'N','R'};
static char array_seme[4]={'P','F','Q','C'};
static char *array_carte[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
static char *strP[]={"Coppia","Doppia Coppia","Tris","Scala","Colore","Full","Poker","Scala colorata","Scala reale"};
static Carta deck[SIZE];

void main(){
 char lookuptable[SIZE]={0};
 size_t player[HAND_SIZE],banco[HAND_SIZE];
 int pointsPlayer,pointsBanco;
 size_t Pplayer,Pbanco;
 srand(time(NULL));
 createDeck();
 createPlayer(player,lookuptable);
 createPlayer(banco,lookuptable);
 //displayDeck(deck);
 printf("Mano del giocatore\n");
 displayHand(player);
 changeCards(player,lookuptable);
 printf("Nuova mano del giocatore\n");
 displayHand(player);
 pointsPlayer=score(player,&Pplayer);
 pointsBanco=score(banco,&Pbanco);
 winner(player,banco,pointsPlayer,pointsBanco,Pplayer,Pbanco);
}

static void createDeck(){
 for(int i=0; i<SIZE; i++){
  deck[i].faccia=(i/26)%2;
  deck[i].seme=(i/13)%4;
  deck[i].numero=i%13;
 }
}

static void displayDeck(){
 for(int i=0; i<SIZE; i++)
  printf("Carta del mazzo -> %s%c %c\n",array_carte[deck[i].numero],array_seme[deck[i].seme],array_facce[deck[i].faccia]);
 printf("\n");
}

static void createPlayer(size_t player[], char lookuptable[]){
 size_t comodo;
 for(int i=0; i<HAND_SIZE; i++){
  comodo=rand()%52;
  if(!lookuptable[comodo]){
   lookuptable[comodo]=1;
   player[i]=comodo;
  }
  else
   i--;
 }
 mergesortHand(player);
}

static void displayHand(size_t player[]){
 size_t faccia;
 size_t seme;
 size_t numero;
 for(int i=0; i<HAND_SIZE; i++){
  faccia=deck[player[i]].faccia;
  seme=deck[player[i]].seme;
  numero=deck[player[i]].numero;
  printf("%s%c %c ",array_carte[numero],array_seme[seme],array_facce[faccia]);
 }
 printf("\n");
}

static void mergesortHand(size_t player[]){
 size_t a=0,b=HAND_SIZE-1;
 mergesort(player,a,b);
}

static void mergesort(size_t player[], size_t a, size_t b){
 if((b-a)>=1){
  size_t middle1=(b+a)/2;
  size_t middle2=middle1+1;
  
  mergesort(player,a,middle1);
  mergesort(player,middle2,b);
  merge(player,a,middle1,middle2,b);
 }
} 

static void merge(size_t player[], size_t a, size_t middle1, size_t middle2, size_t b){
 size_t i=a,j=middle2;
 size_t numero1,numero2,seme1,seme2,k=a;
 size_t support[HAND_SIZE]={0};
 while((i<=middle1)&&(j<=b)){
  numero1=deck[player[i]].numero;
  numero2=deck[player[j]].numero;
  seme1=deck[player[i]].seme;
  seme2=deck[player[j]].seme;
  if((numero1<numero2)||((numero1==numero2)&&(seme1<seme2))){
   support[k]=player[i];
   i++;
  }
  else{
   support[k]=player[j];
   j++;
  }
  k++;
 }
 if(i>middle1)
  while(j<=b){
   support[k]=player[j];
   j++;
   k++;
  }
 else
  while(i<=middle1){
   support[k]=player[i];
   i++;
   k++;
  }
 for(size_t x=a; x<=b; player[x]=support[x],x++);
}

static int score(size_t player[], size_t *card){
 size_t punteggi[9]={0};
 size_t player2[5]={8,9,10,11,12};
 int i,val=-1;
 couple(player,0,punteggi);
 dCouple(player,punteggi);
 tris(player,punteggi);
 fp(player,punteggi);
 scala(player,punteggi);
 colore(player,punteggi);
 for(i=8; (i>=0)&&(!punteggi[i]); i--);
 if(i>=0){
  val=i;
  *card=player[punteggi[i]];
 }
 else
  *card=player[4];
 return val;
}

//Funzioni punteggi
static void couple(size_t player[], size_t a, size_t punteggi[]){
 char flag=1;
 size_t numero1,numero2,k=0;
 for(size_t i=a;(i<HAND_SIZE-1)&&flag;i++){
  numero1=deck[player[i]].numero;
  numero2=deck[player[i+1]].numero;
  if((numero1==numero2)&&flag){
   punteggi[0]=i+1;
   flag=0;
   k=i+1;
  }
 }
}

static void dCouple(size_t player[], size_t punteggi[]){
 size_t comodo;
 size_t a=punteggi[0];
 //coppia presente
 if(punteggi[0]){
  comodo=punteggi[0];
  punteggi[0]=0;
  couple(player,a+1,punteggi);
  //accensione doppia coppia
  if(punteggi[0])
   punteggi[1]=punteggi[0];
  //ripristino valore
  punteggi[0]=comodo;
 }
}

static void tris(size_t player[], size_t punteggi[]){
 char flag=1;
 size_t numero1,numero2,numero3,k=0;
 size_t a=punteggi[0];
 //coppia presente
 if(punteggi[0]){
  if(a!=HAND_SIZE-1){
   numero1=deck[player[a]].numero;
   numero2=deck[player[a+1]].numero;
   //numero accanto alla coppia
   if(numero1==numero2){
    punteggi[2]=a+1;
    return;
   }
   //numero non accanto alla coppia
   else
    a++;
  }
  //coppia alla fine della mano
  else
   a=0;
 }
 for(size_t i=a;(i<HAND_SIZE-2)&&flag;i++){
  numero1=deck[player[i]].numero;
  numero2=deck[player[i+1]].numero;
  numero3=deck[player[i+2]].numero;
  if((numero1==numero2)&&(numero2==numero3)&&flag){
   punteggi[2]=i+2;
   flag=0;
  }
 }
}
static void fp(size_t player[], size_t punteggi[]){
 size_t numero1,numero2,numero3;
 if(punteggi[2]&&punteggi[1]){
  numero1=deck[player[punteggi[0]]].numero;
  numero2=deck[player[punteggi[1]]].numero;
  numero3=deck[player[punteggi[2]]].numero;
  if(numero1!=numero2)
   punteggi[5]=punteggi[2];
  else
   punteggi[6]=punteggi[1];
 }
}

static void scala(size_t player[], size_t punteggi[]){
 size_t numero1,numero2,numero3;
 size_t i=0;
 if(!punteggi[0]&&!punteggi[1]&&!punteggi[2]&&!punteggi[5]&&!punteggi[6]){
  do{
   numero1=deck[player[i]].numero;
   numero2=deck[player[i+1]].numero;
   i++;
  }while((i<HAND_SIZE-1)&&(numero2==(numero1+1)));
  if(i==4){
   numero3=deck[player[0]].numero;
   if((numero2==(numero1+1))||((numero2==12)&&(numero3==0))){
    punteggi[3]=4;
    if((numero3==8)&&(numero2==12))
     punteggi[8]=4;
   }
  }
 }
}

static void colore(size_t player[], size_t punteggi[]){
 size_t colore=deck[player[0]].faccia;
 size_t faccia=deck[player[0]].faccia;
 int i;
 for(i=4; (i>=0)&&(faccia==colore); faccia=deck[player[i]].faccia,i--);
 if(i<0){
  punteggi[4]=4;
  if(punteggi[3])
   punteggi[7]=4;
 }
}

static void winner(size_t player[], size_t banco[], int pointsPlayer, int pointsBanco, size_t Pplayer, size_t Pbanco){
 size_t numero1=deck[Pplayer].numero,numero2=deck[Pbanco].numero;
 size_t seme1=deck[Pplayer].seme,seme2=deck[Pbanco].seme;
 size_t faccia;
 printf("Mano del banco\n");
 displayHand(banco);
 
 if((pointsPlayer==-1)&&(pointsBanco==-1)){
  if(numero1==numero2){
   if(seme1>seme2)
    printf("Vincita del giocatore per seme piu' alto %c\n",array_seme[seme1]);
   else
    printf("Vincita del banco per seme piu' alto %c\n",array_seme[seme2]);
  }
  else{
   if(numero1>numero2)
    printf("Vincita del giocatore per carta piu' alta %s%c\n",array_carte[numero1],array_seme[seme1]);
   else
    printf("Vincita del banco per carta piu' alta %s%c\n",array_carte[numero2],array_seme[seme2]);
  }
 }
 else{
  if(pointsPlayer==pointsBanco){
   if(numero1==numero2){
    if(seme1>seme2)
     printf("Vincita del giocatore. Stesso punteggio (%s), ma seme piu' alto: %c\n",strP[pointsPlayer],array_seme[seme1]);
    else
     printf("Vincita del banco. Stesso punteggio (%s), ma seme piu' alto: %c\n",strP[pointsBanco],array_seme[seme2]);
   }
   else{
    if(numero1>numero2)
     printf("Vincita del giocatore. Stesso punteggio (%s), ma carta piu' alta: %s%c\n",strP[pointsPlayer],array_carte[numero1],array_seme[seme1]);
    else
     printf("Vincita del banco. Stesso punteggio (%s), ma carta piu' alta: %s%c\n",strP[pointsBanco],array_carte[numero2],array_seme[seme2]);
   }
  }
  else{
   if(pointsPlayer>pointsBanco)
    printf("Vincita del giocatore. Punteggio: %s\n",strP[pointsPlayer]);
   else
    printf("Vincita del banco. Punteggio: %s\n",strP[pointsBanco]);
  }
 }
}

static void changeCards(size_t player[], char lookuptable[]){
 int choose=0,carta=0,N;
 size_t comodo;
 char lookCarte[HAND_SIZE]={0};
 do{
 printf("Quante carte vuoi cambiare?\nSe non vuoi cambiare carte, premi 0\n");
 scanf("%d",&N);
 }while((N<0)||(N>5));
 for(size_t i=0; i<N; i++){
  do{
   printf("Quale carta vuoi cambiare?\n");
   scanf("%d",&carta);
  }while((carta<1||carta>5)||lookCarte[carta-1]);
  lookCarte[carta-1]=1;
 }
 for(size_t j=0; j<HAND_SIZE; j++)
  if(lookCarte[j]){
   do{
   comodo=rand()%52;
   }while(lookuptable[comodo]);
   lookuptable[player[j]]=0;
   player[j]=comodo;
   lookuptable[comodo]=1;
   printf("Carta cambiata\n");
  }
 mergesortHand(player);
}
