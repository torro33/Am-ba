#include "widgets.hpp"

using namespace genv;

Widget::Widget(int x,int y,int sx,int sy):x(x),y(y),sx(sx),sy(sy){};

bool Widget::isselected(int mousex, int mousey){
    return mousex > x && mousex < x+sx && mousey > y && mousey < y+sy;
}
