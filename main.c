// Headers

#include "starting/startConn.h"
#include "capturing/capture.h"
#include "logging/screen_log.h"

// Libs

#include <net/ethernet.h>

int main(){
	int socket;

	socket = init(); // initializing socket
	
	if (socket < 0){
		return 0;
	}
	
	unsigned char buffer[65536];
		
	int size;

	while (1){
		
		size = capture_packet(socket, buffer, sizeof(buffer));
		if (size<0){
			return 0;
		}

		PacketInfo info;

		int pack = process_packet(buffer, size, &info);
		printing(info);
	}




	return 0;
}




