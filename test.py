for i in range(2):
    for j in range(2):
        for k in range(2):
            print("{} {} {} {}".format(i, j, k, i^j^k))