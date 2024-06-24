//termwork 3 emulate unix


#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
using namespace std;
int main( int argc , char* argv[] )
 {
   if( ((argc<3) || (argc>4)) || (argc==4 && strcmp(argv[1],"-s")) )
    { 
      cerr<<"Usage : "<< argv[0]<<" [-s] <orig_file> <new_file> \n";
      return 1;
    }
   if( argc == 4 )   // programName -s <source_file> <destination_file>
    {
      if( symlink( argv[2] ,argv[3] ) == -1 )
        {
	  	perror("link");   		return 1;
	   }
           cout<<"Symbolic | Soft link of File created successfully\n";
    }


if( argc == 3 )  // programName <source_file> <destination_file>
    {
	   if( link(argv[1],argv[2]) == -1 )
	    {
	      perror("link"); 
	      return 1;
	    }
	   cout<<"Hard link of File created successfully\n";
    }
   return 0; 
 }

