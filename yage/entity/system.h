class BaseSystem
{
public:
    virtual void update() = 0;
};

template <typename T>
class System : public BaseSystem
{
};
