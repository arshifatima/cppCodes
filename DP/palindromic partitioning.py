#Palindrome Partitioning | DP-17
#Memory required - O(n), complexity - O(n^2)

print("enter the string:")
str = raw_input("");

def isPalindrome(str, i, j):
        t = 0;
        for k in range(0, j-i):
                if (str[i + t] != str[j - t]):
                        return -1
                t = t+1
        return 0

def palindromeMap(str, i , j, d):
        global c

        if (i == j):
                return 0
        if (isPalindrome(str, i, j) == 0):
                if ( d[i] < (j-i)):
                        d[i] = j - i
                        print( 'i:', i, 'j:', j)
        else:
                palindromeMap(str, i+1, j, d)
                palindromeMap(str, i, j-1, d)
        return 0

def partitionCount(str, i , j):
        w = len(str)
        d = [0 for x in range(w)]
        palindromeMap(str, 0, w-1, d)
        k = 0
        c = 0
        while ( k < w ):
                max_d = 0
                if (d[k] > 0):
                        max_d = max(d[k:k+d[k]])
                        for t in range(k,k+d[k]+1):
                                if (max_d == d[t]):
                                        k = t
                c = c + max_d
                k = k + max_d + 1
        print (w-1-c,' ', str)

partitionCount(str, 0, len(str)-1)