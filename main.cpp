#include <iostream>
#include <string>
#include <vector>
#include <fstream>

constexpr char TODOLIST_FILEPATH[] = "ToDoList.json";

struct Task
{
    int id;
    std::string title;
    bool status;
};

int main(int argc, char const *argv[])
{
    std::vector<Task> todolist{};
    // TODO: Load `ToDoList.json` into an instance of ToDoList.
    std::ifstream f { "ToDoList.json" };
    if (!f) {
        std::cerr << "Failed to load `" << TODOLIST_FILEPATH << "`\n";
    }
    return 0;
}