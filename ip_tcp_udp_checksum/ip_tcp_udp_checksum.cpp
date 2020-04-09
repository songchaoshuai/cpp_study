// ip_tcp_udp_checksum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// ip_tcpudpchecksum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

const int IP_ADDR_LEN = 4;
const int IPPROTO_TCP = 6;
const int IPPROTO_UDP = 17;

unsigned char src_recv[] = { 0x0A,0x0A,0x0A,0x65 };
unsigned char dst_recv[] = { 0x0A,0x0A,0x0A,0x64 };
unsigned char src_send[] = { 0x0A,0x0A,0x0A,0x64 };
unsigned char dst_send[] = { 0x0A,0x0A,0x0A,0x65 };

unsigned char IP[] = { 0x45,0x00,0x00,0x34, \
0x31,0xfb,0x40,0x00, \
0x80,0x06,0x00,0x00, \
0x0a,0x0a,0x0a,0x64, \
0x0a,0x0a,0x0a,0x65 };

//right+
unsigned char UDP_right[] = {
	0x09,0x40,0x09,0x40,0x00,0x86,0x00,0x00,0xff,0x01,0xe4,0x39,0x5d,0x09,0x11,0x5e,
	0x09,0x11,0xff,0x01,0xfc,0x39,0x59,0x09,0x11,0x5c,0x09,0x11,0xff,0x01,0x14,0x3a,
	0x56,0x09,0x11,0x55,0x09,0x11,0xff,0x01,0x2c,0x3a,0x54,0x09,0x11,0x51,0x09,0x11,
	0xff,0x01,0x44,0x3a,0x4f,0x09,0x11,0x4d,0x09,0x11,0xff,0x01,0x5c,0x3a,0x4d,0x09,
	0x11,0x4c,0x09,0x11,0xff,0x01,0x74,0x3a,0x4a,0x09,0x11,0x4b,0x09,0x11,0xff,0x01,
	0x8c,0x3a,0x46,0x09,0x11,0x46,0x09,0x11,0xff,0x01,0xa4,0x3a,0x49,0x09,0x10,0x51,
	0x09,0x0e,0xff,0x01,0xbc,0x3a,0x65,0x09,0x0b,0x81,0x09,0x0a,0xff,0x01,0xd4,0x3a,
	0x8f,0x09,0x0a,0x87,0x09,0x0b,0xff,0x01,0xec,0x3a,0x6b,0x09,0x0e,0x55,0x09,0x10,
	0xc3,0x2f,0x93,0xa0,0x37,0x22 };
//wrong
unsigned char UDP_wrong[] = {
	0x09,0x40,0x09,0x40,0x00,0x86,0x00,0x00,
	0xff,0x01,0xc4,0x38,0x89,0x09,0x11,0x86,
	0x09,0x11,0xff,0x01,0xdc,0x38,0x83,0x09,
	0x11,0x84,0x09,0x11,0xff,0x01,0xf4,0x38,
	0x84,0x09,0x11,0x7f,0x09,0x11,0xff,0x01,
	0x0c,0x39,0x7c,0x09,0x11,0x78,0x09,0x11,
	0xff,0x01,0x24,0x39,0x76,0x09,0x12,0x76,
	0x09,0x11,0xff,0x01,0x3c,0x39,0x74,0x09,
	0x11,0x73,0x09,0x11,0xff,0x01,0x54,0x39,
	0x72,0x09,0x11,0x72,0x09,0x11,0xff,0x01,
	0x6c,0x39,0x6d,0x09,0x12,0x6f,0x09,0x11,
	0xff,0x01,0x84,0x39,0x6b,0x09,0x11,0x69,
	0x09,0x12,0xff,0x01,0x9c,0x39,0x6a,0x09,
	0x11,0x65,0x09,0x11,0xff,0x01,0xb4,0x39,
	0x65,0x09,0x11,0x61,0x09,0x12,0xff,0x01,
	0xcc,0x39,0x64,0x09,0x11,0x62,0x09,0x12,
	0xbc,0x2d,0x93,0xa0,0x37,0x22 };

unsigned char tcp_test_send[] = {
	0xc1,0x6b,0x09,0x40,0x53,0x27,0x56,0x77,
	0x00,0x00,0x00,0x00,0xa0,0x02,0x72,0x10,
	0x00,0x00,0x00,0x00,0x02,0x04,0x05,0xb4,
	0x04,0x02,0x08,0x0a,0xbd,0xdd,0x83,0xd9,
	0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x07
};

