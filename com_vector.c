//
// Created by artemisvenari on 25.03.2022.
//

#include <stdio.h>
#include "com_vector.h"


vector init(){
    m_node = (vector *) malloc(sizeof(vector));

    m_node->poi = (entry *) malloc(sizeof(entry));
    m_node->dat = (entry *) malloc(sizeof(entry));
    m_node->o_poi = (entry **) malloc((sizeof(entry)));
    m_node->o_dat = (entry **) malloc(sizeof(entry));

    *m_node->dat = new();
    *m_node->poi = *m_node->dat;

    *m_node->o_dat = m_node->dat;
    *m_node->o_poi = m_node->poi;

    return *m_node;
}

entry *get_entry(uint16_t index){

}

void reset() {
    *m_node->dat = *m_node->poi;
}

entry new(){
    entry *tmp = (entry *) malloc(sizeof(entry));
    tmp->next = NULL;
    tmp->str = NULL;
    tmp->pos = 1;
    tmp->befor = NULL;
    return *tmp;
}

uint16_t count(){
    entry *tmp = m_node->poi;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp->pos;
}

void append(){
    uint16_t len_1 = count()+1;

    while (m_node->poi->next != NULL) {
        m_node->poi = m_node->poi->next;
    }

    m_node->poi->next = malloc(sizeof(entry));
    *m_node->poi->next = new();

    m_node->poi->next->befor = malloc(sizeof(entry));
    *m_node->poi->next->befor = *m_node->poi;

    m_node->poi->next->pos = len_1;
    *m_node->dat = *m_node->poi->next;
}

void append_c(char *str) {
    uint16_t len_1 = count()+1;

    while (m_node->poi->next != NULL) {
        m_node->poi = m_node->poi->next;
    }

    m_node->poi->next = malloc(sizeof(entry));
    *m_node->poi->next = new();

    m_node->poi->next->befor = malloc(sizeof(entry));
    *m_node->poi->next->befor = *m_node->poi;

    m_node->poi->next->pos = len_1;

    m_node->poi->next->str = malloc(strlen(str));
    m_node->poi->next->str = str;
    *m_node->dat = *m_node->poi->next;
}

bool next() {
    if (m_node->dat->next != NULL) {
        *m_node->dat = *m_node->dat->next;
        return true;
    }
    return false;
}

bool befor() {
    if (m_node->dat->befor != NULL) {
        *m_node->dat = *m_node->dat->befor;
        return true;
    }
    return false;
}

