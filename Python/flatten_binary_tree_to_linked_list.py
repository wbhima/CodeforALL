# Node class to represent a node of the tree
class Node:
	def __init__(self, data):
		self.data = data
		self.right = None
		self.left = None

# Utility function to print the inorder
# traversal of the tree
def PrintInorderBinaryTree(root):
	if(root == None):
		return
	PrintInorderBinaryTree(root.left)
	print(str(root.data), end = " ")
	PrintInorderBinaryTree(root.right)

# Function to make current node right of
# the last node in the list
def FlattenBinaryTree(root):

	# A global variable which maintains the last node
	# that was added to the linked list
	global last
	if(root == None):
		return
	
	left = root.left
	right = root.right

	# Avoid first iteration where root is
	# the only node in the list
	if(root != last):
		last.right = root
		last.left = None
		last = root
	FlattenBinaryTree(left)
	FlattenBinaryTree(right)
	if(left == None and right == None):
		last = root

# Build the tree
root = Node(1)
root.left = Node(2)
root.left.left = Node(3)
root.left.right = Node(4)
root.right = Node(5)
root.right.right = Node(6)

# Print the inorder traversal of the
# original tree
print("Original inorder traversal : ", end = "")
PrintInorderBinaryTree(root)
print("")

# Global variable to maintain the
# last node added to the linked list
last = root

# Flatten the binary tree, at the beginning
# root node is the only node in the list
FlattenBinaryTree(root)

# Print the inorder traversal of the flattened
# binary tree
print("Flattened inorder traversal : ", end = "")
PrintInorderBinaryTree(root)
