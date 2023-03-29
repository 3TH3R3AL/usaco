/*
ID: oliverm4
TASK: beads
LANG: C++                 
*/
#include <fstream>
#include <iostream>
using namespace std;
struct sequence
{
  char color;
  int number;
  sequence *next;
};

void freeSequence (struct sequence *root){
  struct sequence *current = root;
  struct sequence *tmp;
  do {
    tmp = current->next;
    free(current);
    current = tmp;
  } while (current != root);
};


int main()
{
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");
  int n;
  struct sequence *root = (struct sequence *) malloc(sizeof(struct sequence));
  struct sequence *head = root;
  fin >> n;
  fin >> head->color;
  head->next = 0;
  head->number = 1;
  // Convert to continous strands
  for(int i = 0;i<n-1;i++){
    char current;
    fin >> current;
    if(current == head->color){
      head->number++;
      continue;
    }
    struct sequence *tmp = (struct sequence *) malloc(sizeof(struct sequence));
    head->next = tmp;
    head = tmp;
    head->color=current;
    head->number = 1;
  }

  // Edge Case: there is only one strand
  if(root->next == 0){
    fout << n << "\n";
    return 0;
  }
  // Compact head to root if they are the same color
  if(head->color == root->color){
    root->number += head->number;
    struct sequence *tmp = root;
    while(tmp->next != head){
      tmp=tmp->next;
    }
    free(head);
    head = tmp;
  
  }
  
  // Wrap the head to root
  head->next = root;
  
  //Make sure root is red or blue
  while(root->color == 'w'){
    root = root->next;
  }
  
  // Second Condensation: Go from RWR -> R, BWB -> B, BR -> BWR, RB -> RWB
  head = root;
  int condensed;
  do {
    if(root == head){
      condensed = 1;
    }
    // RB -> RWB, BR -> BWR
    if(head->next->color != 'w'){
      struct sequence *tmp = (struct sequence *) malloc(sizeof(struct sequence));
      tmp->number = 0;
      tmp->color = 'w';
      tmp->next = head->next;
      head->next = tmp;
      condensed = 0;
    }
    if(head->next->next == head){
      continue;
    } 
    // RWR -> R, BWB -> B
    if(head->next->next->color == head->color){
      head->number += head->next->next->number + head->next->number;
      struct sequence *tmp = head->next;
      head->next = head->next->next->next;
      if(tmp == root || tmp->next == root){
        root = head;
      }
      free(tmp->next);
      free(tmp);
      condensed = 0;
      continue;
    }
    head = head->next->next;
  } while (condensed != 1 || head != root);
  
  // Edge cases: there are not enough strands
  int length = 0;
  head = root;
  do
  {
    length++;
    head = head->next;
  } while(head != root);
  if(length == 2){
    fout << head->number + head->next->number << "\n";
    return 0;
  }
  if(length == 4){
    fout << head->number + head->next->number + head->next->next->number  + head->next->next->next->number << "\n";
    return 0;
  }
  // Iterate through all WRWBW Sets to compare, as it is now all in the form WRWBWRWBW, etc
  int max = 0;
  head = root->next;
  do {
    int sum = head->number + head->next->number + head->next->next->number + head->next->next->next->number + head->next->next->next->next->number;
    if(sum > max)
      max = sum;
    head = head->next->next;
  } while (head->next != root);
  fout << max << "\n";
  freeSequence(root);
  return 0;
}

