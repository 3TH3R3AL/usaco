/*
ID: oliverm4
TASK: milk2
LANG: C++                 
*/
#include <fstream>
#include <iostream>
using namespace std;

struct interval {
  int low;
  int high;
  struct interval *next;
};
void printInterval(interval* root){
  while (root != 0){
    cout << root->low << " | " << root->high << "\n";
    root = root->next;
  }
}
void freeInterval (struct interval *root){
  freeInterval(root->next);
  free(root);
};
int checkInterval(struct interval *toCheck, int high, int low){
  if(low > toCheck->high){
    return 0;
  }
  if(high < toCheck->low){
    return 1;
  }
  int ret = 3;
  if(high > toCheck->high){
     toCheck->high = high;
     ret += 2;  
  }
  if (low < toCheck->low){
     toCheck->low = low;
     ret += 1;
  }
  return ret;
}
struct interval *findPrevious(struct interval *root, struct interval *head){
  if(root == head){
    return 0;   
  }
  while(true){    
    if(root->next = head){
      return root;
    }
     root = root->next; 
  }
}
int main()
{
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");
  
  int n;
  fin >> n;
  struct interval *root = (interval *) malloc(sizeof(struct interval));
  struct interval *head;
  fin >> root->low;
  fin >> root->high;
  root->next = 0;
  if(n == 1){
    fout << root->high - root->low << " " << 0 << "\n";
    return 0;
  }
  for(int i = 0;i<n-1;i++){
    head = root;
    int low, high;
    fin >> low; 
    fin >> high;
    int ret = 0;
    while(true){
      ret = checkInterval(head,high,low);
      if(head->next == 0 && ret == 0){
        ret = 2;
      } 
      if(ret)
        break;
      head = head->next;
    }
    while((ret == 5 || ret == 6) && head->next != 0 && head->next->low < high){
      if(head->next->high > high){
        head->high = head->next->high;
      }
      struct interval *tmp = head->next;
      head->next = head->next->next;
      free(tmp);
    }
    if(ret == 4 || ret == 6){
      struct interval *prev = findPrevious(root,head);
      while(prev && prev->high > low){
        if(prev->low > low){
          prev->low = low;
        }
        if(high > prev->high){
          prev->high = high;
        } 
        
        struct interval *tmp = head;
        prev->next = head->next;
        head = prev;
        free(tmp);
      }


    } 
      
    if(ret == 2){
      struct interval *new_i =(interval *) malloc(sizeof(struct interval));
      head->next = new_i;
      new_i->low = low;
      new_i->high = high;
      new_i->next = 0;
    
    } else if(ret == 1){
      struct interval *tmp = findPrevious(root,head);
      
      struct interval *new_i =(interval *) malloc(sizeof(struct interval));
      if(tmp){
        tmp->next = new_i;
      }else{
        root = new_i;
      }
      new_i->low = low;
      new_i->high = high;
      new_i->next = head;
    }  
    ;
  }
  printInterval(root);
  int maxCont = 0;
  int maxInt = 0;
  head = root;
  while(true){
    if(head->high - head->low > maxCont ){
      maxCont = head->high - head->low;
    }
    if(head->next == 0){
      break;
    }
    if(head->next->low - head->high > maxInt){
      maxInt = head->next->low - head->high;
    }
    head = head->next;
  }
  fout << maxCont << " " << maxInt << "\n";
  freeInterval(root);

  return 0;
}
