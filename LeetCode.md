# LeetCode

**题目一：**树——Minimum Depth ofBinary Tree

求给定二叉树的最小深度。最小深度是指树的根结点到最近叶子结点的最短路径上结点的数量。

**题解：**递归，若为空树返回0；

​           若左子树为空，则返回右子树的最小深度+1；（+1是因为要加上根结点）

​           若右子树为空，则返回左子树的最小深度+1；

​           若左右子树都不为空，则取左、右子树最小深度的最小值，+1；

```c++
class Solution
{
public:
    int run(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return run(root->right) + 1;
        if (root->right == NULL)
            return rin(root->left) + 1;
        int leftDepth = run(root->left) + 1;
        int rightDepth = run(root->right) + 1；
        return (leftDepth < rightDepth) ? leftDepth : rightDepth;
    }
}
```

**题目二：**计算逆波兰式（后缀表达式）的值

运算符仅包含"+","-","*"和"/"，被操作数可能是整数或其他表达式

例如：

```
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9↵  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
```

**题解：**遇到操作数就出栈，把计算结果入栈

​                  计算结果时，stack至少有两个数，否则不合法，返回0

​			遇到数字就入栈

​			结果合法

​					如果遍历完成，stack的元素不止一个，说明不合法，返回0；

​					当stack元素只有一个的时候，返回结果

```c++
class Solution {
public:
    int evalRPN(vector<string> &tokens) 
    {
        if (tokens.size() == 0)
            return 0;
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                if (s.size() < 2)
                    return 0;
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if (tokens[i] == "+")
                    s.push(num1 + num2);
                else if (tokens[i] == "-")
                    s.push(num2 - num1);
                else if (tokens[i] == "*")
                    s.push(num1 * num2);
                else
                    s.push(num2 / num1);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        if (s.size() != 1)
            return 0;
        else
            return s.top();
    }
}
```

**题目三：**max-points-on-a-line

对于给定的n个位于同一二维平面上的点，求最多能有多少个点位于同一直线上

**题解：**从头到尾遍历，第一重循环从起始点a开始，第二重循环遍历剩余的b

​           若a和b不重合，就可以确定一条直线

​			对于每个点a，构建斜率->点数 的map

​	（1）b与a重合，以a起始的所有直线点数+1

​	（2）b与a不重合，a与b确定的直线点数+1

```c++
Definition for a point.
struct Point 
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution 
{
public:
    bool compare(double x, double y)
    {
        if (fabs(x - y) < 1e-6)
            return true;
        else
            return false;
    }
    int maxPoints(vector<Point> &points) 
    {
        int size = points.size();
        if (size <= 2)
            return size;
        map<double, int> mp;
        int dup = 0;//重复的点数
        int ver = 0;//垂直的点数
        int curmax = 1;//当前最大的在一条直线上的点数
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                double x_dis = points[i].x - points[j].x;
                double y_dis = points[i].y - points[j].y;
                if (compare(points[i].x, points[j].x) && compare(points[i].y, points[j].y))
                    dup++;
                else if (compare(x_dis, 0.0))
                {
                    if (ver == 0)
                        ver = 2;
                    else
                        ver++;
                    curmax = curmax > ver ? curmax : ver;
                }
                else
                {
                    double k = y_dis / x_dis;
                    if (mp[k] == 0)
                        mp = 2;
                    else
                        mp++;
                    curmax = curmax >mp[k] ? curmax : mp[k];
                }
            }
            ret = ret > (curmax + dup) ? ret : (curmax + dup);
        }
        return ret;
    }
};
```

**题目四：**sort-list

在O(n log n)的时间内使用常数级空间复杂度对链表进行排序。

**题解：**我们可以考虑归并算法。

归并算法的一般步骤为：

1） 将待排序数组（链表）取重点并一分为二；

2） 递归地对左半部分进行归并排序；

3） 递归地对右半部分进行归并排序；

4） 将两半部分进行合并，得到结果

所以对应此题目，可以划分为三个小问题：

1） 找到链表重点（快慢指针思路，快指针一次走两步，慢指针一次走一步，快指针在链表尾部时，慢指针恰好在链表中点）；

2） 写出merge函数，即如何合并链表

3） 写出mergesort函数，实现上述步骤

```c++
class Solution
{
public:
    ListNode *FindMid(ListNode *head)
    {
        ListNode *pSlow = head;
        ListNode *pFast = head;
        while (pFast != NULL && pFast->next != NULL && pFast->next->next != NULL)
        {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        return pSlow;
    }
    ListNode *MergeSort(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        ListNode *MergeHead = new ListNode(0);
        ListNode *head = MergeHead;
        while (left != NULL && right != NULL)
        {
            if (left->val < right->val)
            {
                head->next = left;
                left = left->next;
            }
            else
            {
                head->next = right;
                right = right-next;
            }
            head = head->next;
        }
        if (left == NULL)
            head->next = right;
        if (right == NULL)
            head->next = left;
        return MergeHead->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)//空链表或是单一链表
            return head;
        ListNode *mid = FindMid(head);
        ListNode *left = sortList(mid->next);
        mid->next = NULL;
        ListNode *right = sortList(head);
        return MergeSort(left, right);
    }
}
```

