def get_kill_nums(sons,farthers,kill_num):
    farther_son_dic = dict()
    for index,father in enumerate(farthers):
        if father not in farther_son_dic:
            farther_son_dic[father] = [sons[index]]
        else:
            farther_son_dic[father].append(sons[index])
    print(farther_son_dic)

    count = 0
    kill_deque = [kill_num]
    while kill_deque:
        assist_arr = kill_deque[:]
        print(assist_arr)
        kill_deque = []
        count += len(assist_arr)
        # print(count)

        for num in assist_arr:
            if num in farther_son_dic:
                kill_deque += farther_son_dic[num]

    print(count)

def main():
    sons = [3,1,5,21,10]
    farthers = [0,3,3,1,5]
    kill_num = 3
    get_kill_nums(sons,farthers,kill_num)

if __name__ == '__main__':
    main()