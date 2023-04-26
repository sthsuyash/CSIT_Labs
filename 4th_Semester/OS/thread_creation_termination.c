#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Global variable:
int i = 2; //Parent Thread

// Child Thread
void* foo(void* p){
  // Print value received as argument:
  printf("Value recevied as argument in starting routine: ");
  printf("%i\n", * (int*)p);

  // Exit the thread and return ref to global variable i
  pthread_exit(&i);
}

int main(void){
  // Declare variable for thread's ID:
  pthread_t id;

  int j = 1; //local variable for parent
  pthread_create(&id, NULL, foo, &j); //create child thread at foo() and pass j as a parameter
    
  int* ptr;
  // Wait for foo() and retrieve value in ptr;
  pthread_join(id, (void**)&ptr);

  printf("Value recevied by parent from child: ");
  printf("%i\n", *ptr);
}
