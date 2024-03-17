#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define QUEUES 4

struct weight_node
{
	char  name[80];
        int   current_weight;
        int   weight;
};


struct weight_node node[QUEUES];

int getMaxCurrentWeight(struct weight_node *pnode)
{
    int maxw = 0;
    int i=0;

    maxw = pnode[0].current_weight;
    i=0;
    if(pnode[1].current_weight>maxw)
    {
	maxw=pnode[1].current_weight;
        i=1;
    }
    if(pnode[2].current_weight>maxw)
    {
	maxw=pnode[2].current_weight;
        i=2;
    }
    if(pnode[3].current_weight>maxw)
    {
	maxw=pnode[3].current_weight;
        i=3;
    }

    return i;
}


void node_init(int w0,int w1,int w2,int w3)
{
        int i=0;
        for(i=0;i<QUEUES;i++)
        {
                memset(node[i].name,0x00,sizeof(node[i].name));
                node[i].current_weight=0;
                node[i].weight=0;
        }

        strcpy(node[0].name,"A");
        strcpy(node[1].name,"B");
        strcpy(node[2].name,"C");
        strcpy(node[3].name,"D");

        node[0].weight=w0;
        node[1].weight=w1;
        node[2].weight=w2;
        node[3].weight=w3;

}

int  main(int agrc, char *agrv[])
{
        int total_weight=0;
        int i;
        int w0=atoi(agrv[1]);
        int w1=atoi(agrv[2]);
        int w2=atoi(agrv[3]);
        int w3=atoi(agrv[4]);
        node_init(w0,w1,w2,w3);
 
        for(i=0;i<QUEUES;i++)
        {
		printf("node[%d].name=[%s] and node.weight=[%d]\n",i,node[i].name,node[i].weight);
        }

        total_weight=w0+w1+w2+w3;
 
        printf("total_weight=[%d]\n",total_weight);
        printf("\n############################################################\n");
        int j=0;
        char result[1024];
        memset(result,0x00,sizeof(result));

        for(j=0;j<total_weight;j++)
	{
                int k=0;
		for(k=0;k<QUEUES;k++)
		{
			node[k].current_weight+=node[k].weight;
		}	
                //判断max in node[k].current_weight
                int pos=getMaxCurrentWeight(node);
                //printf("pos=[%d]\n",pos);
                printf("current.weight is[%d,%d,%d,%d] so max value is node[%d].weight[%d] and select node[%d].name[%s]\n",node[0].current_weight,node[1].current_weight,node[2].current_weight,
                        node[3].current_weight,pos,node[pos].current_weight,pos,node[pos].name);

                strcat(result,node[pos].name);
                
                node[pos].current_weight-=total_weight;
                printf("current.weight is[%d,%d,%d,%d]\n\n",node[0].current_weight,node[1].current_weight,node[2].current_weight,node[3].current_weight);

        }

        printf("############################################################\n");
        printf("result=%s\n",result);
        printf("############################################################\n");

        return 0; 
}
