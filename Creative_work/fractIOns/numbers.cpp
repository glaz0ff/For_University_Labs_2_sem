#include "numbers.h"
#include <cmath>
#include <iostream>
using namespace std;

numbers& numbers::operator=(const numbers& t)
{
    if (&t == this) return *this;
    cel = t.cel;
    chisl = t.chisl;
    znam = t.znam;
    return *this;
}

numbers numbers::operator+(const numbers& t)
{

    numbers p;
    chisl = (cel*znam) + chisl;
    p.chisl = (t.cel*t.znam) + t.chisl;
    p.cel = t.cel;


    if(cel == 0)
    {
        cel = 1;
    }
    if(t.cel == 0)
    {
        p.cel = 1;
    }

    if(znam!=t.znam)
    {
        chisl = chisl*t.znam;
        p.chisl = t.chisl*znam;
        znam = znam*t.znam;
        chisl = chisl + p.chisl;
    }
    else
    {
        chisl = chisl + p.chisl;
    }
    cel = chisl/znam;
    chisl = chisl%znam;

    return *this;
}

numbers& numbers::operator-(const numbers& t)
{
    numbers p;
    //if(cel == 0)
    //{
    //    cel = 1;
    //}
    //if(t.cel == 0)
    //{
    //    p.cel = 1;
    //}
    chisl = cel*znam + chisl;
    p.chisl = t.cel*t.znam + t.chisl;
    if(znam!=t.znam)
    {
        chisl = chisl*t.znam - p.chisl*znam;
        znam = znam*t.znam;
    }
    else
    {
        chisl = chisl - p.chisl;
        znam = t.znam;
    }
    cel = chisl/znam;
    chisl = chisl%znam;
    return *this;
}

numbers& numbers::operator*(const numbers& t)
{
    numbers p;

    if(cel == 0)
    {
        cel = 1;
    }
    if(t.cel == 0)
    {
        p.cel = 1;
    }
    cel *= p.cel;
    chisl *= t.chisl;
    znam *= t.znam;
    return *this;
}

numbers& numbers::operator*(const int& t)
{
    if(t == -1)
    {
    cel *= t;
    }
    else
    {
        cel *= t;
        chisl *= t;
        znam *= t;
    }
    return *this;
}

numbers& numbers::operator/(const numbers& t)
{
    numbers p, k;
    if(cel == 0)
    {
        cel = 1;
    }
    if(t.cel == 0)
    {
        p.cel = 1;
    }
    chisl = cel*znam + chisl;
    p.chisl = t.cel*t.znam + t.chisl;

    k.chisl = t.chisl;
    p.chisl = t.znam;
    p.znam = k.chisl;

    chisl *= p.chisl;
    znam *= p.znam;

    cel = chisl/znam;
    chisl = chisl%znam;

    return *this;
}

numbers& numbers::operator()()
{
    this->cel = pow(cel,step);
    this->chisl = pow(chisl,step);
    this->znam = pow(znam,step);
    return *this;
}

numbers& numbers::operator--()
{
    cel = chisl/znam;
    chisl = chisl%znam;
    return *this;
}

numbers& numbers::operator--(int)
{
    cel = chisl/znam;
    chisl = chisl%znam;
    return *this;
}

numbers numbers::stepen()
{

    //numbers p;

    for(int i = 1; i < step; i++)
    {
        chisl = chisl*chisl;
        znam = znam*znam;
        cel = cel*cel;

    }


    return *this;
}
