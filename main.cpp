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
    if (argc < 2) {
        std::cout << "Usage: `" << argv[0] << " <command> <arguments>`\n";
        return 0;
    }
    std::string_view command = argv[1];
    if (command == "add")
    {
        if (argc < 3) {
            std::cerr << "Invalid arguments.\n";
            return 1;
        }
        Task task = {argv[2], false};
        std::ofstream f{TODOLIST_FILEPATH, std::ios::app};
        f << "- [";
        if (task.status)
        {
            f << "x";
        }
        else
        {
            f << " ";
        }
        f << "] " << task.title << "\n";
        f.close();
        std::cout << "Added a task: `" << task.title << "`\n";
    }
    else if (command == "list")
    {
        std::ifstream f{TODOLIST_FILEPATH};
        std::string line{};
        int line_num{1};
        while (std::getline(f, line))
            std::cout << line_num++ << "| " << line << '\n';
    }
    else if (command == "delete" || command == "remove")
    {
        if (argc < 3) {
            std::cerr << "Invalid arguments.\n";
            return 1;
        }
        std::ifstream ifs{TODOLIST_FILEPATH};
        std::string line{};
        // -- 削除するタスクを除いたToDoリストを作成 --
        std::vector<std::string> lines{};
        int line_num_remove{};
        try
        {
            line_num_remove = std::stoi(argv[2]);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid argument.\n";
            return 1;
        }
        int line_num{1};
        while (std::getline(ifs, line))
        {
            if (line_num != line_num_remove)
            {
                lines.push_back(line);
            }
            ++line_num;
        }
        ifs.close();
        // ----
        std::ofstream ofs{TODOLIST_FILEPATH, std::ios::trunc};
        for (const auto &line : lines)
        {
            ofs << line << "\n";
        }
        std::cout << "The task has removed.\n";
    }
    else if (command == "done")
    {
        if (argc < 3) {
            std::cerr << "Invalid arguments.\n";
            return 1;
        }
        int line_num_done{};
        try
        {
            line_num_done = std::stoi(argv[2]);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid arguments.\n";
            return 1;
        }
        std::ifstream ifs{TODOLIST_FILEPATH};
        std::string line{};
        std::vector<std::string> lines{};
        int line_num{1};
        while (std::getline(ifs, line))
        {
            if (line_num == line_num_done)
            {
                std::string::size_type pos = line.find("- [ ]");
                if (pos != std::string::npos)
                {
                    line.replace(pos, 5, "- [x]");
                }
            }
            lines.push_back(line);
            ++line_num;
        }
        std::ofstream ofs{TODOLIST_FILEPATH, std::ios::trunc};
        for (const auto &line : lines)
        {
            ofs << line << "\n";
        }
    } else if (command == "undo")
    {
        if (argc < 3) {
            std::cerr << "Invalid arguments.\n";
            return 1;
        }
        int line_num_done{};
        try
        {
            line_num_done = std::stoi(argv[2]);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid arguments.\n";
            return 1;
        }
        std::ifstream ifs{TODOLIST_FILEPATH};
        std::string line{};
        std::vector<std::string> lines{};
        int line_num{1};
        while (std::getline(ifs, line))
        {
            if (line_num == line_num_done)
            {
                std::string::size_type pos = line.find("- [x]");
                if (pos != std::string::npos)
                {
                    line.replace(pos, 5, "- [ ]");
                }
            }
            lines.push_back(line);
            ++line_num;
        }
        std::ofstream ofs{TODOLIST_FILEPATH, std::ios::trunc};
        for (const auto &line : lines)
        {
            ofs << line << "\n";
        }
    } else {
        std::cerr << "Invalid command.\n";
        return 1;
    }
    return 0;
}