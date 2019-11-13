/*
 * person.c
 * Copyright (C) 2019 Tim Hughes
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "person.h"


APerson *get_person(const char *name, const char *long_name){

    APerson *fmt = malloc(sizeof(APerson));
    fmt->name = name;
    fmt->long_name = long_name;

    printf("C ptr = %p\n", fmt);

    return fmt;
};

int change_person(APerson *fmt, const char *name, const char *long_name) {

    printf("%p %s %s\n", fmt, name, long_name);

    if (!fmt)
        return -1;
    fmt->name = name;
    fmt->long_name = long_name;

    return 0;
}
