#include "Person.h"

// Person Member Functions
Person::Person(std::string& name_person, Gender gender_person, Person* mother, Person* father)
{
    this->name_ = name_person;
    this->gender_ = gender_person;
    this->mother_ = mother;
    this->father_ = father;
    if(father)
    {
        father->child.insert(this);
    }
    if(mother){
        mother_->child.insert(this);
    }
}

Person::~Person(){}

const std::string& Person::name()const
{
    return name_;
}

Gender Person::gender()const
{
    return gender_;
}

Person* Person::mother()
{
    return mother_;
}

Person* Person::father()
{
    return father_;
}

void Person:: setMother(Person* mother)
{
    mother_=mother;
}

void Person:: setFather(Person* father)
{
    father_=father;
}

std::set<Person *> Person::parents(PMod pmod)
{
    std::set<Person*> parent;
    if(pmod == PMod::MATERNAL || pmod==PMod::ANY)
    {
          if(mother_!=nullptr)
          {
             parent.insert(mother_);
          }
    }
    if(pmod == PMod::PATERNAL)
    {
         if(father_!=nullptr)
         {
             parent.insert(father_);
         }
    }
    return parent;
}

std::set<Person *> Person::daughters()
{
    std::set<Person*>girl;
    for(auto& g: child )
    {
        if(g->gender_ == Gender::FEMALE)
        {
            girl.insert(g);
        }
    }
    return girl;
}

 std::set<Person *> Person::sons()
 {
    std::set<Person*>son;
    for(auto& boy: child )
    {
        if(boy->gender_ == Gender::MALE)
        {
            son.insert(boy);
        }
    }
    return son;
 }

 std::set<Person*> Person::grandparents(PMod pmod)
 {
    std::set<Person*> grandparent;
    if(pmod == PMod::MATERNAL || pmod==PMod::ANY)
    {
        if(mother_!=nullptr)
        {
            std::set<Person*> matmother = mother_->parents(PMod::ANY);
            grandparent.insert(matmother.begin(),matmother.end());
        }
    }
    if(pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if(father_!=nullptr)
        {
            std::set<Person*> patfather = father_->parents(PMod::ANY);
            grandparent.insert(patfather.begin(),patfather.end());
        }
    }
    return grandparent;
 }

 std::set<Person*> Person::children()
 {
    std::set<Person*> mychild;
    for(auto& my: child)
    {
        mychild.insert(my);
    }
    return mychild;
 }

 std::set<Person*> Person::grandfathers(PMod pmod)
 {
    std::set<Person*> grandfather;
    if(pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if(mother_ != nullptr)
        {
            std::set<Person*>momfather = mother_->parents(PMod::ANY);
            for(Person* grand: momfather)
            {
                if(grand)
                {
                    if(grand->gender_ == Gender::MALE)
                    {
                        grandfather.insert(grand);
                    }
                }

            }
        }
    }
    if(pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if(father_ != nullptr)
        {
            std::set<Person*>dadfather = father_->parents(PMod::ANY);
            for(Person* grand: dadfather)
            {
                if(grand)
                {
                    if(grand->gender_ == Gender::MALE)
                    {
                        grandfather.insert(grand);
                    }
                }

            }
        }
    }
    return grandfather;
 }

std::set<Person*> Person::grandmothers(PMod pmod)
{
    std::set<Person*> grandmother;
    if(pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if(mother_ != nullptr)
        {
            std::set<Person*>mommother = mother_->parents(PMod::ANY);
            for(Person* grand: mommother)
            {
                if(grand)
                {
                    if(grand->gender_ == Gender::FEMALE)
                    {
                        grandmother.insert(grand);
                    }
                }

            }
        }
    }
    if(pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if(father_ != nullptr)
        {
            std::set<Person*>dadmother = father_->parents(PMod::ANY);
            for(Person* grand: dadmother)
            {
                if(grand)
                {
                    if(grand->gender_ == Gender::FEMALE)
                    {
                        grandmother.insert(grand);
                    }
                }

            }
        }
    }
    return grandmother;
}

std::set<Person*> Person::grandchildren()
{
    std::set<Person*>grandchild;
    for(Person* children: child)
    {
        std::set<Person*>children_child = children->children();
        grandchild.insert(children_child.begin(), children_child.end());
    }
    return grandchild;
}

std::set<Person*> Person::granddaughters()
{
    std::set<Person*>grandgirl;
    for(Person* children: child)
    {
        std::set<Person*>children_child = children->children();
        for(Person* grandchild: children_child)
        {
            if(grandchild)
            {
                if(grandchild->gender_ == Gender::FEMALE)
                {
                    grandgirl.insert(grandchild);
                }
            }
        }
    }
    return grandgirl;
}

std::set<Person*> Person::grandsons()
{
    std::set<Person*>grandson;
    for(Person* children: child)
    {
        std::set<Person*>children_child = children->children();
        for(Person* grandchild: children_child)
        {
            if(grandchild)
            {
                if(grandchild->gender_ == Gender::MALE)
                {
                    grandson.insert(grandchild);
                }
            }
        }
    }
    return grandson;
}

std::set<Person*> Person::siblings(PMod pmod, SMod smod)
{
    std::set<Person*>sibling;
    if(pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if(mother_!=nullptr)
        {
            std::set<Person*>mother_child = mother_->children();
            for(Person* silb: mother_child)
            {
                if(silb!=this)
                {
                    if(smod == SMod::FULL || smod == SMod::HALF)
                    {
                        sibling.insert(silb);
                    }
                }
            }
        }
    }
    if(pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if(father_!=nullptr)
        {
            std::set<Person*>father_child = father_->children();
            for(Person* silb: father_child)
            {
                if(silb!=this)
                {
                    if(smod == SMod::FULL || smod == SMod::HALF)
                    {
                        sibling.insert(silb);
                    }
                }
            }
        }
    }
    return sibling;
}

