def get_kill_nums(farther_son_dic,kill_num):
    global count
    count += 1
    if kill_num in farther_son_dic:
        sons = farther_son_dic[kill_num]
        for son in sons:
            get_kill_nums(farther_son_dic,son)

def main():
    sons = [3,1,5,21,10]
    farthers = [0,3,3,1,5]
    farther_son_dic = dict()
    for index,father in enumerate(farthers):
        if father not in farther_son_dic:
            farther_son_dic[father] = [sons[index]]
        else:
            farther_son_dic[father].append(sons[index])
    kill_num = 3
    get_kill_nums(farther_son_dic,kill_num)

if __name__ == '__main__':
    count = 0
    main()
    print(count)