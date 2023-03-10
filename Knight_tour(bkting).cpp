 #include<bits/stdc++.h>
 using namespace std;
 #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 #define n 7

 bool valid(int nx,int ny,int &count)
 {
      if(nx<0 || nx>n || ny<0 || ny>n)
        return false;
      count++;
     return true;
 }
 bool go(int mat[n][n],int x,int y, int mv,int dx[n],int dy[n])
 {
     if(mv==n*n)
        return true;
     int count=0;
     for(int k=0;k<8;k++)
     {
         int nx=x+dx[k];
         int ny=y+dy[k];
         if(valid(nx,ny,count) and mat[nx][ny]==-1)
         {

             mat[nx][ny]=mv;
             if(go(mat,nx,ny,mv+1,dx,dy))
             {
                 cout<<count<<endl;
                 return true;
             }
             mat[nx][ny]=-1;

         }
     }
     return false;
 }
 int main()
 {

     int mat[n][n];
     memset(mat,-1,sizeof(mat));
     mat[0][0]=0;
     int dx[8]={1,1,-1,-1,2,2,-2,-2};
     int dy[8]={2,-2,2,-2,1,-1,1,-1};
     if(go(mat,0,0,1,dx,dy))
     {

         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 cout<<mat[i][j]<<" ";
             }
             cout<<endl;
         }
     }
     return 0;
 }
