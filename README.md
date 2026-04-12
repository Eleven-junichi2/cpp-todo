# cpp-todo

A practice project for learning C++.

## Model

- Task
    - title: std::string
    - status: bool

Store ToDo List in a file called `ToDoList`.

## Usage

### Example Case

```sh
cpp-todo add "study math"
cpp-todo add "practice coding C++"
cpp-todo list
1| [ ] study math
2| [ ] practice coding C++
cpp-todo rename 0 "study mathematics"
cpp-todo list
1| [ ] study mathematics
2| [ ] practice coding C++
cpp-todo done 1
cpp-todo done "practice coding C++"
cpp-todo list
1| [x] study mathematics
2| [x] practice coding C++
cpp-todo undo 0
cpp-todo list
1| [ ] study mathematics
2| [x] practice coding C++
cpp-todo delete 1
cpp-todo list
1| [ ] study mathematics
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
