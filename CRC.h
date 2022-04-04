//
// Created by Shane Sepac on 4/4/22.
//

#ifndef UNTITLED_CRC_H
#define UNTITLED_CRC_H


class CRC {
    /* Table of CRCs of all 8-bit messages. */
    unsigned long crc_table[256];
/* Flag: has the table been computed? Initially false. */
    int crc_table_computed = 0;

public:
    void make_crc_table();
    unsigned long update_crc(unsigned long crc, unsigned char *buf,
                             int len);
    unsigned long crc(unsigned char *buf, int len);
};


#endif //UNTITLED_CRC_H
