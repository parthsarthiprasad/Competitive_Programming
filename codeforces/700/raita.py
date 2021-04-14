def findMaximumPath(mat): 
    rows = cols = len(mat)
    count_list = []

    for i in range(rows):
        summ = 0
        mat_index = [rows-1, cols-1]
        curr_index = [0, i]
        summ = mat[curr_index[0]][curr_index[1]]

        while curr_index[0] != rows-1 and curr_index[1] != cols-1:
            if mat[curr_index[0]][curr_index[1]+1] > mat[curr_index[0]+1][curr_index[1]]:
                   curr_index[1] = curr_index[1] + 1
            else:
                   curr_index[0] = curr_index[0] + 1        

            summ += mat[curr_index[0]][curr_index[1]]
            #print(str(curr_index) + " Sum: " + str(summ))


        if curr_index[0] != rows-1 and curr_index[1] == cols-1:
            for i in range(curr_index[0]+1, rows):
                summ += mat[i][cols-1]
                #print(str(i) + "    Sum1: " +str(summ))

        if curr_index[0] == rows-1 and curr_index[1] != cols-1:
            for i in range(curr_index[1]+1, cols):
                summ += mat[rows-1][i]
                #print(str(i) + "    Sum2: " +str(summ))


        count_list.append(summ)

    max_sum = max(count_list)
    count = 0
    for element in count_list:  
        if(element == max_sum): 
            count+= 1

    print(count_list)
    print("Maximum Sum: " + str(max_sum))
    print("Number of Occurrences: " + str(count) + "\n")



R = int(input("Enter the number of rows:")) 
# C = int(input("Enter the number of columns:")) 
  
# Initialize matrix 
matrix = [] 
print("Enter the entries rowwise:") 
  
# For user input 
for i in range(R):          # A for loop for row entries 
    a =[] 
    for j in range(R):      # A for loop for column entries 
         a.append(int(input())) 
    matrix.append(a) 

findMaximumPath(matrix)

# findMaximumPath(mat2)