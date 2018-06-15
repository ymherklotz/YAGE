typedef unsigned int GroupId;

class BaseComponent
{
protected:
    GroupId getGroup();

private:
    friend class EntityManager;

    static GroupId group_id_counter_;
};

template <typename T>
class Component : public BaseComponent
{
};
