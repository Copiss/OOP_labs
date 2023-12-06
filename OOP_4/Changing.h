#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

enum class CollectionChangeStatus {
    Added,
    Removed,
    ItemChanged
};

class INotifyPropertyChanged {
public:
    virtual void AddPropertyChangedListener(std::function<void()> listener) = 0;
    virtual void RemovePropertyChangedListener(std::function<void()> listener) = 0;
};

class INotifyPropertyChanging {
public:
    virtual void AddPropertyChangingListener(std::function<void(const std::string&, const std::string&, bool&)> listener) = 0;
    virtual void RemovePropertyChangingListener(std::function<void(const std::string&, const std::string&, bool&)> listener) = 0;
};

class INotifyCollectionChanged {
public:
    virtual void AddCollectionChangedListener(std::function<void(CollectionChangeStatus)> listener) = 0;
    virtual void RemoveCollectionChangedListener(std::function<void(CollectionChangeStatus)> listener) = 0;
};

class MyClass : public INotifyPropertyChanged, public INotifyPropertyChanging, public INotifyCollectionChanged {
private:
    std::vector<int> myCollection;
    std::string myProperty;

    std::vector<std::function<void()>> propertyChangedListeners;
    std::vector<std::function<void(const std::string&, const std::string&, bool&)>> propertyChangingListeners;
    std::vector<std::function<void(CollectionChangeStatus)>> collectionChangedListeners;

public:
    void AddPropertyChangedListener(std::function<void()> listener) override {
        propertyChangedListeners.push_back(listener);
    }

    void RemovePropertyChangedListener(std::function<void()> listener) override {
        propertyChangedListeners.erase(
                std::remove_if(propertyChangedListeners.begin(), propertyChangedListeners.end(),
                               [&](const auto& func) { return &func == &listener; }),
                propertyChangedListeners.end()
        );
    }

    void AddPropertyChangingListener(std::function<void(const std::string&, const std::string&, bool&)> listener) override {
        propertyChangingListeners.push_back(listener);
    }

    void RemovePropertyChangingListener(std::function<void(const std::string&, const std::string&, bool&)> listener) override {
        propertyChangingListeners.erase(
                std::remove_if(propertyChangingListeners.begin(), propertyChangingListeners.end(),
                               [&](const auto& func) { return &func == &listener; }),
                propertyChangingListeners.end()
        );
    }

    void AddCollectionChangedListener(std::function<void(CollectionChangeStatus)> listener) override {
        collectionChangedListeners.push_back(listener);
    }

    void RemoveCollectionChangedListener(std::function<void(CollectionChangeStatus)> listener) override {
        collectionChangedListeners.erase(
                std::remove_if(collectionChangedListeners.begin(), collectionChangedListeners.end(),
                               [&](const auto& func) { return &func == &listener; }),
                collectionChangedListeners.end()
        );
    }

    // Пример метода, меняющего свойство
    void SetProperty(const std::string& newValue) {
        for (auto& listener : propertyChangingListeners) {
            bool cancel = false;
            listener("myProperty", newValue, cancel);
            if (cancel) {
                std::cout << "Property change canceled!" << std::endl;
                return;
            }
        }

        myProperty = newValue;

        for (auto& listener : propertyChangedListeners) {
            listener();
        }
    }

    // Пример метода, изменяющего коллекцию
    void AddToCollection(int value) {
        myCollection.push_back(value);

        for (auto& listener : collectionChangedListeners) {
            listener(CollectionChangeStatus::Added);
        }
    }
};
