#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "model.h"

int no_of_users = 0;

char input_buffer[0xff];
int  input_int_buffer;

int main() {

	user users[0xff] = {};	
	int users_size = 0;
	
	while ( true ) {
		#if defined(DEBUG) 
			printf("$> ");
		#endif
		scanf("%s",input_buffer);
		if ( strcmp (input_buffer, "i" ) == 0 ) {
			scanf("%d",&input_int_buffer);
			if (input_int_buffer > users_size-1) {
				printf("wrong user value");
				return EXIT_FAILURE;
			}
			int user_number = input_int_buffer;
			scanf("%d",&input_int_buffer);
			printf("%s added %d \n",users[user_number].name,input_int_buffer);
			for ( int i = 0 ; i < users_size ; i++ ) {
				users[i].balance -= input_int_buffer/users_size ;
				users[user_number].trans[i] += input_int_buffer/users_size ;
			}
			users[user_number].balance +=  2 * (input_int_buffer/users_size) ;
		} else if ( strcmp ( input_buffer ,"e" ) == 0 ) {
			exit(EXIT_SUCCESS);
		} else if ( strcmp ( input_buffer ,"p" ) == 0 ) {
			scanf("%d",&input_int_buffer);
			printf("%s has %d money\n" ,users[input_int_buffer].name , users[input_int_buffer].balance);
			for ( int  i = 0 ; i < users_size ; i++ ) {
				if ( i == input_int_buffer ) continue ; 
				printf("%d$ from %s \n",users[input_int_buffer].trans[i] , users[i].name);
			}
		} else if ( strcmp ( input_buffer , "u" ) == 0 ) {
			scanf("%s",input_buffer);
			users_size++;
			for ( int i = 0 ; i < 255 ; i++ ) {
				users[users_size-1].name[i] = input_buffer[i];
			}
		}
	}

	return EXIT_SUCCESS;
}

