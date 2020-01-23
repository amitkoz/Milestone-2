#include <string>
#include "StringReverser.h"
#include "Main.h"
int main(int argc, char *argv[]) {
    //set the number of port
    int port =5600;;
    if(argv[1] != NULL) {
        port = stoi(argv[1]);
    }
    //call main method in Main(boot)
    boot::Main().main(port) ;
    return 0;
}

