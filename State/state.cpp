#include<iostream>

/*Esta es la *interfaz* que representa el estado.*/
/*De la cuál todos los estados descenderán*/
class State {
public:

    virtual int Do(int hp) = 0;
};

// Estado morir 
class DieState : public State
{
public:
    int Do(int hp) override
    {
        return 0;
    }
};

// Estado caminar 
class WalkState : public State
{
public:
    int Do(int hp) override
    {
        return hp + 2;
    }
};

// Estado correr 
class RunState : public State
{
public:
    int Do(int hp) override
    {
        return hp + 10;
    }
};

class Human
{
public:
    // Inicializa las variables.
    Human(int hp) : healthPoint_(hp), state_(nullptr) {}

    // Métodos accesores 
    void setState(State* state)
    {
        state_ = state;
    }
    int GetHealthPoint()
    {
        return healthPoint_;
    }
    // Le enviamos HealPoint_ a la interfaz.
    void Request()
    {
        healthPoint_ = state_->Do(healthPoint_);
    }
private:
    // Puntos de Vida
    int healthPoint_;

    // Puntero a la interfaz
    State* state_;
};

int main()
{
    // Imprimimos la vida inicial del humano
    Human human(100);
    std::cout << human.GetHealthPoint() << std::endl;

    // 'Walk' Cambiar de estado y solicitar.
    human.setState(new WalkState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    // 'Run' Cambiar de estado y solicitar.
    human.setState(new RunState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    // 'Die' Cambiar de estado y solicitar.
    human.setState(new DieState());
    human.Request();
    std::cout << human.GetHealthPoint() << std::endl;

    return 0;
}