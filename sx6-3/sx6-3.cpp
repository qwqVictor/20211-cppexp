#include <iostream>
#include <cstdint>
#include <cstdio>

union IP {
    uint32_t ip_int;
    struct {
        uint8_t ip4, ip3, ip2, ip1;
    };
    bool operator==(IP const &other) {
        return ip_int == other.ip_int;
    }
};

void setIP(IP& ip, char *pIp);
void setIP(IP& ip, uint8_t ip1, uint8_t ip2, uint8_t ip3, uint8_t ip4);
void setIP(IP& ip, uint32_t iIp);
IP hostAddress(IP& ip, IP& mask);
IP netAddress(IP& ip, IP& mask);
void print(IP& ip);

void sendTo(IP ipSend, IP ipReceive, char pData, IP mask, IP ipGateway);

int main() {
    IP ipSend, ipReceive, mask, ipGateway;
    setIP(ipSend, 0xc0a80103);              // 192.168.1.3
    setIP(ipReceive, (char*)"192.168.1.2");
    setIP(mask, 255, 255, 255, 0);
    setIP(ipGateway, 3232235777);
    sendTo(ipSend, ipReceive, '1', mask, ipGateway);
    return 0;
}

void setIP(IP& ip, char *pIp) {
    uint32_t ip1, ip2, ip3, ip4;
    sscanf(pIp, "%u.%u.%u.%u", &ip1, &ip2, &ip3, &ip4);
    setIP(ip, (uint8_t)ip1, (uint8_t)ip2, (uint8_t)ip3, (uint8_t)ip4);
}
void setIP(IP& ip, uint8_t ip1, uint8_t ip2, uint8_t ip3, uint8_t ip4) {
    ip.ip1 = ip1, ip.ip2 = ip2, ip.ip3 = ip3, ip.ip4 = ip4;
}
void setIP(IP& ip, uint32_t iIp) {
    ip.ip_int = iIp;
}
IP hostAddress(IP& ip, IP& mask) {
    IP host;
    host.ip_int = ((mask.ip_int)^(-1))&(ip.ip_int);
    return host;
}
IP netAddress(IP& ip, IP& mask) {
    IP net;
    net.ip_int = (ip.ip_int) & (mask.ip_int);
    return net;
}
void print(IP& ip) {
    printf("%d.%d.%d.%d", ip.ip1, ip.ip2, ip.ip3, ip.ip4);
}

void sendTo(IP ipSend, IP ipReceive, char pData, IP mask, IP ipGateway) {
    if (netAddress(ipSend, mask) == netAddress(ipReceive, mask)) {
        print(ipReceive);
    }
    else {
        print(ipGateway);
    }
}