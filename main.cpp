#include "window.hpp"

using namespace std;
using namespace genv;

int main()
{
    Window * win = new Window(750,750);
    win->eventloop();
    return 0;
}//main
