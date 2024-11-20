// 解释为什么OSG需要accept nodeVisitor， nodeVisitor再apply node
#include <iostream>
#include <iostream>

class ObjectVisitor;

class Parent
{
public:
    Parent() {};
    virtual ~Parent() {};
    virtual void outPutWhoAmI()
    {
        std::cout << "I am Parent" << std::endl;
    };
    virtual void accept(ObjectVisitor* visitor);
};

class ChildA : public Parent
{
public:
    ChildA() {};
    ~ChildA() {};
    void outPutWhoAmI()
    {
        std::cout << "I am ChildA" << std::endl;
    };
    // 每个必须实现虚函数accept
    virtual void accept(ObjectVisitor* visitor);
};

class ChildAA : public ChildA
{
public:
    ChildAA() {};
    ~ChildAA() {};
    void outPutWhoAmI()
    {
        std::cout << "I am ChildAA" << std::endl;
    };
    virtual void accept(ObjectVisitor* visitor);
};

class ChildB : public Parent
{
public:
    ChildB() {};
    ~ChildB() {};
    void outPutWhoAmI()
    {
        std::cout << "I am ChildB" << std::endl;
    };
    virtual void accept(ObjectVisitor* visitor);
};

class ObjectVisitor
{
public:
    ObjectVisitor() {};
    ~ObjectVisitor() {};
    void apply(Parent* node);
    void apply(Parent& node);
    void apply(ChildA* node);
    void apply(ChildA& node);
    void apply(ChildB* node);
    void apply(ChildB& node);
    void apply(ChildAA* node);
    void apply(ChildAA& node);
};

void Parent::accept(ObjectVisitor* visitor)
{
    std::cout << "Parent:: accept" << std::endl;
    visitor->apply(*this);
}
void ChildA::accept(ObjectVisitor* visitor)
{
    std::cout << "ChildA:: accept" << std::endl;
    visitor->apply(*this);
}
void ChildAA::accept(ObjectVisitor* visitor)
{
    std::cout << "ChildAA:: accept" << std::endl;
    visitor->apply(*this);
}
void ChildB::accept(ObjectVisitor* visitor)
{
    std::cout << "ChildB:: accept" << std::endl;
    visitor->apply(*this);
}
void ObjectVisitor::apply(Parent* node)
{
    node->outPutWhoAmI();
    std::cout << "apply Parent: " << node << std::endl;
}

void ObjectVisitor::apply(Parent& node)
{
    node.outPutWhoAmI();
    std::cout << "apply Parent: " << &node << std::endl;
}

void ObjectVisitor::apply(ChildA* node)
{
    node->outPutWhoAmI();
    std::cout << "apply ChildA: " << node << std::endl;
}

void ObjectVisitor::apply(ChildA& node)
{
    node.outPutWhoAmI();
    std::cout << "apply ChildA: " << &node << std::endl;
}

void ObjectVisitor::apply(ChildAA* node)
{
    node->outPutWhoAmI();
    std::cout << "apply ChildAA: " << node << std::endl;
}

void ObjectVisitor::apply(ChildAA& node)
{
    node.outPutWhoAmI();
    std::cout << "apply ChildAA: " << &node << std::endl;
}

void ObjectVisitor::apply(ChildB* node)
{
    node->outPutWhoAmI();
    std::cout << "apply ChildB: " << node << std::endl;
}

void ObjectVisitor::apply(ChildB& node)
{
    node.outPutWhoAmI();
    std::cout << "apply ChildB: " << &node << std::endl;
}

int main()
{
    ObjectVisitor objVisitor;
    Parent* par = new Parent;
    Parent* childA = new ChildA;
    Parent* childAA = new ChildAA;
    std::cout << "直接apply，是无法区分真正的对象类型的" << std::endl;
    objVisitor.apply(par);
    objVisitor.apply(childA);
    objVisitor.apply(childAA);
    std::cout << "dynamic_cast<ChildAA*>(childAA)" << std::endl;
    objVisitor.apply(dynamic_cast<ChildAA*>(childAA));
    std::cout << "使用虚函数accpet，才能真正区分对象类型" << std::endl;
    par->accept(&objVisitor);
    childA->accept(&objVisitor);
    childAA->accept(&objVisitor);
    return 0;
}


