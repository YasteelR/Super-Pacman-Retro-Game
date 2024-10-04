#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <raylib-cpp.hpp>

using namespace std;

class BaseObject {
    public:
    BaseObject(int x, int y);
    BaseObject();
    int get_x();
    int get_y();
    void set_location(int x, int y);
    void set_window(shared_ptr<raylib::Window> window);
    shared_ptr<raylib::Window> get_window();


    protected:
        int current_x;
        int current_y;
    private:
        shared_ptr<raylib::Window> window_;
};


#endif 
