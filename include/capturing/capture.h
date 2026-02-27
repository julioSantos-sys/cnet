#ifndef CAPTURE_H
#define CAPTURE_H

typedef struct {
    int is_ip;
    int protocol;   // TCP = 6, UDP = 17
    char src_ip[16];
    char dst_ip[16];
    int src_port;
    int dst_port;
} PacketInfo;

int capture_packet(int sock, unsigned char *buffer, int buffer_size);
int process_packet(unsigned char *buffer, int size, PacketInfo *info);

#endif
