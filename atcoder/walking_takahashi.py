from math import floor, ceil

num_arr = input().split(" ")
X = int(num_arr[0])
K = int(num_arr[1])
D = int(num_arr[2])

if abs(X) >= K*D:  
    print(abs(X) - K*D)
else:
    steps_needed = floor(abs(X)/D)
    
    if (K - steps_needed)%2 == 0:
        print(abs(abs(X) - steps_needed * D))
    else:
        print(abs(abs(X) - (steps_needed+1)*D))
    
    
    

    
    # if (steps_needed % 2 == 1) and (K % 2 == 1):
    #     print(abs(abs(X) - steps_needed * D))
    # elif (steps_needed % 2 == 1) and (K % 2 == 0):
    #     print(abs(abs(X) - alt_steps_needed * D))
    # elif (steps_needed % 2 == 0) and (K % 2 == 0):
    #     print(abs(abs(X) - steps_needed * D))
    # elif (steps_needed % 2 == 0) and (K % 2 == 1):
    #     print(abs(abs(X) - alt_steps_needed * D))
    # print(lower_steps_needed, lower_min_dist)
    # print(upper_steps_needed, upper_min_dist)
 