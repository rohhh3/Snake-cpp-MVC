#include "Gameplay.hpp"
#include "../../Controller/Controller.hpp"
#include <iostream>
namespace View
{
    Gameplay::Gameplay()
    {
        Controller::resetGameplay();
        board_height = Controller::getBoardHeight();
        board_width  = Controller::getBoardWidth();
    }

    Gameplay::~Gameplay(){ }

    void Gameplay::print_board()
    {
        snake_body = Controller::getSnake();
        system("cls");
        board_string = "";
        fruit_position = Controller::getFruitPosition();
        for (int y = 0; y < board_height; ++y)
        {
            for (int x = 0; x < board_width; ++x)
            {
                Position current_position = { x, y };
                if(snake_body.count(current_position))
                    board_string += "S";
                else if(current_position == fruit_position)
                    board_string += "F";
                else
                    board_string += ".";
            }
            board_string += "\n";
        }
        board_string += "\n";
        std::cout << board_string;
        std::cout << "Score: " << Controller::getScore();
/*
        std::cout << "tailpos: "<< static_cast<uint16_t>(tail_position.first)
        << ", " << static_cast<uint16_t>(tail_position.second);
        switch(head_direction)
        {
            case UP:
                std::cout << " head_dir: UP" << std::endl;
                break;
            case RIGHT:
                std::cout << " head_dir: RIGHT" << std::endl;
                break;
            case DOWN:
                std::cout << " head_dir: DOWN" << std::endl;
                break;
            case LEFT:
                std::cout << " head_dir: LEFT" << std::endl;
                break;
        }

        std::cout << "headpos: "<< static_cast<uint16_t>(head_position.first) << ", "
        << static_cast<uint16_t>(head_position.second) << std::endl;
*/
    }

    ESection Gameplay::execute()
    {
        while(true)
        {
            print_board();
            Sleep(80);
            Controller::handleUserInput();
            if(!Controller::moveSnake())
                break;
        }
        //....
        return MAIN_MENU;
    }
}
