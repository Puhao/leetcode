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

##Construct Binary Tree from Inorder and Postorder Traversal
递归构造

##Construct Binary Tree from Preorder and Inorder Traversal
递推构造

##Same Tree
递归比较下就可以了

##Merge Two Sorted Lists
递归合并

##Reverse Nodes in k-Group
通过一个reverse函数来实现k组的reverse

##Swap Nodes in Pairs
递归合并，题目要求只能常数空间的话，就使用while循环，记录一个pre指针。

##Merge k Sorted Lists
两两归并

##Generate Parentheses
DFS产生所有的组合

##Valid Parentheses
用一个stack记录元素，然后配对出栈，不然就是不符合的，最后检查栈为空

##Remove Nth Node From End of List
两个指针，一个先移动n步

##Letter Combinations of a Phone Number
DFS查找所有结果

##4Sum
可以两两一组，然后hash来做，降低复杂度到O(n<sup>2</sup>)

##3Sum Closest
轮询每个数，记住最小差，退化为2Sum问题

##3Sum
轮询每个数字，退化为2Sum问题

##Longest Common Prefix
把握细节

##Roman to Integer
根据罗马数字规则，进行转换.

##Integer to Roman
[Roman数字](http://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97)写法。

##Container With Most Water
头尾指针移动,数学归纳证明和排序好的数组找两个值相加为某个定值是一样的。

##Regular Expression Matching
递归比较

##Palindrome Number
从reverse integer提示，比较两头数值

##String to Integer (atoi)
考虑各种情形

##Reverse Integer
就是把输入的数的个位依次变成另外一个数的高位


##ZigZag Conversion
创建一个nRows的vector<vector <int> >，然后按照题目意思，一个个把char放进对应的vector，最后把nRows个vector依次组成string返回

##Longest Palindromic Substring
函数f(n)表示到第n个位置最长的回文字符，则f(n+1)就是从n+1个位置开始往前最长的回文与f(n)的回文长度更大的那个回文字符

##Add Two Numbers
递归的增加，只是每次增加的时候带上进位

##Longest Substring Without Repeating Characters
设计函数f(n)，到第n个位置的最长子不重复子序列长度，则f(n+1)就是比较从n+1个位置开始往前数的最长不重复子序列和f(n)两者的较大值

##Median of Two Sorted Arrays
查找第K个数，因为已经排序好，查找算法相当于二分查找方法。

##Two Sum
做个排序，然后从两头开始加，找到合适的两个数，算法复杂度O(nlogn)，或者使用hash，查找item，target-item, 这样算法复杂度O(n)
 



