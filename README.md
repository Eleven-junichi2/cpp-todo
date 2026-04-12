# cpp-todo

A practice project for learning C++

## Model

- Task
    - id: int
    - title: std::string
    - status: bool
- TodoList
    - tasks: std::vector<Task>
- taskTitle2Id(TodoList, const& std::string) -> int

Store ToDoList data in `ToDoList.json`.

## Usage

### Example Case

```sh
cpp-todo add "study math"
cpp-todo add "practice coding C++"
cpp-todo list
[ ] 0 study math
[ ] 1 practice coding C++
cpp-todo rename 0 "study mathematics"
cpp-todo list
[ ] 0 study mathematics
[ ] 1 practice coding C++
cpp-todo done 1
cpp-todo done "practice coding C++"
cpp-todo list
[x] 0 study mathematics
[x] 1 practice coding C++
cpp-todo undo 0
cpp-todo list
[ ] 0 study mathematics
[x] 1 practice coding C++
cpp-todo delete 1
cpp-todo list
[ ] 0 study mathematics
cpp-todo remove 0
cpp-todo list

```

### Add task

```sh
cpp-todo add <title>
```

### List tasks

```sh
cpp-todo list
```

Output:
```sh
[ ]|[x] <id> <title>
…
```

### Rename task title

```sh
cpp-todo rename (<id> | --id <id> | <title> | --title <title>) (<new-title> | --new-title <new-title>)
```

### Done task

```sh
cpp-todo done (<id> | --id <id> | <title> | --title <title>)
```

### Undo task

```sh
cpp-todo undo (<id> | --id <id> | <title> | --title <title>)
```

### Delete task

```sh
cpp-todo delete | remove (<id> | --id <id> | <title> | --title <title>)
```

### Enter REPL mode

```sh
cpp-todo
```

You can use same command as CLI arguments.

#### Exit REPL

```
> exit | quit | q
```
