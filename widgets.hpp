#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

using namespace genv;

class Widget{
protected:
    int x, y, sx, sy;
public:
    Widget(int x,int y, int sx, int sy);
    virtual bool isselected(int mousex, int mousey);
    virtual void draw() = 0;
    virtual void eventhandler(event ev) = 0;
};

#endif // WIDGETS_HPP_INCLUDED
