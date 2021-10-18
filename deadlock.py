if __name__ == "__main__":
    # number of processes
    n = 5 
    # number of resources 
    m = 4
    # allocation matrix 
    alloc = [[0, 0, 1, 2], [1, 0, 0, 0], [1, 3, 5, 4], [0, 6, 3, 2], [0, 0, 1, 4]]
    # max resource matrix 
    max = [[0, 0, 1, 2], [1, 7, 5, 0], [2, 3, 5, 6], [0, 6, 5, 2], [0, 6, 5, 6]]
    # available 
    avail = [1, 5, 2, 0]


    f = [0]*n   # N urttai 0 matrix 
    ans = [0]*n # N urttai 0 matrix
    ind = 0 
    for k in range(n):
        f[k] = 0
          
    need = [[ 0 for i in range(m)]for i in range(n)]
    for i in range(n):
        for j in range(m):
            need[i][j] = max[i][j] - alloc[i][j]
    y = 0
    for k in range(5):
        for i in range(n):
            if (f[i] == 0):
                flag = 0
                for j in range(m):
                    if (need[i][j] > avail[j]):
                        flag = 1
                        break
                  
                if (flag == 0):
                    ans[ind] = i
                    ind += 1
                    for y in range(m):
                        avail[y] += alloc[i][y]
                    f[i] = 1
                      
    print("Program safe ajillaj baina \n")
      
    for i in range(n - 1):
        print(" P", ans[i], " ->", sep="", end="")
    print(" P", ans[n - 1], sep="")
    
