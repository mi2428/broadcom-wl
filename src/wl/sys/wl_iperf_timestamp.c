#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/inet.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <wl_iperf_timestamp.h>

extern void wl_create_timestamp(packet_location loc, struct sk_buff *skb) {
    ktime_t ct;
    struct iphdr *iph;
    struct udphdr *udph;
    unsigned char *payload;
    uint32_t sec, usec, pcount;

    ct = ktime_get();
    iph = ip_hdr(skb);
    udph = udp_hdr(skb);
    payload = (unsigned char *)udph + 8;
    sec = ntohl(*(uint32_t *)payload);
    usec = ntohl(*(uint32_t *)(payload + 4));
    pcount = ntohl(*(uint32_t *)(payload + 8));

    if (iph->protocol != 17) return;
    if (ntohs(udph->dest) != IPERF_UDP_PORT) return;
    if (sec > 2147483647) return;
    if (usec > 1000000) return;

    if (loc == PACKET_ARRIVAL) printk("iperf3: ARRIVAL %d %lld\n", pcount, ct);
    if (loc == PACKET_DEPARTURE) printk("iperf3: DEPARTURE %d %lld\n", pcount, ct);

    return;
}
