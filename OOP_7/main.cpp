#include <iostream>
#include <vector>
#include <string>
// Создаем шаблонный интерфейс репозитория
template <class T>
class IRepository
{
public:
    // Определяем чисто виртуальные методы для добавления, обновления и удаления элементов,
    // И получения элементов из репозитория с заданными параметрами
    virtual void Add(T* item) = 0;
    virtual void Update(T* item) = 0;
    virtual void Delete(T* item) = 0;
    virtual std::vector<T*> Get(const std::string    where, const std::string    orderBy) = 0;
};
    // Определяем перечисление пола
    enum Gender  {Male, Female};
    // Создаем класс пользователя
    class User {
    private:
        // Определяем приватные поля класса
        int mId;
        std::string mName;
        std::string mEmail;
        std::string mPhone;
        std::string mCity;
        Gender mGender;
    public:
        // Определяем публичные методы для получения и установки значений полей класса
        int getId() const { return mId; }

        void setId(int id) { mId = id; }

        std::string getName() const { return mName; }

        void setName(const std::string name) { mName = name; }

        std::string getEmail() const { return mEmail; }

        void setEmail(const std::string email) { mEmail = email; }

        std::string getPhone() const { return mPhone; }

        void setPhone(const std::string phone) { mPhone = phone; }

        std::string getCity() const { return mCity; }

        void setCity(const std::string city) { mCity = city; }

        Gender getGender() const { return mGender; }

        void setGender(Gender Gender) { mGender = Gender; }
    };
        // Создаем интерфейс репозитория пользователей
        class IUserRepository {
        public:
            // Определяем чисто виртуальные методы для получения пользователя по id, имени и email,
            // а также для получения списка пользователей по городу и полу
            virtual User *getById(int id) = 0;

            virtual User *getByName(const std::string name) = 0;

            virtual User *getByEmail(const std::string email) = 0;

            virtual std::vector<User *> getByCity(const std::string city) = 0;

            virtual std::vector<User *> getByGender(Gender Gender) = 0;
        };
            // Создаем класс репозитория в памяти
            template <class T>
            class MemoryRepository : public virtual IRepository<T>
            {
            protected:
                std::vector<T*> mItems;  // Вектор для хранения элементов репозитория
            public:
                void Add(T* item) override
                {// Добавляем элемент в вектор
                    mItems.push_back(item);
                }
                void Update(T* item) override
                {
                    for (int i = 0; i < mItems.size(); i++)
                    {// Если элемент найден, заменяем его на новый
                        if (mItems[i] == item)
                        {
                            mItems[i] = item;
                        break;
                    }
                }
            }
            void Delete(T* item) override
            {
                for (int i = 0; i < mItems.size(); i++)
                { // Если элемент найден, удаляем его из вектора
                    if (mItems[i] == item)
                    {
                        mItems.erase(mItems.begin() + i);
                    break;
                }
            }
        }
                std::vector<T*> Get(const std::string where, const std::string orderBy) override
                {// Возвращаем все элементы репозитория
                    return mItems;
                }
        };
        // Создаем класс репозитория пользователей в памяти
        class MemoryUserRepository : public MemoryRepository<User>, public IUserRepository {
        public:
            User *getById(int id) override {
                for (User *user: mItems) {// Если пользователь с заданным id найден, возвращаем его
                    if (user->getId() == id) {
                        return user;
                    }
                }
                return nullptr;  // Если пользователь не найден, возвращаем nullptr
            }

            User *getByName(const std::string name) override {
                for (User *user: mItems) { // Если пользователь с заданным именем найден, возвращаем его
                    if (user->getName() == name) {
                        return user;
                    }
                }
                return nullptr;  // Если пользователь не найден, возвращаем nullptr
            }

            User *getByEmail(const std::string email) override {
                for (User *user: mItems) {// Если пользователь с заданным email найден, возвращаем его
                    if (user->getEmail() == email) {
                        return user;
                    }
                }
                return nullptr; // Если пользователь не найден, возвращаем nullptr
            }

            std::vector<User *> getByCity(const std::string city) override
            {
                std::vector<User *> result;
                for (User *user: mItems)
                {  // Если пользователь из заданного города найден, добавляем его в результирующий вектор
                    if (user->getCity() == city)
                    {
                        result.push_back(user);
                    }
                }
                return result; // Возвращаем вектор пользователей из заданного города
            }
            std::vector<User*> getByGender(Gender Gender) override
                {
                    std::vector<User *> result;
                    for (User *user: mItems)
                    {// Если пользователь с заданным полом найден, добавляем его в результирующий вектор
                        if (user->getGender() == Gender)
                        {
                        result.push_back(user);
                        }
                    }
                return result;  // Возвращаем вектор пользователей с заданным полом
                }
        };

int main() {
    MemoryUserRepository repo;  // Создаем объект репозитория пользователей

    // Создаем пользователей и добавляем их в репозиторий
    User *user1 = new User();
    user1->setId(1001);
    user1->setName("Ksenia");
    user1->setEmail("kaglaiboroda@stud.kantiana.ru");
    user1->setPhone("9572665093");
    user1->setCity("Kaliningrad");
    user1->setGender(Female);

    User *user2 = new User();
    user2->setId(1002);
    user2->setName("Dima");
    user2->setEmail("chubbybunny@gmail.com");
    user2->setPhone("9565634212");
    user2->setCity("Arkhangelsk");
    user2->setGender(Male);

    User *user3 = new User();
    user3->setId(1003);
    user3->setName("Adelia");
    user3->setEmail("Lia123@yandex.ru");
    user3->setPhone("0955111515");
    user3->setCity("Orenburg");
    user3->setGender(Male);

    repo.Add(user1);
    repo.Add(user2);
    repo.Add(user3);

    // Получаем всех пользователей из репозитория и выводим их на экран
    std::vector<User *> users = repo.Get("", "");
    std::cout << "All users:";
    for (User *user: users) {
        std::cout << user->getId() << " " << user->getName() << " " << user->getEmail() << " " << user->getPhone()
                  << " " << user->getCity() << " " << user->getGender() << "";
    }
}