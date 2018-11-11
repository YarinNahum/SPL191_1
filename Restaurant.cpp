//
// Created by ravidlevy99 on 11/8/18.
//
#include <vector>
#include <string>
#include "Dish.h"
#include "Table.h"
#include "Restaurant.h"

Restaurant::Restaurant(): open(false), tables(std::vector<Table*>()), menu(std::vector<Dish>()), actionsLog(std::vector<BaseAction*>()){}
Restaurant::Restaurant(const std::string &configFilePath): open(false), tables(std::vector<Table*>()), menu(std::vector<Dish>()), actionsLog(std::vector<BaseAction*>())
{
    readFile();
}
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
    return tables.at(ind);
}