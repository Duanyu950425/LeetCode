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