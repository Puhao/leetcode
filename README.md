leetcode
========
##Same Tree
递归比较下就可以了

##Longest Consecutive Sequence
应该是用hash查找，但是C++里面没有hash的STL，直接使用set替代，算法复杂度还是O(n)  

##Minimum Depth of Binary Tree
就是个BFS，每个节点加入队列，查到左，右子节点都是NULL代表到了叶节点了，返回当前查找的深度。

##Word Ladder
使用BFS查找,每个深度查询的时候，记录下queue的size，这样就知道这个深度下面一共有几个待检查的元素。