#include "vector"
#include "Customer.h"
#include "Dish.h"

AlchoholicCustomer::AlchoholicCustomer(std::string name, int id):Customer(name , id) {}
std::vector<int> AlchoholicCustomer::order(const std::vector<Dish> &menu) {

}
std::string AlchoholicCustomer::toString() const {
    std::string ret = "Name:" + getName() + ". " + "Customer Type: Alcoholic.";
    return ret;
}