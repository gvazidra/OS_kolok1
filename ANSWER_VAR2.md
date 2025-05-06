# Коллоквиум №1
# Чиж Елена 2 курс, 11 группа
# Вариант 2

--- 

## 1.  Приведите Win API, необходимое для решения Лабораторной работы номер 2

```cpp
// Создание потока
HANDLE CreateThread(
    LPSECURITY_ATTRIBUTES   lpThreadAttributes,
   SIZE_T                  dwStackSize,
    LPTHREAD_START_ROUTINE  lpStartAddress,
    LPVOID                  lpParameter,
    DWORD                   dwCreationFlags,
    LPDWORD                 lpThreadId
);

// Ожидание завершения потока
DWORD WaitForSingleObject(
    HANDLE hHandle,
    DWORD  dwMilliseconds
);
// Пример использования:
WaitForSingleObject(hAverage, INFINITE);

// Засыпание (задержка потока)
VOID Sleep(
    DWORD dwMilliseconds
);
// Пример использования:
Sleep(12);
```

---

## 2. Что такое процесс в ОС Windows

Процесс в операционной системе Windows — это объект ядра, которому принадлежат системные ресурсы, используемые приложением. Процесс — это экземпляр выполняемой программы.

### Основные характеристики процесса:
- Процесс имеет собственное виртуальное адресное пространство.
- Выполнение процесса начинается с **первичного потока** (main thread).
- Процесс может создавать дополнительные потоки во время выполнения.
- Процесс управляется системой с помощью **идентификатора** и **дескриптора**.

### Жизненный цикл процесса:
1. **Создание** — через функцию `CreateProcess`.
2. **Выполнение** — выполняется основной поток и другие потоки, если созданы.
3. **Завершение** — процесс завершает работу после завершения всех своих потоков или через системные вызовы.

### Прототип функции для создания процесса:

```cpp
BOOL CreateProcess(
    LPCTSTR lpApplicationName,      // имя исполняемого модуля
    LPTSTR lpCommandLine,           // командная строка
    LPSECURITY_ATTRIBUTES lpProcessAttributes, // атрибуты защиты процесса
    LPSECURITY_ATTRIBUTES lpThreadAttributes,  // атрибуты защиты потока
    BOOL bInheritHandles,           // наследование дескрипторов
    DWORD dwCreationFlags,          // флаги создания процесса
    LPVOID lpEnvironment,           // указатель на блок новой среды окружения
    LPCTSTR lpCurrentDirectory,     // текущий каталог
    LPSTARTUPINFO lpStartupInfo,    // указатель на структуру STARTUPINFO
    LPPROCESS_INFORMATION lpProcessInformation // указатель на структуру PROCESS_INFORMATION
);
```
### Пример создания процесса:

```cpp
STARTUPINFO si;
PROCESS_INFORMATION pi;
ZeroMemory(&si, sizeof(si));
si.cb = sizeof(si);

if (CreateProcess(
        "C:\\Program.exe", // путь к исполняемому файлу
        NULL,              // параметры командной строки
        NULL,              // защита процесса
        NULL,              // защита потока
        FALSE,             // наследование дескрипторов
        CREATE_NEW_CONSOLE,// создание новой консоли
        NULL,              // окружение
        NULL,              // текущий каталог
        &si,               // информация о запуске
        &pi))              // информация о процессе
{
    // Ждем завершения процесса
    WaitForSingleObject(pi.hProcess, INFINITE);
    // Закрываем дескрипторы
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

```

### Примеры завершения процесса:

- Завершение процесса самим собой:
```cpp
VOID ExitProcess(
    UINT uExitCode // код возврата для всех потоков
);
// Пример использования:
ExitProcess(0);
```

- Завершение процесса извне:
```cpp
BOOL TerminateProcess(
    HANDLE hProcess, // дескриптор процесса
    UINT uExitCode   // код завершения процесса
);
// Пример использования:
TerminateProcess(hProcess, 1);
```

### Особенности:
- Процессы могут создавать дочерние процессы, которые после запуска работают независимо.
- Каждому процессу выделяется изолированное виртуальное адресное пространство для защиты от сбоев других процессов.
- Завершение основного (первичного) потока приводит к завершению всего процесса.
- Использование TerminateProcess должно быть оправдано, так как оно не освобождает все ресурсы корректно (применяется только в аварийных ситуациях).
