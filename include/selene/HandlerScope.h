#pragma once

#include "ExceptionHandler.h"
#include <vector>

namespace sel {

class HandlerList
{
public:
    static HandlerList& instance()
    {
        static HandlerList staticScope;
        return staticScope;
    }

    void push(ExceptionHandler* h)
    {
        handlers.push_back(h);
    }
    void pop()
    {
        handlers.pop_back();
    }
    ExceptionHandler* current()
    {
        return !handlers.empty() ? handlers.back() : 0;
    }

private:
    HandlerList() { }

private:
    std::vector<ExceptionHandler*> handlers;
};

class HandlerScope
{
public:
    HandlerScope(ExceptionHandler* h)
    {
        HandlerList::instance().push(h);
    }
    ~HandlerScope()
    {
        HandlerList::instance().pop();
    }
};

} // namespace sel
