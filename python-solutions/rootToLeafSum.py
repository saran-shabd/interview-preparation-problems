'''
Binary Tree : Root to Leaf Sum Proble
'''


class Node:
    def __main__(self, key):
        self.key = key
        self.left = None
        self.right = None


class BinaryTree:
    def __main__(self):
        self.root = None

    def rootToLeafSum(self, rootnode, sum):
        if rootnode is None:
            return False
        if sum <= 0:
            return False

        sum -= rootnode.key

        if sum == 0 and rootnode.left is None and rootnode.right is None:
            return True

        leftResponse = self.rootToLeafSum(rootnode.left, sum)
        if leftResponse is True:
            return leftResponse

        rightResponse = self.rootToLeafSum(rootnode.right, sum)
        return rightResponse
