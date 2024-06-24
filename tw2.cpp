#define _POSIX_SOURCE 
#define _POSIX_C_SOURCE 199309L 
#include<unistd.h> 
#include<iostream> 
using namespace std; 
int main(){ 
 #ifdef _POSIX_JOB_CONTROL 
  cout<<"System Supports Job Control feature"<<endl; 
 #else 
  cout<<"System does not support job control\n"; 
 #endif 
  
 #ifdef _POSIX_SAVED_IDS 
  cout<<"System Supports saved set-UID and saved set-GID"<<endl; 
 #else 
  cout<<"System does not support saved set-UID\n"; 
 #endif 
  
 #ifdef _POSIX_CHOWN_RESTRICTED 
  cout<<"System Supports change ownership feature"<<endl; 
 #else 
  cout<<"System does not support change ownership feature\n"; 
 #endif 
 
 #ifdef _POSIX_NO_TRUNC 
  cout<<"System Supports path truncation option."<<endl; 
 #else 
  cout<<"System does not support path truncation\n"; 
 #endif 
 
 #ifdef _POSIX_VDISABLE 
  cout<<"System Supports disable character for files."<<endl; 
 #else 
  cout<<"System does not support disable character\n"; 
 #endif 
 return 0; 
}