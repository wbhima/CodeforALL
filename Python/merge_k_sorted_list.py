# Program to merge K sorted arrays of size 'N' each.
N = 6

# printArray() function for printing array elements.
def printArray(arr, size):
    for itr in range(size):
        print(arr[itr], end = " ")

# mergeArrays() function, that will merge firstArr and secondArr to form mergeArr.
def mergeArrays(firstArr, secondArr, firstSize, secondSize, mergeArr):
    i, j, k = 0, 0, 0
    # Traverse both array
    while(i < firstSize and j < secondSize):
        if(firstArr[i] < secondArr[j]):
            mergeArr[k] = firstArr[i]
            k += 1
            i += 1
        else:
            mergeArr[k] = secondArr[j]
            k += 1
            j += 1
    # Remaining elements of first array
    while(i < firstSize):
        mergeArr[k] = firstArr[i]
        k += 1
        i += 1
    # Remaining elements of second array
    while(j < secondSize):
        mergeArr[k] = secondArr[j]
        k += 1
        j += 1
 
 
# mergeKArrays() function, that will take 'k' sorted arrays as argument,
# and prpint the final merged array after merging.
def mergeKArrays(arr, i, j, outputArr):
    global N
    if(i == j):
        for itr in range(N):
            outputArr[itr] = arr[i][itr]
        return
    if(j-i == 1):
        mergeArrays(arr[i], arr[j], N, N, outputArr)
        return
 
    # Output arrays
    firstMerge = [0 for i in range(N * (((i+j)//2) - i+1))]
    secondMerge = [0 for i in range(N * (j-((i+j)//2)))]
 
    # Dividing arrays into hapves.
    mergeKArrays(arr, i, (i+j)//2, firstMerge)
    mergeKArrays(arr, (i+j)//2+1, j, secondMerge)
 
    # Merge the two output arrays.
    mergeArrays(firstMerge, secondMerge, N*(((i+j)/2)-i+1), N*(j-((i+j)/2)), outputArr)
 
 
# main() function or the driver function
if __name__ == '__main__':
    arr = [
        [7, 15, 32, 43, 89, 100],
        [0, 5, 12, 19, 23, 95],
        [13, 27, 31, 43, 57, 67],
        [10, 20, 40, 50, 70, 80]
    ]
    
    print("Arrays Before Merging: ")
    for itr in range(len(arr)):
        printArray(arr[itr], N)
        print()

    K = len(arr)-1
    outputArr = [0 for i in range(N * K)]
 
    # Function call
    mergeKArrays(arr, 0, 2, outputArr)
 
    print("\n\nArray After Merging: ")
    printArray(outputArr, N * K)
 
#  Contributed with 🧡 by Motasim (@motasimmakki)