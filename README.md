LeetCode
========
##Longest Consecutive Sequence
应该是用hash查找，但是C++里面没有hash的STL，直接使用set替代，算法复杂度还是O(n) 

##Word Ladder
使用BFS查找,每个深度查询的时候，记录下queue的size，这样就知道这个深度下面一共有几个待检查的元素。

##Minimum Depth of Binary Tree
就是个BFS，每个节点加入队列，查到左，右子节点都是NULL代表到了叶节点了，返回当前查找的深度。

##Balanced Binary Tree
递归求解树的高度，为了解决重复计算子节点高度问题（一遍计算高度，一遍判断是否平衡），采用后续遍历树，这样计算高度和检查是否平衡可以同时进行。

##Same Tree
递归比较下就可以了
 