unsigned char tcp_test_recv[] = {
	0x09 ,0x40 ,0xda ,0x6f ,0xaf ,0xdc ,0x05 ,0xb6 ,0x2d ,0xce ,0x18 ,0x64 ,0x50 ,0x18,
	0x20 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0xff ,0x01 ,0xf8 ,0x75 ,0xc8 ,0x08 ,0xa1 ,0xcd ,0x08 ,0xa0,
	0xff ,0x01 ,0x38 ,0x76 ,0xd2 ,0x08 ,0x9f ,0xd3 ,0x08 ,0x9e ,0xff ,0x01 ,0x78 ,0x76 ,0xda ,0x08,
	0x9c ,0xda ,0x08 ,0x9c ,0xff ,0x01 ,0xb8 ,0x76 ,0xdb ,0x08 ,0x9c ,0xde ,0x08 ,0x9c ,0xb1 ,0x7e,
	0x09 ,0xb0 ,0xd2 ,0x35 ,0x7c ,0x00 ,0x37 ,0x22 ,0x00 ,0x00 ,0x38 ,0x71 ,0xa0 ,0x08 ,0xaa ,0xa2,
	0x08 ,0xa9 ,0xff ,0x01 ,0x78 ,0x71 ,0xa0 ,0x08 ,0xa9 ,0x9f ,0x08 ,0xa9 ,0xff ,0x01 ,0xb8 ,0x71,
	0x9f ,0x08 ,0xaa ,0x9e ,0x08 ,0xad ,0xff ,0x01 ,0xf8 ,0x71 ,0x9e ,0x08 ,0xac ,0xa0 ,0x08 ,0xab,
	0xff ,0x01 ,0x38 ,0x72 ,0x9f ,0x08 ,0xaa ,0xa6 ,0x08 ,0xa7 ,0xff ,0x01 ,0x78 ,0x72 ,0xa4 ,0x08,
	0xa8 ,0xa3 ,0x08 ,0xa9 ,0xff ,0x01 ,0xb8 ,0x72 ,0xa5 ,0x08 ,0xaa ,0xa1 ,0x08 ,0xab ,0x1d ,0x32,
	0x63 ,0x00 ,0x37 ,0x22
};

/*
功能：计算IP报文的checksum
输入参数：
1.initcksum，初始checksum参数，0x0000
2.ptr,IP报文头
3.len，IP报文头的长度
返回值：
ip报文头的checksum
*/
uint16_t ip_chksum(uint16_t initcksum, uint8_t *ptr, int len)
{
	unsigned int cksum;
	int idx;
	int odd;

	cksum = (unsigned int)initcksum;

	odd = len & 1;
	len -= odd;

	for (idx = 0; idx < len; idx += 2) {
		cksum += ((unsigned long)ptr[idx] << 8) + ((unsigned long)ptr[idx + 1]);
	}

	if (odd) {      /* buffer is odd length */
		cksum += ((unsigned long)ptr[idx] << 8);
	}

	/*
	* Fold in the carries
	*/

	while (cksum >> 16) {
		cksum = (cksum & 0xFFFF) + (cksum >> 16);
	}

	return cksum;
}

/*
功能：计算TCP/UDP报文的checksum
输入参数：
1.tcp_udp,确定计算的TCP、UDP协议，值IPPROTO_TCP IPPROTO_UDP
2.initcksum，初始checksum参数，0x0000
3.head,TCP/UDP报文头
4.len，报文头的长度
5.srcaddr,源IP地址
6.destaddr，目的IP地址
返回值：
报文头的checksum
*/
uint16_t tcp_chksum(int tcp_udp, uint16_t initcksum, uint8_t *head, int len, unsigned char  *srcaddr, unsigned char *destaddr)
{
	uint8_t pseudoheader[12];
	uint16_t calccksum;

	memcpy(&pseudoheader[0], srcaddr, IP_ADDR_LEN);
	memcpy(&pseudoheader[4], destaddr, IP_ADDR_LEN);
	pseudoheader[8] = 0; /* 填充零 */
	pseudoheader[9] = tcp_udp;
	//pseudoheader[9] = IPPROTO_UDP; //IPPROTO_UDP
	pseudoheader[10] = (len >> 8) & 0xFF;
	pseudoheader[11] = (len & 0xFF);

	calccksum = ip_chksum(0, pseudoheader, sizeof(pseudoheader));
	calccksum = ip_chksum(calccksum, head, len);
	cout << std::hex << calccksum << endl;
	calccksum = ~calccksum;
	return calccksum;
}

int main()
{
	uint16_t tmp = 0;
	//check the IP checksum
	//ip_chksum 取反
	cout << "The IP head checksum:" << std::endl;
	tmp = ip_chksum(0, IP, 20);
	// f5 e8
	cout << std::hex << ((~tmp >> 8) & 0xff) << " " << ((~tmp) & 0xff) << " " << sizeof(unsigned short) << endl;
	//check the UDPchecksum
	//ip_chksum 取反
	cout << "The UDP head checksum:" << std::endl;
	cout << "the right checksum:" << std::endl;
	tmp = tcp_chksum(IPPROTO_UDP, 0, UDP_right, 134, src_recv, dst_recv);
	//c9 a5
	cout << std::hex << tmp << endl;
	cout << "the wrong checksum:" << std::endl;
	//tmp=tcp_chksum(0, tcp_test, 32, src,dst );
	tmp = tcp_chksum(IPPROTO_UDP, 0, UDP_wrong, 134, src_recv, dst_recv);
	//c9 a5
	cout << std::hex << tmp << endl;
	cout << "The TCP head checksum:" << std::endl;
	cout << "the tcp checksum send:" << std::endl;
	tmp = tcp_chksum(IPPROTO_TCP, 0, tcp_test_send, 40, src_send, dst_send);
	cout << std::hex << tmp << endl;
	cout << "the tcp checksum recv:" << std::endl;
	tmp = tcp_chksum(IPPROTO_TCP, 0, tcp_test_recv, 146, src_recv, dst_recv);
	cout << std::hex << tmp << endl;
	return 0;
}

