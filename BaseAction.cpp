//
// Created by ravidlevy99 on 11/11/18.
//

#include "Action.h"

BaseAction::BaseAction(): status(PENDING) {}

ActionStatus BaseAction::getStatus() const
{
    return status;
}

void BaseAction::complete()
{
    status = COMPLETED;
}

void BaseAction::error(std::string errorMsg)
{
    this->errorMsg = errorMsg;
    status = ERROR;
    std::cout << "ERROR:" + this->getErrorMsg();
}