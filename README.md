LeetCode
========
##Longest Consecutive Sequence
应该是用hash查找，编译器如果支持C++ 11，则可以直接使用STD里面的hash，算法复杂度O(n),能过。这里直接使用set替代，但是set是使用红黑树实现的。  

##Word Ladder
使用BFS查找,每个深度查询的时候，记录下queue的size，这样就知道这个深度下面一共有几个待检查的元素。

##Word Ladder 2
还是BFS查找，只是需要记录所有可以查找到的路径，因此不能找到就返回，需要把相同深度的便利完，才能最终确定找到，同理，每轮清除dict中的元素的时候，也是得这轮查找玩，然后再从dict中清除。有个小陷阱就是需要注意，每轮queue进入的元素可能有重复的，需要用个set确保每轮queue里面的元素是一个set集合。

##Minimum Depth of Binary Tree
就是个BFS，每个节点加入队列，查到左，右子节点都是NULL代表到了叶节点了，返回当前查找的深度。

##Balanced Binary Tree
递归求解树的高度，为了解决重复计算子节点高度问题（一遍计算高度，一遍判断是否平衡），采用后续遍历树，这样计算高度和检查是否平衡可以同时进行。

##Same Tree
递归比较下就可以了

#Longest Palindromic Substring
函数f(n)表示到第n个位置最长的回文字符，则f(n+1)就是从n+1个位置开始往前最长的回文与f(n)的回文长度更大的那个回文字符

#Add Two Numbers
递归的增加，只是每次增加的时候带上进位

#Longest Substring Without Repeating Characters
设计函数f(n)，到第n个位置的最长子不重复子序列长度，则f(n+1)就是比较从n+1个位置开始往前数的最长不重复子序列和f(n)两者的较大值

#Median of Two Sorted Arrays
查找第K个数，因为已经排序好，查找算法相当于二分查找方法。

##Two Sum
做个排序，然后从两头开始加，找到合适的两个数，算法复杂度O(nlogn)，或者使用hash，查找item，target-item, 这样算法复杂度O(n)
 
