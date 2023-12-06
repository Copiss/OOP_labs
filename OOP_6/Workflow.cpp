#include "Workflow.hpp"
void Workflow::keypress(const std::string& key)
{
    keyboard.pressKey(key);
    std::this_thread::sleep_for(std::chrono::seconds(1)); // добавляем задержку, чтобы действия были заметны
}
void Workflow::undo()
{
    keyboard.undo();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
// Выполняем все действия в рабочем процессе (workflow)
void Workflow::perform()
{
    for (const auto& action : actions)
    {
        action();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
// Добавляем действие в рабочий процесс (workflow)
void Workflow::addAction(const Action& action)
{
    actions.push_back(action);
}