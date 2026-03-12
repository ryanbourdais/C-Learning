#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Task
{
    char name[100];
    char description[500];
    int priority;
    bool completed;
};

void add_task(struct Task *tasks, int *task_count)
{
    if (*task_count >= 100)
    {
        printf("Task list is full. Cannot add more tasks.\n");
        return;
    }

    getchar(); // consume leftover newline from earlier scanf

    printf("Enter task name: ");
    fgets(tasks[*task_count].name, sizeof(tasks[*task_count].name), stdin);
    tasks[*task_count].name[strcspn(tasks[*task_count].name, "\n")] = '\0';

    printf("Enter task description: ");
    fgets(tasks[*task_count].description, sizeof(tasks[*task_count].description), stdin);
    tasks[*task_count].description[strcspn(tasks[*task_count].description, "\n")] = '\0';
    printf("Enter task priority (1-5): ");
    scanf("%d", &tasks[*task_count].priority);
    tasks[*task_count].completed = false;
    (*task_count)++;
    printf("Task added successfully!\n");
}

void view_task(struct Task task)
{
    printf("Name: %s\nDescription: %s\nPriority: %d\n", task.name, task.description, task.priority);
    printf("Completed: %s\n", task.completed ? "Yes" : "No");
}

void view_tasks(struct Task *tasks, int task_count)
{
    if (task_count == 0)
    {
        printf("No tasks to display.\n");
        return;
    }
    printf("To-Do List:\n");
    for (int i = 0; i < task_count; i++)
    {
       view_task(tasks[i]);
    }
}

void delete_task(struct Task *tasks, int *task_count)
{
    if (task_count == 0)
    {
        printf("No tasks to delete.\n");
        return;
    }
    printf("Enter the name of the task to delete: ");
    char name[100];
    scanf("%s", name);
    for (int i = 0; i < *task_count; i++)
    {
        if (strcmp(tasks[i].name, name) == 0)
        {
            for (int j = i; j < *task_count - 1; j++)
            {
                tasks[j] = tasks[j + 1];
            }
            (*task_count)--;
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task not found. Please try again.\n");
}

void complete_task(struct Task *tasks, int *task_count)
{
    if (*task_count == 0)
    {
        printf("No tasks to complete.\n");
        return;
    }
    printf("Enter the name of the task to mark as completed: ");
    char name[100];
    scanf("%s", name);
    for (int i = 0; i < *task_count; i++)
    {
        if (strcmp(tasks[i].name, name) == 0)
        {
            tasks[i].completed = true;
            printf("Task '%s' marked as completed!\n", tasks[i].name);
            return;
        }
    }
    printf("Task not found. Please try again.\n");
}

bool prompt_user(struct Task *tasks, int *task_count)
{
    printf("Please enter a command (add, view, complete, delete, exit): ");
    char command[100];
    scanf("%s", command);   
    if (strcmp(command, "add") == 0)
    {            
        add_task(tasks, task_count);
        printf("Task added:\nName: %s\nDescription: %s\nPriority: %d\n", tasks[*task_count - 1].name, tasks[*task_count - 1].description, tasks[*task_count - 1].priority);
    }
    else if (strcmp(command, "delete") == 0)
    {
        delete_task(tasks, task_count);
    }
    else if (strcmp(command, "view") == 0)
    {
        view_tasks(tasks, *task_count);
    }
    else if (strcmp(command, "complete") == 0)
    {
        complete_task(tasks, task_count);
    }
    else if(strcmp(command, "exit") == 0)
    {
        return false;
    }
    else
    {
        printf("Invalid command. Please try again.\n");
    }
    return true;
}


int main()
{
    struct Task tasks[100];
    int task_count = 0;
    printf("Welcome to the To-Do List App!\n");
    printf("You can add tasks, view tasks, and mark tasks as completed.\n");
    bool running = true;
    while(running) {
        running = prompt_user(tasks, &task_count);
    }
    return 1;
}