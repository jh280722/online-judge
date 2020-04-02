#include<iostream>
#define HASH_SIZE 100007
using namespace std;


int m_strlen(char* str) {
   register int lng = 0;
   while (*str) {
      lng++;
      *str++;
   }
   return lng;
}

void m_strcpy(char* dst, char* src) {
   while (*dst++ = *src++);
}

bool m_strcmp(char* src1, char* src2) {
   while (*src1) {
      if (*src1++ != *src2++) return false; 
   }
   if (*src2) return false; 
   return true; 
}

int idx; 

struct Node {
   int id;  // 내가 채우고자 하는 데이터 변수 // 배열이나 숫자나 캐릭터나 뭐 문자열 다 가능 string 이거는 지양하고 char [] 선호하자 
   bool exist;
   Node* nxt;  
}nodes[1000001];

Node* newNode() {
   nodes[idx].exist = true; 
   return &nodes[idx++]; 
}

struct List {
   Node* head; 
   Node dummy; 

   void init() {
      head = &dummy; 
      head->nxt = 0; 
   }

   void insert(int id) {
      Node* node = newNode(); 
      node->id = id; 

      node->nxt = head->nxt; 
      head->nxt = node;
   }
}list[HASH_SIZE];


int MY_HASH(char* str) {
   register int lng = m_strlen(str); 
   int key = 0, power = 1;
   for (register int i = 0; i < lng; i++) {
      key += (str[i] * power);
      power *= 3; 
   }
   return key%HASH_SIZE; 
}


int main() {
   char arr[20];
   Node* tmp = list[MY_HASH(arr)].head->nxt;
   while (tmp) {
      if (tmp->exist == false) {
         tmp = tmp->nxt; 
         continue; 
      }

      tmp = tmp->nxt; 
   }

   return 0;
}