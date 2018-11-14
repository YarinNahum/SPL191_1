//
// Created by ravidlevy99 on 11/8/18.
//
#include <vector>
#include <string>
#include "Dish.h"
#include "Table.h"
#include "Restaurant.h"

Restaurant::Restaurant(): open(false), tables(std::vector<Table*>()), menu(std::vector<Dish>()), actionsLog(std::vector<BaseAction*>()){}

Restaurant::Restaurant(const std::string &configFilePath): open(false), tables(std::vector<Table*>()), menu(std::vector<Dish>()), actionsLog(std::vector<BaseAction*>()) {}

void Restaurant::readFile()
{

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