#include "checkbox.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

Checkbox::Checkbox(int x,int y,int sx,int sy,int p):Widget(x,y,sx,sy),player(p){
    checked = false;
}

void Checkbox::draw(){
    gout << move_to(x, y) << color(255,255,255) << box(sx, sy);//feher
    gout << move_to(x+2, y+2) << color(0,0,0) << box(sx-4, sy-4);//fekete
        if(checked && player%2==0 && player!=0){
            gout << move_to(x+sx/2-14,y+sy/2-25) << color(255,0,0) << text("X");
        }
        if(checked && player%2==1 && player!=0){
            gout << move_to(x+sx/2-17,y+sy/2-25) << color(0,0,255) << text("O");
        }
}

void Checkbox::eventhandler(event ev){
    if (ev.type == ev_mouse && isselected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        checked = true;
    }
}

bool Checkbox::Getchecked(){
    return checked;
}

int Checkbox::Getplayer(){
    return player;
}

void Checkbox::Setplayer(int p){
    player = p;
}

