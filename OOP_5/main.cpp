#include <iostream>
#include <string>
#include <memory>


// Базовый класс для контролов
class Control {
public:
    virtual void setPosition(int x, int y) = 0;
    virtual std::pair<int, int> getPosition() const = 0;
    virtual void setText(const std::string& text) = 0;
    virtual std::string getText() = 0;
    virtual ~Control() = default;
};

// Классы контролов
class Form : public Control {
public:
    void setPosition(int x, int y) override
    {
        std::cout << "Form: setPosition at (" << x << ", " << y << ")" << std::endl;
    }
    std::pair<int, int> getPosition() const override
    {
        return {0, 0};
    }
    void setText(const std::string& text) override
    {
        std::cout << "Установка текста для формы " << text <<std::endl;
    }
    std::string getText() override
    {
        std::cout << "Вызван метод возрата текста формы у контролла" << std::endl;
    }
};

class Label : public Control {
public:
    void setPosition(int x, int y) override
    {
        std::cout << "Label: setPosition at (" << x << ", " << y << ")" << std::endl;
    }
    std::pair<int, int> getPosition() const override
    {
        return {0, 0};
    }
    void setText(const std::string& text) override
    {
        std::cout << "Label: setText - \"" << text << "\"" << std::endl;
    }
    std::string getText() override {
        return "Sample Text";
    }
};

// Абстрактная фабрика для создания контролов
class ControlFactory {
public:
    virtual std::unique_ptr<Control> createForm() = 0;
    virtual std::unique_ptr<Control> createLabel() = 0;
    virtual ~ControlFactory() = default;
};

// Фабрики для различных операционных систем
class WindowsControlFactory : public ControlFactory {
public:
    std::unique_ptr<Control> createForm() override
    {
        return std::make_unique<Form>();
    }
    std::unique_ptr<Control> createLabel() override
    {
        return std::make_unique<Label>();
    }
};

class LinuxControlFactory : public ControlFactory {
public:
    std::unique_ptr<Control> createForm() override
    {
        return std::make_unique<Form>();
    }
    std::unique_ptr<Control> createLabel() override
    {
        return std::make_unique<Label>();
    }
};

class MacOSControlFactory : public ControlFactory {
public:
    std::unique_ptr<Control> createForm() override
    {
        return std::make_unique<Form>();
    }
    std::unique_ptr<Control> createLabel() override
    {
        return std::make_unique<Label>();
    }
};

int main() {

    system("chcp 65001");
    std::string os = "MacOS";
    std::unique_ptr<ControlFactory> factory;
    if (os == "Windows")
    {
        factory = std::make_unique<WindowsControlFactory>();
    }
    else if (os == "Linux")
    {
        factory = std::make_unique<LinuxControlFactory>();
    }
    else if (os == "MacOS")
    {
        factory = std::make_unique<MacOSControlFactory>();
    }
    if (factory)
    {
        auto form = factory->createForm();
        auto label = factory->createLabel();
        form->setPosition(100, 50);
        form ->setText("Hi");
        auto position = label->getPosition();
        std::cout << "Label position: (" << position.first << ", " << position.second << ")" << std::endl;
        label->setText("Hello, World!");
        auto text = label->getText();
        std::cout << "Label text: " << text << std::endl;
    }
    return 0;
}