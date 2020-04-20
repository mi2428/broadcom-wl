#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/inet.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <wl_iperf_timestamp.h>

extern void wl_create_timestamp(enum wl_stamp_location loc, struct sk_buff *skb) {
    struct iphdr *iph = ip_hdr(skb);
    struct udphdr *udph = udp_hdr(skb);
    unsigned char *payload;
    uint32_t *sec, *usec, *pcount;

    payload = (unsigned char *)udph + 8;
    sec = (uint32_t *)payload;
    usec = (uint32_t *)(payload + 4);
    pcount = (uint32_t *)(payload + 8);

    if (iph->protocol != 17) return;
    if (ntohs(udph->dest) != 5201) return;
    if (ntohl(*sec) > 2147483647) return;
    if (ntohl(*usec) > 1000000) return;

    return;
}
