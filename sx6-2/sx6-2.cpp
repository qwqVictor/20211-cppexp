/** ALERT: you have to use compiler flag -m32 to get a correct result. */
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::hex;
using std::dec;

namespace union_10_1_3 {
    union Mem {
        unsigned long um;
        signed long sm;
        float fm;
    };

    void main() {
        Mem t;
        t.um = 0xf3000000;
        cout << "sizeof:" << sizeof(t) << endl;
        cout << "addr:" << hex << &t << "/" << t.um << endl << endl;
        cout << "t.um:" << hex << &t.um << "/" << dec << t.um << endl << endl;
        cout << "t.sm:" << hex << &t.sm << "/" << dec << t.sm << endl << endl;
        cout << "t.fm:" << hex << &t.fm << "/" << dec << t.fm << endl << endl;
    }
}

namespace union_10_1_4 {
    union IpAddress {
        unsigned long int ip_int;
        struct {
            unsigned char ip4, ip3, ip2, ip1;
        } ip_string;
    };

    void main() {
        // IPv4 地址 ..........: 192.168.1.6;
        IpAddress ip;
        ip.ip_string.ip1 = 192;
        ip.ip_string.ip2 = 168;
        ip.ip_string.ip3 = 1;
        ip.ip_string.ip4 = 6;
        cout << "IP 地址："
             << (int)ip.ip_string.ip1 << "."
             << (int)ip.ip_string.ip2 << "."
             << (int)ip.ip_string.ip3 << "."
             << (int)ip.ip_string.ip4 << endl;

        IpAddress mask;
        mask.ip_string.ip1 = 255;
        mask.ip_string.ip2 = 255;
        mask.ip_string.ip3 = 255;
        mask.ip_string.ip4 = 0;
        cout << "子网掩码："
             << (int)mask.ip_string.ip1 << "."
             << (int)mask.ip_string.ip2 << "."
             << (int)mask.ip_string.ip3 << "."
             << (int)mask.ip_string.ip4 << endl;

        IpAddress net, host;
        net.ip_int = (ip.ip_int) & (mask.ip_int);
        host.ip_int = ((mask.ip_int)^(-1))&(ip.ip_int);

        cout << "网络地址："
             << (int)net.ip_string.ip1 << "."
             << (int)net.ip_string.ip2 << "."
             << (int)net.ip_string.ip3 << "."
             << (int)net.ip_string.ip4 << endl;

        cout << "主机地址："
             << (int)host.ip_string.ip1 << "."
             << (int)host.ip_string.ip2 << "."
             << (int)host.ip_string.ip3 << "."
             << (int)host.ip_string.ip4 << endl;
    }
}

int main() {
    cout << endl << "=============== 10.1.3 =============" << endl;
    union_10_1_3::main();
    cout << endl << "=============== 10.1.4 =============" << endl;
    union_10_1_4::main();
#ifdef WIN32
    system("pause");
#endif
}