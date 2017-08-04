# IntervalBinarySearchTrees

This is a part of my Diploma thesis.
It shows a data structure called Interval Trees.
The base of the Interval Tree is Binary Search Tree(BST).

The idea is to augment a self-balancing Binary Search Tree (BST)
in order to maintain the intervals and all operations can be done in O(Logn) time.
Every node of Interval Tree stores following information.
a) i: An interval which is represented as a pair [low, high]
b) max: Maximum high value in subtree rooted with this node.

The low value of an interval is used as key to maintain order in BST. The insert and delete operations are same as insert and delete in self-balancing BST used.

How does the above algorithm work?
Let the interval to be searched be x. We need to prove this in for following two cases.

Case 1: When we go to right subtree, one of the following must be true.
a) There is an overlap in right subtree: This is fine as we need to return one overlapping interval.
b) There is no overlap in either subtree: We go to right subtree only when either left is NULL or maximum value in left is smaller than x.low. So the interval cannot be present in left subtree.

Case 2: When we go to left subtree, one of the following must be true.
a) There is an overlap in left subtree: This is fine as we need to return one overlapping interval.
b) There is no overlap in either subtree: This is the most important part. We need to consider following facts.
… We went to left subtree because x.low <= max in left subtree
…. max in left subtree is a high of one of the intervals let us say [a, max] in left subtree.
…. Since x doesn’t overlap with any node in left subtree x.low must be smaller than ‘a‘.
…. All nodes in BST are ordered by low value, so all nodes in right subtree must have low value greater than ‘a‘.
…. From above two facts, we can say all intervals in right subtree have low value greater than x.low. So x cannot overlap with any interval in right subtree.


Queries require O(log n + m) time, with n being the total number of intervals and m being the number of reported results. 
Construction requires O(n log n) time, and storage requires O(n) space.

https://en.wikipedia.org/wiki/Interval_tree
