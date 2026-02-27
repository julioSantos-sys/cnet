#include "logging/screen_log.h"
#include "capturing/capture.h"
#include <stdio.h>

int printing(PacketInfo info){
	printf("[%d]%s -> [%d]%s - [%d]\n", info.src_port, info.src_ip, info.dst_port, info.dst_ip, info.protocol);
	return  0;
}

