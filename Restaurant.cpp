//
// Created by ravidlevy99 on 11/8/18.
//
#include "Dish.h"
#include "Table.h"
#include "Restaurant.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iosfwd>
#include <algorithm>
using namespace std;

Restaurant::Restaurant(): open(false), tables(std::vector<Table*>()), menu(std::vector<Dish>()), actionsLog(std::vector<BaseAction*>()){}

Restaurant::Restaurant(const std::string &configFilePath): open(false), tables(std::vector<Table*>()), menu(std::vector<Dish>()), actionsLog(std::vector<BaseAction*>())
{
    ReadFile(configFilePath);
}

inline std::string trim(const std::string &s)
{
    auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c){return std::isspace(c);});
    auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c){return std::isspace(c);}).base();
    return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

std::vector<std::string> split(const std::string &string, char delimiter)
{
    std::stringstream stream(string);
    std::string item;
    std::vector<std::string> elements;

    while (std::getline(stream, item, delimiter))
        elements.push_back(item);

    return elements;
}

void Restaurant::ReadFile(const string& configFilePath)
{
    ifstream stream(configFilePath);

    int counter(0), hashtags(0);

    string line;
    std::vector<std::string> strings;

    getline(stream, line);

    while (stream)
    {
        line = trim(line);

        if(line.compare("") != 0)
        {
            if(line[0] == '#')
                hashtags++;

            else
                {
                strings = split(line, ',');

                if (hashtags == 2)
                    for (auto string: strings)
                        tables.push_back(new Table(stoi(string)));

                else if (hashtags == 3)
                {
                    DishType type;

                    if (strings[1].compare("ALC") == 0) type = ALC;
                    else if (strings[1].compare("BVG") == 0) type = BVG;
                    else if (strings[1].compare("SPC") == 0) type = SPC;
                    else type = VEG;

                    menu.push_back(Dish(counter, strings[0], stoi(strings[2]), type));
                    counter++;
                }
            }
        }

        getline(stream, line);
    }

    stream.close();
}

const std::vector<BaseAction*>& Restaurant::getActionsLog() const
{
    return actionsLog;
}

std::vector<Dish>& Restaurant::getMenu()
{
    return menu;
}

int Restaurant::getNumOfTables() const
{
    return tables.size();
}

void Restaurant::start()
{
    open = true;
}

Table* Restaurant::getTable(int ind)
{
    if(ind >= tables.size())
        return nullptr;
    return tables.at(ind);
}

std::vector<Table*> Restaurant::getTables() {
    return tables;
}

void Restaurant::CloseRestaurant() {
    open = false;
}

void Restaurant::copy(const Restaurant& restaurant)
{
    open = restaurant.open;

    for(auto table: restaurant.tables)
    {
        tables.push_back(table->clone());
    }

    for(auto dish: restaurant.menu)
    {
        menu.push_back(dish);
    }

    for(auto action: restaurant.actionsLog)
    {
        actionsLog.push_back(action->clone());
    }
}

void Restaurant::clear()
{
    for(auto table: tables)
    {
        delete table;
    }

    tables.clear();

    for(auto action: actionsLog)
    {
        delete action;
    }

    actionsLog.clear();
}

//Rule of 5

Restaurant::~Restaurant()
{
    clear();
}

Restaurant::Restaurant(const Restaurant& restaurant)
{
    copy(restaurant);
}

Restaurant& Restaurant::operator=(const Restaurant &restaurant) {
    if(this == &restaurant)
        return *this;
    clear();
    copy(restaurant);
}

Restaurant::Restaurant(Restaurant &&restaurant)
{
    copy(restaurant);
    for(auto table: restaurant.tables)
    {
        table = nullptr;
    }
    restaurant.tables.clear();

    for(auto action: restaurant.actionsLog)
    {
        action = nullptr;
    }
    restaurant.actionsLog.clear();
}

Restaurant& Restaurant::operator=(Restaurant &&restaurant) {
    if(this == &restaurant)
        return *this;

    clear();
    copy(restaurant);

    for(auto table: restaurant.tables)
    {
        table = nullptr;
    }
    restaurant.tables.clear();

    for(auto action: restaurant.actionsLog)
    {
        action = nullptr;
    }
    restaurant.actionsLog.clear();

    return *this;
}