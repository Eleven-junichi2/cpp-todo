# cpp-todo

A practice project for learning C++

## Model

- Task
    - title: std::string
    - status: bool
- TodoList
    - tasks: std::vector<Task>

Store ToDoList data in a file called `ToDoList`.

## Usage

### Example Case

```sh
cpp-todo add "study math"
cpp-todo add "practice coding C++"
cpp-todo list
0| [ ] study math
1| [ ] practice coding C++
cpp-todo rename 0 "study mathematics"
cpp-todo list
0| [ ] study mathematics
1| [ ] practice coding C++
cpp-todo done 1
cpp-todo done "practice coding C++"
cpp-todo list
0| [x] study mathematics
1| [x] practice coding C++
cpp-todo undo 0
cpp-todo list
0| [ ] study mathematics
1| [x] practice coding C++
cpp-todo delete 1
cpp-todo list
0| [ ] study mathematics
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
[ ]|[x] <line> <title>
…
```

### Rename task title

```sh
cpp-todo rename <line> <new title>
```

### Done task

```sh
cpp-todo done <line>
```

### Undo task

```sh
cpp-todo undo <line>
```

### Delete task

```sh
cpp-todo delete | remove <line>
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
