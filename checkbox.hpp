#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Checkbox : public Widget{
protected:
    bool checked;
    int player;
public:
    Checkbox(int x,int y,int sx,int sy,int player);
    virtual void draw() override;
    virtual void eventhandler(genv::event ev);
    bool Getchecked();
    int Getplayer();
    void Setplayer(int p);
};

#endif // CHECKBOX_HPP_INCLUDED
