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
			#ifdef USE_NAME
			scanf("%s", input_buffer);
			for ( int i = 0 ; i < users_size ; i++ ) {
				if ( strcmp (users[i].name,input_buffer) == 0 ) {
					input_int_buffer = i;
					goto exit_loop;
				}
			}
			printf("sorry cant find the user %s\n",input_buffer);
			continue;
			exit_loop:
			#endif
			#ifdef USE_NUMBER
				scanf("%d",&input_int_buffer);	
			#endif

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
				users[i].trans[user_number] -= input_int_buffer/users_size ;
			}
			users[user_number].balance +=  2 * (input_int_buffer/users_size) ;
		} else if ( strcmp ( input_buffer ,"e" ) == 0 ) {
			exit(EXIT_SUCCESS);
		} else if ( strcmp ( input_buffer ,"p" ) == 0 ) {
			#ifdef USE_NAME
			scanf("%s", input_buffer);
			for ( int i = 0 ; i < users_size ; i++ ) {
				if ( strcmp (users[i].name,input_buffer) == 0 ) {
					input_int_buffer = i;
					goto exit_loop_1;
				}
			}
			printf("sorry cant find the user %s\n",input_buffer);
			continue;
exit_loop_1:
			#endif
			#ifdef USE_NUMBER
				scanf("%d",&input_int_buffer);	
			#endif
			printf("%s has total  %d $$$$ \n" ,users[input_int_buffer].name , users[input_int_buffer].balance);
			for ( int  i = 0 ; i < users_size ; i++ ) {
				if ( i == input_int_buffer ) continue ; 
				if ( users[input_int_buffer].trans[i] > 0 ) {
					printf(" ++++ %d$ from %s \n",users[input_int_buffer].trans[i] , users[i].name);
				} else { 
					printf(" ---- %d$ to   %s \n", -users[input_int_buffer].trans[i] , users[i].name);
				}
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

