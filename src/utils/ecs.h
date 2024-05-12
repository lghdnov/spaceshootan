#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include <chrono>

using namespace std;

class Entity;
class Component;
class System;
class World;

class Component {
public:
    virtual ~Component() = default;
};

class Entity {
private:
    unordered_map<size_t, shared_ptr<Component>> components;
public:
    template<typename T>
    void addComponent(shared_ptr<T> component) {
        components[typeid(T).hash_code()] = component;
    }

    template<typename T>
    shared_ptr<T> getComponent() {
        auto it = components.find(typeid(T).hash_code());
        if (it != components.end()) {
            return dynamic_pointer_cast<T>(it->second);
        }
        return nullptr;
    }
};

class System {
public:
    virtual ~System() = default;
    virtual void init(World* pWorld) = 0;
    virtual void update(float deltaTime) = 0;
};

class World{
private:
    vector<shared_ptr<System>> systems;
    vector<shared_ptr<Entity>> entities;
public:

    shared_ptr<Entity> createEntity(){
        shared_ptr<Entity> entity = make_shared<Entity>();
        entities.push_back(entity);
        return entity;
    }

    template<typename T>
    void addSystem(){
        static_assert(is_base_of<System, T>::value, "T must be a subclass of System");

        auto system = make_shared<T>();
        systems.push_back(system);
        systems.back()->init(this);
    }


    void update(){

        auto currentTime = std::chrono::high_resolution_clock::now();
        static auto previousTime = currentTime; // Статическая переменная для хранения предыдущего времени

        // Вычисляем разницу между текущим и предыдущим временем
        std::chrono::duration<float> deltaTime = currentTime - previousTime;

        // Обновляем предыдущее время до текущего для следующего вызова
        previousTime = currentTime;

        // Преобразуем deltaTime в секунды с плавающей точкой
        float deltaTimeSeconds = deltaTime.count();

        // Обновляем каждую систему, передавая deltaTime
        for (const auto& system : systems) {
            system->update(deltaTimeSeconds);
        }
    }

    vector<shared_ptr<Entity>> &getEntities(){
        return entities;
    }
};
