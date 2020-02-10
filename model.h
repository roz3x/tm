//
// model file 
//

#define MAX_USERS 0xff
#define MAX_NAME  0xff

#pragma pack(1)
struct user {
	int 	id;
	char    name[0xff];
	int	balance;	
	int 	trans[MAX_USERS];
};

typedef enum { STATUS_OK , STATUS_NOT_OK } status;
