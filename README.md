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

## Usage

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
