# wrr
nignx smooth weighted round-robin balancing的一个简单实现【4个元素：ABCD】
算法请参考：https://github.com/nginx/nginx/commit/52327e0627f49dbda1e8db695e63a4b0af4448b1
实现参考了：https://github.com/SunilBojanapally/WRR-Scheduler
1,编译过程：#gcc mywrr4.c -o mywrr4
2,运行实例：ABCD的权重分别为 3 4 1 2
3,
#./mywrr4 3 4 1 2
node[0].name=[A] and node.weight=[3]
node[1].name=[B] and node.weight=[4]
node[2].name=[C] and node.weight=[1]
node[3].name=[D] and node.weight=[2]
total_weight=[10]
############################################################
current.weight is[3,4,1,2] so max value is node[1].weight[4] and select node[1].name[B]
current.weight is[3,-6,1,2]
current.weight is[6,-2,2,4] so max value is node[0].weight[6] and select node[0].name[A]
current.weight is[-4,-2,2,4]
current.weight is[-1,2,3,6] so max value is node[3].weight[6] and select node[3].name[D]
current.weight is[-1,2,3,-4]
current.weight is[2,6,4,-2] so max value is node[1].weight[6] and select node[1].name[B]
current.weight is[2,-4,4,-2]
current.weight is[5,0,5,0] so max value is node[0].weight[5] and select node[0].name[A]
current.weight is[-5,0,5,0]
current.weight is[-2,4,6,2] so max value is node[2].weight[6] and select node[2].name[C]
current.weight is[-2,4,-4,2]
current.weight is[1,8,-3,4] so max value is node[1].weight[8] and select node[1].name[B]
current.weight is[1,-2,-3,4]
current.weight is[4,2,-2,6] so max value is node[3].weight[6] and select node[3].name[D]
current.weight is[4,2,-2,-4]
current.weight is[7,6,-1,-2] so max value is node[0].weight[7] and select node[0].name[A]
current.weight is[-3,6,-1,-2]
current.weight is[0,10,0,0] so max value is node[1].weight[10] and select node[1].name[B]
current.weight is[0,0,0,0]
############################################################
result=BADBACBDAB
############################################################
