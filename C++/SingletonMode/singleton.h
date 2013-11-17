#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
public:
    static Singleton* interface();

protected:
    Singleton();

private:
    static Singleton* _interface;
};

#endif // SINGLETON_H
