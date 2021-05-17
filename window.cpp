#include "graphics.hpp"
#include "checkbox.hpp"
#include "window.hpp"
#include "button.hpp"
#include "string"
#include <iostream>

using namespace std;
using namespace genv;

Window::Window(int x,int y):X(x), Y(y){
    gout << font("LiberationSans-Regular.ttf",45);
    gout.open(X,Y);
    btn = new Button(225,325,300,100,"New Game","");
}

void Window::create(){
    gout << move_to(0,0) << color(0,0,0) << box(X,Y);//
    for(int i=0;i<fields;i++){//row
            vector<Checkbox*> v1;
        for(int j=0;j<fields;j++){//col
            Checkbox * wij = new Checkbox(50*i,50*j,50,50,0);
            v1.push_back(wij);
        }
        widgets.push_back(v1);
    }
}

void Window::eventloop(){
    event ev;
    player = 1;
    judge = false;
    int focus = -1;
    int focus2 = -1;
    create();
        while(gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left && !run) {
            for(int i=0;i<widgets.size();i++){
                for(int j=0;j<widgets[i].size();j++){
                   if (widgets[i][j]->isselected(ev.pos_x, ev.pos_y) && widgets[i][j]->Getchecked()==false) {
                        player++;
                        focus = i;
                        focus2 = j;
                    }
                }
            }
        }
        if (focus!=-1 && focus2!=-1) {
            widgets[focus][focus2]->Setplayer(player);
            widgets[focus][focus2]->eventhandler(ev);
        }
        for(int i=0;i<widgets.size();i++){//sor i
            for(int j=0;j<widgets[i].size();j++){//oszlop j
               widgets[i][j]->draw();
            }
        }

        if(focus != -1 && focus2 != -1 && !run)
        monitor(focus,focus2);
        if(run){
                if(newgamebuttonstatus){
                    if(btn->isselected(ev.pos_x, ev.pos_y) && ev.type == ev_mouse && ev.button==btn_left){
                        btn->eventhandler(ev);
                        widgets.clear();
                        player = 1;
                        create();
                        run = false;
                        judge = false;
                        newgamebuttonstatus = false;
                        btn->Setselected(false);
                    }
                }else{
                    string win;
                    newgamebuttonstatus = true;
                    if(player == widgets.size()*widgets.size()+1 && !judge){
                        win = "Its a draw";
                    }else if(player%2==0){
                        win = "Player 1 Won";
                    }
                    else if(player%2==1){
                        win = "Player 2 Won";
                    }
                        btn->Setplayer(win);
                }
                btn->draw();
        }
        gout << refresh;
    }//while
}//eventloop

void Window::monitor(int x,int y){
    int counter = 0;
    for(int k = 0;k<2;k++){//player1=páros/player2=páratlan
        if(widgets[x][y]->Getchecked() && widgets[x][y]->Getplayer()%2 == k){
                for(int i = 4;i>=0;i--){//függõleges
                    for(int j = 0;j<5;j++){
                        if(x+j-i >= 0 && x+j-i <= widgets.size()-1){
                            if(widgets[x-i+j][y]->Getchecked() && widgets[x-i+j][y]->Getplayer()%2 == k){
                                counter++;
                                if(counter == 5){run = true;i=-1;judge = true;}
                            }
                        }else{break;}
                    }//for1
                    counter = 0;
                }//for2
                for(int i = 4;i>=0;i--){//vízszintes
                    for(int j = 0;j<5;j++){
                        if(y-i+j >= 0 && y-i+j <= widgets.size()-1){
                            if(widgets[x][y-i+j]->Getchecked() && widgets[x][y-i+j]->Getplayer()%2 == k){
                                counter++;
                                if(counter == 5){run = true;i=-1;judge = true;}
                            }
                        }else{break;}
                    }
                    counter = 0;
                }
                for(int i = 4;i>=0;i--){//balátló
                    for(int j = 0;j<5;j++){
                        if(x-i+j >= 0 && x-i+j <= widgets.size()-1 && y-i+j >= 0 && y-i+j <= widgets.size()-1){
                            if(widgets[x-i+j][y-i+j]->Getchecked() && widgets[x-i+j][y-i+j]->Getplayer()%2 == k){
                                counter++;
                                if(counter == 5){run = true;i=-1;judge = true;}
                            }
                        }else{break;}
                    }
                    counter = 0;
                }
                for(int i = 4;i>=0;i--){//jobbátló
                    for(int j = 0;j<5;j++){
                        if(x-j+i >= 0 && x-j+i <= widgets.size()-1 && y+j-i >= 0 && y+j-i <= widgets.size()-1){
                            if(widgets[x-j+i][y+j-i]->Getchecked() && widgets[x-j+i][y+j-i]->Getplayer()%2 == k){//hibás
                                counter++;
                                if(counter == 5){run = true;i=-1;judge = true;}
                            }
                        }else{break;}
                    }
                    counter = 0;
                }
                int full = 0;//ha tele a tábla és nincs nyerés
                for(int i=0;i<widgets.size();i++){//sor i
                    for(int j=0;j<widgets[i].size();j++){//oszlop j
                        if(widgets[i][j]->Getchecked()){full++;}
                        if(widgets.size()*widgets[i].size() == full){run = true;}
                    }
                }
        }//if
    }//player
}//monitor
