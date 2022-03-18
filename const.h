#pragma once
#include<direct.h>

#define slen 30 

const int ml[12] = {31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void dataBase()
{
    mkdir("data");
    mkdir("data\\schoolyears");
    mkdir("data\\classes");
}