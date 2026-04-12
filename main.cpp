#include <iostream>
#include <string>
#include <vector>
#include <fstream>

constexpr char TODOLIST_FILEPATH[] = "ToDoList.md";

struct Task
{
    std::string title;
    bool status;
};

int main(int argc, char const *argv[])
{
    std::string_view command = argv[1];
    if (command == "add")
    {
        Task task = {argv[2], false};
        std::ofstream f { TODOLIST_FILEPATH, std::ios::app };
        f << "- [";
        if (task.status) {
            f << "x";
        } else {
            f << " ";
        }
        f << "] " << task.title << "\n";
        f.close();
        std::cout << "Added a task: `" << task.title << "`\n";
    } else if (command == "list") {
        std::ifstream f { TODOLIST_FILEPATH };
        std::string line {};
        int line_num {0};
        while (std::getline(f, line))
            std::cout << line_num++ << "| " << line << '\n';
    } else if (command == "delete" || command == "remove") {
        std::ifstream ifs { TODOLIST_FILEPATH };
        std::string line {};
        std::vector<std::string> lines {};
        int line_num_remove {};
        try {
            line_num_remove = std::stoi(argv[2]);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument.\n";
        }
        int line_num {1};
        while (std::getline(ifs, line))
        {
            if (line_num != line_num_remove) {
                lines.push_back(line);
            }
            ++line_num;
        }
        ifs.close();
        std::ofstream ofs { TODOLIST_FILEPATH, std::ios::trunc};
        for (const auto& line : lines) {
            ofs << line << "\n";
        }
    }
    return 0;
}