#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> answer(2);

struct Node {
    int data;
    int x, y;
    Node* left, * right;
};

void preorder(Node* root)
{
    //root가 null이 아니라면
    if (root)
    {
        answer[0].push_back(root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
{
    //root가 null이 아니라면
    if (root)
    {   
        postorder(root->left);
        postorder(root->right);
        answer[1].push_back(root->data);
    }
}
bool comp(Node& a, Node& b)
{
    if (a.y == b.y)
        return a.x < b.x;
    else
        return a.y > b.y;
}

void insert(Node* parent, Node* child)
{
    if(child->x < parent->x)
    {
        if (parent->left)
            insert(parent->left, child);
        else
            parent->left = child;
    }
    else
    {
        if (parent->right)
            insert(parent->right, child);
        else
            parent->right = child;
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
        
    vector<Node> n;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        n.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
    }

    //y값 내림차순, x값 오름차순
    sort(n.begin(), n.end(), comp);

    Node* root = &n[0];
    for (int i = 1; i < n.size(); i++)
    {
        insert(root, &n[i]);
    }

    preorder(root);
    postorder(root);

    return answer;
}

//Ref:::https://blog.naver.com/csezsw/221552558499