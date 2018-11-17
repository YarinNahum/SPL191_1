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
    int cusID = 0;
    string input;
    cout << "Restaurant is open!";
    getline(cin , input);
    while (input !="closeall")
    {
        if(input == "menu")
        {
            BaseAction *action = new PrintMenu();
            action->act(*this);
            actionsLog.push_back(action);

        }

        if(input == "log")
        {
            BaseAction *action = new PrintActionsLog();
            action->act(*this);
            actionsLog.push_back(action);
        }

        if(input == "backup")
        {
            BaseAction *action = new BackupRestaurant();
            action->act(*this);
            actionsLog.push_back(action);
        }

        if(input == "restore")
        {
            BaseAction *action = new RestoreResturant();
            action->act(*this);
            actionsLog.push_back(action);
        }

        if(input.substr(0 , 4) == "open" )
        {
            input.erase(0 ,5);
            int tableId = findTableID(input);
            vector <string> tokens = getCustList(input);
            vector<Customer*> customerList;
            for(int i = 0 ; i < tokens.size() ; i++)
            {
                string cust = tokens[i];
                int pos = cust.find(",");
                string Name = cust.substr(0,pos);
                cust.erase(0,pos + 1);
                string Type = cust;
                Customer * C;
                if(Type == "veg")
                    C= new VegetarianCustomer(Name , cusID);
                if(Type == "chp")
                    C = new CheapCustomer(Name , cusID);
                if(Type == "spc")
                    C = new SpicyCustomer(Name, cusID);
                if(Type == "acl")
                    C= new AlchoholicCustomer(Name , cusID);
                customerList.push_back(C);
                cusID++;
            }
            BaseAction *action = new OpenTable(tableId , customerList);
            action->act(*this);
            actionsLog.push_back(action);
        }

        if(input.substr(0,5) == "order")
        {
            int i =stoi(input.substr(6,input.size()));
            BaseAction *action = new Order(i);
            action->act(*this);
            actionsLog.push_back(action);
        }

        if(input.substr(0,5) == "close")
        {
            int i = stoi(input.substr(6,input.size()));
            BaseAction *action = new Close(i);
            action->act(*this);
            actionsLog.push_back(action);
        }

        if(input.substr(0,6) == "status")
        {
            int i = stoi(input.substr(7,input.size()));
            BaseAction *action = new PrintTableStatus(i);
            action->act(*this);
            actionsLog.push_back(action);
        }

        if(input.substr(0,4) == "move")
        {
            input.erase(0 , 5);
            vector<int> vec = getNumbers(input);
            BaseAction *action = new MoveCustomer(vec[0] , vec[1] , vec[2]);
            action->act(*this);
            actionsLog.push_back(action);
        }
    }

    BaseAction *action = new CloseAll();
    action->act(*this);
    actionsLog.push_back(action);
}

std::vector<string> Restaurant::getCustList(std::string input) { // A helper function for the open action
    string del = " ";
    string token;
    vector<string> output;
    size_t pos =0;
    while((pos = input.find(del)) != string::npos)
    {
        token = input.substr(0,pos);
        output.push_back(token);
        input.erase(0,pos +del.length());
    }
    if(input.length()!= 0)
        output.push_back(input);
    return output;
}

std:: vector<int> Restaurant::getNumbers(std::string input) { // A helper function for the MoveCustomer action.
    string del = " ";
    string temp = input;
    size_t pos = 0;
    std::string token;
    vector <int> output;

    while ((pos = temp.find(del)) != std::string::npos) {
        token = temp.substr(0, pos);
        output.push_back(stoi(token));
        temp.erase(0, pos + del.length());
    }
    if(temp.length() != 0)
        output.push_back(stoi(temp));
    return output;
}

int Restaurant::findTableID(string input) { // A helper function to find the tableID for the open action
    string token = input.substr(0 , input.find(" "));
    int i = stoi(token);
    input.erase(0 , token . length()+1);
    return i;
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
    for(int i =0 ; i < restaurant.tables.size() ; i++)
    {
        restaurant.tables[i] = nullptr;
    }
    restaurant.tables.clear();

    for(int i = 0 ; i < restaurant.actionsLog.size() ; i++)
    {
        restaurant.actionsLog[i] = nullptr;
    }
    restaurant.actionsLog.clear();
}

Restaurant& Restaurant::operator=(Restaurant &&restaurant) {
    if(this == &restaurant)
        return *this;

    clear();
    copy(restaurant);

    for(int i =0 ; i < restaurant.tables.size() ; i++)
    {
        restaurant.tables[i] =nullptr;
    }
    restaurant.tables.clear();

    for(int i = 0 ; i < restaurant.actionsLog.size() ; i++)
    {
        restaurant.actionsLog[i] = nullptr;
    }
    restaurant.actionsLog.clear();

    return *this;
}