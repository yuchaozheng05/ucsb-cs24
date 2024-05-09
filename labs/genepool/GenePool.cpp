#include "GenePool.h"
#include <iostream>
#include <sstream>

// GenePool Member Functions
GenePool::GenePool(std::istream& stream)
{
    Gender gender;
    std::string line;
    Person* mother_;
    Person* father_;
    while(getline(stream, line))
    {
        if(line.empty() || line[0]=='#' )
        {
            continue;
        }
        std::istringstream data(line);
        std::string name;
        data>>name;
        std::string gender_p;
        data>>gender_p;
        if(gender_p == "male")
        {
            gender = Gender::MALE;
        }
        else
        {
            gender = Gender::FEMALE;
        }
        std::string mother;
        data>>mother;
        if(mother != "???")
        {
            //person->setMother(find(mother));
            mother_ = find(mother);
        }
        if(mother == "???")
        {
            mother_ = nullptr;
        }
        std::string father;
        data>>father;
        if(father =="???")
        {
            father_=nullptr;
        }
        if(father != "???")
        {
            father_=find(father);
        }
        Person* person = new Person(name, gender, mother_, father_);
        addPerson(name, person);
    }
}

GenePool::~GenePool()
{
    for(auto& p: people)
    {
        delete p.second;
    }
}

void GenePool::addPerson(const std::string& name, Person* person)
{
    people[name] = person;
}

std::set<Person*> GenePool::everyone()const
{
    std::set<Person*>allperson;
    for(auto& p: people)
    {
        allperson.insert(p.second);
    }
    return allperson;
}

Person* GenePool::find(const std::string& name)const
{
    auto person = people.find(name);
    if(person == people.end())
    {
        //addPerson(name, Person*person);
        throw std::runtime_error("can't find person");
        //return nullptr;
    }
    else
    {
        return person->second;
    }
}