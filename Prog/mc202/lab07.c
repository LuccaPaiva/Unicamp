//LUCCA FERREIRA PAIVA 240229


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct vet{
  int capacity;//initial capacity;
  int used;// No. of elements inserted so far
  int *head, *tail, *start, *end;
  int *arr;
}vet;

void atualiza(vet *array){
  if(array->used == 0){
    array->head = array->start;
    array->tail = array->head;
  }
  if(array->used <= array->capacity/4 && array->capacity >= 128*2){
    array->capacity = array->capacity / 2;
    array->arr =  (int *)realloc(array->arr, sizeof(int) * array->capacity);
  }
  if(array->used >= array->capacity && array->capacity < 2024){
    array->capacity = array->capacity * 2;
    array->arr =  (int *)realloc(array->arr, sizeof(int) * array->capacity);
  }
  /*
  else if (array->used >= array->capacity){
    array->capacity = array->capacity + 224;
    array->arr =  (int *)realloc(array->arr, sizeof(int) * array->capacity);
  }
  */
  array->start = array->arr;
  array->end = array->start + array->capacity;
}

void insert_f(vet *array, int num){
  if(array->used == 0){
    *array->head = num;
  }
  else if(array->head > array->start){
      *(array->head - 1) = num;
      array->head = array->head - 1;
  }
  else{
    *(array->end) = num;
    array->head = array->end;
  }
  array->used ++;
}

void remove_f(vet *array){
  if(array->used != 0){
    *array->head = -1;
    if(array->head != array->end){
      array->head ++;
    }
    else{
      array->head = array->start;
    }
    array->used --;
  }
}

void print_f(vet *array){
  if(array->used != 0){
    printf("%d\n", *array->head);
  }
}

void insert_l(vet *array, int num){
  if(array->used == 0){
    *array->tail = num;
    array->head = array->tail;
  }
  else if(array->tail < array->end){
    array->tail ++;
    *array->tail = num;
  }
  else{
    array->tail = array->start;
    *array->tail = num;
  }
  array->used ++;
}

void remove_l(vet *array){
  if(array->used != 0){
    *array->tail = -1;
    if(array->tail != array->start){
      array->tail --;
    }
    else{
      array->tail = array->end;
    }
    array->used --;
  }
}

void print_l(vet *array){
  if(array->used != 0){
    printf("%d\n", *array->tail);
  }
}
void empty(vet *array){
  if(!array->used)
    printf("yes\n");
  else
    printf("no\n");
}



int main(){
    vet *array = malloc(sizeof(vet));
    array->capacity = 128;
    array->used = 0;
    array->arr = malloc(sizeof(int) * array->capacity);
    array->start = array->arr;
    array->end = array->start + array->capacity;
    char in0[15];
    int num;
    scanf("%s", in0);
    do{
        if(strcmp(in0, "insert-first") == 0){
            scanf("%d", &num);
            atualiza(array);
            insert_f(array, num);
        }
        else if(strcmp(in0, "remove-first") == 0){
            remove_f(array);
        }
        else if(strcmp(in0, "print-first") == 0){
            print_f(array);
        }
        else if(strcmp(in0, "insert-last") == 0){
            atualiza(array);
            scanf("%d", &num);
            insert_l(array, num);
        }
        else if(strcmp(in0, "remove-last") == 0){
            remove_l(array);
        }
        else if(strcmp(in0, "print-last") == 0){
            print_l(array);
        }
        else if(strcmp(in0, "is-empty") == 0){
            empty(array);
        }
        scanf("%s", in0);
    }while(strcmp(in0, "exit") );
    return 0;
}
