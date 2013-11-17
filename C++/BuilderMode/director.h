#ifndef DIRECTOR_H
#define DIRECTOR_H

class Builder;

class Director
{
public:
    ~Director();
    Director(Builder *bld);

    void construct();

private:
    Builder *_bld;
};

#endif // DIRECTOR_H
