#include "src/View/ConsoleInit.hpp"
#include "src/Controller/Controller.hpp"

using namespace std;

int main()
{
    Controller::initGame();
    View::console_init();
    return 0;
}
