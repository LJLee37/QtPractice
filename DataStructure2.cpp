#include <iostream>
#include <string>
using namespace std;
template <typename Q>
class node_t
{
private:
    Q data;
    node_t* prev;
public:
    Q get_data()
    {
        return data;
    }
    node_t(Q initData)
    {    
        data = initData;
        prev = nullptr;
    }
    node_t* get_prev()
    {
        return prev;
    }
    void edit_prev(node_t* editPrev)
    {
        prev = editPrev;
    }
};

template <typename Q>
class queue_t
{
private:
    node_t<Q>* top{nullptr};
    node_t<Q>* rear{nullptr};
public:
    queue_t(){}
    queue_t(Q initData)
    {
        push(initData);
    }
    bool empty()
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }
    void push(Q data)
    {
        if (top != nullptr)
        {
            top->edit_prev(new node_t<Q>(data));
            top = top->get_prev();
        }
        else
        {
            top = new node_t<Q>(data);
            rear = top;
        }
        
    }
    Q pop()
    {
        if(rear == nullptr)
            return 0;
        else
        { 
            auto* temp = rear->get_prev();
            auto data = rear->get_data();
            delete rear;
            rear = temp;
            if(rear == nullptr)
            {
                top = nullptr;
            }
            return data;
        }
    }
    Q get_top()
    {
        if(top == nullptr)
            return 0;
        return top->get_data();
    }
    Q get_rear()
    {
        if(rear == nullptr)
            return 0;
        return rear->get_data();
    }
    ~queue_t()
    {
        while(top != nullptr)
            pop();
    }

};

int main()
{
    cout << "Queue Program" << endl;
    queue_t<int> q;
    while(true)
    {
        auto cmd = 0;
        cout << endl << "choose action" << endl;
        cout << "1: push, 2: pop, 3: get_top, 4: get_rear, 5: empty, 6: end" << endl;
        cout << "your choice : ";
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            cout << "type a number : ";
            int a;
            cin >> a;
            q.push(a);
            break;
        case 2:
            cout << q.pop() << endl;
            break;
        case 3:
            cout << q.get_top() << endl;
            break;
        case 4:
            cout << q.get_rear() << endl;
            break;
        case 5:
            cout << q.empty() << endl;
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "wrong choice." << endl;
            break;
        }
    }
}