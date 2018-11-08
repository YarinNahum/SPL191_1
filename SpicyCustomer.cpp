#include "vector"
#include "Customer.h"
#include "Dish.h"

SpicyCustomer::SpicyCustomer(std::string name, int id):Customer(name , id) {}
std::vector<int> SpicyCustomer::order(const std::vector<Dish> &menu) {

}
std::string SpicyCustomer::toString() const {
    std::string ret = "Name:" + getName() + ". " + "Customer Type: Spicy.";
    return ret;
}