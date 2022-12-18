#include "graphics.hpp"
#include "button.hpp"
#include "string"
using namespace genv;
using namespace std;

Button::Button(int x, int y, int sx, int sy,string s,string p) : Widget(x,y,sx,sy),txt(s),player(p){
    selected = false;
}
void Button::draw(){
        gout << move_to(150, 150) << color(100,100,100) << box(450, 450);
        if(player == "Player 1 Won"){
            gout << move_to(x+10, y-90) << color (255,0,0) << text(player);
        }else if(player == "Player 2 Won"){
            gout << move_to(x+10, y-90) << color (0,0,255) << text(player);
        }else{
            gout << move_to(x+50, y-90) << color (0,255,0) << text(player);
        }
            gout << move_to(x, y) << color(255,255,255) << box(sx, sy);
            gout << move_to(x+4, y+4) << color(0,0,255) << box(sx-8,sy-8);
        gout << move_to(x+30, y+20) << color (0,0,0) << text(txt);
}

void Button::eventhandler(event ev){
    if(ev.type == ev_mouse && isselected(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        selected = true;
    }
    if(ev.button == btn_left && !isselected(ev.pos_x, ev.pos_y))
        selected = false;
}

bool Button::Getselected(){
    return selected;
}

bool Button::Setselected(bool b){
    selected = b;
}

void Button::Setplayer(string s){
    player = s;
}
//