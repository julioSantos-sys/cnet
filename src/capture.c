#include "capturing/capture.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>
#include <stddef.h>
#include <string.h>

int capture_packet(int sock, unsigned char *buffer, int buffer_size){
	return recvfrom(sock, buffer, buffer_size, 0, NULL, NULL);
}

int process_packet(unsigned char *buffer, int size, PacketInfo *info){
	struct ethhdr *eth = (struct ethhdr *)buffer;

	if (ntohs(eth->h_proto) != ETH_P_IP) return 0;

	struct iphdr *ip = (struct iphdr*)(buffer + sizeof(struct ethhdr));

	info->is_ip = 1;
    info->protocol = ip->protocol;

    struct sockaddr_in src, dst;
    src.sin_addr.s_addr = ip->saddr;
    dst.sin_addr.s_addr = ip->daddr;

    strcpy(info->src_ip, inet_ntoa(src.sin_addr));
    strcpy(info->dst_ip, inet_ntoa(dst.sin_addr));

    if (ip->protocol == IPPROTO_TCP) {

        struct tcphdr *tcp =
            (struct tcphdr *)(buffer +
                              sizeof(struct ethhdr) +
                              ip->ihl * 4);

        info->src_port = ntohs(tcp->source);
        info->dst_port = ntohs(tcp->dest);
    }
    return 1;
}


