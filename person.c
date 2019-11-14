/*
 * person.c
 * Copyright (C) 2019 Tim Hughes
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "person.h"


APerson *get_person(const char *name, const char *long_name) {

    APerson *p = malloc(sizeof(APerson));
    p->name = name;
    p->long_name = long_name;

    printf("C ptr = %p\n", p);

    return p;
};

int change_person(APerson *p, const char *name, const char *long_name) {

    if (!p)
        return -1;

    printf("%p %s %s\n", p, name, long_name);
    p->name = name;
    p->long_name = long_name;

    return 0;
}

void clean_person(APerson **p) {
    if (*p) {
        printf("C to clean: %p\n", *p);
        free(*p);
        *p = NULL;
        printf("C Cleaned: %p\n", *p);
    }
}
