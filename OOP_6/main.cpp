#include "Workflow.hpp"
#include "Keyboard.hpp"
int main()
{
    SetConsoleOutputCP(1251); // Устанавливаем кодировку консоли, чтобы корректно отображать русский текст
    SetConsoleOutputCP(CP_UTF8); // для CLION
    Keyboard keyboard;
    // Регистрируем клавиши и связываем их с действиями
    keyboard.registerKey("A", []() { std::cout << "Key A pressed\n"; }, []() { std::cout << "Key A action undone\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C pressed\n"; }, []() { std::cout << "Ctrl+C action undone\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V pressed\n"; }, []() { std::cout << "Ctrl+V action undone\n"; });
    Workflow workflow(keyboard);
    // Добавляем в рабочий процесс действия: нажатие клавиш и отмену последних двух действий
    workflow.addAction([&]() { workflow.keypress("A"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+C"); });
    workflow.addAction([&]() { workflow.keypress("Ctrl+V"); });
    workflow.addAction([&]() { workflow.undo(); });
    workflow.addAction([&]() { workflow.undo(); });
    // Запускаем рабочий процесс
    std::cout << "Начало работы...\n";
    workflow.perform();
    // Меняем действия, связанные с нажатием клавиш и повторно запускаем рабочий процесс
    std::cout << "\nПереназначение клавиш и перезапуск процесса...\n";
    keyboard.registerKey("A", []() { std::cout << "Key A теперь выводит это сообщение\n"; }, []() { std::cout << "Undo action for A\n"; });
    keyboard.registerKey("Ctrl+C", []() { std::cout << "Combination Ctrl+C теперь ничего не делает\n"; }, []() { std::cout << "Undo action for Ctrl+C\n"; });
    keyboard.registerKey("Ctrl+V", []() { std::cout << "Combination Ctrl+V теперь говорит привет\n"; }, []() { std::cout << "Undo action for Ctrl+V\n"; });
    workflow.perform();
    // Проверяем, зарегистрирована ли клавиша "Ctrl+V"
    if (keyboard.isKeyRegistered("Ctrl+V"))
    {
        std::cout << "Клавиша Ctrl+V зарегистрирована в системе\n";
    }
    return 0;
}