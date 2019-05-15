//new stuff
#include "E101.h"


int main(){
char ip[15]="130.195.6.196";
connect_to_server(ip, 1024);
char message[15]="Please";
send_to_server(message);
char password[24];
receive_from_server(password);
send_to_server(password);
}









//old stuff
#include "E101.h"


int main(){
char ip[15]=('1','3','0','.','1','9','5','.','6','.','1','9','6');
connect_to_server(ip, 1024);
char message[15]=('P','l','e','a','s','e');
send_to_server(message);
char password[24];
receive_from_server(password);
send_to_server(password);
}
