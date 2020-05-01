#include <iostream>
#include <string>
using namespace std;
template <typename Q>
class node_t
{
private:
    Q data;
    node_t* prev;
    node_t* next;
public:
    Q get_data()
    {
        return data;
    }
    node_t(Q initData)
    {    
        data = initData;
        prev = nullptr;
        next = nullptr;
    }
    node_t* get_prev()
    {
        return prev;
    }
    node_t* get_next()
    {
        return next;
    }
    void edit_prev(node_t* editPrev)
    {
        prev = editPrev;
    }
    
    void edit_next(node_t* editNext)
    {
        next = editNext;
    }
};

template <typename Q>
class dllist_t
{
private:
    node_t<Q>* top{nullptr};
    node_t<Q>* rear{nullptr};
    node_t<Q>* current{nullptr};
public:
    dllist_t(){}
    dllist_t(Q initData)
    {
        push(initData);
    }
    bool empty()
    {
        if (current == nullptr)
            return true;
        else
            return false;
    }
    void push(Q data)
    {
        auto* temp1 = new node_t<Q>(data); // temp1 : 새로 만든 거의 포인터
        if (rear == nullptr) // 맨 앞이 비어있다면
        {
            rear = temp1;
        }
        if (top == nullptr || top == current) // 맨 뒤가 비어있거나 이전 거가 맨 뒤일 경우
        {
            top = temp1;
        }
        if (current != nullptr) // 이전 거가 비어있지 않다면
        {
            auto* temp2 = current->get_next(); // temp2 : 다음 거의 포인터
            current->edit_next(temp1); // 이전 거의 next를 새로 만든 거로 변경
            temp1->edit_prev(current); // 새로 만든 거의 prev를 이전 거로 변경
            if (temp2 != nullptr) // 다음 거가 비어있지 않다면
            {
                temp2->edit_prev(temp1); // 다음 거의 prev를 새로 만든 거로 변경
                temp1->edit_next(temp2); // 새로 만든 거의 next를 다음 거로 변경
            }
        }
        
        current = temp1; // 현재 포인터를 새로 만든 거로 변경
    }
    Q pop()
    {
        if(current == nullptr)
            return 0;
        else
        {
            node_t<Q>* temp1 = current->get_prev();
            node_t<Q>* temp2 = current->get_next();
            auto data = current->get_data();
            if(temp1 != nullptr)
                temp1->edit_next(temp2);
            if(temp2 != nullptr)
                temp2->edit_prev(temp1);
            delete current;
            if(temp1 != nullptr)
            current = temp1;
            else
            current = temp2;
            if(current == nullptr)
            {
                top = nullptr;
                rear == nullptr;
            }
            return data;
        }
    }
    bool goto_prev()
    {
        if((current == nullptr) || (current->get_prev() == nullptr))
            return 0;
        current = current->get_prev();
        return 1;
    }
    bool goto_next()
    {
        if((current == nullptr) || (current->get_next() == nullptr))
            return 0;
        current = current->get_next();
        return 1;
    }
    bool goto_top()
    {
        if(current == nullptr)
            return 0;
        current = top;
        return 1;
    }
    bool goto_rear()
    {
        if(current == nullptr)
            return 0;
        current = rear;
        return 1;
    }
    ~dllist_t()
    {
        while(current != nullptr)
            pop();
    }
    Q get_cur_data()
    {
        if(current != nullptr)
            return current->get_data();
        return 0;
    }
};

int main()
{
    cout << "Dual List Queue Program" << endl;
    dllist_t<int> q;
    while(true)
    {
        auto cmd = 0;
        cout << endl << "choose action" << endl;
        cout << "1: push, 2: pop, 3: goto_prev, 4: goto_next, 5: goto_top, 6: goto_rear, 7: get_cur_data, 8: empty, 9: end" << endl;
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
            cout << q.goto_prev() << endl;
            break;
        case 4:
            cout << q.goto_next() << endl;
            break;
        case 5:
            cout << q.goto_top() << endl;
            break;
        case 6:
            cout << q.goto_rear() << endl;
            break;
        case 7:
            cout << q.get_cur_data() << endl;
            break;
        case 8:
            cout << q.empty() << endl;
            break;
        case 9:
            return 0;
            break;
        default:
            cout << "wrong choice." << endl;
            break;
        }
    }
}