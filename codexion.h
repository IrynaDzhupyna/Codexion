#ifndef CODEXION_H
#define CODEXION_H

#include <pthread.h>
#include <unistd.h>

//REMOVE ME
#include <stdio.h>

typedef struct  s_args
{
    int number_of_coders;
    int time_to_burnout;
    int time_to_compile;
    int time_to_debug;
    int time_to_refactor;
    int number_of_compiles_required;
    int dongle_cooldown;
    char    *scheduler;
}   t_args;

typedef struct  s_coder
{
    int id;

}   t_coder;

int	ft_strlen(const char *s);

#endif
