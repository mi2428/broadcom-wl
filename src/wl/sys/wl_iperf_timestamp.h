#ifndef _wl_iperf_timestamp_h_
#define _wl_iperf_timestamp_h_

#define IPERF_UDP_PORT 5201

typedef enum {
    PACKET_ARRIVAL,
    PACKET_DEPARTURE
} packet_location;

extern void wl_create_timestamp(packet_location loc, struct sk_buff *skb);

#endif
