#include <bits/stdc++.h>
using namespace std;

class min_heap
{
public:
    vector<int> nodes;
    min_heap() {}

    void up_heapify()
    {
        int cur_idx = nodes.size() - 1;
        int comp_idx = (cur_idx - 1) / 2;
        if (cur_idx >= 0 && comp_idx >= 0 && nodes[cur_idx] < nodes[comp_idx])
        {
            swap(nodes[cur_idx], nodes[comp_idx]);
            cur_idx = comp_idx;
            comp_idx = (cur_idx - 1) / 2;
        }
    }

    void down_heapify(int idx)
    {
        while (true)
        {
            int cur_idx = idx;
            int cur_left = cur_idx * 2 + 1;
            int cur_right = cur_idx * 2 + 2;

            if (cur_left < nodes.size() && nodes[cur_idx] > nodes[cur_left])
            {
                cur_idx = cur_left;
            }

            if (cur_right < nodes.size() && nodes[cur_idx] > nodes[cur_right])
            {
                cur_idx = cur_right;
            }

            if (cur_idx == idx)
            {
                break;
            }
            swap(nodes[cur_idx], nodes[idx]);
            idx = cur_idx;
        }
    }

    void insert(int val)
    {
        nodes.push_back(val);
        up_heapify();
    }

    void delet(int idx)
    {
        if (nodes.empty() == true)
        {
            return;
        }
        int last_idx = nodes.size() - 1;
        swap(nodes[0], nodes[last_idx]);
        nodes.pop_back();
        down_heapify(0);
    }

    int exact_min()
    {
        if (nodes.empty() == true)
            return -1;

        int return_num = nodes[0];
        delet(0);
        return return_num;
    }

    void display()
    {
        for (auto it : nodes)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
};

vector<int> heap_sort(vector<int> &v)
{
    min_heap mn;
    for (auto it : v)
    {
        mn.insert(it);
    }
    vector<int> result;
    for (int i = 0; i < v.size(); i++)
    {
        result.push_back(mn.exact_min());
    }
    return result;
}

int main()
{
    /*min_heap mn;
    mn.insert(2);
    mn.insert(6);
    mn.insert(1);
    mn.insert(9);
    mn.insert(7);
    mn.display();*/
    vector<int> v = {7, 9, 3, 2, 1, 2, 7};
    vector<int> sort_v = heap_sort(v);
    for (auto it : sort_v)
    {
        cout << it << " ";
    }
}

