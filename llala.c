#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <unistd.h>
#include <stdbool.h>

const char* suitUnicode[] = {"\u2661", "\u2663", "\u2662", "\u2660",};
// HEARTS, CLUBS, DIAMONDS, SPADES
const char* ranks[] =
{"2", "3", "4", "5", "6", "7", "8", "9", "10", "JACK", "QUEEN", "KING", "ACE"};


typedef struct card{
  int suit;
  int rank;
  int value;
} card;

typedef struct node {
  card card;
  struct node *next;
} node;

typedef struct list{
  node *head;
  node *tail;
} list;

typedef struct person{
  list person;
  int score; 
} person;

void printCard(card card){
  printf("%s %s value: %d\n", suitUnicode[card.suit], ranks[card.rank], card.value);
}

void print(list list){
  struct node *cur = list.head;
  while(cur != NULL){
    printf("%s %s value: %d\n",
    suitUnicode[cur->card.suit], ranks[cur->card.rank], cur->card.value);
    cur = cur->next;
  }
  printf("\n");
}

list generateDesk(){
  list desk;
  node *temp = (node*)malloc(sizeof(node));
  temp->card.suit = 0;
  temp->card.rank = 0;
  temp->card.value = 0;
  temp->next = NULL;
  
  desk.head = temp;
  desk.tail = temp;

  // generating
  for(int i = 0; i < 13; i++){ 
    temp = (node*)malloc(sizeof(node));
    temp->card.suit = 0;
    temp->card.rank = i;
    temp->card.value = 2+i;
    if(i>8){
      temp->card.value = 10;
    }if(i==12){
      temp->card.value = 11;
    }
    temp->next = NULL;
    desk.tail->next = temp;
    desk.tail = temp;
  }
  for(int i = 0; i < 13; i++){ 
    temp = (node*)malloc(sizeof(node));
    temp->card.suit = 1;
    temp->card.rank = i;
    temp->card.value = 2+i;
    if(i>8){
      temp->card.value = 10;
    }if(i==12){
      temp->card.value = 11;
    }
    temp->next = NULL;
    desk.tail->next = temp;
    desk.tail = temp;
  }
  for(int i = 0; i < 13; i++){ 
    temp = (node*)malloc(sizeof(node));
    temp->card.suit = 2;
    temp->card.rank = i;
    temp->card.value = 2+i;
    if(i>8){
      temp->card.value = 10;
    }if(i==12){
      temp->card.value = 11;
    }
    temp->next = NULL;
    desk.tail->next = temp;
    desk.tail = temp;
  }
  for(int i = 0; i < 13; i++){ 
    temp = (node*)malloc(sizeof(node));
    temp->card.suit = 3;
    temp->card.rank = i;
    temp->card.value = 2+i;
    if(i>8){
      temp->card.value = 10;
    }if(i==12){
      temp->card.value = 11;
    }
    temp->next = NULL;
    desk.tail->next = temp;
    desk.tail = temp;
  }
  // deleting the first one
  temp = desk.head;
  desk.head = desk.head->next;
  free(temp);

  
  return desk;
}

card get_certain(list list, int n){
  struct node* current = list.head;
  int count = 0;
  while (current != NULL){
    if (count == n){
      return (current->card);
    }
    count++;
    current = current->next;
  }
}

struct node* get_certain_node(list list, int n){
  struct node* current = list.head;
  int count = 0;
  while (current != NULL){
    if (count == n){
      return current;
    }
    count++;
    current = current->next;
  }
}

void printNode(struct node* current){
  printf("%s %s value: %d\n", suitUnicode[current->card.suit], ranks[current->card.rank], current->card.value);
}

int list_quan(list list){
  struct node* current = list.head;
  int count = 0;
  while (current != NULL){
    count++;
    current = current->next;
  }
  return count;
}


void swap(list list, int a, int b){
  if(a != 0 && b != list_quan(list)){
    struct node* curr1 = get_certain_node(list, a);
    struct node* curr2 = get_certain_node(list, b);
    struct node* prev1 = get_certain_node(list, a-1);
    struct node* prev2 = get_certain_node(list, b-1);
    
    struct node* temp = curr2->next;
    prev1->next = curr2;
    curr2->next = curr1->next;
    prev2->next = curr1;
    curr1->next = temp;
  } else{
    // struct node *current = list.head, *temp = NULL, *index = NULL; 
    // temp = list.head;   
    // list.head = current;  
    // list.head->next = temp->next;  
    // index->next = temp;
    // temp->next = NULL; 
  }

}

void shuffle(list list){
  swap(list, 1, 50);
}

int main() {
  list desk = generateDesk();
  print(desk);
  
  // printNode(get_certain_node(desk, 51));
  
  // swap(desk, 2, 6);
  shuffle(desk);
  print(desk);
  
  return 0;
}