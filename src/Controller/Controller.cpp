#include "Controller.hpp"
#include <iostream>
namespace Controller
{
    void initGame(){
        Model::section = Model::MAIN_MENU;
    }

    bool doesScoreQualify(int32_t fresh_score){
        if(
           Model::scoreboard.empty() ||
           fresh_score > Model::scoreboard.back().score ||
           Model::scoreboard.size() < Model::MAX_SCOREBOARD_SIZE
           )
            return true;
        else
            return false;
    }

    void addScoreboardEntry(std::string player_name, int32_t fresh_score){
        // Binary insertion sort in descending order
        Model::ScoreboardEntry new_entry;
        new_entry.name       = player_name;
        new_entry.score      = fresh_score;

        int low            = 0;
        int high           = Model::scoreboard.size() - 1;
        int insertPosition = -1;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(Model::scoreboard[mid].score > fresh_score)
                low = mid + 1;
            else if(Model::scoreboard[mid].score < fresh_score)
                high = mid - 1;
            else
            {
                insertPosition = mid;
                break;
            }
        }

        if (insertPosition == -1)
            insertPosition = low; // If not found, insert after the closest lower score

        if(doesScoreQualify(new_entry.score))
            Model::scoreboard.insert(Model::scoreboard.begin() + insertPosition, new_entry);
    }

    Model::ScoreboardEntry getScoreboardEntry(uint16_t id){
        if(id < Model::scoreboard.size())
            return Model::scoreboard[id];

        else
        {
            //nie jestem pewien jak to obsluzyc
            Model::ScoreboardEntry none;
            return none;
        }
    }

    void setSection(Model::ESection section){
        Model::section = section;
    }

    Model::ESection getCurrentSection(){
        return Model::section;
    }
}

