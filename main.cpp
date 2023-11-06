#include "src/View/ConsoleInit.hpp"
#include "src/Controller/Controller.hpp"
#include <iostream>

using namespace std;

int main()
{
    Controller::initGame();
    View::console_init();
    // Test the addScoreboardEntry function with some sample entries
    Controller::addScoreboardEntry("Alice", 100);
    Controller::addScoreboardEntry("Bob", 80);
    Controller::addScoreboardEntry("Charlie", 120);
    Controller::addScoreboardEntry("David", 90);
    Controller::addScoreboardEntry("Eve", 110);

    // Display the sorted scoreboard
    std::cout << "Sorted Scoreboard:\n";
    for(const Model::ScoreboardEntry& entry : Model::scoreboard)
        std::cout << entry.name << ": " << entry.score << std::endl;

    return 0;
}
