#pragma once
#include <direct.h>

#define slen 30 

const int ml[12] = {31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static void dataBase()
{
    _mkdir("data");
    _mkdir("data\\schoolyears");
    _mkdir("data\\classes");
}