std::set<Person*> Person::brothers(PMod pmod, SMod smod)
{
    std::set<Person*> bro;
    std::set<Person*>slib = this->siblings(PMod::ANY, SMod::ANY);
    for(Person* slibing: slib)
    {
        if(slibing)
        {
            if(slibing->gender_ == Gender::MALE)
            {
                bro.insert(slibing);
            }
        }
    }
    return bro;
}

std::set<Person*> Person::sisters(PMod pmod, SMod smod)
{
    std::set<Person*> sis;
    std::set<Person*>slib = this->siblings(PMod::ANY, SMod::ANY);
    for(Person* slibing: slib)
    {
        if(slibing)
        {
            if(slibing->gender_ == Gender::FEMALE)
            {
                sis.insert(slibing);
            }
        }
    }
    return sis; 
}

std::set<Person*> Person::nieces(PMod pmod, SMod smod)
{
    std::set<Person*> niece;
    std::set<Person*> silbing = this->siblings(PMod::ANY, SMod::ANY);
    for(Person* silb: silbing)
    {
        std::set<Person*>child = silb->children();
        for(Person* children: child)
        {
            if(children->gender_ == Gender::FEMALE)
            {
                niece.insert(children);
            }
        }
    }
    return niece;
}

std::set<Person*> Person::nephews(PMod pmod, SMod smod)
{
    std::set<Person*> nephews;
    std::set<Person*> silbing = this->siblings(PMod::ANY, SMod::ANY);
    for(Person* silb: silbing)
    {
        std::set<Person*>child = silb->children();
        for(Person* children: child)
        {
            if(children->gender_ == Gender::MALE)
            {
                nephews.insert(children);
            }
        }
    }
    return nephews;
}

std::set<Person*> Person::aunts(PMod pmod, SMod smod)
{
    std::set<Person*> aunt;
    if(pmod == PMod::MATERNAL||pmod==PMod::ANY)
    {
        if(mother_!=nullptr)
        {
            std::set<Person*> mother_sibl = mother_->siblings(PMod::ANY, SMod::ANY);
            for(Person* sibl: mother_sibl)
            {
                if(sibl)
                {
                    if(sibl->gender_ == Gender::FEMALE)
                    {
                        aunt.insert(sibl);
                    }
                }
            }
        }
    }
    if(pmod == PMod::PATERNAL||pmod==PMod::ANY)
    {
        if(father_!=nullptr)
        {
            std::set<Person*> father_sibl = father_->siblings(PMod::ANY, SMod::ANY);
            for(Person* sibl: father_sibl)
            {
                if(sibl)
                {
                    if(sibl->gender_ == Gender::FEMALE)
                    {
                        aunt.insert(sibl);
                    }
                }
            }
        }
    }
    return aunt;
}

std::set<Person*> Person::uncles(PMod pmod, SMod smod)
{
     std::set<Person*> uncle;
    if(pmod == PMod::MATERNAL||pmod==PMod::ANY)
    {
        if(mother_!=nullptr)
        {
            std::set<Person*> mother_sibl = mother_->siblings(PMod::ANY, SMod::ANY);
            for(Person* sibl: mother_sibl)
            {
                if(sibl)
                {
                    if(sibl->gender_ == Gender::MALE)
                    {
                        uncle.insert(sibl);
                    }
                }
            }
        }
    }
    if(pmod == PMod::PATERNAL||pmod==PMod::ANY)
    {
        if(father_!=nullptr)
        {
            std::set<Person*> father_sibl = father_->siblings(PMod::ANY, SMod::ANY);
            for(Person* sibl: father_sibl)
            {
                if(sibl)
                {
                    if(sibl->gender_ == Gender::MALE)
                    {
                        uncle.insert(sibl);
                    }
                }
            }
        }
    }
    return uncle;
}

std::set<Person*> Person::cousins(PMod pmod, SMod smod)
{
    std::set<Person*>cousin;
    std::set<Person*>aunt_ = this->aunts(PMod::ANY, SMod::ANY);
    std::set<Person*>uncle_ = this->uncles(PMod::ANY, SMod::ANY);
    for(Person* aunt_child: aunt_)
    {
        std::set<Person*>child = aunt_child->children();
        cousin.insert(child.begin(), child.end());  
    }
    for(Person* uncle_child: uncle_)
    {
        std::set<Person*>child = uncle_child->children();
        cousin.insert(child.begin(), child.end());  
    }
    return cousin;
}

std::set<Person*> Person::ancestors(PMod pmod)
{
    std::set<Person*> ancestor;
    if(pmod == PMod::MATERNAL || pmod == PMod::ANY)
    {
        if(mother_!= nullptr)
        {
            ancestor.insert(mother_);
            auto mother_mother = mother_->ancestors(PMod::ANY);
            ancestor.insert(mother_mother.begin(), mother_mother.end());
        }
    }
    if(pmod == PMod::PATERNAL || pmod == PMod::ANY)
    {
        if(father_!= nullptr)
        {
            ancestor.insert(father_);
            auto father_father = father_->ancestors(PMod::ANY);
            ancestor.insert(father_father.begin(), father_father.end());
        }
    }
    return ancestor;
}

std::set<Person*> Person:: descendants()
{
    std::set<Person*>descendant;
    for(Person* children: child)
    {
        descendant.insert(children);
        std::set<Person*>child_child = children->descendants();
        descendant.insert(child_child.begin(), child_child.end());
    }
    return descendant;
}