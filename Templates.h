#ifndef TEMPLATES_H_INCLUDED
#define TEMPLATES_H_INCLUDED

//шаблон итератора

template<class Type>
class Iterator
{
protected:
    //защищенный конструктор
    Iterator() {}

//открытый интерфейс
public:
    virtual ~Iterator() {}
    virtual void First() = 0;            //позиционирует на первом эл-те из контейнера
    virtual void Next() = 0;             //позиционирует на следующем
    virtual bool IsDone() const = 0;     //возвращает истину если обход закончен
    virtual Type GetCurrent() const = 0; //возвращает текущий эл-т
};


//Базовый интерфейс декоратора
//Так сказать абстрактный декоратор
//Нужен для того чтобы динамически изменить поведение декорируемого объекта
//В нашем случае - декоратор для итератора, для сортировки/фильтрации
//Имеет тот же интерфейс что и декорируемый объект
template<class Type>
class IteratorDecorator : public Iterator<Type>
{
protected:
    Iterator<Type> *It;

public:
    IteratorDecorator(Iterator<Type> *it)
    {
        It = it;
    }
    virtual ~IteratorDecorator() { delete It; }
    virtual void First() { It->First(); }
    virtual void Next() { It->Next(); }
    virtual bool IsDone() const { return It->IsDone(); }
    virtual Type GetCurrent() const { return It->GetCurrent(); }

};



#endif // TEMPLATES_H_INCLUDED
