#include "Changing.h"

int main()
{
    MyClass obj;
    auto propertyChangedListener = [&]()
    {
        std::cout << "Property changed!" << std::endl;
    };
    auto propertyChangingListener = [&](const std::string& propertyName, const std::string& newValue, bool& cancel)
    {
        std::cout << "Property changing: " << propertyName << " to " << newValue << std::endl;
        // Оставим возможность отмены изменения в консоли (введите 'y' для отмены)
        char input;
        std::cout << "Cancel property change? (y/n): ";
        std::cin >> input;
        cancel = (input == 'y');
    };
    auto collectionChangedListener = [&](CollectionChangeStatus status)
    {
        std::cout << "Collection changed: ";
        switch (status)
        {
            case CollectionChangeStatus::Added:
                std::cout << "Added";
                break;
            case CollectionChangeStatus::Removed:
                std::cout << "Removed";
                break;
            case CollectionChangeStatus::ItemChanged:
                std::cout << "ItemChanged";
                break;
        }
        std::cout << std::endl;
    };
    obj.AddPropertyChangedListener(propertyChangedListener);
    obj.AddPropertyChangingListener(propertyChangingListener);
    obj.AddCollectionChangedListener(collectionChangedListener);
    obj.SetProperty("New Value");
    int value;
    std::cout << "Enter a value to add to the collection: ";
    std::cin >> value;
    obj.AddToCollection(value);
    // Удаление слушателей
    obj.RemovePropertyChangedListener(propertyChangedListener);
    obj.RemovePropertyChangingListener(propertyChangingListener);
    obj.RemoveCollectionChangedListener(collectionChangedListener);
    return 0;
}