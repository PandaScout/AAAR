#include <stdio.h>
#include "E101.h"
#include <time.h>

int main(){

connect_to_server("130.195.6.196", 1024);
send_to_server("Please");
char password[24];
receive_from_server(password);
send_to_server(password);
}
