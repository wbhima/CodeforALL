# Python program to sort a string and return
# its reverse string according to pattern string

# This function will return the reverse of sorted string
# according to the pattern

def sortbyPattern(pat, str):

	priority = list(pat)

	# Create a dictionary to store priority of each character
	myDict = { priority[i] : i for i in range(len(priority))}

	str = list(str)

	# Pass lambda function as key in sort function
	str.sort( key = lambda ele : myDict[ele])

	# Reverse the string using reverse()
	str.reverse()

	new_str = ''.join(str)
	return new_str


if __name__=='__main__':
	pat = "asbcklfdmegnot"
	str = "eksge"
	new_str = sortbyPattern(pat, str)
	print(new_str)
