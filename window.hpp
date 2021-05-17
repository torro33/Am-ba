#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include "checkbox.hpp"
#include "button.hpp"
#include <vector>

using namespace std;
using namespace genv;

class Window{
protected:
    vector<vector<Checkbox*>> widgets;
    const int X;
    const int Y;
    const int fields = 15;
    bool run = false;
    int player;
    bool judge;
    Button * btn;
    bool newgamebuttonstatus = false;
public:
    Window(int x, int y);
    void create();
    void eventloop();
    void monitor(int,int);
};

#endif // WINDOW_HPP_INCLUDED
