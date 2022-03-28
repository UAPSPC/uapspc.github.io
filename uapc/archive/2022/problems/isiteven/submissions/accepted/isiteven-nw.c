main(p,n,k,x){for(scanf("%d %d",&n,&k);n--;)for(scanf("%d",&x);~x&1;x/=2)++p;printf("%d",p>k);}
