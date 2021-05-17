#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "string"
#include "widgets.hpp"

using namespace genv;
using namespace std;

class Button : public Widget{
protected:
    string txt;
    string player;
    bool selected;
public:
    Button(int x,int y,int sx,int sy,string s,string p);
    virtual void draw() override;
    virtual void eventhandler(event ev) override;
    bool Getselected();
    bool Setselected(bool b);
    void Setplayer(string s);
};

#endif // BUTTON_HPP_INCLUDED
