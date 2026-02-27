// Headers 

#include "starting/startConn.h"

// Required libs 
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>
#include <stdio.h>
#include <stdlib.h>

// returns -1 if something goes wrong while creating raw_sock
int init(){
	int raw_sock;
		
	raw_sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

	if (raw_sock < 0){
		perror("Something went wrong!");
		return -1;
	}

	return raw_sock;

}
