#include "vector"
#include "Customer.h"
#include "Dish.h"

CheapCustomer::CheapCustomer(std::string name, int id):Customer(name , id) {}
std::vector<int> CheapCustomer::order(const std::vector<Dish> &menu) {

}
std::string CheapCustomer::toString() const {
    std::string ret = "Name:" + getName() + ". " + "Customer Type: Cheap.";
    return ret;
}