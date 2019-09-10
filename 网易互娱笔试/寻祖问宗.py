"""/*
姓氏是人的符号标志，是家族血脉的传承；族谱是家族血脉传承的文字记载。
同姓的两个中国人，根据族谱或许能够查出上面几代内是同一个祖先。查一下族谱，
也许当代某位同姓名人就是你的远房亲戚，惊喜不惊喜，意外不意外！！！
输入
二元查找树（
1.若左子树不空，左子树值都小于父节点；
2.如右子树不空，右子树值都大于父节点；
3.左、右子树都是二元查找树；
4. 没有键值相等的节点）

二元查找树上任意两个节点的值，请找出它们最近的公共祖先。
输入三行行，第一行为树层级，第二行为数节点（其中-1表示为空节点），第三行为需要查找祖先的两个数。
在例图中（虚线框没有真实节点，为了输入方便对应位置输-1）查找12和20的最近公共祖先
输入为：
4
9 6 15 2 -1 12 25 -1 -1 -1 -1 -1 -1 20 37
12 20
输出
输出给出两个数在树上的最近公共祖先数值，如果没有公共祖先，输出-1；如果其中一个节点是另一个节点的祖先，
输出这个祖先点（如例图中找15、20最近公共祖先，输出15）；如果输入无效，输出-1。

样例输入
4
9 6 15 2 -1 12 25 -1 -1 -1 -1 -1 -1 20 37
12 20

样例输出
15
 */"""

def get_same_father(arr,son1,son2,max_row):
    if son1 not in arr or son2 not in arr:
        print(-1)
        return

    root_index = 0
    while root_index < len(arr):
        if arr[root_index] > min(son1,son2) and arr[root_index] < max(son1,son2):
            print(arr[root_index])
            return
        elif arr[root_index] in [son1,son2] or arr[root_index] in [son1,son2]:
            print(arr[root_index])
            return
        elif arr[root_index] < min(son1,son2):
            root_index = root_index*2+2
        else:
            root_index = root_index*2+1
    print(-1)
    return
        
def main():
    arr = list(map(int,'9 6 15 2 -1 12 25 -1 -1 -1 -1 -1 -1 20 37'.split(' ')))
    son1,son2 = 12,20
    max_row = 4 #用不到这个
    get_same_father(arr,son1,son2,max_row)

if __name__ == '__main__':
    main()