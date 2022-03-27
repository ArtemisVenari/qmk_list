//
// Created by artemisvenari on 25.03.2022.
//

#ifndef MAKRO_VEKOR_COM_VECTOR_H
#define MAKRO_VEKOR_COM_VECTOR_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct com{
    char *str;
    uint16_t pos;
    struct com *next;
    struct com *befor;
};
typedef struct com entry;

struct vec{
    entry *poi;
    entry **o_poi;

    entry *dat;
    entry **o_dat;
};

typedef struct vec vector;

static vector *m_node;

vector init();
entry *get_entry(uint16_t index);
entry new();
void reset();

bool next();
bool befor();
void clear();

uint16_t count();

void append();
void append_c(char *str);

bool input(char *in, uint16_t pos);

entry *search(char *str);



#endif //MAKRO_VEKOR_COM_VECTOR_H
