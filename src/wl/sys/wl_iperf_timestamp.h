#ifndef _wl_iperf_timestamp_h_
#define _wl_iperf_timestamp_h_

#define WL_STAMP_ARRIVAL     0
#define WL_STAMP_DEPARTURE   1

#define IPERF_UDP_PORT       5201

enum wl_stamp_location {
    PACKET_ARRIVAL,
    PACKET_DEPARTURE
};

extern void wl_create_timestamp(enum wl_stamp_location loc, struct sk_buff *skb);

#endif
