typedef struct node
{
    int n;
    int a[20];
    int b[20];
}yh;
yh a[20];
double s[65535];
int p[20],r[20];
int p2[20]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int main()
{
    int i,j,k,l,m,n,zr,nn;
    double zp,pr;
    int get[20],sk;
    double min;

    while(scanf("%d",&n),n!=0)
    {
        for(i=1;i<=n;i++)
        {
            a[i].n=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&p[i],&r[i],&(m));
            for(j=0;j<m;j++)
            {
                scanf("%d%d",&k,&l);
                a[k].a[a[k].n]=i;
                a[k].b[a[k].n]=l;
                a[k].n=a[k].n+1;
            }
        }
        min=p[1]/(double)(r[1]);
        s[0]=0;
        for(i=1;i<=n;i++)
        {
            get[1]=0;
            sk=1;
            while(sk>0)
            {
                get[sk]++;
                if(get[sk]>n)
                {
                    sk--;
                }
                else
                {
                    if(sk==i)
                    {
                        zp=0;
                        zr=0;
                        for(j=1;j<=sk;j++)
                        {
                            zr+=r[get[j]];
                            zp+=p2[get[j]];
                        }
                        nn=zp;s[nn]=1e100;
                        for(j=1;j<=sk;j++)
                        {
                            zp=s[nn-p2[get[j]]];
                            pr=p[get[j]];
                            for(k=0;k<a[get[j]].n;k++)
                            {
                                if((p2[a[get[j]].a[k]]&nn))
                                pr*=(100-a[get[j]].b[k])/100.0;

                            }
                            zp+=pr;
                            if(zp/zr<min)
                            {
                                min=zp/zr;
                            }
                            if(s[nn]>zp)
                            s[nn]=zp;
                        }

                    }
                    else
                    {
                        sk++;
                        get[sk]=get[sk-1];
                    }
                }
            }
        }
        printf("%.4lf\n",min);
    }
    return 0;
}
