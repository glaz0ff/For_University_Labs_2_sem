#ifndef NUMBERS_H
#define NUMBERS_H


class numbers
{
    int cel, chisl, znam, step;
public:
    numbers(){cel = 1; chisl = 1; znam = 1; step = 1;}
    numbers(int ce, int ch, int zn, int st) { cel = ce; chisl = ch; znam = zn; step = st;}
    numbers(const numbers&t) { cel = t.cel; chisl = t.chisl; znam = t.znam; }
    ~numbers() {};

    int get_cel() { return cel; }
    int get_chisl() { return chisl; }
    int get_znam() { return znam; }
    int get_step() { return step; }
    void set_cel(int ce) { cel = ce; }
    void set_chisl(int ch) { chisl = ch; }
    void set_znam(int zn) { znam = zn; }
    void set_step(int st) { step = st; }

    numbers& operator =(const numbers&);
    numbers operator +(const numbers&);
    numbers& operator -(const numbers&);
    numbers& operator *(const numbers&);
    numbers& operator *(const int&);
    numbers& operator /(const numbers&);
    numbers& operator ()();
    numbers& operator--();
    numbers& operator--(int);

    numbers stepen();
};

#endif // NUMBERS_H
